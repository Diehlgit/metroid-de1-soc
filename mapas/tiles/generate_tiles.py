"""
generate_tiles.py  (tiles/)
Lê tile_config.json e gera generated/tiles.h
"""

import json
import sys
from pathlib import Path

from PIL import Image

CONFIG = Path("tile_config.json")
OUTPUT = Path("../../generated/tiles.h")

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
    tiles = json.loads(CONFIG.read_text())["tiles"]
    OUTPUT.parent.mkdir(parents=True, exist_ok=True)

    lines = [
        "/* AUTO-GERADO por generate_tiles.py — não edite */",
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

    # externs de on_collision (cada tile tem seu próprio collision.c)
    # externs de on_collision — usando set para deduplicar
    callbacks = sorted(set(
        t["on_collision"] for t in tiles if t["on_collision"]
    ))
    for cb in callbacks:
        lines.append(f"extern void {cb}(struct Entity*,struct Entity*);")
    lines.append("")

    # pixels + sprites
    for t in tiles:
        name = c_id(t["name"])
        pxl, w, h = gen_pixels(t["sprite"], name)
        lines += pxl
        lines += [
            f"static Sprite SPRITE_{name} = {{",
            f"    .height={h}, .width={w},",
            f"    .pixels=(uint16_t*){name}_PIXELS,",
            f"}};",
            "",
        ]

    # TileInfo registry
    lines += [
        "typedef struct {",
        "    uint8_t r,g,b;",
        "    Sprite *sprite;",
        "    Hitbox  hitbox;",
        "    void (*on_collision)(struct Entity*,struct Entity*);",
        "    void (*think)(struct Entity*);",
        "} TileInfo;",
        "",
        "static TileInfo TILE_REGISTRY[] = {",
    ]
    for t in tiles:
        name = c_id(t["name"])
        r, g, b = t["color"]
        cb = t["on_collision"] if t["on_collision"] else "NULL"
        think = t["think"] if t["think"] else "NULL"
        lines += (
            [
                f"    {{ /* {t['name']} */",
                f"        .r={r},.g={g},.b={b},",
                f"        .sprite=&SPRITE_{name},",
                f"        .hitbox={{",
            ]
            + ["    " + l for l in hitbox_lines(t["hitbox"])]
            + [
                f"        }},",
                f"        .on_collision={cb},",
                f"        .think={think},",
                f"    }},",
            ]
        )
    lines += [
        "};",
        f"static int TILE_REGISTRY_SIZE={len(tiles)};",
        "",
        "static TileInfo* tile_from_color(uint8_t r,uint8_t g,uint8_t b){",
        "    for(int i=0;i<TILE_REGISTRY_SIZE;i++){",
        "        TileInfo *t=&TILE_REGISTRY[i];",
        "        if(t->r==r&&t->g==g&&t->b==b) return t;",
        "    }",
        "    return nullptr;",
        "}",
    ]

    OUTPUT.write_text("\n".join(lines) + "\n")
    print(f"Gerado: {OUTPUT}  ({len(tiles)} tiles)")


if __name__ == "__main__":
    main()
