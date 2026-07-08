"""
generate_itens.py  (itens/)
Lê itens_config.json e gera generated/itens.h
"""

import json
import sys
from pathlib import Path

from PIL import Image

CONFIG = Path("itens_config.json")
OUTPUT = Path("../../generated/itens.h")

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
    itens = json.loads(CONFIG.read_text())["itens"]
    OUTPUT.parent.mkdir(parents=True, exist_ok=True)

    lines = [
        "/* AUTO-GERADO por generate_itens.py — não edite */",
        "#pragma once",
        "#include <stdint.h>",
        '#include "../include/structs.h"',
        "",
        "extern CellList get_rectangle_cells(Hitbox*,Coordinates,int);",
        "extern CellList get_circle_cells   (Hitbox*,Coordinates,int);",
        "extern CellList get_triangle_cells (Hitbox*,Coordinates,int);",
        "",
    ]

    # externs — cada item tem seu próprio collision.c em itens/<nome>/
    for it in itens:
        if it["on_collision"]:
            lines.append(
                f"extern void {it['on_collision']}(struct Entity*,struct Entity*);"
            )
        if it["think"]:
            lines.append(
                f"extern Intent {it['think']}(Grid *grid, struct Entity *self);"
            )
    lines.append("")

    # pixels + sprites
    for it in itens:
        name = c_id(it["name"])
        pxl, w, h = gen_pixels(it["sprite"], name)
        lines += pxl
        lines += [
            f"static Sprite SPRITE_{name} = {{",
            f"    .height={h}, .width={w},",
            f"    .pixels=(uint16_t*){name}_PIXELS,",
            f"}};",
            "",
        ]

    # ItemInfo registry  (análogo ao TileInfo)
    lines += [
        "typedef struct {",
        "    uint8_t r,g,b;",
        "    Sprite *sprite;",
        "    Hitbox  hitbox;",
        "    void (*on_collision)(struct Entity*,struct Entity*);",
        "    void (*think)(struct Entity*);",
        "} ItemInfo;",
        "",
        "static ItemInfo ITEM_REGISTRY[] = {",
    ]
    for it in itens:
        name = c_id(it["name"])
        color = it.get("color") or [0, 0, 0]
        r, g, b = color
        cb = it["on_collision"] if it["on_collision"] else "NULL"
        think = it["think"] if it["think"] else "NULL"
        lines += (
            [
                f"    {{ /* {it['name']} */",
                f"        .r={r},.g={g},.b={b},",
                f"        .sprite=&SPRITE_{name},",
                f"        .hitbox={{",
            ]
            + ["    " + l for l in hitbox_lines(it["hitbox"])]
            + [
                f"        }},",
                f"        .on_collision={cb},",
                f"        .think={think},",
                f"    }},",
            ]
        )
    lines += [
        "};",
        f"static int ITEM_REGISTRY_SIZE={len(itens)};",
        "",
        "static ItemInfo* item_from_color(uint8_t r,uint8_t g,uint8_t b){",
        "    for(int i=0;i<ITEM_REGISTRY_SIZE;i++){",
        "        ItemInfo *it=&ITEM_REGISTRY[i];",
        "        if(it->r==r&&it->g==g&&it->b==b) return it;",
        "    }",
        "    return nullptr;",
        "}",
        "",
        "/* Cria uma Entity de item na posição dada (alocação estática via pool) */",
        "#define MAX_ITEM_INSTANCES 64",
        "static Entity _item_pool[MAX_ITEM_INSTANCES];",
        "static int    _item_pool_count = 0;",
        "",
        "static Entity* item_create(ItemInfo *info, Coordinates pos){",
        "    if(!info || _item_pool_count >= MAX_ITEM_INSTANCES) return nullptr;",
        "    Entity *e = &_item_pool[_item_pool_count++];",
        "    e->position       = pos;",
        "    e->type           = ENTITY_ITEM;",
        "    e->hitbox         = info->hitbox;",
        "    e->current_sprite = info->sprite;",
        "    e->think          = info->think;",
        "    e->on_collision   = info->on_collision;",
        "    return e;",
        "}",
    ]

    OUTPUT.write_text("\n".join(lines) + "\n")
    print(f"Gerado: {OUTPUT}  ({len(itens)} itens)")


if __name__ == "__main__":
    main()
