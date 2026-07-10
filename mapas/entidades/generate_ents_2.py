"""
generate_entidades.py  (entidades/)
Lê entidades_config.json e gera generated/entidades.h
Entidades não têm cor fixa no mapa — são instanciadas via entidade_create().
"""

import json
import sys
from pathlib import Path

from PIL import Image

ENTS_DIR = Path(".")


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


def gen_states(name):
    lines = [
        f"static State {name} = {{",
        f"    .id                    = {name.upper()},",
        f"    .allowed_transitions  = {{}},",
        f"    .count                = 0,",
        f"    .animation            = &anim_{name},",
        f"    .evaluate_entry       = NULL,",
        f"    .evaluate_exit        = NULL,",
        f"}};",
    ]

    return lines

def main():
    ents = sorted(e for e in ENTS_DIR.iterdir() if e.is_dir() and not e.name.startswith("."))
    if not ents: print("Nenhuma área encontrada"); sys.exit(1)

    for e in ents:
        import_lines = ['#include "../../../include/entity.h"', '#include "../../../include/physics.h"', f'#include "{e.name}.h"', ""]
        enum_lines = [f"typedef enum {{"]
        declaration_lines = []
        transition_function_lines = []
        handle_input_lines = [f"static Intent default_input(Entity *self, char key) {{", "    Intent intent = {0};", "    return intent;", f"}}", "" ]
        states_lines = []

        functions_output = e/f"{e.name}.c"
        animation_output = e/f"{e.name}.h"
        animation_lines = ['#include "../../../include/entity.h"', ""]

        states_path = e / "states"
        states = sorted(s for s in states_path.iterdir() if s.is_dir() and not s.name.startswith("."))

        for s in states:
            enum_lines.append(f"    {s.name.upper()},")
            declaration_lines.append(f"static State {s.name};")
            transition_function_lines.extend([f"static bool {s.name}_evaluate_entry(Entity *self, State *current, State *next) {{}}", f"static bool {s.name}_evaluate_exit(Entity *self, State *current, State *next) {{}}", ""])
            handle_input_lines.extend([f"static Intent {s.name}_input(Entity *self, char key) {{", "    Intent intent = {0};", "    return intent;", "}"])
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
        enum_lines.extend([f"}} {e.name}_state;"])
        lines.extend(enum_lines + [""])
        lines.extend(declaration_lines + [""])
        lines.extend(transition_function_lines + [""])
        lines.extend(handle_input_lines  + [""])
        lines.extend(states_lines  + [""])
        lines.extend([f"Intent {e.name}_ai(Grid *grid, Entity *self) {{", "",  "    State *s = self->sm.current_state;", "    if (s->handle_input)", "        return s->handle_input(self);", "    return (Intent){0};", f"}}"])
        lines.append(f"void {e.name}_collision(Entity *self, Entity *others){{}}")
        functions_output.write_text("\n".join(lines)+"\n")

if __name__ == "__main__":
    main()
