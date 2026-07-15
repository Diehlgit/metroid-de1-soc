import json
import sys
from pathlib import Path

from PIL import Image

I_CONFIG = Path("itens_config.json")
ENTS_DIR = Path(".")
OUTPUT = Path("../../generated/itens.h")

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

def gen_states(ent, name):
    lines = [
        f"State {ent}_{name} = {{",
        f'    .id                   = {ent.upper()}_{name.upper()},',
        f"    .allowed_transitions  = {{}},",
        f"    .count                = 0,",
        f"    .evaluate_entry       = NULL,",
        f"    .evaluate_exit        = NULL,",
        f"    .decide_input         = NULL,",
        f"}};",
    ]

    return lines

def main():
    json_data = json.loads(I_CONFIG.read_text())
    itens = sorted(i for i in ENTS_DIR.iterdir() if i.is_dir() and not i.name.startswith("."))
    if not itens: print("Nenhuma área encontrada"); sys.exit(1)

    itens_h_linhas = ["#pragma once", '#include "../include/entity.h"', '#include "../mapas/entidades/projetil/projetil.h"']
    for i in itens:
        name = i.name

        functions_output = i/f"{name}.c"
        dados_output     = i/f"{name}.h"
        animation_output = i/f"{name}_sprites.h"

        animation_lines = ["#pragma once", '#include "../../../include/entity.h"', ""]

        movement_states_list = []
        itens_states_list = []

        states_path = i / "states"
        itens_states = sorted(es for es in states_path.iterdir() if es.is_dir() and not es.name.startswith("."))

        for it_s in itens_states:
            itens_states_list.append(it_s.name)

            movement_path = i / "states" / it_s.name
            move_states = sorted(ms for ms in movement_path.iterdir() if ms.is_dir() and not ms.name.startswith("."))

            for ms in move_states:
                if ms.name not in movement_states_list:
                    movement_states_list.append(ms.name)

                sprites = sorted(p for p in ms.iterdir() if p.suffix == ".png")

                sprites_list = []
                for sprite in sprites:
                    sprite_name = f"{it_s.name.upper()}_{sprite.stem}"
                    sprites_list.append(sprite_name)

                    lines, w, h = gen_pixels(sprite, sprite_name)

                    lines += [
                        f"static Sprite {sprite_name} = {{",
                        f"    .height={h}, .width={w},",
                        f"    .pixels=(uint16_t*){sprite_name}_PIXELS",
                        f"}};",
                        "",
                    ]

                    animation_lines.extend(lines)

                animation_lines += [f"static Sprite *{name}_frames[] = {{"]
                for sn in sprites_list:
                    animation_lines += [f"    &{sn},"]
                animation_lines += ["};", ""]

                animation_lines += [
                    f"static Animation anim_{name} = {{",
                    f"    .frames          = {name}_frames,",
                    f"    .frame_count     = {len(sprites_list)},",
                    f"    .frame_duration  = 1,",
                    f"    .loops           = 0,",
                    f"}};",
                    "",
                ]

        #========================
        #   GERANDO ENTIDADE_sprites.h
        #=======================
        animation_output.write_text("\n".join(animation_lines)+"\n")

        #========================
        #   GERANDO itens.h
        #=======================

        dados_linhas = ["#pragma once",
            '#include "../../../include/entity.h"', "",]

        for it_s in itens_states_list:
            dados_linhas += [f"extern State {name}_{it_s};"]

         # Adiciona os estados de entidade .h
        dados_linhas += ["", f"typedef enum {{"]
        for s in itens_states_list:
            dados_linhas += [f"    {name.upper()}_{s.upper()},"]
        dados_linhas += [f"}} {name}States;", ""]

        # adiciona a struct data da entidade no .h
        dados_linhas += [f"typedef struct {{"]
        for atr in json_data[name]["ent_data"]:
            dados_linhas += [f"    {atr};"]

        dados_linhas += [f"    {name}States ent_state;",
            f"}} {name}_data;", ""
        ]

        # Adiciona o header das funções create e collision no .h
        dados_linhas += [
            f"Entity *{name}_create({json_data[name]["create_args"]});",
            f"void {name}_collision(Entity *self, Entity *other, Grid **g, EntityList *l);"
        ]

        dados_output.write_text("\n".join(dados_linhas)+"\n")

        #========================
        #   GERANDO ENTIDADE.c
        #=======================

        function_lines = ['#include "../../../include/entity.h"', '#include "../../../include/physics.h"', '#include "../../entidades/samus/samus.h"',
            f'#include "{name}_sprites.h"', f'#include "{name}.h"', "",
            f"Animation *{name}_get_animation(Entity *e){{}}",
        ]

        function_lines += [f"void {name}_collision(Entity *self, Entity *other, Grid **g, EntityList *l){{}}", "",]

        for ts in itens_states_list:
            function_lines += gen_states(name, ts)

        function_lines += [
            f"static {name}_data _{name}_data_pool[1024];",
            f"static int _{name}_data_count = 0;",
            "",
            f"Entity *{name}_create({json_data[name]["create_args"]}){{",
            f"    Entity *e = entity_alloc();",
            f"    {name}_data *d = &_{name}_data_pool[_{name}_data_count++];",
            f"",
            f"    *d = ({name}_data){{",
        ]
        for atr in json_data[name]["ent_data"]:
            function_lines += [f"        {atr} = ,"]

        hitbox_lines = get_hitbox_lines(json_data[name]["hitbox"])
        function_lines += [
            f"    }};", "",
            f"    e->position     = (Coordinates){{x, y}};",
            f"    e->velocity     = (Coordinates){{0, 0}};",
            f"    e->type         = {json_data[name]["entity_type"] or "ENTITY_ENEMY"};",
            f"    e->orientation  = (Orientation){{ RIGHT, UP }};",
            f"    e->hp           = 10;",
            f"    e->invulnerable = true;",
            f"    e->hit          = false;",
            f"    e->mv_state     = IDLE;",
            f"    e->hitbox       = (Hitbox){{",
        ]
        function_lines += hitbox_lines
        function_lines += [
            f"    e->data         = d;",
            f"    e->sm.current_state = &{name}_{json_data[name]["sm_starting_state"]};",
            f"    e->sm.transition    = {json_data[name]["sm_transition_func"]};",
            f"    e->sm.get_animation = &{name}_get_animation;",
            f"    e->on_collision     = {name}_collision;",
            f"    return e;",
            "};",
        ]

        functions_output.write_text("\n".join(function_lines)+"\n")

        itens_h_linhas += [f"Entity *{name}_create({json_data[name]["create_args"]});"]
        OUTPUT.write_text("\n".join(itens_h_linhas)+"\n")

if __name__ == "__main__":
    main()
