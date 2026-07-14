import math
from PIL import Image
from pathlib import Path
import json, sys

T_CONFIG = Path("../tiles/tile_config.json")
I_CONFIG = Path("../itens/itens_config.json")
E_CONFIG = Path("../entidades/entidades_config.json")
MAPS_DIR = Path(".")
OUTPUT   = Path("../../generated/maps.h")
OUTPUT_2 = Path("../../include/area_id.h")

CELL_SIZE         = 16
MAX_ENTS_PER_CELL = 16
GRID_BUCKETS      = 1024
EMPTY             = (0,0,0)

def c_id(s): return s.upper().replace("-","_").replace(" ","_")
def grid_hash(col,row): return ((row*31)^col)&(GRID_BUCKETS-1)

def build_color_map(cfg_path):
    data = json.loads(cfg_path.read_text())
    return { tuple(dict["color"]): f"{e}_create" for e, dict in data.items() if dict["color"] }

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
            f = color_map.get(color)
            if f is None: unknown.add(color); continue
            entries.append((col,row,f))
    for c in unknown:
        print(f"  AVISO [{png_path.name}/{label}]: cor {c} não definida em config")
    return entries

def main():
    for cfg in [T_CONFIG, I_CONFIG, E_CONFIG]:
        if not cfg.exists(): print(f"{cfg} não encontrado"); sys.exit(1)

    areas = sorted(p for p in MAPS_DIR.iterdir() if p.is_dir() and not p.name.startswith("."))
    if not areas: print("Nenhuma área encontrada"); sys.exit(1)

    OUTPUT.parent.mkdir(parents=True, exist_ok=True)

    lines = [
        "/* AUTO-GERADO por generate_mapas.py — não edite */",
        "#pragma once","#include <stdint.h>",
        '#include \"../include/basics.h"',
        '#include \"../include/entity.h"',
        "#include \"../include/grid.h\"",
        '#include "../include/area_id.h"',
        "#include \"tiles.h\"","#include \"itens.h\"","#include \"entidades.h\"","",

        f"static void map_add_tile(Grid *grid, Entity *ent) {{",
        f"    if (!ent) return;",
        f"    grid_add_entity(grid, ent);",
        f"}}",

        f"static void map_add_entity( Grid *grid, EntityList *list, Entity *ent) {{",
        f"    if (!ent) return;",
        f"    grid_add_entity(grid, ent);",
        f"    list->ents[list->count++] = ent;",
        f"}}",
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

        col_img = Image.open(col_png).convert("RGB")
        grid_w  = col_img.width  * CELL_SIZE
        grid_h  = col_img.height * CELL_SIZE

        name = area.name.upper()
        map_names.append(name)
        lines += [f"/* {'─'*60} */",
                  f"/* Área: {area.name} */",
                  f"/* {'─'*60} */",""]

        lines += [
            f"static EntityList ENTIDADES_{name} = {{",
            f"    .ents = {{  }},",
            f"    .count = 0,",
            f"}};",
            "",
            f"static Grid GRID_{name} = {{",
            f"    .cells     = {{ NULL }},",
            f"    .height    = {grid_h},",
            f"    .width     = {grid_w},",
            f"    .cell_size = {CELL_SIZE},",
            f"}};",
            "",
            f"static void map_init_{name}(void) {{"
        ]

        tile_colors = build_color_map(T_CONFIG)
        item_colors = build_color_map(I_CONFIG)
        ent_colors  = build_color_map(E_CONFIG)

        col_entries = load_png_entries(col_png, tile_colors, "colisao")
        item_entries = load_png_entries(ite_png, item_colors, "itens")
        ent_entries = load_png_entries(ent_png, ent_colors,  "entidades")

        for col, row, f in col_entries:
            lines += [f"map_add_tile(&GRID_{name}, {f}({col*CELL_SIZE},{row*CELL_SIZE}));"]

        for col, row, f in item_entries:
            lines += [f"map_add_entity(&GRID_{name}, &ENTIDADES_{name}, {f}({col*CELL_SIZE},{row*CELL_SIZE}));"]

        for col, row, f in ent_entries:
            lines += [f"map_add_entity(&GRID_{name}, &ENTIDADES_{name}, {f}({col*CELL_SIZE},{row*CELL_SIZE}, RIGHT, UP));"]

        lines += [
            f"}};", ""
        ]


    lines += ["static Grid *_grids[] = {"]
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
              "typedef void (*MapInitFn)(void);", "",
              "static MapInitFn _map_init[] = {",
    ]
    for n in map_names: lines.append(f"    [AREA_{n}] = map_init_{n},")
    lines.append("};")

    lines += ["",
        "static Grid *load_area(AreaId id) {",
        "    if(id >= AREA_COUNT) return NULL;",
        "    _map_init[id]();",
        "    return _grids[id];",
        "}"
    ]

    OUTPUT.write_text("\n".join(lines)+"\n")
    print(f"Gerado: {OUTPUT}  ({len(map_names)} áreas)")

    # AreaId enum + get_grid
    area_id_lines = ["#pragma once", ""]
    area_id_lines += ["typedef enum {"]
    for n in map_names: lines.append(f"    AREA_{n},")
    lines += ["    AREA_COUNT,","} AreaId;",""]

if __name__=="__main__": main()
