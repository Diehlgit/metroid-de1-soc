"""
generate_entidades.py  (entidades/)
Lê entidades_config.json e gera generated/entidades.h
Entidades não têm cor fixa no mapa — são instanciadas via entidade_create().
"""

import json
import sys
from pathlib import Path

from PIL import Image

CONFIG = Path("entidades_config.json")
OUTPUT = Path("../../generated/entidades.h")

HITBOX_ENUM = {
    "rectangle": "HITBOX_RECTANGLE",
    "circle": "HITBOX_CIRCLE",
    "triangle": "HITBOX_TRIANGLE",
}
HITBOX_FN = {
    "rectangle": "get_rectangle_cells",
    "circle": "get_circle_cells",
    "triangle": "get_triangle_cells",
}


def to_rgb565(r, g, b):
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)


def c_id(s):
    return s.upper().replace("-", "_").replace(" ", "_")


def gen_pixels(path, name):
    img = Image.open(path).convert("RGBA")
    w, h = img.size
    lines = [f"static const uint16_t {name}_PIXELS[{w * h}] = {{"]
    for y in range(h):
        row = []
        for x in range(w):
            r, g, b, a = img.getpixel((x, y))
            row.append("0x8001" if a < 128 else f"0x{to_rgb565(r, g, b):04X}")
        lines.append("    " + ", ".join(row) + ",")
    lines.append("};")
    return lines, w, h


def hitbox_lines(hb):
    t = hb["type"]
    if t == "rectangle":
        data = f".rectangle = {{ {hb['width']}, {hb['height']} }}"
    elif t == "circle":
        data = f".circle    = {{ {hb['radius']} }}"
    else:
        data = f".triangle  = {{ {hb['width']}, {hb['height']} }}"
    return [
        f"        .type      = {HITBOX_ENUM[t]},",
        f"        .data      = {{ {data} }},",
        f"        .get_cells = {HITBOX_FN[t]},",
    ]


def main():
    if not CONFIG.exists():
        print(f"{CONFIG} não encontrado")
        sys.exit(1)
    ents = json.loads(CONFIG.read_text())["entidades"]
    OUTPUT.parent.mkdir(parents=True, exist_ok=True)

    lines = [
        "/* AUTO-GERADO por generate_entidades.py — não edite */",
        "#pragma once",
        "#include <stdint.h>",
        '#include "../include/basics.h"',
        '#include "../include/entity.h"',
        "",
        "extern CellList get_rectangle_cells(Hitbox*,Coordinates,int);",
        "extern CellList get_circle_cells   (Hitbox*,Coordinates,int);",
        "extern CellList get_triangle_cells (Hitbox*,Coordinates,int);",
        "",
    ]

    # externs — cada entidade tem collision.c e possivelmente read_uart.c / ai.c
    for e in ents:
        if e["on_collision"]:
            lines.append(
                f"extern void {e['on_collision']}(struct Entity*,struct Entity*);"
            )
        if e["think"]:
            lines.append(
                f"extern Intent {e['think']}(Grid *grid, struct Entity *self);"
            )
    lines.append("")

    # pixels + sprite padrão (sprite inicial — idle/parado)
    for e in ents:
        name = c_id(e["name"])
        pxl, w, h = gen_pixels(e["sprite"], name)
        lines += pxl
        lines += [
            f"static Sprite SPRITE_{name} = {{",
            f"    .height={h}, .width={w},",
            f"    .pixels=(uint16_t*){name}_PIXELS,",
            f"}};",
            "",
        ]

    # EntidadeInfo — template para instanciar cada tipo de entidade
    lines += [
        "typedef struct {",
        "    const char *name;",
        "    EntityType  type;",
        "    Sprite     *default_sprite;",
        "    Hitbox      hitbox;",
        "    void (*on_collision)(struct Entity*,struct Entity*);",
        "    Intent (*think)(Grid*, struct Entity*);",
        "} EntidadeInfo;",
        "",
        "static EntidadeInfo ENTIDADE_REGISTRY[] = {",
    ]
    for e in ents:
        name = c_id(e["name"])
        cb = e["on_collision"] if e["on_collision"] else "NULL"
        think = e["think"] if e["think"] else "NULL"
        lines += (
            [
                f"    {{ /* {e['name']} */",
                f'        .name           = "{e["name"]}",',
                f"        .type           = {e['entity_type']},",
                f"        .default_sprite = &SPRITE_{name},",
                f"        .hitbox={{",
            ]
            + ["    " + l for l in hitbox_lines(e["hitbox"])]
            + [
                f"        }},",
                f"        .on_collision={cb},",
                f"        .think={think},",
                f"    }},",
            ]
        )
    lines += [
        "};",
        f"static int ENTIDADE_REGISTRY_SIZE={len(ents)};",
        "",
        "static EntidadeInfo* entidade_info_by_name(const char *name){",
        "    for(int i=0;i<ENTIDADE_REGISTRY_SIZE;i++)",
        "        if(__builtin_strcmp(ENTIDADE_REGISTRY[i].name,name)==0)",
        "            return &ENTIDADE_REGISTRY[i];",
        "    return NULL;",
        "}",
        "",
        "/* Pool estático de instâncias */",
        "#define MAX_ENTIDADE_INSTANCES 32",
        "static Entity _ent_pool[MAX_ENTIDADE_INSTANCES];",
        "static int    _ent_pool_count=0;",
        "",
        "static Entity* entidade_create(EntidadeInfo *info, Coordinates pos){",
        "    if(!info || _ent_pool_count>=MAX_ENTIDADE_INSTANCES) return NULL;",
        "    Entity *e=&_ent_pool[_ent_pool_count++];",
        "    e->position       = pos;",
        "    e->type           = info->type;",
        "    e->hitbox         = info->hitbox;",
        "    e->current_sprite = info->default_sprite;",
        "    e->think          = info->think;",
        "    e->on_collision   = info->on_collision;",
        "    return e;",
        "}",
    ]

    OUTPUT.write_text("\n".join(lines) + "\n")
    print(f"Gerado: {OUTPUT}  ({len(ents)} entidades)")


if __name__ == "__main__":
    main()
