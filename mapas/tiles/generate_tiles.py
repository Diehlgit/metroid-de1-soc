"""
generate_entidades.py  (entidades/)
Lê entidades_config.json e gera generated/entidades.h
Entidades não têm cor fixa no mapa — são instanciadas via entidade_create().
"""

import json
import sys
from pathlib import Path

from PIL import Image

E_CONFIG = Path("tile_config.json")
ENTS_DIR = Path(".")
OUTPUT = Path("../../generated/tiles.h")

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

HITBOX_ENUM = {"rectangle":"HITBOX_RECTANGLE","circle":"HITBOX_CIRCLE","triangle":"HITBOX_TRIANGLE"}
HITBOX_FN   = {"rectangle":"get_rectangle_cells","circle":"get_circle_cells","triangle":"get_triangle_cells"}

def get_hitbox_lines(hb):
    t = hb["type"]
    if   t=="rectangle": data=f".rectangle={{ {hb['width']}, {hb['height']} }}"
    elif t=="circle":    data=f".circle   ={{ {hb['radius']} }}"
    else:                data=f".triangle ={{ {hb['width']}, {hb['height']} }}"
    return [f"        .type       = {HITBOX_ENUM[t]},",
            f"        .data       = {{ {data} }},",
            f"        .get_cells  = {HITBOX_FN[t]},",
            "    };"]

def gen_states(name):
    lines = [
        f"static State {name} = {{",
        f"    .id                    = {name.upper()},",
        f"    .allowed_transitions  = {{}},",
        f"    .count                = 0,",
        f"    .animation            = &anim_{name},",
        f"    .evaluate_entry       = NULL,",
        f"    .evaluate_exit        = NULL,",
        f"    .decide_input         = NULL,",
        f"}};",
    ]

    return lines

def main():
    json_data = json.loads(E_CONFIG.read_text())
    ents = sorted(e for e in ENTS_DIR.iterdir() if e.is_dir() and not e.name.startswith("."))
    if not ents: print("Nenhuma área encontrada"); sys.exit(1)

    generated_h_lines = ["#pragma once", '#include "../include/entity.h"', ""]
    for e in ents:
        generated_h_lines += [f"Entity *{e.name}_create(int x, int y);"]
        import_lines = ['#include "../../../include/entity.h"', f'#include "{e.name}.h"', ""]
        enum_lines = [f"typedef enum {{"]
        states_lines = []

        functions_output = e/f"{e.name}.c"
        animation_output = e/f"{e.name}.h"
        animation_lines = ['#include "../../../include/entity.h"', ""]

        states_path = e / "states"
        states = sorted(s for s in states_path.iterdir() if s.is_dir() and not s.name.startswith("."))

        for s in states:
            enum_lines.append(f"    {s.name.upper()},")
            states_lines.extend(gen_states(s.name))

            sprites = sorted(p for p in s.iterdir() if p.suffix == ".png")

            sprites_list = []
            for sprite in sprites:
                sprite_name = f"{s.name.upper()}_{sprite.stem}"
                sprites_list.append(sprite_name)

                lines, w, h = gen_pixels(sprite, sprite_name)

                lines += [
                    f"static Sprite {s.name.upper()}_{sprite.stem} = {{",
                    f"    .height={h}, .width={w},",
                    f"    .pixels=(uint16_t*){sprite_name}_PIXELS",
                    f"}};",
                    "",
                ]

                animation_lines.extend(lines)

            animation_lines += [f"static Sprite *{e.name}_{s.stem}_frames[] = {{"]
            for sn in sprites_list:
                animation_lines += [f"    &{sn},"]
            animation_lines += ["};", ""]

            animation_lines += [
                f"static Animation anim_{s.name} = {{",
                f"    .frames          = {e.name}_{s.stem}_frames,",
                f"    .frame_count     = {len(sprites_list)},",
                f"    .frame_duration  = 1,",
                f"    .loops           = 0,",
                f"}};",
                "",
            ]

        animation_output.write_text("\n".join(animation_lines)+"\n")

        lines = []
        lines.extend(import_lines)
        lines.extend([f"void {e.name}_collision(Entity *self, Entity *others){{}}", ""])
        enum_lines.extend([f"}} {e.name}_state;"])
        lines.extend(enum_lines + [""])
        lines.extend(states_lines  + [""])

        hitbox_lines = get_hitbox_lines(json_data[e.name]["hitbox"])
        lines += [
            f"const Entity *{e.name}_create(int x, int y){{",
            f"    Entity *e = entity_alloc();",
            f"    e->position     = (Coordinates){{y, x}};",
            f"    e->velocity     = (Coordinates){{0, 0}};",
            f"    e->type         = {json_data[e.name]["entity_type"] or "ENTITY_ENEMY"};",
            f"    e->orientation  = (Orientation){{ RIGHT, UP}};",
            f"    e->hitbox       = (Hitbox){{",
        ]
        lines += hitbox_lines
        lines += [
            f"    e->sm.current_state = &{json_data[e.name]["sm_starting_state"]};",
            f"    e->sm.transition    = {json_data[e.name]["sm_transition_func"]};",
            f"    e->on_collision     = {e.name}_collision;",
            f"    return e;",
            "};",
        ]
        functions_output.write_text("\n".join(lines)+"\n")
        OUTPUT.write_text("\n".join(generated_h_lines)+"\n")

if __name__ == "__main__":
    main()
