/* AUTO-GERADO por generate_mapas.py — não edite */
#pragma once
#include <stdint.h>
#include "../include/structs.h"
#include "../include/grid.h"
#include "tiles.h"
#include "itens.h"
#include "entidades.h"

#define CELL_SIZE         16
#define MAX_ENTS_PER_CELL 16
#define GRID_BUCKETS      1024

/* ──────────────────────────────────────────────────────────── */
/* Área: starting_area */
/* ──────────────────────────────────────────────────────────── */

static Entity STARTING_AREA_COL_0 = {
    .position       = { 0,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_1 = {
    .position       = { 16,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_2 = {
    .position       = { 32,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_3 = {
    .position       = { 48,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_4 = {
    .position       = { 64,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_5 = {
    .position       = { 80,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_6 = {
    .position       = { 96,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_7 = {
    .position       = { 112,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_8 = {
    .position       = { 128,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_9 = {
    .position       = { 144,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_10 = {
    .position       = { 160,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_11 = {
    .position       = { 176,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_12 = {
    .position       = { 192,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_13 = {
    .position       = { 208,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_14 = {
    .position       = { 224,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_15 = {
    .position       = { 240,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_16 = {
    .position       = { 256,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_17 = {
    .position       = { 272,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_18 = {
    .position       = { 288,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_19 = {
    .position       = { 304,0 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_20 = {
    .position       = { 0,16 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_21 = {
    .position       = { 304,16 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TRANSICAO,
    .think          = NULL,
    .on_collision   = transicao_collision,
};
static Entity STARTING_AREA_COL_22 = {
    .position       = { 0,32 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_23 = {
    .position       = { 304,32 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TRANSICAO,
    .think          = NULL,
    .on_collision   = transicao_collision,
};
static Entity STARTING_AREA_COL_24 = {
    .position       = { 0,48 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_25 = {
    .position       = { 304,48 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TRANSICAO,
    .think          = NULL,
    .on_collision   = transicao_collision,
};
static Entity STARTING_AREA_COL_26 = {
    .position       = { 0,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_27 = {
    .position       = { 16,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_28 = {
    .position       = { 32,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_29 = {
    .position       = { 48,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_30 = {
    .position       = { 64,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_31 = {
    .position       = { 80,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_32 = {
    .position       = { 96,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_33 = {
    .position       = { 112,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_34 = {
    .position       = { 128,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_35 = {
    .position       = { 176,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_METAL,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_36 = {
    .position       = { 192,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_37 = {
    .position       = { 208,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_38 = {
    .position       = { 224,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_39 = {
    .position       = { 240,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_40 = {
    .position       = { 256,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_41 = {
    .position       = { 272,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_42 = {
    .position       = { 288,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_43 = {
    .position       = { 304,64 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_44 = {
    .position       = { 0,80 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_45 = {
    .position       = { 128,80 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_46 = {
    .position       = { 192,80 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_47 = {
    .position       = { 288,80 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_48 = {
    .position       = { 304,80 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_49 = {
    .position       = { 0,96 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_50 = {
    .position       = { 128,96 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_51 = {
    .position       = { 144,96 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_METAL,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_52 = {
    .position       = { 192,96 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_53 = {
    .position       = { 304,96 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_54 = {
    .position       = { 0,112 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_55 = {
    .position       = { 128,112 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_56 = {
    .position       = { 192,112 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_57 = {
    .position       = { 208,112 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_METAL,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_58 = {
    .position       = { 304,112 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_PORTA,
    .think          = NULL,
    .on_collision   = porta_collision,
};
static Entity STARTING_AREA_COL_59 = {
    .position       = { 0,128 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_60 = {
    .position       = { 128,128 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_61 = {
    .position       = { 176,128 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_METAL,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_62 = {
    .position       = { 192,128 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_63 = {
    .position       = { 208,128 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_64 = {
    .position       = { 224,128 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_65 = {
    .position       = { 240,128 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_66 = {
    .position       = { 304,128 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_PORTA,
    .think          = NULL,
    .on_collision   = porta_collision,
};
static Entity STARTING_AREA_COL_67 = {
    .position       = { 0,144 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_68 = {
    .position       = { 112,144 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_METAL,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_69 = {
    .position       = { 128,144 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_70 = {
    .position       = { 192,144 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_71 = {
    .position       = { 208,144 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_72 = {
    .position       = { 224,144 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_73 = {
    .position       = { 240,144 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_74 = {
    .position       = { 256,144 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_75 = {
    .position       = { 304,144 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_PORTA,
    .think          = NULL,
    .on_collision   = porta_collision,
};
static Entity STARTING_AREA_COL_76 = {
    .position       = { 0,160 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_77 = {
    .position       = { 64,160 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_METAL,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_78 = {
    .position       = { 80,160 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_79 = {
    .position       = { 96,160 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_80 = {
    .position       = { 112,160 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_81 = {
    .position       = { 128,160 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_82 = {
    .position       = { 144,160 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_METAL,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_83 = {
    .position       = { 192,160 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_84 = {
    .position       = { 208,160 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_85 = {
    .position       = { 224,160 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_86 = {
    .position       = { 304,160 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_METAL,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_87 = {
    .position       = { 0,176 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_88 = {
    .position       = { 48,176 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_METAL,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_89 = {
    .position       = { 64,176 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_90 = {
    .position       = { 80,176 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_91 = {
    .position       = { 208,176 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_92 = {
    .position       = { 288,176 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_METAL,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_93 = {
    .position       = { 304,176 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_94 = {
    .position       = { 0,192 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_95 = {
    .position       = { 48,192 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_96 = {
    .position       = { 64,192 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_97 = {
    .position       = { 160,192 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_METAL,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_98 = {
    .position       = { 272,192 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_METAL,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_99 = {
    .position       = { 288,192 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_100 = {
    .position       = { 304,192 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_101 = {
    .position       = { 0,208 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_102 = {
    .position       = { 16,208 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_103 = {
    .position       = { 96,208 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_METAL,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_104 = {
    .position       = { 160,208 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_METAL,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_105 = {
    .position       = { 176,208 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_METAL,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_106 = {
    .position       = { 256,208 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_METAL,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_107 = {
    .position       = { 272,208 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_108 = {
    .position       = { 288,208 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_109 = {
    .position       = { 304,208 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_110 = {
    .position       = { 0,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_111 = {
    .position       = { 16,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_112 = {
    .position       = { 32,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_113 = {
    .position       = { 48,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_114 = {
    .position       = { 64,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_115 = {
    .position       = { 80,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_116 = {
    .position       = { 96,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_117 = {
    .position       = { 112,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_118 = {
    .position       = { 128,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_119 = {
    .position       = { 144,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_120 = {
    .position       = { 160,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_121 = {
    .position       = { 176,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_122 = {
    .position       = { 192,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_123 = {
    .position       = { 208,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_124 = {
    .position       = { 224,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_125 = {
    .position       = { 240,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_126 = {
    .position       = { 256,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_127 = {
    .position       = { 272,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_128 = {
    .position       = { 288,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};
static Entity STARTING_AREA_COL_129 = {
    .position       = { 304,224 },
    .type           = ENTITY_TILE,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_TIJOLOS,
    .think          = NULL,
    .on_collision   = tijolos_collision,
};

static Entity STARTING_AREA_ITE_130 = {
    .position       = { 208,96 },
    .type           = ENTITY_ITEM,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_POWERUP_BOLA,
    .think          = NULL,
    .on_collision   = ball_collision,
};
static Entity STARTING_AREA_ITE_131 = {
    .position       = { 112,128 },
    .type           = ENTITY_ITEM,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_POWERUP_ARMA,
    .think          = NULL,
    .on_collision   = gun_collision,
};

static Entity STARTING_AREA_ENT_132 = {
    .position       = { 160,32 },
    .type           = ENTITY_ENEMY,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 32, 32 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_PINWHEEL,
    .think          = pinwheel_ai,
    .on_collision   = pinwheel_collision,
};
static Entity STARTING_AREA_ENT_133 = {
    .position       = { 96,48 },
    .type           = ENTITY_ENEMY,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 32, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_ESCORPIAO,
    .think          = scorpion_ai,
    .on_collision   = scorpion_collision,
};
static Entity STARTING_AREA_ENT_134 = {
    .position       = { 192,48 },
    .type           = ENTITY_ENEMY,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 32, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_ESCORPIAO,
    .think          = scorpion_ai,
    .on_collision   = scorpion_collision,
};
static Entity STARTING_AREA_ENT_135 = {
    .position       = { 288,48 },
    .type           = ENTITY_ENEMY,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 32, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_ESCORPIAO,
    .think          = scorpion_ai,
    .on_collision   = scorpion_collision,
};
static Entity STARTING_AREA_ENT_136 = {
    .position       = { 256,96 },
    .type           = ENTITY_ENEMY,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 32, 32 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_PINWHEEL,
    .think          = pinwheel_ai,
    .on_collision   = pinwheel_collision,
};
static Entity STARTING_AREA_ENT_137 = {
    .position       = { 48,128 },
    .type           = ENTITY_ENEMY,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 32, 32 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_PINWHEEL,
    .think          = pinwheel_ai,
    .on_collision   = pinwheel_collision,
};
static Entity STARTING_AREA_ENT_138 = {
    .position       = { 96,128 },
    .type           = ENTITY_ENEMY,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 32, 32 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_PINWHEEL,
    .think          = pinwheel_ai,
    .on_collision   = pinwheel_collision,
};
static Entity STARTING_AREA_ENT_139 = {
    .position       = { 240,208 },
    .type           = ENTITY_ENEMY,
    .hitbox         = {
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 32, 16 } },
        .get_cells = get_rectangle_cells,
    },
    .current_sprite = &SPRITE_ESCORPIAO,
    .think          = scorpion_ai,
    .on_collision   = scorpion_collision,
};

static GridEntry STARTING_AREA_GENTRY_0_0 = {
    .key  = { 0,0 },
    .cell = { .ents={&STARTING_AREA_COL_0}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_1_0 = {
    .key  = { 1,0 },
    .cell = { .ents={&STARTING_AREA_COL_1}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_2_0 = {
    .key  = { 2,0 },
    .cell = { .ents={&STARTING_AREA_COL_2}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_3_0 = {
    .key  = { 3,0 },
    .cell = { .ents={&STARTING_AREA_COL_3}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_4_0 = {
    .key  = { 4,0 },
    .cell = { .ents={&STARTING_AREA_COL_4}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_5_0 = {
    .key  = { 5,0 },
    .cell = { .ents={&STARTING_AREA_COL_5}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_6_0 = {
    .key  = { 6,0 },
    .cell = { .ents={&STARTING_AREA_COL_6}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_7_0 = {
    .key  = { 7,0 },
    .cell = { .ents={&STARTING_AREA_COL_7}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_8_0 = {
    .key  = { 8,0 },
    .cell = { .ents={&STARTING_AREA_COL_8}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_9_0 = {
    .key  = { 9,0 },
    .cell = { .ents={&STARTING_AREA_COL_9}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_10_0 = {
    .key  = { 10,0 },
    .cell = { .ents={&STARTING_AREA_COL_10}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_11_0 = {
    .key  = { 11,0 },
    .cell = { .ents={&STARTING_AREA_COL_11}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_12_0 = {
    .key  = { 12,0 },
    .cell = { .ents={&STARTING_AREA_COL_12}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_13_0 = {
    .key  = { 13,0 },
    .cell = { .ents={&STARTING_AREA_COL_13}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_14_0 = {
    .key  = { 14,0 },
    .cell = { .ents={&STARTING_AREA_COL_14}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_15_0 = {
    .key  = { 15,0 },
    .cell = { .ents={&STARTING_AREA_COL_15}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_16_0 = {
    .key  = { 16,0 },
    .cell = { .ents={&STARTING_AREA_COL_16}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_17_0 = {
    .key  = { 17,0 },
    .cell = { .ents={&STARTING_AREA_COL_17}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_18_0 = {
    .key  = { 18,0 },
    .cell = { .ents={&STARTING_AREA_COL_18}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_19_0 = {
    .key  = { 19,0 },
    .cell = { .ents={&STARTING_AREA_COL_19}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_0_1 = {
    .key  = { 0,1 },
    .cell = { .ents={&STARTING_AREA_COL_20}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_19_1 = {
    .key  = { 19,1 },
    .cell = { .ents={&STARTING_AREA_COL_21}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_0_2 = {
    .key  = { 0,2 },
    .cell = { .ents={&STARTING_AREA_COL_22}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_19_2 = {
    .key  = { 19,2 },
    .cell = { .ents={&STARTING_AREA_COL_23}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_0_3 = {
    .key  = { 0,3 },
    .cell = { .ents={&STARTING_AREA_COL_24}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_19_3 = {
    .key  = { 19,3 },
    .cell = { .ents={&STARTING_AREA_COL_25, &STARTING_AREA_ENT_135}, .count=2 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_0_4 = {
    .key  = { 0,4 },
    .cell = { .ents={&STARTING_AREA_COL_26}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_1_4 = {
    .key  = { 1,4 },
    .cell = { .ents={&STARTING_AREA_COL_27}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_2_4 = {
    .key  = { 2,4 },
    .cell = { .ents={&STARTING_AREA_COL_28}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_3_4 = {
    .key  = { 3,4 },
    .cell = { .ents={&STARTING_AREA_COL_29}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_4_4 = {
    .key  = { 4,4 },
    .cell = { .ents={&STARTING_AREA_COL_30}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_5_4 = {
    .key  = { 5,4 },
    .cell = { .ents={&STARTING_AREA_COL_31}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_6_4 = {
    .key  = { 6,4 },
    .cell = { .ents={&STARTING_AREA_COL_32}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_7_4 = {
    .key  = { 7,4 },
    .cell = { .ents={&STARTING_AREA_COL_33}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_8_4 = {
    .key  = { 8,4 },
    .cell = { .ents={&STARTING_AREA_COL_34}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_11_4 = {
    .key  = { 11,4 },
    .cell = { .ents={&STARTING_AREA_COL_35}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_12_4 = {
    .key  = { 12,4 },
    .cell = { .ents={&STARTING_AREA_COL_36}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_13_4 = {
    .key  = { 13,4 },
    .cell = { .ents={&STARTING_AREA_COL_37}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_14_4 = {
    .key  = { 14,4 },
    .cell = { .ents={&STARTING_AREA_COL_38}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_15_4 = {
    .key  = { 15,4 },
    .cell = { .ents={&STARTING_AREA_COL_39}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_16_4 = {
    .key  = { 16,4 },
    .cell = { .ents={&STARTING_AREA_COL_40}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_17_4 = {
    .key  = { 17,4 },
    .cell = { .ents={&STARTING_AREA_COL_41}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_18_4 = {
    .key  = { 18,4 },
    .cell = { .ents={&STARTING_AREA_COL_42}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_19_4 = {
    .key  = { 19,4 },
    .cell = { .ents={&STARTING_AREA_COL_43}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_0_5 = {
    .key  = { 0,5 },
    .cell = { .ents={&STARTING_AREA_COL_44}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_8_5 = {
    .key  = { 8,5 },
    .cell = { .ents={&STARTING_AREA_COL_45}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_12_5 = {
    .key  = { 12,5 },
    .cell = { .ents={&STARTING_AREA_COL_46}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_18_5 = {
    .key  = { 18,5 },
    .cell = { .ents={&STARTING_AREA_COL_47}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_19_5 = {
    .key  = { 19,5 },
    .cell = { .ents={&STARTING_AREA_COL_48}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_0_6 = {
    .key  = { 0,6 },
    .cell = { .ents={&STARTING_AREA_COL_49}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_8_6 = {
    .key  = { 8,6 },
    .cell = { .ents={&STARTING_AREA_COL_50}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_9_6 = {
    .key  = { 9,6 },
    .cell = { .ents={&STARTING_AREA_COL_51}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_12_6 = {
    .key  = { 12,6 },
    .cell = { .ents={&STARTING_AREA_COL_52}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_19_6 = {
    .key  = { 19,6 },
    .cell = { .ents={&STARTING_AREA_COL_53}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_0_7 = {
    .key  = { 0,7 },
    .cell = { .ents={&STARTING_AREA_COL_54}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_8_7 = {
    .key  = { 8,7 },
    .cell = { .ents={&STARTING_AREA_COL_55}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_12_7 = {
    .key  = { 12,7 },
    .cell = { .ents={&STARTING_AREA_COL_56}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_13_7 = {
    .key  = { 13,7 },
    .cell = { .ents={&STARTING_AREA_COL_57}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_19_7 = {
    .key  = { 19,7 },
    .cell = { .ents={&STARTING_AREA_COL_58}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_0_8 = {
    .key  = { 0,8 },
    .cell = { .ents={&STARTING_AREA_COL_59}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_8_8 = {
    .key  = { 8,8 },
    .cell = { .ents={&STARTING_AREA_COL_60}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_11_8 = {
    .key  = { 11,8 },
    .cell = { .ents={&STARTING_AREA_COL_61}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_12_8 = {
    .key  = { 12,8 },
    .cell = { .ents={&STARTING_AREA_COL_62}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_13_8 = {
    .key  = { 13,8 },
    .cell = { .ents={&STARTING_AREA_COL_63}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_14_8 = {
    .key  = { 14,8 },
    .cell = { .ents={&STARTING_AREA_COL_64}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_15_8 = {
    .key  = { 15,8 },
    .cell = { .ents={&STARTING_AREA_COL_65}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_19_8 = {
    .key  = { 19,8 },
    .cell = { .ents={&STARTING_AREA_COL_66}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_0_9 = {
    .key  = { 0,9 },
    .cell = { .ents={&STARTING_AREA_COL_67}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_7_9 = {
    .key  = { 7,9 },
    .cell = { .ents={&STARTING_AREA_COL_68, &STARTING_AREA_ENT_138}, .count=2 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_8_9 = {
    .key  = { 8,9 },
    .cell = { .ents={&STARTING_AREA_COL_69}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_12_9 = {
    .key  = { 12,9 },
    .cell = { .ents={&STARTING_AREA_COL_70}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_13_9 = {
    .key  = { 13,9 },
    .cell = { .ents={&STARTING_AREA_COL_71}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_14_9 = {
    .key  = { 14,9 },
    .cell = { .ents={&STARTING_AREA_COL_72}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_15_9 = {
    .key  = { 15,9 },
    .cell = { .ents={&STARTING_AREA_COL_73}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_16_9 = {
    .key  = { 16,9 },
    .cell = { .ents={&STARTING_AREA_COL_74}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_19_9 = {
    .key  = { 19,9 },
    .cell = { .ents={&STARTING_AREA_COL_75}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_0_10 = {
    .key  = { 0,10 },
    .cell = { .ents={&STARTING_AREA_COL_76}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_4_10 = {
    .key  = { 4,10 },
    .cell = { .ents={&STARTING_AREA_COL_77}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_5_10 = {
    .key  = { 5,10 },
    .cell = { .ents={&STARTING_AREA_COL_78}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_6_10 = {
    .key  = { 6,10 },
    .cell = { .ents={&STARTING_AREA_COL_79}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_7_10 = {
    .key  = { 7,10 },
    .cell = { .ents={&STARTING_AREA_COL_80}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_8_10 = {
    .key  = { 8,10 },
    .cell = { .ents={&STARTING_AREA_COL_81}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_9_10 = {
    .key  = { 9,10 },
    .cell = { .ents={&STARTING_AREA_COL_82}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_12_10 = {
    .key  = { 12,10 },
    .cell = { .ents={&STARTING_AREA_COL_83}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_13_10 = {
    .key  = { 13,10 },
    .cell = { .ents={&STARTING_AREA_COL_84}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_14_10 = {
    .key  = { 14,10 },
    .cell = { .ents={&STARTING_AREA_COL_85}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_19_10 = {
    .key  = { 19,10 },
    .cell = { .ents={&STARTING_AREA_COL_86}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_0_11 = {
    .key  = { 0,11 },
    .cell = { .ents={&STARTING_AREA_COL_87}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_3_11 = {
    .key  = { 3,11 },
    .cell = { .ents={&STARTING_AREA_COL_88}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_4_11 = {
    .key  = { 4,11 },
    .cell = { .ents={&STARTING_AREA_COL_89}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_5_11 = {
    .key  = { 5,11 },
    .cell = { .ents={&STARTING_AREA_COL_90}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_13_11 = {
    .key  = { 13,11 },
    .cell = { .ents={&STARTING_AREA_COL_91}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_18_11 = {
    .key  = { 18,11 },
    .cell = { .ents={&STARTING_AREA_COL_92}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_19_11 = {
    .key  = { 19,11 },
    .cell = { .ents={&STARTING_AREA_COL_93}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_0_12 = {
    .key  = { 0,12 },
    .cell = { .ents={&STARTING_AREA_COL_94}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_3_12 = {
    .key  = { 3,12 },
    .cell = { .ents={&STARTING_AREA_COL_95}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_4_12 = {
    .key  = { 4,12 },
    .cell = { .ents={&STARTING_AREA_COL_96}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_10_12 = {
    .key  = { 10,12 },
    .cell = { .ents={&STARTING_AREA_COL_97}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_17_12 = {
    .key  = { 17,12 },
    .cell = { .ents={&STARTING_AREA_COL_98}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_18_12 = {
    .key  = { 18,12 },
    .cell = { .ents={&STARTING_AREA_COL_99}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_19_12 = {
    .key  = { 19,12 },
    .cell = { .ents={&STARTING_AREA_COL_100}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_0_13 = {
    .key  = { 0,13 },
    .cell = { .ents={&STARTING_AREA_COL_101}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_1_13 = {
    .key  = { 1,13 },
    .cell = { .ents={&STARTING_AREA_COL_102}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_6_13 = {
    .key  = { 6,13 },
    .cell = { .ents={&STARTING_AREA_COL_103}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_10_13 = {
    .key  = { 10,13 },
    .cell = { .ents={&STARTING_AREA_COL_104}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_11_13 = {
    .key  = { 11,13 },
    .cell = { .ents={&STARTING_AREA_COL_105}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_16_13 = {
    .key  = { 16,13 },
    .cell = { .ents={&STARTING_AREA_COL_106, &STARTING_AREA_ENT_139}, .count=2 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_17_13 = {
    .key  = { 17,13 },
    .cell = { .ents={&STARTING_AREA_COL_107}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_18_13 = {
    .key  = { 18,13 },
    .cell = { .ents={&STARTING_AREA_COL_108}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_19_13 = {
    .key  = { 19,13 },
    .cell = { .ents={&STARTING_AREA_COL_109}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_0_14 = {
    .key  = { 0,14 },
    .cell = { .ents={&STARTING_AREA_COL_110}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_1_14 = {
    .key  = { 1,14 },
    .cell = { .ents={&STARTING_AREA_COL_111}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_2_14 = {
    .key  = { 2,14 },
    .cell = { .ents={&STARTING_AREA_COL_112}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_3_14 = {
    .key  = { 3,14 },
    .cell = { .ents={&STARTING_AREA_COL_113}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_4_14 = {
    .key  = { 4,14 },
    .cell = { .ents={&STARTING_AREA_COL_114}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_5_14 = {
    .key  = { 5,14 },
    .cell = { .ents={&STARTING_AREA_COL_115}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_6_14 = {
    .key  = { 6,14 },
    .cell = { .ents={&STARTING_AREA_COL_116}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_7_14 = {
    .key  = { 7,14 },
    .cell = { .ents={&STARTING_AREA_COL_117}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_8_14 = {
    .key  = { 8,14 },
    .cell = { .ents={&STARTING_AREA_COL_118}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_9_14 = {
    .key  = { 9,14 },
    .cell = { .ents={&STARTING_AREA_COL_119}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_10_14 = {
    .key  = { 10,14 },
    .cell = { .ents={&STARTING_AREA_COL_120}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_11_14 = {
    .key  = { 11,14 },
    .cell = { .ents={&STARTING_AREA_COL_121}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_12_14 = {
    .key  = { 12,14 },
    .cell = { .ents={&STARTING_AREA_COL_122}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_13_14 = {
    .key  = { 13,14 },
    .cell = { .ents={&STARTING_AREA_COL_123}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_14_14 = {
    .key  = { 14,14 },
    .cell = { .ents={&STARTING_AREA_COL_124}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_15_14 = {
    .key  = { 15,14 },
    .cell = { .ents={&STARTING_AREA_COL_125}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_16_14 = {
    .key  = { 16,14 },
    .cell = { .ents={&STARTING_AREA_COL_126}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_17_14 = {
    .key  = { 17,14 },
    .cell = { .ents={&STARTING_AREA_COL_127}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_18_14 = {
    .key  = { 18,14 },
    .cell = { .ents={&STARTING_AREA_COL_128}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_19_14 = {
    .key  = { 19,14 },
    .cell = { .ents={&STARTING_AREA_COL_129}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_13_6 = {
    .key  = { 13,6 },
    .cell = { .ents={&STARTING_AREA_ITE_130}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_7_8 = {
    .key  = { 7,8 },
    .cell = { .ents={&STARTING_AREA_ITE_131, &STARTING_AREA_ENT_138}, .count=2 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_10_2 = {
    .key  = { 10,2 },
    .cell = { .ents={&STARTING_AREA_ENT_132}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_11_2 = {
    .key  = { 11,2 },
    .cell = { .ents={&STARTING_AREA_ENT_132}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_10_3 = {
    .key  = { 10,3 },
    .cell = { .ents={&STARTING_AREA_ENT_132}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_11_3 = {
    .key  = { 11,3 },
    .cell = { .ents={&STARTING_AREA_ENT_132}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_6_3 = {
    .key  = { 6,3 },
    .cell = { .ents={&STARTING_AREA_ENT_133}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_7_3 = {
    .key  = { 7,3 },
    .cell = { .ents={&STARTING_AREA_ENT_133}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_12_3 = {
    .key  = { 12,3 },
    .cell = { .ents={&STARTING_AREA_ENT_134}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_13_3 = {
    .key  = { 13,3 },
    .cell = { .ents={&STARTING_AREA_ENT_134}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_18_3 = {
    .key  = { 18,3 },
    .cell = { .ents={&STARTING_AREA_ENT_135}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_16_6 = {
    .key  = { 16,6 },
    .cell = { .ents={&STARTING_AREA_ENT_136}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_17_6 = {
    .key  = { 17,6 },
    .cell = { .ents={&STARTING_AREA_ENT_136}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_16_7 = {
    .key  = { 16,7 },
    .cell = { .ents={&STARTING_AREA_ENT_136}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_17_7 = {
    .key  = { 17,7 },
    .cell = { .ents={&STARTING_AREA_ENT_136}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_3_8 = {
    .key  = { 3,8 },
    .cell = { .ents={&STARTING_AREA_ENT_137}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_4_8 = {
    .key  = { 4,8 },
    .cell = { .ents={&STARTING_AREA_ENT_137}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_3_9 = {
    .key  = { 3,9 },
    .cell = { .ents={&STARTING_AREA_ENT_137}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_4_9 = {
    .key  = { 4,9 },
    .cell = { .ents={&STARTING_AREA_ENT_137}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_6_8 = {
    .key  = { 6,8 },
    .cell = { .ents={&STARTING_AREA_ENT_138}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_6_9 = {
    .key  = { 6,9 },
    .cell = { .ents={&STARTING_AREA_ENT_138}, .count=1 },
    .next = NULL,
};
static GridEntry STARTING_AREA_GENTRY_15_13 = {
    .key  = { 15,13 },
    .cell = { .ents={&STARTING_AREA_ENT_139}, .count=1 },
    .next = NULL,
};

static EntityList ENTIDADES_STARTING_AREA = {
    .ents     = { &STARTING_AREA_ENT_132, &STARTING_AREA_ENT_133, &STARTING_AREA_ENT_134, &STARTING_AREA_ENT_135, &STARTING_AREA_ENT_136, &STARTING_AREA_ENT_137, &STARTING_AREA_ENT_138, &STARTING_AREA_ENT_139,  },
    .count = 8,
};

static Grid GRID_STARTING_AREA = {
    .cells     = { NULL },
    .cell_size = 16,
};

static void map_init_STARTING_AREA(void) {
    STARTING_AREA_GENTRY_0_0.next = GRID_STARTING_AREA.cells[0];
    GRID_STARTING_AREA.cells[0] = &STARTING_AREA_GENTRY_0_0;
    STARTING_AREA_GENTRY_1_0.next = GRID_STARTING_AREA.cells[1];
    GRID_STARTING_AREA.cells[1] = &STARTING_AREA_GENTRY_1_0;
    STARTING_AREA_GENTRY_2_0.next = GRID_STARTING_AREA.cells[2];
    GRID_STARTING_AREA.cells[2] = &STARTING_AREA_GENTRY_2_0;
    STARTING_AREA_GENTRY_3_0.next = GRID_STARTING_AREA.cells[3];
    GRID_STARTING_AREA.cells[3] = &STARTING_AREA_GENTRY_3_0;
    STARTING_AREA_GENTRY_4_0.next = GRID_STARTING_AREA.cells[4];
    GRID_STARTING_AREA.cells[4] = &STARTING_AREA_GENTRY_4_0;
    STARTING_AREA_GENTRY_5_0.next = GRID_STARTING_AREA.cells[5];
    GRID_STARTING_AREA.cells[5] = &STARTING_AREA_GENTRY_5_0;
    STARTING_AREA_GENTRY_6_0.next = GRID_STARTING_AREA.cells[6];
    GRID_STARTING_AREA.cells[6] = &STARTING_AREA_GENTRY_6_0;
    STARTING_AREA_GENTRY_7_0.next = GRID_STARTING_AREA.cells[7];
    GRID_STARTING_AREA.cells[7] = &STARTING_AREA_GENTRY_7_0;
    STARTING_AREA_GENTRY_8_0.next = GRID_STARTING_AREA.cells[8];
    GRID_STARTING_AREA.cells[8] = &STARTING_AREA_GENTRY_8_0;
    STARTING_AREA_GENTRY_9_0.next = GRID_STARTING_AREA.cells[9];
    GRID_STARTING_AREA.cells[9] = &STARTING_AREA_GENTRY_9_0;
    STARTING_AREA_GENTRY_10_0.next = GRID_STARTING_AREA.cells[10];
    GRID_STARTING_AREA.cells[10] = &STARTING_AREA_GENTRY_10_0;
    STARTING_AREA_GENTRY_11_0.next = GRID_STARTING_AREA.cells[11];
    GRID_STARTING_AREA.cells[11] = &STARTING_AREA_GENTRY_11_0;
    STARTING_AREA_GENTRY_12_0.next = GRID_STARTING_AREA.cells[12];
    GRID_STARTING_AREA.cells[12] = &STARTING_AREA_GENTRY_12_0;
    STARTING_AREA_GENTRY_13_0.next = GRID_STARTING_AREA.cells[13];
    GRID_STARTING_AREA.cells[13] = &STARTING_AREA_GENTRY_13_0;
    STARTING_AREA_GENTRY_14_0.next = GRID_STARTING_AREA.cells[14];
    GRID_STARTING_AREA.cells[14] = &STARTING_AREA_GENTRY_14_0;
    STARTING_AREA_GENTRY_15_0.next = GRID_STARTING_AREA.cells[15];
    GRID_STARTING_AREA.cells[15] = &STARTING_AREA_GENTRY_15_0;
    STARTING_AREA_GENTRY_16_0.next = GRID_STARTING_AREA.cells[16];
    GRID_STARTING_AREA.cells[16] = &STARTING_AREA_GENTRY_16_0;
    STARTING_AREA_GENTRY_17_0.next = GRID_STARTING_AREA.cells[17];
    GRID_STARTING_AREA.cells[17] = &STARTING_AREA_GENTRY_17_0;
    STARTING_AREA_GENTRY_18_0.next = GRID_STARTING_AREA.cells[18];
    GRID_STARTING_AREA.cells[18] = &STARTING_AREA_GENTRY_18_0;
    STARTING_AREA_GENTRY_19_0.next = GRID_STARTING_AREA.cells[19];
    GRID_STARTING_AREA.cells[19] = &STARTING_AREA_GENTRY_19_0;
    STARTING_AREA_GENTRY_0_1.next = GRID_STARTING_AREA.cells[31];
    GRID_STARTING_AREA.cells[31] = &STARTING_AREA_GENTRY_0_1;
    STARTING_AREA_GENTRY_19_1.next = GRID_STARTING_AREA.cells[12];
    GRID_STARTING_AREA.cells[12] = &STARTING_AREA_GENTRY_19_1;
    STARTING_AREA_GENTRY_0_2.next = GRID_STARTING_AREA.cells[62];
    GRID_STARTING_AREA.cells[62] = &STARTING_AREA_GENTRY_0_2;
    STARTING_AREA_GENTRY_19_2.next = GRID_STARTING_AREA.cells[45];
    GRID_STARTING_AREA.cells[45] = &STARTING_AREA_GENTRY_19_2;
    STARTING_AREA_GENTRY_0_3.next = GRID_STARTING_AREA.cells[93];
    GRID_STARTING_AREA.cells[93] = &STARTING_AREA_GENTRY_0_3;
    STARTING_AREA_GENTRY_19_3.next = GRID_STARTING_AREA.cells[78];
    GRID_STARTING_AREA.cells[78] = &STARTING_AREA_GENTRY_19_3;
    STARTING_AREA_GENTRY_0_4.next = GRID_STARTING_AREA.cells[124];
    GRID_STARTING_AREA.cells[124] = &STARTING_AREA_GENTRY_0_4;
    STARTING_AREA_GENTRY_1_4.next = GRID_STARTING_AREA.cells[125];
    GRID_STARTING_AREA.cells[125] = &STARTING_AREA_GENTRY_1_4;
    STARTING_AREA_GENTRY_2_4.next = GRID_STARTING_AREA.cells[126];
    GRID_STARTING_AREA.cells[126] = &STARTING_AREA_GENTRY_2_4;
    STARTING_AREA_GENTRY_3_4.next = GRID_STARTING_AREA.cells[127];
    GRID_STARTING_AREA.cells[127] = &STARTING_AREA_GENTRY_3_4;
    STARTING_AREA_GENTRY_4_4.next = GRID_STARTING_AREA.cells[120];
    GRID_STARTING_AREA.cells[120] = &STARTING_AREA_GENTRY_4_4;
    STARTING_AREA_GENTRY_5_4.next = GRID_STARTING_AREA.cells[121];
    GRID_STARTING_AREA.cells[121] = &STARTING_AREA_GENTRY_5_4;
    STARTING_AREA_GENTRY_6_4.next = GRID_STARTING_AREA.cells[122];
    GRID_STARTING_AREA.cells[122] = &STARTING_AREA_GENTRY_6_4;
    STARTING_AREA_GENTRY_7_4.next = GRID_STARTING_AREA.cells[123];
    GRID_STARTING_AREA.cells[123] = &STARTING_AREA_GENTRY_7_4;
    STARTING_AREA_GENTRY_8_4.next = GRID_STARTING_AREA.cells[116];
    GRID_STARTING_AREA.cells[116] = &STARTING_AREA_GENTRY_8_4;
    STARTING_AREA_GENTRY_11_4.next = GRID_STARTING_AREA.cells[119];
    GRID_STARTING_AREA.cells[119] = &STARTING_AREA_GENTRY_11_4;
    STARTING_AREA_GENTRY_12_4.next = GRID_STARTING_AREA.cells[112];
    GRID_STARTING_AREA.cells[112] = &STARTING_AREA_GENTRY_12_4;
    STARTING_AREA_GENTRY_13_4.next = GRID_STARTING_AREA.cells[113];
    GRID_STARTING_AREA.cells[113] = &STARTING_AREA_GENTRY_13_4;
    STARTING_AREA_GENTRY_14_4.next = GRID_STARTING_AREA.cells[114];
    GRID_STARTING_AREA.cells[114] = &STARTING_AREA_GENTRY_14_4;
    STARTING_AREA_GENTRY_15_4.next = GRID_STARTING_AREA.cells[115];
    GRID_STARTING_AREA.cells[115] = &STARTING_AREA_GENTRY_15_4;
    STARTING_AREA_GENTRY_16_4.next = GRID_STARTING_AREA.cells[108];
    GRID_STARTING_AREA.cells[108] = &STARTING_AREA_GENTRY_16_4;
    STARTING_AREA_GENTRY_17_4.next = GRID_STARTING_AREA.cells[109];
    GRID_STARTING_AREA.cells[109] = &STARTING_AREA_GENTRY_17_4;
    STARTING_AREA_GENTRY_18_4.next = GRID_STARTING_AREA.cells[110];
    GRID_STARTING_AREA.cells[110] = &STARTING_AREA_GENTRY_18_4;
    STARTING_AREA_GENTRY_19_4.next = GRID_STARTING_AREA.cells[111];
    GRID_STARTING_AREA.cells[111] = &STARTING_AREA_GENTRY_19_4;
    STARTING_AREA_GENTRY_0_5.next = GRID_STARTING_AREA.cells[155];
    GRID_STARTING_AREA.cells[155] = &STARTING_AREA_GENTRY_0_5;
    STARTING_AREA_GENTRY_8_5.next = GRID_STARTING_AREA.cells[147];
    GRID_STARTING_AREA.cells[147] = &STARTING_AREA_GENTRY_8_5;
    STARTING_AREA_GENTRY_12_5.next = GRID_STARTING_AREA.cells[151];
    GRID_STARTING_AREA.cells[151] = &STARTING_AREA_GENTRY_12_5;
    STARTING_AREA_GENTRY_18_5.next = GRID_STARTING_AREA.cells[137];
    GRID_STARTING_AREA.cells[137] = &STARTING_AREA_GENTRY_18_5;
    STARTING_AREA_GENTRY_19_5.next = GRID_STARTING_AREA.cells[136];
    GRID_STARTING_AREA.cells[136] = &STARTING_AREA_GENTRY_19_5;
    STARTING_AREA_GENTRY_0_6.next = GRID_STARTING_AREA.cells[186];
    GRID_STARTING_AREA.cells[186] = &STARTING_AREA_GENTRY_0_6;
    STARTING_AREA_GENTRY_8_6.next = GRID_STARTING_AREA.cells[178];
    GRID_STARTING_AREA.cells[178] = &STARTING_AREA_GENTRY_8_6;
    STARTING_AREA_GENTRY_9_6.next = GRID_STARTING_AREA.cells[179];
    GRID_STARTING_AREA.cells[179] = &STARTING_AREA_GENTRY_9_6;
    STARTING_AREA_GENTRY_12_6.next = GRID_STARTING_AREA.cells[182];
    GRID_STARTING_AREA.cells[182] = &STARTING_AREA_GENTRY_12_6;
    STARTING_AREA_GENTRY_19_6.next = GRID_STARTING_AREA.cells[169];
    GRID_STARTING_AREA.cells[169] = &STARTING_AREA_GENTRY_19_6;
    STARTING_AREA_GENTRY_0_7.next = GRID_STARTING_AREA.cells[217];
    GRID_STARTING_AREA.cells[217] = &STARTING_AREA_GENTRY_0_7;
    STARTING_AREA_GENTRY_8_7.next = GRID_STARTING_AREA.cells[209];
    GRID_STARTING_AREA.cells[209] = &STARTING_AREA_GENTRY_8_7;
    STARTING_AREA_GENTRY_12_7.next = GRID_STARTING_AREA.cells[213];
    GRID_STARTING_AREA.cells[213] = &STARTING_AREA_GENTRY_12_7;
    STARTING_AREA_GENTRY_13_7.next = GRID_STARTING_AREA.cells[212];
    GRID_STARTING_AREA.cells[212] = &STARTING_AREA_GENTRY_13_7;
    STARTING_AREA_GENTRY_19_7.next = GRID_STARTING_AREA.cells[202];
    GRID_STARTING_AREA.cells[202] = &STARTING_AREA_GENTRY_19_7;
    STARTING_AREA_GENTRY_0_8.next = GRID_STARTING_AREA.cells[248];
    GRID_STARTING_AREA.cells[248] = &STARTING_AREA_GENTRY_0_8;
    STARTING_AREA_GENTRY_8_8.next = GRID_STARTING_AREA.cells[240];
    GRID_STARTING_AREA.cells[240] = &STARTING_AREA_GENTRY_8_8;
    STARTING_AREA_GENTRY_11_8.next = GRID_STARTING_AREA.cells[243];
    GRID_STARTING_AREA.cells[243] = &STARTING_AREA_GENTRY_11_8;
    STARTING_AREA_GENTRY_12_8.next = GRID_STARTING_AREA.cells[244];
    GRID_STARTING_AREA.cells[244] = &STARTING_AREA_GENTRY_12_8;
    STARTING_AREA_GENTRY_13_8.next = GRID_STARTING_AREA.cells[245];
    GRID_STARTING_AREA.cells[245] = &STARTING_AREA_GENTRY_13_8;
    STARTING_AREA_GENTRY_14_8.next = GRID_STARTING_AREA.cells[246];
    GRID_STARTING_AREA.cells[246] = &STARTING_AREA_GENTRY_14_8;
    STARTING_AREA_GENTRY_15_8.next = GRID_STARTING_AREA.cells[247];
    GRID_STARTING_AREA.cells[247] = &STARTING_AREA_GENTRY_15_8;
    STARTING_AREA_GENTRY_19_8.next = GRID_STARTING_AREA.cells[235];
    GRID_STARTING_AREA.cells[235] = &STARTING_AREA_GENTRY_19_8;
    STARTING_AREA_GENTRY_0_9.next = GRID_STARTING_AREA.cells[279];
    GRID_STARTING_AREA.cells[279] = &STARTING_AREA_GENTRY_0_9;
    STARTING_AREA_GENTRY_7_9.next = GRID_STARTING_AREA.cells[272];
    GRID_STARTING_AREA.cells[272] = &STARTING_AREA_GENTRY_7_9;
    STARTING_AREA_GENTRY_8_9.next = GRID_STARTING_AREA.cells[287];
    GRID_STARTING_AREA.cells[287] = &STARTING_AREA_GENTRY_8_9;
    STARTING_AREA_GENTRY_12_9.next = GRID_STARTING_AREA.cells[283];
    GRID_STARTING_AREA.cells[283] = &STARTING_AREA_GENTRY_12_9;
    STARTING_AREA_GENTRY_13_9.next = GRID_STARTING_AREA.cells[282];
    GRID_STARTING_AREA.cells[282] = &STARTING_AREA_GENTRY_13_9;
    STARTING_AREA_GENTRY_14_9.next = GRID_STARTING_AREA.cells[281];
    GRID_STARTING_AREA.cells[281] = &STARTING_AREA_GENTRY_14_9;
    STARTING_AREA_GENTRY_15_9.next = GRID_STARTING_AREA.cells[280];
    GRID_STARTING_AREA.cells[280] = &STARTING_AREA_GENTRY_15_9;
    STARTING_AREA_GENTRY_16_9.next = GRID_STARTING_AREA.cells[263];
    GRID_STARTING_AREA.cells[263] = &STARTING_AREA_GENTRY_16_9;
    STARTING_AREA_GENTRY_19_9.next = GRID_STARTING_AREA.cells[260];
    GRID_STARTING_AREA.cells[260] = &STARTING_AREA_GENTRY_19_9;
    STARTING_AREA_GENTRY_0_10.next = GRID_STARTING_AREA.cells[310];
    GRID_STARTING_AREA.cells[310] = &STARTING_AREA_GENTRY_0_10;
    STARTING_AREA_GENTRY_4_10.next = GRID_STARTING_AREA.cells[306];
    GRID_STARTING_AREA.cells[306] = &STARTING_AREA_GENTRY_4_10;
    STARTING_AREA_GENTRY_5_10.next = GRID_STARTING_AREA.cells[307];
    GRID_STARTING_AREA.cells[307] = &STARTING_AREA_GENTRY_5_10;
    STARTING_AREA_GENTRY_6_10.next = GRID_STARTING_AREA.cells[304];
    GRID_STARTING_AREA.cells[304] = &STARTING_AREA_GENTRY_6_10;
    STARTING_AREA_GENTRY_7_10.next = GRID_STARTING_AREA.cells[305];
    GRID_STARTING_AREA.cells[305] = &STARTING_AREA_GENTRY_7_10;
    STARTING_AREA_GENTRY_8_10.next = GRID_STARTING_AREA.cells[318];
    GRID_STARTING_AREA.cells[318] = &STARTING_AREA_GENTRY_8_10;
    STARTING_AREA_GENTRY_9_10.next = GRID_STARTING_AREA.cells[319];
    GRID_STARTING_AREA.cells[319] = &STARTING_AREA_GENTRY_9_10;
    STARTING_AREA_GENTRY_12_10.next = GRID_STARTING_AREA.cells[314];
    GRID_STARTING_AREA.cells[314] = &STARTING_AREA_GENTRY_12_10;
    STARTING_AREA_GENTRY_13_10.next = GRID_STARTING_AREA.cells[315];
    GRID_STARTING_AREA.cells[315] = &STARTING_AREA_GENTRY_13_10;
    STARTING_AREA_GENTRY_14_10.next = GRID_STARTING_AREA.cells[312];
    GRID_STARTING_AREA.cells[312] = &STARTING_AREA_GENTRY_14_10;
    STARTING_AREA_GENTRY_19_10.next = GRID_STARTING_AREA.cells[293];
    GRID_STARTING_AREA.cells[293] = &STARTING_AREA_GENTRY_19_10;
    STARTING_AREA_GENTRY_0_11.next = GRID_STARTING_AREA.cells[341];
    GRID_STARTING_AREA.cells[341] = &STARTING_AREA_GENTRY_0_11;
    STARTING_AREA_GENTRY_3_11.next = GRID_STARTING_AREA.cells[342];
    GRID_STARTING_AREA.cells[342] = &STARTING_AREA_GENTRY_3_11;
    STARTING_AREA_GENTRY_4_11.next = GRID_STARTING_AREA.cells[337];
    GRID_STARTING_AREA.cells[337] = &STARTING_AREA_GENTRY_4_11;
    STARTING_AREA_GENTRY_5_11.next = GRID_STARTING_AREA.cells[336];
    GRID_STARTING_AREA.cells[336] = &STARTING_AREA_GENTRY_5_11;
    STARTING_AREA_GENTRY_13_11.next = GRID_STARTING_AREA.cells[344];
    GRID_STARTING_AREA.cells[344] = &STARTING_AREA_GENTRY_13_11;
    STARTING_AREA_GENTRY_18_11.next = GRID_STARTING_AREA.cells[327];
    GRID_STARTING_AREA.cells[327] = &STARTING_AREA_GENTRY_18_11;
    STARTING_AREA_GENTRY_19_11.next = GRID_STARTING_AREA.cells[326];
    GRID_STARTING_AREA.cells[326] = &STARTING_AREA_GENTRY_19_11;
    STARTING_AREA_GENTRY_0_12.next = GRID_STARTING_AREA.cells[372];
    GRID_STARTING_AREA.cells[372] = &STARTING_AREA_GENTRY_0_12;
    STARTING_AREA_GENTRY_3_12.next = GRID_STARTING_AREA.cells[375];
    GRID_STARTING_AREA.cells[375] = &STARTING_AREA_GENTRY_3_12;
    STARTING_AREA_GENTRY_4_12.next = GRID_STARTING_AREA.cells[368];
    GRID_STARTING_AREA.cells[368] = &STARTING_AREA_GENTRY_4_12;
    STARTING_AREA_GENTRY_10_12.next = GRID_STARTING_AREA.cells[382];
    GRID_STARTING_AREA.cells[382] = &STARTING_AREA_GENTRY_10_12;
    STARTING_AREA_GENTRY_17_12.next = GRID_STARTING_AREA.cells[357];
    GRID_STARTING_AREA.cells[357] = &STARTING_AREA_GENTRY_17_12;
    STARTING_AREA_GENTRY_18_12.next = GRID_STARTING_AREA.cells[358];
    GRID_STARTING_AREA.cells[358] = &STARTING_AREA_GENTRY_18_12;
    STARTING_AREA_GENTRY_19_12.next = GRID_STARTING_AREA.cells[359];
    GRID_STARTING_AREA.cells[359] = &STARTING_AREA_GENTRY_19_12;
    STARTING_AREA_GENTRY_0_13.next = GRID_STARTING_AREA.cells[403];
    GRID_STARTING_AREA.cells[403] = &STARTING_AREA_GENTRY_0_13;
    STARTING_AREA_GENTRY_1_13.next = GRID_STARTING_AREA.cells[402];
    GRID_STARTING_AREA.cells[402] = &STARTING_AREA_GENTRY_1_13;
    STARTING_AREA_GENTRY_6_13.next = GRID_STARTING_AREA.cells[405];
    GRID_STARTING_AREA.cells[405] = &STARTING_AREA_GENTRY_6_13;
    STARTING_AREA_GENTRY_10_13.next = GRID_STARTING_AREA.cells[409];
    GRID_STARTING_AREA.cells[409] = &STARTING_AREA_GENTRY_10_13;
    STARTING_AREA_GENTRY_11_13.next = GRID_STARTING_AREA.cells[408];
    GRID_STARTING_AREA.cells[408] = &STARTING_AREA_GENTRY_11_13;
    STARTING_AREA_GENTRY_16_13.next = GRID_STARTING_AREA.cells[387];
    GRID_STARTING_AREA.cells[387] = &STARTING_AREA_GENTRY_16_13;
    STARTING_AREA_GENTRY_17_13.next = GRID_STARTING_AREA.cells[386];
    GRID_STARTING_AREA.cells[386] = &STARTING_AREA_GENTRY_17_13;
    STARTING_AREA_GENTRY_18_13.next = GRID_STARTING_AREA.cells[385];
    GRID_STARTING_AREA.cells[385] = &STARTING_AREA_GENTRY_18_13;
    STARTING_AREA_GENTRY_19_13.next = GRID_STARTING_AREA.cells[384];
    GRID_STARTING_AREA.cells[384] = &STARTING_AREA_GENTRY_19_13;
    STARTING_AREA_GENTRY_0_14.next = GRID_STARTING_AREA.cells[434];
    GRID_STARTING_AREA.cells[434] = &STARTING_AREA_GENTRY_0_14;
    STARTING_AREA_GENTRY_1_14.next = GRID_STARTING_AREA.cells[435];
    GRID_STARTING_AREA.cells[435] = &STARTING_AREA_GENTRY_1_14;
    STARTING_AREA_GENTRY_2_14.next = GRID_STARTING_AREA.cells[432];
    GRID_STARTING_AREA.cells[432] = &STARTING_AREA_GENTRY_2_14;
    STARTING_AREA_GENTRY_3_14.next = GRID_STARTING_AREA.cells[433];
    GRID_STARTING_AREA.cells[433] = &STARTING_AREA_GENTRY_3_14;
    STARTING_AREA_GENTRY_4_14.next = GRID_STARTING_AREA.cells[438];
    GRID_STARTING_AREA.cells[438] = &STARTING_AREA_GENTRY_4_14;
    STARTING_AREA_GENTRY_5_14.next = GRID_STARTING_AREA.cells[439];
    GRID_STARTING_AREA.cells[439] = &STARTING_AREA_GENTRY_5_14;
    STARTING_AREA_GENTRY_6_14.next = GRID_STARTING_AREA.cells[436];
    GRID_STARTING_AREA.cells[436] = &STARTING_AREA_GENTRY_6_14;
    STARTING_AREA_GENTRY_7_14.next = GRID_STARTING_AREA.cells[437];
    GRID_STARTING_AREA.cells[437] = &STARTING_AREA_GENTRY_7_14;
    STARTING_AREA_GENTRY_8_14.next = GRID_STARTING_AREA.cells[442];
    GRID_STARTING_AREA.cells[442] = &STARTING_AREA_GENTRY_8_14;
    STARTING_AREA_GENTRY_9_14.next = GRID_STARTING_AREA.cells[443];
    GRID_STARTING_AREA.cells[443] = &STARTING_AREA_GENTRY_9_14;
    STARTING_AREA_GENTRY_10_14.next = GRID_STARTING_AREA.cells[440];
    GRID_STARTING_AREA.cells[440] = &STARTING_AREA_GENTRY_10_14;
    STARTING_AREA_GENTRY_11_14.next = GRID_STARTING_AREA.cells[441];
    GRID_STARTING_AREA.cells[441] = &STARTING_AREA_GENTRY_11_14;
    STARTING_AREA_GENTRY_12_14.next = GRID_STARTING_AREA.cells[446];
    GRID_STARTING_AREA.cells[446] = &STARTING_AREA_GENTRY_12_14;
    STARTING_AREA_GENTRY_13_14.next = GRID_STARTING_AREA.cells[447];
    GRID_STARTING_AREA.cells[447] = &STARTING_AREA_GENTRY_13_14;
    STARTING_AREA_GENTRY_14_14.next = GRID_STARTING_AREA.cells[444];
    GRID_STARTING_AREA.cells[444] = &STARTING_AREA_GENTRY_14_14;
    STARTING_AREA_GENTRY_15_14.next = GRID_STARTING_AREA.cells[445];
    GRID_STARTING_AREA.cells[445] = &STARTING_AREA_GENTRY_15_14;
    STARTING_AREA_GENTRY_16_14.next = GRID_STARTING_AREA.cells[418];
    GRID_STARTING_AREA.cells[418] = &STARTING_AREA_GENTRY_16_14;
    STARTING_AREA_GENTRY_17_14.next = GRID_STARTING_AREA.cells[419];
    GRID_STARTING_AREA.cells[419] = &STARTING_AREA_GENTRY_17_14;
    STARTING_AREA_GENTRY_18_14.next = GRID_STARTING_AREA.cells[416];
    GRID_STARTING_AREA.cells[416] = &STARTING_AREA_GENTRY_18_14;
    STARTING_AREA_GENTRY_19_14.next = GRID_STARTING_AREA.cells[417];
    GRID_STARTING_AREA.cells[417] = &STARTING_AREA_GENTRY_19_14;
    STARTING_AREA_GENTRY_13_6.next = GRID_STARTING_AREA.cells[183];
    GRID_STARTING_AREA.cells[183] = &STARTING_AREA_GENTRY_13_6;
    STARTING_AREA_GENTRY_7_8.next = GRID_STARTING_AREA.cells[255];
    GRID_STARTING_AREA.cells[255] = &STARTING_AREA_GENTRY_7_8;
    STARTING_AREA_GENTRY_10_2.next = GRID_STARTING_AREA.cells[52];
    GRID_STARTING_AREA.cells[52] = &STARTING_AREA_GENTRY_10_2;
    STARTING_AREA_GENTRY_11_2.next = GRID_STARTING_AREA.cells[53];
    GRID_STARTING_AREA.cells[53] = &STARTING_AREA_GENTRY_11_2;
    STARTING_AREA_GENTRY_10_3.next = GRID_STARTING_AREA.cells[87];
    GRID_STARTING_AREA.cells[87] = &STARTING_AREA_GENTRY_10_3;
    STARTING_AREA_GENTRY_11_3.next = GRID_STARTING_AREA.cells[86];
    GRID_STARTING_AREA.cells[86] = &STARTING_AREA_GENTRY_11_3;
    STARTING_AREA_GENTRY_6_3.next = GRID_STARTING_AREA.cells[91];
    GRID_STARTING_AREA.cells[91] = &STARTING_AREA_GENTRY_6_3;
    STARTING_AREA_GENTRY_7_3.next = GRID_STARTING_AREA.cells[90];
    GRID_STARTING_AREA.cells[90] = &STARTING_AREA_GENTRY_7_3;
    STARTING_AREA_GENTRY_12_3.next = GRID_STARTING_AREA.cells[81];
    GRID_STARTING_AREA.cells[81] = &STARTING_AREA_GENTRY_12_3;
    STARTING_AREA_GENTRY_13_3.next = GRID_STARTING_AREA.cells[80];
    GRID_STARTING_AREA.cells[80] = &STARTING_AREA_GENTRY_13_3;
    STARTING_AREA_GENTRY_18_3.next = GRID_STARTING_AREA.cells[79];
    GRID_STARTING_AREA.cells[79] = &STARTING_AREA_GENTRY_18_3;
    STARTING_AREA_GENTRY_16_6.next = GRID_STARTING_AREA.cells[170];
    GRID_STARTING_AREA.cells[170] = &STARTING_AREA_GENTRY_16_6;
    STARTING_AREA_GENTRY_17_6.next = GRID_STARTING_AREA.cells[171];
    GRID_STARTING_AREA.cells[171] = &STARTING_AREA_GENTRY_17_6;
    STARTING_AREA_GENTRY_16_7.next = GRID_STARTING_AREA.cells[201];
    GRID_STARTING_AREA.cells[201] = &STARTING_AREA_GENTRY_16_7;
    STARTING_AREA_GENTRY_17_7.next = GRID_STARTING_AREA.cells[200];
    GRID_STARTING_AREA.cells[200] = &STARTING_AREA_GENTRY_17_7;
    STARTING_AREA_GENTRY_3_8.next = GRID_STARTING_AREA.cells[251];
    GRID_STARTING_AREA.cells[251] = &STARTING_AREA_GENTRY_3_8;
    STARTING_AREA_GENTRY_4_8.next = GRID_STARTING_AREA.cells[252];
    GRID_STARTING_AREA.cells[252] = &STARTING_AREA_GENTRY_4_8;
    STARTING_AREA_GENTRY_3_9.next = GRID_STARTING_AREA.cells[276];
    GRID_STARTING_AREA.cells[276] = &STARTING_AREA_GENTRY_3_9;
    STARTING_AREA_GENTRY_4_9.next = GRID_STARTING_AREA.cells[275];
    GRID_STARTING_AREA.cells[275] = &STARTING_AREA_GENTRY_4_9;
    STARTING_AREA_GENTRY_6_8.next = GRID_STARTING_AREA.cells[254];
    GRID_STARTING_AREA.cells[254] = &STARTING_AREA_GENTRY_6_8;
    STARTING_AREA_GENTRY_6_9.next = GRID_STARTING_AREA.cells[273];
    GRID_STARTING_AREA.cells[273] = &STARTING_AREA_GENTRY_6_9;
    STARTING_AREA_GENTRY_15_13.next = GRID_STARTING_AREA.cells[412];
    GRID_STARTING_AREA.cells[412] = &STARTING_AREA_GENTRY_15_13;
}

typedef enum {
    AREA_STARTING_AREA,
    AREA_COUNT,
} AreaId;

static Grid *_grids[] = {
    [AREA_STARTING_AREA] = &GRID_STARTING_AREA,
};
static EntityList *_entidades[] = {
    [AREA_STARTING_AREA] = &ENTIDADES_STARTING_AREA,
};

static Grid* get_grid(AreaId id){
    if(id<0||id>=AREA_COUNT) return nullptr;
    return _grids[id];
}

static EntityList* get_entidades(AreaId id){
    if(id<0||id>=AREA_COUNT) return nullptr;
    return _entidades[id];
}

static void maps_init(void){
    map_init_STARTING_AREA();
}
