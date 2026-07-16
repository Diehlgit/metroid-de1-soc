"""
generate_entities.py
Lê um arquivo de configuração JSON e os diretórios de entidades,
gerando [nome].h e [nome].c para cada uma.
Também gera um header agregador (ex: generated/tiles.h).

Uso:
    cd mapas/entidades && python3 generate_entities.py entidades_config.json ../../generated/entidades.h
    cd mapas/tiles     && python3 generate_entities.py tile_config.json      ../../generated/tiles.h
    cd mapas/itens     && python3 generate_entities.py itens_config.json     ../../generated/itens.h

Campos obrigatórios em cada entrada do JSON:
    create_args        : string com os argumentos de create() ex: "int x, int y, int h_dir, int v_dir"
    entity_type        : ex: "ENTITY_TILE", "ENTITY_ENEMY"
    hitbox             : { "type": "rectangle", "width": 16, "height": 16 }
    sm_starting_state  : nome do estado inicial ex: "idle"
    sm_transition_func : ex: "generic_transition" ou "NULL"
    ent_data           : lista de declarações de campos ex: ["int hp", "bool item_bola"]
    is_player          : true → usa player_alloc(), false → usa entity_alloc()
    extra_includes     : lista de includes extras ex: ["../projetil/projetil.h"]
"""

import json
import sys
from pathlib import Path

ROOT    = Path(".")
CONFIG  = Path(sys.argv[1]) if len(sys.argv) > 1 else Path("config.json")
OUTPUT  = Path(sys.argv[2]) if len(sys.argv) > 2 else Path("../../generated/entities.h")

HITBOX_ENUM = {
    "rectangle": "HITBOX_RECTANGLE",
    "circle":    "HITBOX_CIRCLE",
    "triangle":  "HITBOX_TRIANGLE",
}
HITBOX_FN = {
    "rectangle": "get_rectangle_cells",
    "circle":    "get_circle_cells",
    "triangle":  "get_triangle_cells",
}
MOVE_STATES = ["IDLE", "MOVE", "AIRBORNE", "HIT"]

def get_hitbox_lines(hb):
    t = hb["type"]
    if   t == "rectangle": data = f".rectangle={{ {hb['width']}, {hb['height']} }}"
    elif t == "circle":    data = f".circle   ={{ {hb['radius']} }}"
    else:                  data = f".triangle ={{ {hb['width']}, {hb['height']} }}"
    return [
        f"        .type      = {HITBOX_ENUM[t]},",
        f"        .data      = {{ {data} }},",
        f"        .get_cells = {HITBOX_FN[t]},",
        "    };",
    ]

def get_state_dirs(ent_dir: Path):
    states_path = ent_dir / "states"
    if not states_path.exists():
        return []
    return sorted(s for s in states_path.iterdir() if s.is_dir() and not s.name.startswith("."))

def gen_header(name, cfg, state_dirs):
    lines = [
        "/* AUTO-GERADO por generate_entities.py — não edite */",
        "#pragma once",
        '#include "../../../include/entity.h"',
        "",
    ]

    # extern dos estados
    for s in state_dirs:
        lines.append(f"extern State {name}_{s.name};")

    # enum de estados
    lines += ["", f"typedef enum {{"]
    for s in state_dirs:
        lines.append(f"    {name.upper()}_{s.name.upper()},")
    lines += [f"}} {name}States;", ""]

    # struct de dados
    lines.append(f"typedef struct {{")
    for field in cfg.get("ent_data", []):
        lines.append(f"    {field};")
    lines += [
        f"    {name}States ent_state;",
        f"}} {name}_data;",
        "",
        f"Entity *{name}_create({cfg['create_args']});",
        f"void {name}_collision(Entity *self, Entity *other, Grid **g, EntityList *l);",
    ]
    return lines

def gen_source(name, cfg, state_dirs, ent_dir: Path):
    is_player   = cfg.get("is_player", False)
    alloc_fn    = "player_alloc" if is_player else "entity_alloc"
    extra_inc   = cfg.get("extra_includes", [])

    lines = [
        "/* AUTO-GERADO por generate_entities.py — não edite */",
        '#include "../../../include/entity.h"',
        '#include "../../../include/physics.h"',
        f'#include "{name}_sprites.h"',
        f'#include "{name}.h"',
    ]
    for inc in extra_inc:
        lines.append(f'#include "{inc}"')
    lines.append("")

    # get_animation stub
    lines += [
        f"Animation *{name}_get_animation(Entity *e) {{",
        f"    /* TODO: implementar */",
        f"    return NULL;",
        f"}}",
        "",
    ]

    # move_transition
    lines += [
        f"bool {name}_move_transition(Entity *self, MovementState next) {{",
        f"    {name}_data *d = ({name}_data *)self->data;",
        f"    (void)d;",
        f"    switch (next) {{",
    ]
    for ms in MOVE_STATES:
        lines += [f"        case {ms}:", f"            break;"]
    lines += [
        "        default: return false;",
        "    }",
        "    self->mv_state = next;",
        "    return true;",
        "}",
        "",
    ]

    # collision stub
    lines += [
        f"void {name}_collision(Entity *self, Entity *other, Grid **g, EntityList *l) {{",
        f"    (void)self; (void)other; (void)g; (void)l;",
        f"}}",
        "",
    ]

    # por estado: evaluate_entry/exit + input + State
    for s in state_dirs:
        sname = s.name
        lines += [
            f"/* ── estado: {sname} ── */",
            f"static bool {sname}_evaluate_entry(Entity *self) {{ (void)self; return true; }}",
            f"static bool {sname}_evaluate_exit (Entity *self) {{ (void)self; return true; }}",
            "",
            f"static Intent {sname}_input(Grid **grid, Entity *self) {{",
            f"    (void)grid; (void)self;",
            f"    Intent intent = {{0}};",
            f"    return intent;",
            f"}}",
            "",
            f"State {name}_{sname} = {{",
            f"    .id                  = {name.upper()}_{sname.upper()},",
            f"    .allowed_transitions = {{}},",
            f"    .count               = 0,",
            f"    .evaluate_entry      = {sname}_evaluate_entry,",
            f"    .evaluate_exit       = {sname}_evaluate_exit,",
            f"    .decide_input        = {sname}_input,",
            f"}};",
            "",
        ]

    # ai
    lines += [
        f"Intent {name}_ai(Grid **grid, Entity *self) {{",
        f"    State *s = self->sm.current_state;",
        f"    if (s && s->decide_input) return s->decide_input(grid, self);",
        f"    return (Intent){{0}};",
        f"}}",
        "",
    ]

    # pool + create
    starting = cfg["sm_starting_state"]
    trans_fn  = cfg["sm_transition_func"]
    lines += [
        f"static {name}_data _{name}_data_pool[1024];",
        f"static int _{name}_data_count = 0;",
        "",
        f"Entity *{name}_create({cfg['create_args']}) {{",
        f"    Entity *e = {alloc_fn}();",
        f"    {name}_data *d = &_{name}_data_pool[_{name}_data_count++];",
        "",
        f"    *d = ({name}_data){{",
        f"        .ent_state = {name.upper()}_{starting.upper()},",
        f"    }};",
        "",
        f"    e->position     = (Coordinates){{x, y}};",
        f"    e->velocity     = (Coordinates){{0, 0}};",
        f"    e->type         = {cfg.get('entity_type', 'ENTITY_ENEMY')};",
        f"    e->orientation  = (Orientation){{ RIGHT, UP }};"
        f"    e->hp           = 10;",
        f"    e->invulnerable = false;",
        f"    e->hit          = false;",
        f"    e->mv_state     = IDLE;",
        f"    e->hitbox       = (Hitbox){{",
    ]
    lines += get_hitbox_lines(cfg["hitbox"])
    lines += [
        f"    e->data               = d;",
        f"    e->sm.current_state   = &{name}_{starting};",
        f"    e->sm.transition      = {trans_fn};",
        f"    e->sm.move_transition = &{name}_move_transition;",
        f"    e->sm.get_animation   = &{name}_get_animation;",
        f"    e->on_collision       = {name}_collision;",
        f"    return e;",
        "}",
    ]
    return lines

def main():
    if not CONFIG.exists():
        print(f"Config não encontrado: {CONFIG}"); sys.exit(1)

    all_cfg = json.loads(CONFIG.read_text())
    ent_dirs = sorted(e for e in ROOT.iterdir() if e.is_dir() and not e.name.startswith("."))

    if not ent_dirs:
        print("Nenhum diretório encontrado."); sys.exit(1)

    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    aggregator = [
        "/* AUTO-GERADO por generate_entities.py — não edite */",
        "#pragma once",
        '#include "../include/entity.h"',
        "",
    ]

    print("Gerando .h e .c:")
    for ent_dir in ent_dirs:
        name = ent_dir.name
        if name not in all_cfg:
            print(f"  AVISO: {name} não encontrado em {CONFIG}, pulando")
            continue

        cfg        = all_cfg[name]
        state_dirs = get_state_dirs(ent_dir)

        header_path = ent_dir / f"{name}.h"
        source_path = ent_dir / f"{name}.c"

        header_path.write_text("\n".join(gen_header(name, cfg, state_dirs)) + "\n")
        source_path.write_text("\n".join(gen_source(name, cfg, state_dirs, ent_dir)) + "\n")

        aggregator.append(f"Entity *{name}_create({cfg['create_args']});")
        print(f"  {header_path}")
        print(f"  {source_path}")

    OUTPUT.write_text("\n".join(aggregator) + "\n")
    print(f"Agregador: {OUTPUT}")

if __name__ == "__main__":
    main()
