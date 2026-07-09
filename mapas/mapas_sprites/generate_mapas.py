"""
generate_mapas.py  (mapas_sprites/<area>/)
Lê os três PNGs de cada área e os três configs, gera generated/maps.h

Estrutura esperada:
  mapas_sprites/
    starting_area/
      colisao.png
      itens.png
      entidades.png
    boss_arena/
      colisao.png
      itens.png
      entidades.png
"""
from PIL import Image
from pathlib import Path
import json, sys

T_CONFIG = Path("../tiles/tile_config.json")
I_CONFIG = Path("../itens/itens_config.json")
E_CONFIG = Path("../entidades/entidades_config.json")
MAPS_DIR = Path(".")          # rodar de dentro de mapas_sprites/
OUTPUT   = Path("../../generated/maps.h")

CELL_SIZE         = 16
MAX_ENTS_PER_CELL = 16
GRID_BUCKETS      = 1024
EMPTY             = (0,0,0)

HITBOX_ENUM = {"rectangle":"HITBOX_RECTANGLE","circle":"HITBOX_CIRCLE","triangle":"HITBOX_TRIANGLE"}
HITBOX_FN   = {"rectangle":"get_rectangle_cells","circle":"get_circle_cells","triangle":"get_triangle_cells"}

def c_id(s): return s.upper().replace("-","_").replace(" ","_")
def grid_hash(col,row): return ((row*31)^col)&(GRID_BUCKETS-1)

def build_color_map(cfg_path, key):
    data = json.loads(cfg_path.read_text())[key]
    return { tuple(e["color"]): e for e in data if e.get("color") }

def hitbox_lines(hb):
    t = hb["type"]
    if   t=="rectangle": data=f".rectangle={{ {hb['width']}, {hb['height']} }}"
    elif t=="circle":    data=f".circle   ={{ {hb['radius']} }}"
    else:                data=f".triangle ={{ {hb['width']}, {hb['height']} }}"
    return [f"        .type      = {HITBOX_ENUM[t]},",
            f"        .data      = {{ {data} }},",
            f"        .get_cells = {HITBOX_FN[t]},"]

def load_png_entries(png_path, color_map, label):
    """Retorna lista de (col, row, def_dict) para pixels não-vazios."""
    img = Image.open(png_path).convert("RGB")
    w,h = img.size
    entries = []
    unknown = set()
    for row in range(h):
        for col in range(w):
            color = img.getpixel((col,row))
            if color == EMPTY: continue
            d = color_map.get(color)
            if d is None: unknown.add(color); continue
            entries.append((col,row,d))
    for c in unknown:
        print(f"  AVISO [{png_path.name}/{label}]: cor {c} não definida em config")
    return entries

import math

def get_entries_for_ent(col, row, d):
    hb = d["hitbox"]
    t = hb["type"]

    # célula onde está o canto superior esquerdo da entidade
    start_col = col
    start_row = row

    if t == "rectangle":
        width = hb["width"]
        height = hb["height"]

    elif t == "circle":
        # diâmetro
        width = height = hb["radius"] * 2

    elif t == "triangle":
        # aproximação usando o bounding box
        width = hb["width"]
        height = hb["height"]

    else:
        raise ValueError(f"Tipo de hitbox desconhecido: {t}")

    cols = math.ceil(width / CELL_SIZE)
    rows = math.ceil(height / CELL_SIZE)

    entries = []
    for dy in range(rows):
        for dx in range(cols):
            entries.append((start_col + dx, start_row + dy))

    return entries

def gen_entities(lines, map_name, layer_name, entries, idx_offset):
    """Gera Entity estáticas e retorna (cell_to_idxs, próximo idx_offset)."""
    cell_to_idxs = {}
    idx = idx_offset
    for col, row, d in entries:
        ent_name = f"{map_name}_{layer_name}_{idx}"
        px, py   = col*CELL_SIZE, row*CELL_SIZE
        name     = c_id(d["name"])
        cb       = d["on_collision"] if d["on_collision"] else "NULL"
        think    = d["think"]        if d["think"]        else "NULL"
        etype    = d["entity_type"]
        lines += [f"static Entity {ent_name} = {{",
                  f"    .position       = {{ {px},{py} }},",
                  f"    .type           = {etype},",
                  f"    .hitbox         = {{"] + \
                 hitbox_lines(d["hitbox"]) + \
                 [f"    }},",
                  f"    .current_sprite = &SPRITE_{name},",
                  f"    .think          = {think},",
                  f"    .on_collision   = {cb},",
                  f"}};"]

        for cell_col, cell_row in get_entries_for_ent(col, row, d):
            cell_to_idxs.setdefault((cell_col, cell_row), []).append(ent_name)
        idx += 1
    lines.append("")
    return cell_to_idxs, idx

def merge_cell_maps(*maps):
    merged = {}
    for m in maps:
        for key,names in m.items():
            merged.setdefault(key,[]).extend(names)
    return merged

def main():
    for cfg in [T_CONFIG, I_CONFIG, E_CONFIG]:
        if not cfg.exists(): print(f"{cfg} não encontrado"); sys.exit(1)

    tile_colors = build_color_map(T_CONFIG, "tiles")
    item_colors = build_color_map(I_CONFIG, "itens")
    ent_colors  = build_color_map(E_CONFIG, "entidades")

    areas = sorted(p for p in MAPS_DIR.iterdir()
                   if p.is_dir() and not p.name.startswith("."))
    if not areas: print("Nenhuma área encontrada"); sys.exit(1)

    OUTPUT.parent.mkdir(parents=True, exist_ok=True)

    lines = [
        "/* AUTO-GERADO por generate_mapas.py — não edite */",
        "#pragma once","#include <stdint.h>",
        '#include \"../include/basics.h"',
        '#include \"../include/entity.h"',
        "#include \"../include/grid.h\"",
        "#include \"tiles.h\"","#include \"itens.h\"","#include \"entidades.h\"","",
        f"#define CELL_SIZE         {CELL_SIZE}",
        f"#define MAX_ENTS_PER_CELL {MAX_ENTS_PER_CELL}",
        f"#define GRID_BUCKETS      {GRID_BUCKETS}","",
    ]

    map_names = []

    for area in areas:
        col_png = area/"colisao.png"
        ite_png = area/"itens.png"
        ent_png = area/"entidades.png"
        missing = [p for p in [col_png,ite_png,ent_png] if not p.exists()]
        if missing:
            print(f"  AVISO [{area.name}]: faltam {[p.name for p in missing]}, pulando")
            continue

        name = c_id(area.name)
        map_names.append(name)
        lines += [f"/* {'─'*60} */",
                  f"/* Área: {area.name} */",
                  f"/* {'─'*60} */",""]

        col_img = Image.open(col_png).convert("RGB")
        grid_w  = col_img.width  * CELL_SIZE
        grid_h  = col_img.height * CELL_SIZE

        col_entries = load_png_entries(col_png, tile_colors, "colisao")
        ite_entries = load_png_entries(ite_png, item_colors, "itens")
        ent_entries = load_png_entries(ent_png, ent_colors,  "entidades")

        idx = 0
        col_cells, idx = gen_entities(lines, name, "COL", col_entries, idx)
        ite_cells, idx = gen_entities(lines, name, "ITE", ite_entries, idx)
        first_ent_idx = idx
        ent_cells, idx = gen_entities(lines, name, "ENT", ent_entries, idx)
        last_ent_idx = idx

        all_cells = merge_cell_maps(col_cells, ite_cells, ent_cells)

        # GridEntries
        for (col,row), ent_names in all_cells.items():
            entry = f"{name}_GENTRY_{col}_{row}"
            ptrs  = ", ".join(f"&{n}" for n in ent_names)
            lines += [f"static GridEntry {entry} = {{",
                      f"    .key  = {{ {col},{row} }},",
                      f"    .cell = {{ .ents={{{ptrs}}}, .count={len(ent_names)} }},",
                      f"    .next = NULL,",
                      f"}};"]
        lines.append("")

        # Entidades
        ents_lines = ""
        for i in range(last_ent_idx - first_ent_idx):
            ents_lines += f"&{name}_ENT_{first_ent_idx + i}, "

        lines += [
            f"static EntityList ENTIDADES_{name} = {{",
            f"    .ents = {{ {ents_lines} }},",
            f"    .count = {last_ent_idx - first_ent_idx},",
            f"}};",
            "",
        ]

        # Grid
        lines += [f"static Grid GRID_{name} = {{",
                  f"    .cells     = {{ NULL }},",
                  f"    .height    = {grid_h},",
                  f"    .width     = {grid_w},",
                  f"    .cell_size = {CELL_SIZE},",
                  f"}};",""]

        # map_init: encadeia GridEntries nos buckets
        lines += [f"static void map_init_{name}(void) {{"]
        for (col,row) in all_cells:
            bucket = grid_hash(col,row)
            entry  = f"{name}_GENTRY_{col}_{row}"
            lines += [f"    {entry}.next = GRID_{name}.cells[{bucket}];",
                      f"    GRID_{name}.cells[{bucket}] = &{entry};"]
        lines += ["}",""]

    # AreaId enum + get_grid
    lines += ["typedef enum {"]
    for n in map_names: lines.append(f"    AREA_{n},")
    lines += ["    AREA_COUNT,","} AreaId;","",
              "static Grid *_grids[] = {"]
    for n in map_names: lines.append(f"    [AREA_{n}] = &GRID_{n},")
    lines += ["};", "",]

    lines += ["static EntityList *_entidades[] = {"]
    for n in map_names: lines.append(f"    [AREA_{n}] = &ENTIDADES_{n},")

    lines += ["};","",
              "static Grid* get_grid(AreaId id){",
              "    if(id>=AREA_COUNT) return NULL;",
              "    return _grids[id];",
              "}","",
              "static EntityList* get_entidades(AreaId id){",
              "    if(id>=AREA_COUNT) return NULL;",
              "    return _entidades[id];",
              "}","",
              "static void maps_init(void){"]
    for n in map_names: lines.append(f"    map_init_{n}();")
    lines.append("}")

    OUTPUT.write_text("\n".join(lines)+"\n")
    print(f"Gerado: {OUTPUT}  ({len(map_names)} áreas)")

if __name__=="__main__": main()
