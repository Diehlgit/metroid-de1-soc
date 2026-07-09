/* AUTO-GERADO por generate_mapas.py — não edite */
#pragma once
#include <stdint.h>
#include "../include/basics.h"
#include "../include/entity.h"
#include "../include/grid.h"
#include "tiles.h"
#include "itens.h"
#include "entidades.h"

#define CELL_SIZE         16
#define MAX_ENTS_PER_CELL 16
#define GRID_BUCKETS      1024

/* ──────────────────────────────────────────────────────────── */
/* Área: inicial */
/* ──────────────────────────────────────────────────────────── */

static Entity INICIAL_COL_0 = {
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
static Entity INICIAL_COL_1 = {
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
static Entity INICIAL_COL_2 = {
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
static Entity INICIAL_COL_3 = {
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
static Entity INICIAL_COL_4 = {
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
static Entity INICIAL_COL_5 = {
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
static Entity INICIAL_COL_6 = {
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
static Entity INICIAL_COL_7 = {
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
static Entity INICIAL_COL_8 = {
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
static Entity INICIAL_COL_9 = {
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
static Entity INICIAL_COL_10 = {
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
static Entity INICIAL_COL_11 = {
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
static Entity INICIAL_COL_12 = {
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
static Entity INICIAL_COL_13 = {
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
static Entity INICIAL_COL_14 = {
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
static Entity INICIAL_COL_15 = {
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
static Entity INICIAL_COL_16 = {
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
static Entity INICIAL_COL_17 = {
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
static Entity INICIAL_COL_18 = {
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
static Entity INICIAL_COL_19 = {
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
static Entity INICIAL_COL_20 = {
    .position       = { 320,0 },
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
static Entity INICIAL_COL_21 = {
    .position       = { 336,0 },
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
static Entity INICIAL_COL_22 = {
    .position       = { 352,0 },
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
static Entity INICIAL_COL_23 = {
    .position       = { 368,0 },
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
static Entity INICIAL_COL_24 = {
    .position       = { 384,0 },
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
static Entity INICIAL_COL_25 = {
    .position       = { 400,0 },
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
static Entity INICIAL_COL_26 = {
    .position       = { 416,0 },
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
static Entity INICIAL_COL_27 = {
    .position       = { 432,0 },
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
static Entity INICIAL_COL_28 = {
    .position       = { 448,0 },
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
static Entity INICIAL_COL_29 = {
    .position       = { 464,0 },
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
static Entity INICIAL_COL_30 = {
    .position       = { 480,0 },
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
static Entity INICIAL_COL_31 = {
    .position       = { 496,0 },
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
static Entity INICIAL_COL_32 = {
    .position       = { 512,0 },
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
static Entity INICIAL_COL_33 = {
    .position       = { 528,0 },
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
static Entity INICIAL_COL_34 = {
    .position       = { 544,0 },
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
static Entity INICIAL_COL_35 = {
    .position       = { 560,0 },
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
static Entity INICIAL_COL_36 = {
    .position       = { 576,0 },
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
static Entity INICIAL_COL_37 = {
    .position       = { 592,0 },
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
static Entity INICIAL_COL_38 = {
    .position       = { 608,0 },
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
static Entity INICIAL_COL_39 = {
    .position       = { 624,0 },
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
static Entity INICIAL_COL_40 = {
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
static Entity INICIAL_COL_41 = {
    .position       = { 624,16 },
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
static Entity INICIAL_COL_42 = {
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
static Entity INICIAL_COL_43 = {
    .position       = { 624,32 },
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
static Entity INICIAL_COL_44 = {
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
static Entity INICIAL_COL_45 = {
    .position       = { 624,48 },
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
static Entity INICIAL_COL_46 = {
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
static Entity INICIAL_COL_47 = {
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
static Entity INICIAL_COL_48 = {
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
static Entity INICIAL_COL_49 = {
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
static Entity INICIAL_COL_50 = {
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
static Entity INICIAL_COL_51 = {
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
static Entity INICIAL_COL_52 = {
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
static Entity INICIAL_COL_53 = {
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
static Entity INICIAL_COL_54 = {
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
static Entity INICIAL_COL_55 = {
    .position       = { 144,64 },
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
static Entity INICIAL_COL_56 = {
    .position       = { 160,64 },
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
static Entity INICIAL_COL_57 = {
    .position       = { 176,64 },
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
static Entity INICIAL_COL_58 = {
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
static Entity INICIAL_COL_59 = {
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
static Entity INICIAL_COL_60 = {
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
static Entity INICIAL_COL_61 = {
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
static Entity INICIAL_COL_62 = {
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
static Entity INICIAL_COL_63 = {
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
static Entity INICIAL_COL_64 = {
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
static Entity INICIAL_COL_65 = {
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
static Entity INICIAL_COL_66 = {
    .position       = { 320,64 },
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
static Entity INICIAL_COL_67 = {
    .position       = { 336,64 },
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
static Entity INICIAL_COL_68 = {
    .position       = { 352,64 },
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
static Entity INICIAL_COL_69 = {
    .position       = { 368,64 },
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
static Entity INICIAL_COL_70 = {
    .position       = { 384,64 },
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
static Entity INICIAL_COL_71 = {
    .position       = { 400,64 },
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
static Entity INICIAL_COL_72 = {
    .position       = { 416,64 },
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
static Entity INICIAL_COL_73 = {
    .position       = { 432,64 },
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
static Entity INICIAL_COL_74 = {
    .position       = { 448,64 },
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
static Entity INICIAL_COL_75 = {
    .position       = { 464,64 },
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
static Entity INICIAL_COL_76 = {
    .position       = { 480,64 },
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
static Entity INICIAL_COL_77 = {
    .position       = { 496,64 },
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
static Entity INICIAL_COL_78 = {
    .position       = { 512,64 },
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
static Entity INICIAL_COL_79 = {
    .position       = { 528,64 },
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
static Entity INICIAL_COL_80 = {
    .position       = { 544,64 },
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
static Entity INICIAL_COL_81 = {
    .position       = { 560,64 },
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
static Entity INICIAL_COL_82 = {
    .position       = { 576,64 },
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
static Entity INICIAL_COL_83 = {
    .position       = { 624,64 },
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
static Entity INICIAL_COL_84 = {
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
static Entity INICIAL_COL_85 = {
    .position       = { 624,80 },
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
static Entity INICIAL_COL_86 = {
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
static Entity INICIAL_COL_87 = {
    .position       = { 624,96 },
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
static Entity INICIAL_COL_88 = {
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
static Entity INICIAL_COL_89 = {
    .position       = { 624,112 },
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
static Entity INICIAL_COL_90 = {
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
static Entity INICIAL_COL_91 = {
    .position       = { 48,128 },
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
static Entity INICIAL_COL_92 = {
    .position       = { 64,128 },
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
static Entity INICIAL_COL_93 = {
    .position       = { 80,128 },
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
static Entity INICIAL_COL_94 = {
    .position       = { 96,128 },
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
static Entity INICIAL_COL_95 = {
    .position       = { 112,128 },
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
static Entity INICIAL_COL_96 = {
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
static Entity INICIAL_COL_97 = {
    .position       = { 144,128 },
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
static Entity INICIAL_COL_98 = {
    .position       = { 160,128 },
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
static Entity INICIAL_COL_99 = {
    .position       = { 176,128 },
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
static Entity INICIAL_COL_100 = {
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
static Entity INICIAL_COL_101 = {
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
static Entity INICIAL_COL_102 = {
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
static Entity INICIAL_COL_103 = {
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
static Entity INICIAL_COL_104 = {
    .position       = { 256,128 },
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
static Entity INICIAL_COL_105 = {
    .position       = { 272,128 },
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
static Entity INICIAL_COL_106 = {
    .position       = { 288,128 },
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
static Entity INICIAL_COL_107 = {
    .position       = { 304,128 },
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
static Entity INICIAL_COL_108 = {
    .position       = { 320,128 },
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
static Entity INICIAL_COL_109 = {
    .position       = { 336,128 },
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
static Entity INICIAL_COL_110 = {
    .position       = { 352,128 },
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
static Entity INICIAL_COL_111 = {
    .position       = { 368,128 },
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
static Entity INICIAL_COL_112 = {
    .position       = { 384,128 },
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
static Entity INICIAL_COL_113 = {
    .position       = { 400,128 },
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
static Entity INICIAL_COL_114 = {
    .position       = { 416,128 },
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
static Entity INICIAL_COL_115 = {
    .position       = { 432,128 },
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
static Entity INICIAL_COL_116 = {
    .position       = { 448,128 },
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
static Entity INICIAL_COL_117 = {
    .position       = { 464,128 },
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
static Entity INICIAL_COL_118 = {
    .position       = { 480,128 },
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
static Entity INICIAL_COL_119 = {
    .position       = { 496,128 },
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
static Entity INICIAL_COL_120 = {
    .position       = { 512,128 },
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
static Entity INICIAL_COL_121 = {
    .position       = { 528,128 },
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
static Entity INICIAL_COL_122 = {
    .position       = { 544,128 },
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
static Entity INICIAL_COL_123 = {
    .position       = { 560,128 },
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
static Entity INICIAL_COL_124 = {
    .position       = { 576,128 },
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
static Entity INICIAL_COL_125 = {
    .position       = { 592,128 },
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
static Entity INICIAL_COL_126 = {
    .position       = { 608,128 },
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
static Entity INICIAL_COL_127 = {
    .position       = { 624,128 },
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
static Entity INICIAL_COL_128 = {
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
static Entity INICIAL_COL_129 = {
    .position       = { 624,144 },
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
static Entity INICIAL_COL_130 = {
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
static Entity INICIAL_COL_131 = {
    .position       = { 624,160 },
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
static Entity INICIAL_COL_132 = {
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
static Entity INICIAL_COL_133 = {
    .position       = { 624,176 },
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
static Entity INICIAL_COL_134 = {
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
static Entity INICIAL_COL_135 = {
    .position       = { 16,192 },
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
static Entity INICIAL_COL_136 = {
    .position       = { 32,192 },
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
static Entity INICIAL_COL_137 = {
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
static Entity INICIAL_COL_138 = {
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
static Entity INICIAL_COL_139 = {
    .position       = { 80,192 },
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
static Entity INICIAL_COL_140 = {
    .position       = { 96,192 },
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
static Entity INICIAL_COL_141 = {
    .position       = { 112,192 },
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
static Entity INICIAL_COL_142 = {
    .position       = { 128,192 },
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
static Entity INICIAL_COL_143 = {
    .position       = { 144,192 },
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
static Entity INICIAL_COL_144 = {
    .position       = { 160,192 },
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
static Entity INICIAL_COL_145 = {
    .position       = { 176,192 },
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
static Entity INICIAL_COL_146 = {
    .position       = { 192,192 },
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
static Entity INICIAL_COL_147 = {
    .position       = { 208,192 },
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
static Entity INICIAL_COL_148 = {
    .position       = { 240,192 },
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
static Entity INICIAL_COL_149 = {
    .position       = { 256,192 },
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
static Entity INICIAL_COL_150 = {
    .position       = { 272,192 },
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
static Entity INICIAL_COL_151 = {
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
static Entity INICIAL_COL_152 = {
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
static Entity INICIAL_COL_153 = {
    .position       = { 320,192 },
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
static Entity INICIAL_COL_154 = {
    .position       = { 336,192 },
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
static Entity INICIAL_COL_155 = {
    .position       = { 352,192 },
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
static Entity INICIAL_COL_156 = {
    .position       = { 368,192 },
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
static Entity INICIAL_COL_157 = {
    .position       = { 384,192 },
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
static Entity INICIAL_COL_158 = {
    .position       = { 400,192 },
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
static Entity INICIAL_COL_159 = {
    .position       = { 416,192 },
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
static Entity INICIAL_COL_160 = {
    .position       = { 432,192 },
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
static Entity INICIAL_COL_161 = {
    .position       = { 448,192 },
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
static Entity INICIAL_COL_162 = {
    .position       = { 464,192 },
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
static Entity INICIAL_COL_163 = {
    .position       = { 480,192 },
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
static Entity INICIAL_COL_164 = {
    .position       = { 496,192 },
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
static Entity INICIAL_COL_165 = {
    .position       = { 512,192 },
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
static Entity INICIAL_COL_166 = {
    .position       = { 528,192 },
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
static Entity INICIAL_COL_167 = {
    .position       = { 544,192 },
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
static Entity INICIAL_COL_168 = {
    .position       = { 560,192 },
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
static Entity INICIAL_COL_169 = {
    .position       = { 624,192 },
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
static Entity INICIAL_COL_170 = {
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
static Entity INICIAL_COL_171 = {
    .position       = { 624,208 },
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
static Entity INICIAL_COL_172 = {
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
static Entity INICIAL_COL_173 = {
    .position       = { 624,224 },
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
static Entity INICIAL_COL_174 = {
    .position       = { 0,240 },
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
static Entity INICIAL_COL_175 = {
    .position       = { 624,240 },
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
static Entity INICIAL_COL_176 = {
    .position       = { 0,256 },
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
static Entity INICIAL_COL_177 = {
    .position       = { 624,256 },
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
static Entity INICIAL_COL_178 = {
    .position       = { 0,272 },
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
static Entity INICIAL_COL_179 = {
    .position       = { 624,272 },
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
static Entity INICIAL_COL_180 = {
    .position       = { 0,288 },
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
static Entity INICIAL_COL_181 = {
    .position       = { 144,288 },
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
static Entity INICIAL_COL_182 = {
    .position       = { 160,288 },
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
static Entity INICIAL_COL_183 = {
    .position       = { 176,288 },
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
static Entity INICIAL_COL_184 = {
    .position       = { 192,288 },
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
static Entity INICIAL_COL_185 = {
    .position       = { 208,288 },
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
static Entity INICIAL_COL_186 = {
    .position       = { 224,288 },
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
static Entity INICIAL_COL_187 = {
    .position       = { 240,288 },
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
static Entity INICIAL_COL_188 = {
    .position       = { 256,288 },
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
static Entity INICIAL_COL_189 = {
    .position       = { 272,288 },
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
static Entity INICIAL_COL_190 = {
    .position       = { 624,288 },
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
static Entity INICIAL_COL_191 = {
    .position       = { 0,304 },
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
static Entity INICIAL_COL_192 = {
    .position       = { 624,304 },
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
static Entity INICIAL_COL_193 = {
    .position       = { 0,320 },
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
static Entity INICIAL_COL_194 = {
    .position       = { 624,320 },
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
static Entity INICIAL_COL_195 = {
    .position       = { 0,336 },
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
static Entity INICIAL_COL_196 = {
    .position       = { 624,336 },
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
static Entity INICIAL_COL_197 = {
    .position       = { 0,352 },
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
static Entity INICIAL_COL_198 = {
    .position       = { 624,352 },
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
static Entity INICIAL_COL_199 = {
    .position       = { 0,368 },
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
static Entity INICIAL_COL_200 = {
    .position       = { 624,368 },
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
static Entity INICIAL_COL_201 = {
    .position       = { 0,384 },
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
static Entity INICIAL_COL_202 = {
    .position       = { 304,384 },
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
static Entity INICIAL_COL_203 = {
    .position       = { 320,384 },
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
static Entity INICIAL_COL_204 = {
    .position       = { 336,384 },
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
static Entity INICIAL_COL_205 = {
    .position       = { 352,384 },
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
static Entity INICIAL_COL_206 = {
    .position       = { 368,384 },
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
static Entity INICIAL_COL_207 = {
    .position       = { 384,384 },
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
static Entity INICIAL_COL_208 = {
    .position       = { 400,384 },
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
static Entity INICIAL_COL_209 = {
    .position       = { 416,384 },
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
static Entity INICIAL_COL_210 = {
    .position       = { 432,384 },
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
static Entity INICIAL_COL_211 = {
    .position       = { 448,384 },
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
static Entity INICIAL_COL_212 = {
    .position       = { 464,384 },
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
static Entity INICIAL_COL_213 = {
    .position       = { 480,384 },
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
static Entity INICIAL_COL_214 = {
    .position       = { 624,384 },
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
static Entity INICIAL_COL_215 = {
    .position       = { 0,400 },
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
static Entity INICIAL_COL_216 = {
    .position       = { 288,400 },
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
static Entity INICIAL_COL_217 = {
    .position       = { 304,400 },
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
static Entity INICIAL_COL_218 = {
    .position       = { 320,400 },
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
static Entity INICIAL_COL_219 = {
    .position       = { 336,400 },
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
static Entity INICIAL_COL_220 = {
    .position       = { 352,400 },
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
static Entity INICIAL_COL_221 = {
    .position       = { 368,400 },
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
static Entity INICIAL_COL_222 = {
    .position       = { 384,400 },
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
static Entity INICIAL_COL_223 = {
    .position       = { 400,400 },
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
static Entity INICIAL_COL_224 = {
    .position       = { 416,400 },
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
static Entity INICIAL_COL_225 = {
    .position       = { 432,400 },
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
static Entity INICIAL_COL_226 = {
    .position       = { 448,400 },
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
static Entity INICIAL_COL_227 = {
    .position       = { 464,400 },
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
static Entity INICIAL_COL_228 = {
    .position       = { 480,400 },
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
static Entity INICIAL_COL_229 = {
    .position       = { 624,400 },
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
static Entity INICIAL_COL_230 = {
    .position       = { 0,416 },
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
static Entity INICIAL_COL_231 = {
    .position       = { 272,416 },
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
static Entity INICIAL_COL_232 = {
    .position       = { 288,416 },
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
static Entity INICIAL_COL_233 = {
    .position       = { 304,416 },
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
static Entity INICIAL_COL_234 = {
    .position       = { 320,416 },
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
static Entity INICIAL_COL_235 = {
    .position       = { 336,416 },
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
static Entity INICIAL_COL_236 = {
    .position       = { 352,416 },
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
static Entity INICIAL_COL_237 = {
    .position       = { 368,416 },
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
static Entity INICIAL_COL_238 = {
    .position       = { 384,416 },
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
static Entity INICIAL_COL_239 = {
    .position       = { 400,416 },
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
static Entity INICIAL_COL_240 = {
    .position       = { 624,416 },
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
static Entity INICIAL_COL_241 = {
    .position       = { 0,432 },
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
static Entity INICIAL_COL_242 = {
    .position       = { 256,432 },
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
static Entity INICIAL_COL_243 = {
    .position       = { 272,432 },
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
static Entity INICIAL_COL_244 = {
    .position       = { 288,432 },
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
static Entity INICIAL_COL_245 = {
    .position       = { 304,432 },
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
static Entity INICIAL_COL_246 = {
    .position       = { 320,432 },
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
static Entity INICIAL_COL_247 = {
    .position       = { 336,432 },
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
static Entity INICIAL_COL_248 = {
    .position       = { 352,432 },
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
static Entity INICIAL_COL_249 = {
    .position       = { 368,432 },
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
static Entity INICIAL_COL_250 = {
    .position       = { 384,432 },
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
static Entity INICIAL_COL_251 = {
    .position       = { 400,432 },
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
static Entity INICIAL_COL_252 = {
    .position       = { 624,432 },
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
static Entity INICIAL_COL_253 = {
    .position       = { 0,448 },
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
static Entity INICIAL_COL_254 = {
    .position       = { 240,448 },
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
static Entity INICIAL_COL_255 = {
    .position       = { 256,448 },
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
static Entity INICIAL_COL_256 = {
    .position       = { 272,448 },
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
static Entity INICIAL_COL_257 = {
    .position       = { 288,448 },
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
static Entity INICIAL_COL_258 = {
    .position       = { 304,448 },
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
static Entity INICIAL_COL_259 = {
    .position       = { 320,448 },
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
static Entity INICIAL_COL_260 = {
    .position       = { 336,448 },
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
static Entity INICIAL_COL_261 = {
    .position       = { 624,448 },
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
static Entity INICIAL_COL_262 = {
    .position       = { 0,464 },
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
static Entity INICIAL_COL_263 = {
    .position       = { 16,464 },
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
static Entity INICIAL_COL_264 = {
    .position       = { 32,464 },
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
static Entity INICIAL_COL_265 = {
    .position       = { 48,464 },
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
static Entity INICIAL_COL_266 = {
    .position       = { 64,464 },
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
static Entity INICIAL_COL_267 = {
    .position       = { 80,464 },
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
static Entity INICIAL_COL_268 = {
    .position       = { 96,464 },
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
static Entity INICIAL_COL_269 = {
    .position       = { 112,464 },
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
static Entity INICIAL_COL_270 = {
    .position       = { 128,464 },
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
static Entity INICIAL_COL_271 = {
    .position       = { 144,464 },
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
static Entity INICIAL_COL_272 = {
    .position       = { 160,464 },
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
static Entity INICIAL_COL_273 = {
    .position       = { 176,464 },
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
static Entity INICIAL_COL_274 = {
    .position       = { 192,464 },
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
static Entity INICIAL_COL_275 = {
    .position       = { 208,464 },
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
static Entity INICIAL_COL_276 = {
    .position       = { 224,464 },
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
static Entity INICIAL_COL_277 = {
    .position       = { 240,464 },
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
static Entity INICIAL_COL_278 = {
    .position       = { 256,464 },
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
static Entity INICIAL_COL_279 = {
    .position       = { 272,464 },
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
static Entity INICIAL_COL_280 = {
    .position       = { 288,464 },
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
static Entity INICIAL_COL_281 = {
    .position       = { 304,464 },
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
static Entity INICIAL_COL_282 = {
    .position       = { 320,464 },
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
static Entity INICIAL_COL_283 = {
    .position       = { 336,464 },
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
static Entity INICIAL_COL_284 = {
    .position       = { 352,464 },
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
static Entity INICIAL_COL_285 = {
    .position       = { 368,464 },
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
static Entity INICIAL_COL_286 = {
    .position       = { 384,464 },
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
static Entity INICIAL_COL_287 = {
    .position       = { 400,464 },
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
static Entity INICIAL_COL_288 = {
    .position       = { 416,464 },
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
static Entity INICIAL_COL_289 = {
    .position       = { 432,464 },
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
static Entity INICIAL_COL_290 = {
    .position       = { 448,464 },
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
static Entity INICIAL_COL_291 = {
    .position       = { 464,464 },
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
static Entity INICIAL_COL_292 = {
    .position       = { 480,464 },
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
static Entity INICIAL_COL_293 = {
    .position       = { 496,464 },
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
static Entity INICIAL_COL_294 = {
    .position       = { 512,464 },
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
static Entity INICIAL_COL_295 = {
    .position       = { 528,464 },
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
static Entity INICIAL_COL_296 = {
    .position       = { 544,464 },
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
static Entity INICIAL_COL_297 = {
    .position       = { 560,464 },
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
static Entity INICIAL_COL_298 = {
    .position       = { 576,464 },
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
static Entity INICIAL_COL_299 = {
    .position       = { 592,464 },
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
static Entity INICIAL_COL_300 = {
    .position       = { 608,464 },
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
static Entity INICIAL_COL_301 = {
    .position       = { 624,464 },
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



static GridEntry INICIAL_GENTRY_0_0 = {
    .key  = { 0,0 },
    .cell = { .ents={&INICIAL_COL_0}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_1_0 = {
    .key  = { 1,0 },
    .cell = { .ents={&INICIAL_COL_1}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_2_0 = {
    .key  = { 2,0 },
    .cell = { .ents={&INICIAL_COL_2}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_3_0 = {
    .key  = { 3,0 },
    .cell = { .ents={&INICIAL_COL_3}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_4_0 = {
    .key  = { 4,0 },
    .cell = { .ents={&INICIAL_COL_4}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_5_0 = {
    .key  = { 5,0 },
    .cell = { .ents={&INICIAL_COL_5}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_6_0 = {
    .key  = { 6,0 },
    .cell = { .ents={&INICIAL_COL_6}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_7_0 = {
    .key  = { 7,0 },
    .cell = { .ents={&INICIAL_COL_7}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_8_0 = {
    .key  = { 8,0 },
    .cell = { .ents={&INICIAL_COL_8}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_9_0 = {
    .key  = { 9,0 },
    .cell = { .ents={&INICIAL_COL_9}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_10_0 = {
    .key  = { 10,0 },
    .cell = { .ents={&INICIAL_COL_10}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_11_0 = {
    .key  = { 11,0 },
    .cell = { .ents={&INICIAL_COL_11}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_12_0 = {
    .key  = { 12,0 },
    .cell = { .ents={&INICIAL_COL_12}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_13_0 = {
    .key  = { 13,0 },
    .cell = { .ents={&INICIAL_COL_13}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_14_0 = {
    .key  = { 14,0 },
    .cell = { .ents={&INICIAL_COL_14}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_15_0 = {
    .key  = { 15,0 },
    .cell = { .ents={&INICIAL_COL_15}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_16_0 = {
    .key  = { 16,0 },
    .cell = { .ents={&INICIAL_COL_16}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_17_0 = {
    .key  = { 17,0 },
    .cell = { .ents={&INICIAL_COL_17}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_18_0 = {
    .key  = { 18,0 },
    .cell = { .ents={&INICIAL_COL_18}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_19_0 = {
    .key  = { 19,0 },
    .cell = { .ents={&INICIAL_COL_19}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_20_0 = {
    .key  = { 20,0 },
    .cell = { .ents={&INICIAL_COL_20}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_21_0 = {
    .key  = { 21,0 },
    .cell = { .ents={&INICIAL_COL_21}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_22_0 = {
    .key  = { 22,0 },
    .cell = { .ents={&INICIAL_COL_22}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_23_0 = {
    .key  = { 23,0 },
    .cell = { .ents={&INICIAL_COL_23}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_24_0 = {
    .key  = { 24,0 },
    .cell = { .ents={&INICIAL_COL_24}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_25_0 = {
    .key  = { 25,0 },
    .cell = { .ents={&INICIAL_COL_25}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_26_0 = {
    .key  = { 26,0 },
    .cell = { .ents={&INICIAL_COL_26}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_27_0 = {
    .key  = { 27,0 },
    .cell = { .ents={&INICIAL_COL_27}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_28_0 = {
    .key  = { 28,0 },
    .cell = { .ents={&INICIAL_COL_28}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_29_0 = {
    .key  = { 29,0 },
    .cell = { .ents={&INICIAL_COL_29}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_30_0 = {
    .key  = { 30,0 },
    .cell = { .ents={&INICIAL_COL_30}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_31_0 = {
    .key  = { 31,0 },
    .cell = { .ents={&INICIAL_COL_31}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_32_0 = {
    .key  = { 32,0 },
    .cell = { .ents={&INICIAL_COL_32}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_33_0 = {
    .key  = { 33,0 },
    .cell = { .ents={&INICIAL_COL_33}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_34_0 = {
    .key  = { 34,0 },
    .cell = { .ents={&INICIAL_COL_34}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_35_0 = {
    .key  = { 35,0 },
    .cell = { .ents={&INICIAL_COL_35}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_36_0 = {
    .key  = { 36,0 },
    .cell = { .ents={&INICIAL_COL_36}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_37_0 = {
    .key  = { 37,0 },
    .cell = { .ents={&INICIAL_COL_37}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_38_0 = {
    .key  = { 38,0 },
    .cell = { .ents={&INICIAL_COL_38}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_0 = {
    .key  = { 39,0 },
    .cell = { .ents={&INICIAL_COL_39}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_1 = {
    .key  = { 0,1 },
    .cell = { .ents={&INICIAL_COL_40}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_1 = {
    .key  = { 39,1 },
    .cell = { .ents={&INICIAL_COL_41}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_2 = {
    .key  = { 0,2 },
    .cell = { .ents={&INICIAL_COL_42}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_2 = {
    .key  = { 39,2 },
    .cell = { .ents={&INICIAL_COL_43}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_3 = {
    .key  = { 0,3 },
    .cell = { .ents={&INICIAL_COL_44}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_3 = {
    .key  = { 39,3 },
    .cell = { .ents={&INICIAL_COL_45}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_4 = {
    .key  = { 0,4 },
    .cell = { .ents={&INICIAL_COL_46}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_1_4 = {
    .key  = { 1,4 },
    .cell = { .ents={&INICIAL_COL_47}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_2_4 = {
    .key  = { 2,4 },
    .cell = { .ents={&INICIAL_COL_48}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_3_4 = {
    .key  = { 3,4 },
    .cell = { .ents={&INICIAL_COL_49}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_4_4 = {
    .key  = { 4,4 },
    .cell = { .ents={&INICIAL_COL_50}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_5_4 = {
    .key  = { 5,4 },
    .cell = { .ents={&INICIAL_COL_51}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_6_4 = {
    .key  = { 6,4 },
    .cell = { .ents={&INICIAL_COL_52}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_7_4 = {
    .key  = { 7,4 },
    .cell = { .ents={&INICIAL_COL_53}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_8_4 = {
    .key  = { 8,4 },
    .cell = { .ents={&INICIAL_COL_54}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_9_4 = {
    .key  = { 9,4 },
    .cell = { .ents={&INICIAL_COL_55}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_10_4 = {
    .key  = { 10,4 },
    .cell = { .ents={&INICIAL_COL_56}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_11_4 = {
    .key  = { 11,4 },
    .cell = { .ents={&INICIAL_COL_57}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_12_4 = {
    .key  = { 12,4 },
    .cell = { .ents={&INICIAL_COL_58}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_13_4 = {
    .key  = { 13,4 },
    .cell = { .ents={&INICIAL_COL_59}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_14_4 = {
    .key  = { 14,4 },
    .cell = { .ents={&INICIAL_COL_60}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_15_4 = {
    .key  = { 15,4 },
    .cell = { .ents={&INICIAL_COL_61}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_16_4 = {
    .key  = { 16,4 },
    .cell = { .ents={&INICIAL_COL_62}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_17_4 = {
    .key  = { 17,4 },
    .cell = { .ents={&INICIAL_COL_63}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_18_4 = {
    .key  = { 18,4 },
    .cell = { .ents={&INICIAL_COL_64}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_19_4 = {
    .key  = { 19,4 },
    .cell = { .ents={&INICIAL_COL_65}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_20_4 = {
    .key  = { 20,4 },
    .cell = { .ents={&INICIAL_COL_66}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_21_4 = {
    .key  = { 21,4 },
    .cell = { .ents={&INICIAL_COL_67}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_22_4 = {
    .key  = { 22,4 },
    .cell = { .ents={&INICIAL_COL_68}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_23_4 = {
    .key  = { 23,4 },
    .cell = { .ents={&INICIAL_COL_69}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_24_4 = {
    .key  = { 24,4 },
    .cell = { .ents={&INICIAL_COL_70}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_25_4 = {
    .key  = { 25,4 },
    .cell = { .ents={&INICIAL_COL_71}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_26_4 = {
    .key  = { 26,4 },
    .cell = { .ents={&INICIAL_COL_72}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_27_4 = {
    .key  = { 27,4 },
    .cell = { .ents={&INICIAL_COL_73}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_28_4 = {
    .key  = { 28,4 },
    .cell = { .ents={&INICIAL_COL_74}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_29_4 = {
    .key  = { 29,4 },
    .cell = { .ents={&INICIAL_COL_75}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_30_4 = {
    .key  = { 30,4 },
    .cell = { .ents={&INICIAL_COL_76}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_31_4 = {
    .key  = { 31,4 },
    .cell = { .ents={&INICIAL_COL_77}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_32_4 = {
    .key  = { 32,4 },
    .cell = { .ents={&INICIAL_COL_78}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_33_4 = {
    .key  = { 33,4 },
    .cell = { .ents={&INICIAL_COL_79}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_34_4 = {
    .key  = { 34,4 },
    .cell = { .ents={&INICIAL_COL_80}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_35_4 = {
    .key  = { 35,4 },
    .cell = { .ents={&INICIAL_COL_81}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_36_4 = {
    .key  = { 36,4 },
    .cell = { .ents={&INICIAL_COL_82}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_4 = {
    .key  = { 39,4 },
    .cell = { .ents={&INICIAL_COL_83}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_5 = {
    .key  = { 0,5 },
    .cell = { .ents={&INICIAL_COL_84}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_5 = {
    .key  = { 39,5 },
    .cell = { .ents={&INICIAL_COL_85}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_6 = {
    .key  = { 0,6 },
    .cell = { .ents={&INICIAL_COL_86}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_6 = {
    .key  = { 39,6 },
    .cell = { .ents={&INICIAL_COL_87}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_7 = {
    .key  = { 0,7 },
    .cell = { .ents={&INICIAL_COL_88}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_7 = {
    .key  = { 39,7 },
    .cell = { .ents={&INICIAL_COL_89}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_8 = {
    .key  = { 0,8 },
    .cell = { .ents={&INICIAL_COL_90}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_3_8 = {
    .key  = { 3,8 },
    .cell = { .ents={&INICIAL_COL_91}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_4_8 = {
    .key  = { 4,8 },
    .cell = { .ents={&INICIAL_COL_92}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_5_8 = {
    .key  = { 5,8 },
    .cell = { .ents={&INICIAL_COL_93}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_6_8 = {
    .key  = { 6,8 },
    .cell = { .ents={&INICIAL_COL_94}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_7_8 = {
    .key  = { 7,8 },
    .cell = { .ents={&INICIAL_COL_95}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_8_8 = {
    .key  = { 8,8 },
    .cell = { .ents={&INICIAL_COL_96}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_9_8 = {
    .key  = { 9,8 },
    .cell = { .ents={&INICIAL_COL_97}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_10_8 = {
    .key  = { 10,8 },
    .cell = { .ents={&INICIAL_COL_98}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_11_8 = {
    .key  = { 11,8 },
    .cell = { .ents={&INICIAL_COL_99}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_12_8 = {
    .key  = { 12,8 },
    .cell = { .ents={&INICIAL_COL_100}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_13_8 = {
    .key  = { 13,8 },
    .cell = { .ents={&INICIAL_COL_101}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_14_8 = {
    .key  = { 14,8 },
    .cell = { .ents={&INICIAL_COL_102}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_15_8 = {
    .key  = { 15,8 },
    .cell = { .ents={&INICIAL_COL_103}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_16_8 = {
    .key  = { 16,8 },
    .cell = { .ents={&INICIAL_COL_104}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_17_8 = {
    .key  = { 17,8 },
    .cell = { .ents={&INICIAL_COL_105}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_18_8 = {
    .key  = { 18,8 },
    .cell = { .ents={&INICIAL_COL_106}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_19_8 = {
    .key  = { 19,8 },
    .cell = { .ents={&INICIAL_COL_107}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_20_8 = {
    .key  = { 20,8 },
    .cell = { .ents={&INICIAL_COL_108}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_21_8 = {
    .key  = { 21,8 },
    .cell = { .ents={&INICIAL_COL_109}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_22_8 = {
    .key  = { 22,8 },
    .cell = { .ents={&INICIAL_COL_110}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_23_8 = {
    .key  = { 23,8 },
    .cell = { .ents={&INICIAL_COL_111}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_24_8 = {
    .key  = { 24,8 },
    .cell = { .ents={&INICIAL_COL_112}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_25_8 = {
    .key  = { 25,8 },
    .cell = { .ents={&INICIAL_COL_113}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_26_8 = {
    .key  = { 26,8 },
    .cell = { .ents={&INICIAL_COL_114}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_27_8 = {
    .key  = { 27,8 },
    .cell = { .ents={&INICIAL_COL_115}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_28_8 = {
    .key  = { 28,8 },
    .cell = { .ents={&INICIAL_COL_116}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_29_8 = {
    .key  = { 29,8 },
    .cell = { .ents={&INICIAL_COL_117}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_30_8 = {
    .key  = { 30,8 },
    .cell = { .ents={&INICIAL_COL_118}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_31_8 = {
    .key  = { 31,8 },
    .cell = { .ents={&INICIAL_COL_119}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_32_8 = {
    .key  = { 32,8 },
    .cell = { .ents={&INICIAL_COL_120}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_33_8 = {
    .key  = { 33,8 },
    .cell = { .ents={&INICIAL_COL_121}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_34_8 = {
    .key  = { 34,8 },
    .cell = { .ents={&INICIAL_COL_122}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_35_8 = {
    .key  = { 35,8 },
    .cell = { .ents={&INICIAL_COL_123}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_36_8 = {
    .key  = { 36,8 },
    .cell = { .ents={&INICIAL_COL_124}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_37_8 = {
    .key  = { 37,8 },
    .cell = { .ents={&INICIAL_COL_125}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_38_8 = {
    .key  = { 38,8 },
    .cell = { .ents={&INICIAL_COL_126}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_8 = {
    .key  = { 39,8 },
    .cell = { .ents={&INICIAL_COL_127}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_9 = {
    .key  = { 0,9 },
    .cell = { .ents={&INICIAL_COL_128}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_9 = {
    .key  = { 39,9 },
    .cell = { .ents={&INICIAL_COL_129}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_10 = {
    .key  = { 0,10 },
    .cell = { .ents={&INICIAL_COL_130}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_10 = {
    .key  = { 39,10 },
    .cell = { .ents={&INICIAL_COL_131}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_11 = {
    .key  = { 0,11 },
    .cell = { .ents={&INICIAL_COL_132}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_11 = {
    .key  = { 39,11 },
    .cell = { .ents={&INICIAL_COL_133}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_12 = {
    .key  = { 0,12 },
    .cell = { .ents={&INICIAL_COL_134}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_1_12 = {
    .key  = { 1,12 },
    .cell = { .ents={&INICIAL_COL_135}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_2_12 = {
    .key  = { 2,12 },
    .cell = { .ents={&INICIAL_COL_136}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_3_12 = {
    .key  = { 3,12 },
    .cell = { .ents={&INICIAL_COL_137}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_4_12 = {
    .key  = { 4,12 },
    .cell = { .ents={&INICIAL_COL_138}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_5_12 = {
    .key  = { 5,12 },
    .cell = { .ents={&INICIAL_COL_139}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_6_12 = {
    .key  = { 6,12 },
    .cell = { .ents={&INICIAL_COL_140}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_7_12 = {
    .key  = { 7,12 },
    .cell = { .ents={&INICIAL_COL_141}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_8_12 = {
    .key  = { 8,12 },
    .cell = { .ents={&INICIAL_COL_142}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_9_12 = {
    .key  = { 9,12 },
    .cell = { .ents={&INICIAL_COL_143}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_10_12 = {
    .key  = { 10,12 },
    .cell = { .ents={&INICIAL_COL_144}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_11_12 = {
    .key  = { 11,12 },
    .cell = { .ents={&INICIAL_COL_145}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_12_12 = {
    .key  = { 12,12 },
    .cell = { .ents={&INICIAL_COL_146}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_13_12 = {
    .key  = { 13,12 },
    .cell = { .ents={&INICIAL_COL_147}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_15_12 = {
    .key  = { 15,12 },
    .cell = { .ents={&INICIAL_COL_148}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_16_12 = {
    .key  = { 16,12 },
    .cell = { .ents={&INICIAL_COL_149}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_17_12 = {
    .key  = { 17,12 },
    .cell = { .ents={&INICIAL_COL_150}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_18_12 = {
    .key  = { 18,12 },
    .cell = { .ents={&INICIAL_COL_151}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_19_12 = {
    .key  = { 19,12 },
    .cell = { .ents={&INICIAL_COL_152}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_20_12 = {
    .key  = { 20,12 },
    .cell = { .ents={&INICIAL_COL_153}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_21_12 = {
    .key  = { 21,12 },
    .cell = { .ents={&INICIAL_COL_154}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_22_12 = {
    .key  = { 22,12 },
    .cell = { .ents={&INICIAL_COL_155}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_23_12 = {
    .key  = { 23,12 },
    .cell = { .ents={&INICIAL_COL_156}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_24_12 = {
    .key  = { 24,12 },
    .cell = { .ents={&INICIAL_COL_157}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_25_12 = {
    .key  = { 25,12 },
    .cell = { .ents={&INICIAL_COL_158}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_26_12 = {
    .key  = { 26,12 },
    .cell = { .ents={&INICIAL_COL_159}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_27_12 = {
    .key  = { 27,12 },
    .cell = { .ents={&INICIAL_COL_160}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_28_12 = {
    .key  = { 28,12 },
    .cell = { .ents={&INICIAL_COL_161}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_29_12 = {
    .key  = { 29,12 },
    .cell = { .ents={&INICIAL_COL_162}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_30_12 = {
    .key  = { 30,12 },
    .cell = { .ents={&INICIAL_COL_163}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_31_12 = {
    .key  = { 31,12 },
    .cell = { .ents={&INICIAL_COL_164}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_32_12 = {
    .key  = { 32,12 },
    .cell = { .ents={&INICIAL_COL_165}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_33_12 = {
    .key  = { 33,12 },
    .cell = { .ents={&INICIAL_COL_166}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_34_12 = {
    .key  = { 34,12 },
    .cell = { .ents={&INICIAL_COL_167}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_35_12 = {
    .key  = { 35,12 },
    .cell = { .ents={&INICIAL_COL_168}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_12 = {
    .key  = { 39,12 },
    .cell = { .ents={&INICIAL_COL_169}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_13 = {
    .key  = { 0,13 },
    .cell = { .ents={&INICIAL_COL_170}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_13 = {
    .key  = { 39,13 },
    .cell = { .ents={&INICIAL_COL_171}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_14 = {
    .key  = { 0,14 },
    .cell = { .ents={&INICIAL_COL_172}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_14 = {
    .key  = { 39,14 },
    .cell = { .ents={&INICIAL_COL_173}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_15 = {
    .key  = { 0,15 },
    .cell = { .ents={&INICIAL_COL_174}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_15 = {
    .key  = { 39,15 },
    .cell = { .ents={&INICIAL_COL_175}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_16 = {
    .key  = { 0,16 },
    .cell = { .ents={&INICIAL_COL_176}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_16 = {
    .key  = { 39,16 },
    .cell = { .ents={&INICIAL_COL_177}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_17 = {
    .key  = { 0,17 },
    .cell = { .ents={&INICIAL_COL_178}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_17 = {
    .key  = { 39,17 },
    .cell = { .ents={&INICIAL_COL_179}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_18 = {
    .key  = { 0,18 },
    .cell = { .ents={&INICIAL_COL_180}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_9_18 = {
    .key  = { 9,18 },
    .cell = { .ents={&INICIAL_COL_181}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_10_18 = {
    .key  = { 10,18 },
    .cell = { .ents={&INICIAL_COL_182}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_11_18 = {
    .key  = { 11,18 },
    .cell = { .ents={&INICIAL_COL_183}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_12_18 = {
    .key  = { 12,18 },
    .cell = { .ents={&INICIAL_COL_184}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_13_18 = {
    .key  = { 13,18 },
    .cell = { .ents={&INICIAL_COL_185}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_14_18 = {
    .key  = { 14,18 },
    .cell = { .ents={&INICIAL_COL_186}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_15_18 = {
    .key  = { 15,18 },
    .cell = { .ents={&INICIAL_COL_187}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_16_18 = {
    .key  = { 16,18 },
    .cell = { .ents={&INICIAL_COL_188}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_17_18 = {
    .key  = { 17,18 },
    .cell = { .ents={&INICIAL_COL_189}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_18 = {
    .key  = { 39,18 },
    .cell = { .ents={&INICIAL_COL_190}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_19 = {
    .key  = { 0,19 },
    .cell = { .ents={&INICIAL_COL_191}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_19 = {
    .key  = { 39,19 },
    .cell = { .ents={&INICIAL_COL_192}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_20 = {
    .key  = { 0,20 },
    .cell = { .ents={&INICIAL_COL_193}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_20 = {
    .key  = { 39,20 },
    .cell = { .ents={&INICIAL_COL_194}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_21 = {
    .key  = { 0,21 },
    .cell = { .ents={&INICIAL_COL_195}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_21 = {
    .key  = { 39,21 },
    .cell = { .ents={&INICIAL_COL_196}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_22 = {
    .key  = { 0,22 },
    .cell = { .ents={&INICIAL_COL_197}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_22 = {
    .key  = { 39,22 },
    .cell = { .ents={&INICIAL_COL_198}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_23 = {
    .key  = { 0,23 },
    .cell = { .ents={&INICIAL_COL_199}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_23 = {
    .key  = { 39,23 },
    .cell = { .ents={&INICIAL_COL_200}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_24 = {
    .key  = { 0,24 },
    .cell = { .ents={&INICIAL_COL_201}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_19_24 = {
    .key  = { 19,24 },
    .cell = { .ents={&INICIAL_COL_202}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_20_24 = {
    .key  = { 20,24 },
    .cell = { .ents={&INICIAL_COL_203}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_21_24 = {
    .key  = { 21,24 },
    .cell = { .ents={&INICIAL_COL_204}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_22_24 = {
    .key  = { 22,24 },
    .cell = { .ents={&INICIAL_COL_205}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_23_24 = {
    .key  = { 23,24 },
    .cell = { .ents={&INICIAL_COL_206}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_24_24 = {
    .key  = { 24,24 },
    .cell = { .ents={&INICIAL_COL_207}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_25_24 = {
    .key  = { 25,24 },
    .cell = { .ents={&INICIAL_COL_208}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_26_24 = {
    .key  = { 26,24 },
    .cell = { .ents={&INICIAL_COL_209}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_27_24 = {
    .key  = { 27,24 },
    .cell = { .ents={&INICIAL_COL_210}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_28_24 = {
    .key  = { 28,24 },
    .cell = { .ents={&INICIAL_COL_211}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_29_24 = {
    .key  = { 29,24 },
    .cell = { .ents={&INICIAL_COL_212}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_30_24 = {
    .key  = { 30,24 },
    .cell = { .ents={&INICIAL_COL_213}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_24 = {
    .key  = { 39,24 },
    .cell = { .ents={&INICIAL_COL_214}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_25 = {
    .key  = { 0,25 },
    .cell = { .ents={&INICIAL_COL_215}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_18_25 = {
    .key  = { 18,25 },
    .cell = { .ents={&INICIAL_COL_216}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_19_25 = {
    .key  = { 19,25 },
    .cell = { .ents={&INICIAL_COL_217}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_20_25 = {
    .key  = { 20,25 },
    .cell = { .ents={&INICIAL_COL_218}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_21_25 = {
    .key  = { 21,25 },
    .cell = { .ents={&INICIAL_COL_219}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_22_25 = {
    .key  = { 22,25 },
    .cell = { .ents={&INICIAL_COL_220}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_23_25 = {
    .key  = { 23,25 },
    .cell = { .ents={&INICIAL_COL_221}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_24_25 = {
    .key  = { 24,25 },
    .cell = { .ents={&INICIAL_COL_222}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_25_25 = {
    .key  = { 25,25 },
    .cell = { .ents={&INICIAL_COL_223}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_26_25 = {
    .key  = { 26,25 },
    .cell = { .ents={&INICIAL_COL_224}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_27_25 = {
    .key  = { 27,25 },
    .cell = { .ents={&INICIAL_COL_225}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_28_25 = {
    .key  = { 28,25 },
    .cell = { .ents={&INICIAL_COL_226}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_29_25 = {
    .key  = { 29,25 },
    .cell = { .ents={&INICIAL_COL_227}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_30_25 = {
    .key  = { 30,25 },
    .cell = { .ents={&INICIAL_COL_228}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_25 = {
    .key  = { 39,25 },
    .cell = { .ents={&INICIAL_COL_229}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_26 = {
    .key  = { 0,26 },
    .cell = { .ents={&INICIAL_COL_230}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_17_26 = {
    .key  = { 17,26 },
    .cell = { .ents={&INICIAL_COL_231}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_18_26 = {
    .key  = { 18,26 },
    .cell = { .ents={&INICIAL_COL_232}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_19_26 = {
    .key  = { 19,26 },
    .cell = { .ents={&INICIAL_COL_233}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_20_26 = {
    .key  = { 20,26 },
    .cell = { .ents={&INICIAL_COL_234}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_21_26 = {
    .key  = { 21,26 },
    .cell = { .ents={&INICIAL_COL_235}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_22_26 = {
    .key  = { 22,26 },
    .cell = { .ents={&INICIAL_COL_236}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_23_26 = {
    .key  = { 23,26 },
    .cell = { .ents={&INICIAL_COL_237}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_24_26 = {
    .key  = { 24,26 },
    .cell = { .ents={&INICIAL_COL_238}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_25_26 = {
    .key  = { 25,26 },
    .cell = { .ents={&INICIAL_COL_239}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_26 = {
    .key  = { 39,26 },
    .cell = { .ents={&INICIAL_COL_240}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_27 = {
    .key  = { 0,27 },
    .cell = { .ents={&INICIAL_COL_241}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_16_27 = {
    .key  = { 16,27 },
    .cell = { .ents={&INICIAL_COL_242}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_17_27 = {
    .key  = { 17,27 },
    .cell = { .ents={&INICIAL_COL_243}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_18_27 = {
    .key  = { 18,27 },
    .cell = { .ents={&INICIAL_COL_244}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_19_27 = {
    .key  = { 19,27 },
    .cell = { .ents={&INICIAL_COL_245}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_20_27 = {
    .key  = { 20,27 },
    .cell = { .ents={&INICIAL_COL_246}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_21_27 = {
    .key  = { 21,27 },
    .cell = { .ents={&INICIAL_COL_247}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_22_27 = {
    .key  = { 22,27 },
    .cell = { .ents={&INICIAL_COL_248}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_23_27 = {
    .key  = { 23,27 },
    .cell = { .ents={&INICIAL_COL_249}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_24_27 = {
    .key  = { 24,27 },
    .cell = { .ents={&INICIAL_COL_250}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_25_27 = {
    .key  = { 25,27 },
    .cell = { .ents={&INICIAL_COL_251}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_27 = {
    .key  = { 39,27 },
    .cell = { .ents={&INICIAL_COL_252}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_28 = {
    .key  = { 0,28 },
    .cell = { .ents={&INICIAL_COL_253}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_15_28 = {
    .key  = { 15,28 },
    .cell = { .ents={&INICIAL_COL_254}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_16_28 = {
    .key  = { 16,28 },
    .cell = { .ents={&INICIAL_COL_255}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_17_28 = {
    .key  = { 17,28 },
    .cell = { .ents={&INICIAL_COL_256}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_18_28 = {
    .key  = { 18,28 },
    .cell = { .ents={&INICIAL_COL_257}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_19_28 = {
    .key  = { 19,28 },
    .cell = { .ents={&INICIAL_COL_258}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_20_28 = {
    .key  = { 20,28 },
    .cell = { .ents={&INICIAL_COL_259}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_21_28 = {
    .key  = { 21,28 },
    .cell = { .ents={&INICIAL_COL_260}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_28 = {
    .key  = { 39,28 },
    .cell = { .ents={&INICIAL_COL_261}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_0_29 = {
    .key  = { 0,29 },
    .cell = { .ents={&INICIAL_COL_262}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_1_29 = {
    .key  = { 1,29 },
    .cell = { .ents={&INICIAL_COL_263}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_2_29 = {
    .key  = { 2,29 },
    .cell = { .ents={&INICIAL_COL_264}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_3_29 = {
    .key  = { 3,29 },
    .cell = { .ents={&INICIAL_COL_265}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_4_29 = {
    .key  = { 4,29 },
    .cell = { .ents={&INICIAL_COL_266}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_5_29 = {
    .key  = { 5,29 },
    .cell = { .ents={&INICIAL_COL_267}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_6_29 = {
    .key  = { 6,29 },
    .cell = { .ents={&INICIAL_COL_268}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_7_29 = {
    .key  = { 7,29 },
    .cell = { .ents={&INICIAL_COL_269}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_8_29 = {
    .key  = { 8,29 },
    .cell = { .ents={&INICIAL_COL_270}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_9_29 = {
    .key  = { 9,29 },
    .cell = { .ents={&INICIAL_COL_271}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_10_29 = {
    .key  = { 10,29 },
    .cell = { .ents={&INICIAL_COL_272}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_11_29 = {
    .key  = { 11,29 },
    .cell = { .ents={&INICIAL_COL_273}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_12_29 = {
    .key  = { 12,29 },
    .cell = { .ents={&INICIAL_COL_274}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_13_29 = {
    .key  = { 13,29 },
    .cell = { .ents={&INICIAL_COL_275}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_14_29 = {
    .key  = { 14,29 },
    .cell = { .ents={&INICIAL_COL_276}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_15_29 = {
    .key  = { 15,29 },
    .cell = { .ents={&INICIAL_COL_277}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_16_29 = {
    .key  = { 16,29 },
    .cell = { .ents={&INICIAL_COL_278}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_17_29 = {
    .key  = { 17,29 },
    .cell = { .ents={&INICIAL_COL_279}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_18_29 = {
    .key  = { 18,29 },
    .cell = { .ents={&INICIAL_COL_280}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_19_29 = {
    .key  = { 19,29 },
    .cell = { .ents={&INICIAL_COL_281}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_20_29 = {
    .key  = { 20,29 },
    .cell = { .ents={&INICIAL_COL_282}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_21_29 = {
    .key  = { 21,29 },
    .cell = { .ents={&INICIAL_COL_283}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_22_29 = {
    .key  = { 22,29 },
    .cell = { .ents={&INICIAL_COL_284}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_23_29 = {
    .key  = { 23,29 },
    .cell = { .ents={&INICIAL_COL_285}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_24_29 = {
    .key  = { 24,29 },
    .cell = { .ents={&INICIAL_COL_286}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_25_29 = {
    .key  = { 25,29 },
    .cell = { .ents={&INICIAL_COL_287}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_26_29 = {
    .key  = { 26,29 },
    .cell = { .ents={&INICIAL_COL_288}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_27_29 = {
    .key  = { 27,29 },
    .cell = { .ents={&INICIAL_COL_289}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_28_29 = {
    .key  = { 28,29 },
    .cell = { .ents={&INICIAL_COL_290}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_29_29 = {
    .key  = { 29,29 },
    .cell = { .ents={&INICIAL_COL_291}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_30_29 = {
    .key  = { 30,29 },
    .cell = { .ents={&INICIAL_COL_292}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_31_29 = {
    .key  = { 31,29 },
    .cell = { .ents={&INICIAL_COL_293}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_32_29 = {
    .key  = { 32,29 },
    .cell = { .ents={&INICIAL_COL_294}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_33_29 = {
    .key  = { 33,29 },
    .cell = { .ents={&INICIAL_COL_295}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_34_29 = {
    .key  = { 34,29 },
    .cell = { .ents={&INICIAL_COL_296}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_35_29 = {
    .key  = { 35,29 },
    .cell = { .ents={&INICIAL_COL_297}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_36_29 = {
    .key  = { 36,29 },
    .cell = { .ents={&INICIAL_COL_298}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_37_29 = {
    .key  = { 37,29 },
    .cell = { .ents={&INICIAL_COL_299}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_38_29 = {
    .key  = { 38,29 },
    .cell = { .ents={&INICIAL_COL_300}, .count=1 },
    .next = NULL,
};
static GridEntry INICIAL_GENTRY_39_29 = {
    .key  = { 39,29 },
    .cell = { .ents={&INICIAL_COL_301}, .count=1 },
    .next = NULL,
};

static EntityList ENTIDADES_INICIAL = {
    .ents = {  },
    .count = 0,
};

static Grid GRID_INICIAL = {
    .cells     = { NULL },
    .height    = 480,
    .width     = 640,
    .cell_size = 16,
};

static void map_init_INICIAL(void) {
    INICIAL_GENTRY_0_0.next = GRID_INICIAL.cells[0];
    GRID_INICIAL.cells[0] = &INICIAL_GENTRY_0_0;
    INICIAL_GENTRY_1_0.next = GRID_INICIAL.cells[1];
    GRID_INICIAL.cells[1] = &INICIAL_GENTRY_1_0;
    INICIAL_GENTRY_2_0.next = GRID_INICIAL.cells[2];
    GRID_INICIAL.cells[2] = &INICIAL_GENTRY_2_0;
    INICIAL_GENTRY_3_0.next = GRID_INICIAL.cells[3];
    GRID_INICIAL.cells[3] = &INICIAL_GENTRY_3_0;
    INICIAL_GENTRY_4_0.next = GRID_INICIAL.cells[4];
    GRID_INICIAL.cells[4] = &INICIAL_GENTRY_4_0;
    INICIAL_GENTRY_5_0.next = GRID_INICIAL.cells[5];
    GRID_INICIAL.cells[5] = &INICIAL_GENTRY_5_0;
    INICIAL_GENTRY_6_0.next = GRID_INICIAL.cells[6];
    GRID_INICIAL.cells[6] = &INICIAL_GENTRY_6_0;
    INICIAL_GENTRY_7_0.next = GRID_INICIAL.cells[7];
    GRID_INICIAL.cells[7] = &INICIAL_GENTRY_7_0;
    INICIAL_GENTRY_8_0.next = GRID_INICIAL.cells[8];
    GRID_INICIAL.cells[8] = &INICIAL_GENTRY_8_0;
    INICIAL_GENTRY_9_0.next = GRID_INICIAL.cells[9];
    GRID_INICIAL.cells[9] = &INICIAL_GENTRY_9_0;
    INICIAL_GENTRY_10_0.next = GRID_INICIAL.cells[10];
    GRID_INICIAL.cells[10] = &INICIAL_GENTRY_10_0;
    INICIAL_GENTRY_11_0.next = GRID_INICIAL.cells[11];
    GRID_INICIAL.cells[11] = &INICIAL_GENTRY_11_0;
    INICIAL_GENTRY_12_0.next = GRID_INICIAL.cells[12];
    GRID_INICIAL.cells[12] = &INICIAL_GENTRY_12_0;
    INICIAL_GENTRY_13_0.next = GRID_INICIAL.cells[13];
    GRID_INICIAL.cells[13] = &INICIAL_GENTRY_13_0;
    INICIAL_GENTRY_14_0.next = GRID_INICIAL.cells[14];
    GRID_INICIAL.cells[14] = &INICIAL_GENTRY_14_0;
    INICIAL_GENTRY_15_0.next = GRID_INICIAL.cells[15];
    GRID_INICIAL.cells[15] = &INICIAL_GENTRY_15_0;
    INICIAL_GENTRY_16_0.next = GRID_INICIAL.cells[16];
    GRID_INICIAL.cells[16] = &INICIAL_GENTRY_16_0;
    INICIAL_GENTRY_17_0.next = GRID_INICIAL.cells[17];
    GRID_INICIAL.cells[17] = &INICIAL_GENTRY_17_0;
    INICIAL_GENTRY_18_0.next = GRID_INICIAL.cells[18];
    GRID_INICIAL.cells[18] = &INICIAL_GENTRY_18_0;
    INICIAL_GENTRY_19_0.next = GRID_INICIAL.cells[19];
    GRID_INICIAL.cells[19] = &INICIAL_GENTRY_19_0;
    INICIAL_GENTRY_20_0.next = GRID_INICIAL.cells[20];
    GRID_INICIAL.cells[20] = &INICIAL_GENTRY_20_0;
    INICIAL_GENTRY_21_0.next = GRID_INICIAL.cells[21];
    GRID_INICIAL.cells[21] = &INICIAL_GENTRY_21_0;
    INICIAL_GENTRY_22_0.next = GRID_INICIAL.cells[22];
    GRID_INICIAL.cells[22] = &INICIAL_GENTRY_22_0;
    INICIAL_GENTRY_23_0.next = GRID_INICIAL.cells[23];
    GRID_INICIAL.cells[23] = &INICIAL_GENTRY_23_0;
    INICIAL_GENTRY_24_0.next = GRID_INICIAL.cells[24];
    GRID_INICIAL.cells[24] = &INICIAL_GENTRY_24_0;
    INICIAL_GENTRY_25_0.next = GRID_INICIAL.cells[25];
    GRID_INICIAL.cells[25] = &INICIAL_GENTRY_25_0;
    INICIAL_GENTRY_26_0.next = GRID_INICIAL.cells[26];
    GRID_INICIAL.cells[26] = &INICIAL_GENTRY_26_0;
    INICIAL_GENTRY_27_0.next = GRID_INICIAL.cells[27];
    GRID_INICIAL.cells[27] = &INICIAL_GENTRY_27_0;
    INICIAL_GENTRY_28_0.next = GRID_INICIAL.cells[28];
    GRID_INICIAL.cells[28] = &INICIAL_GENTRY_28_0;
    INICIAL_GENTRY_29_0.next = GRID_INICIAL.cells[29];
    GRID_INICIAL.cells[29] = &INICIAL_GENTRY_29_0;
    INICIAL_GENTRY_30_0.next = GRID_INICIAL.cells[30];
    GRID_INICIAL.cells[30] = &INICIAL_GENTRY_30_0;
    INICIAL_GENTRY_31_0.next = GRID_INICIAL.cells[31];
    GRID_INICIAL.cells[31] = &INICIAL_GENTRY_31_0;
    INICIAL_GENTRY_32_0.next = GRID_INICIAL.cells[32];
    GRID_INICIAL.cells[32] = &INICIAL_GENTRY_32_0;
    INICIAL_GENTRY_33_0.next = GRID_INICIAL.cells[33];
    GRID_INICIAL.cells[33] = &INICIAL_GENTRY_33_0;
    INICIAL_GENTRY_34_0.next = GRID_INICIAL.cells[34];
    GRID_INICIAL.cells[34] = &INICIAL_GENTRY_34_0;
    INICIAL_GENTRY_35_0.next = GRID_INICIAL.cells[35];
    GRID_INICIAL.cells[35] = &INICIAL_GENTRY_35_0;
    INICIAL_GENTRY_36_0.next = GRID_INICIAL.cells[36];
    GRID_INICIAL.cells[36] = &INICIAL_GENTRY_36_0;
    INICIAL_GENTRY_37_0.next = GRID_INICIAL.cells[37];
    GRID_INICIAL.cells[37] = &INICIAL_GENTRY_37_0;
    INICIAL_GENTRY_38_0.next = GRID_INICIAL.cells[38];
    GRID_INICIAL.cells[38] = &INICIAL_GENTRY_38_0;
    INICIAL_GENTRY_39_0.next = GRID_INICIAL.cells[39];
    GRID_INICIAL.cells[39] = &INICIAL_GENTRY_39_0;
    INICIAL_GENTRY_0_1.next = GRID_INICIAL.cells[31];
    GRID_INICIAL.cells[31] = &INICIAL_GENTRY_0_1;
    INICIAL_GENTRY_39_1.next = GRID_INICIAL.cells[56];
    GRID_INICIAL.cells[56] = &INICIAL_GENTRY_39_1;
    INICIAL_GENTRY_0_2.next = GRID_INICIAL.cells[62];
    GRID_INICIAL.cells[62] = &INICIAL_GENTRY_0_2;
    INICIAL_GENTRY_39_2.next = GRID_INICIAL.cells[25];
    GRID_INICIAL.cells[25] = &INICIAL_GENTRY_39_2;
    INICIAL_GENTRY_0_3.next = GRID_INICIAL.cells[93];
    GRID_INICIAL.cells[93] = &INICIAL_GENTRY_0_3;
    INICIAL_GENTRY_39_3.next = GRID_INICIAL.cells[122];
    GRID_INICIAL.cells[122] = &INICIAL_GENTRY_39_3;
    INICIAL_GENTRY_0_4.next = GRID_INICIAL.cells[124];
    GRID_INICIAL.cells[124] = &INICIAL_GENTRY_0_4;
    INICIAL_GENTRY_1_4.next = GRID_INICIAL.cells[125];
    GRID_INICIAL.cells[125] = &INICIAL_GENTRY_1_4;
    INICIAL_GENTRY_2_4.next = GRID_INICIAL.cells[126];
    GRID_INICIAL.cells[126] = &INICIAL_GENTRY_2_4;
    INICIAL_GENTRY_3_4.next = GRID_INICIAL.cells[127];
    GRID_INICIAL.cells[127] = &INICIAL_GENTRY_3_4;
    INICIAL_GENTRY_4_4.next = GRID_INICIAL.cells[120];
    GRID_INICIAL.cells[120] = &INICIAL_GENTRY_4_4;
    INICIAL_GENTRY_5_4.next = GRID_INICIAL.cells[121];
    GRID_INICIAL.cells[121] = &INICIAL_GENTRY_5_4;
    INICIAL_GENTRY_6_4.next = GRID_INICIAL.cells[122];
    GRID_INICIAL.cells[122] = &INICIAL_GENTRY_6_4;
    INICIAL_GENTRY_7_4.next = GRID_INICIAL.cells[123];
    GRID_INICIAL.cells[123] = &INICIAL_GENTRY_7_4;
    INICIAL_GENTRY_8_4.next = GRID_INICIAL.cells[116];
    GRID_INICIAL.cells[116] = &INICIAL_GENTRY_8_4;
    INICIAL_GENTRY_9_4.next = GRID_INICIAL.cells[117];
    GRID_INICIAL.cells[117] = &INICIAL_GENTRY_9_4;
    INICIAL_GENTRY_10_4.next = GRID_INICIAL.cells[118];
    GRID_INICIAL.cells[118] = &INICIAL_GENTRY_10_4;
    INICIAL_GENTRY_11_4.next = GRID_INICIAL.cells[119];
    GRID_INICIAL.cells[119] = &INICIAL_GENTRY_11_4;
    INICIAL_GENTRY_12_4.next = GRID_INICIAL.cells[112];
    GRID_INICIAL.cells[112] = &INICIAL_GENTRY_12_4;
    INICIAL_GENTRY_13_4.next = GRID_INICIAL.cells[113];
    GRID_INICIAL.cells[113] = &INICIAL_GENTRY_13_4;
    INICIAL_GENTRY_14_4.next = GRID_INICIAL.cells[114];
    GRID_INICIAL.cells[114] = &INICIAL_GENTRY_14_4;
    INICIAL_GENTRY_15_4.next = GRID_INICIAL.cells[115];
    GRID_INICIAL.cells[115] = &INICIAL_GENTRY_15_4;
    INICIAL_GENTRY_16_4.next = GRID_INICIAL.cells[108];
    GRID_INICIAL.cells[108] = &INICIAL_GENTRY_16_4;
    INICIAL_GENTRY_17_4.next = GRID_INICIAL.cells[109];
    GRID_INICIAL.cells[109] = &INICIAL_GENTRY_17_4;
    INICIAL_GENTRY_18_4.next = GRID_INICIAL.cells[110];
    GRID_INICIAL.cells[110] = &INICIAL_GENTRY_18_4;
    INICIAL_GENTRY_19_4.next = GRID_INICIAL.cells[111];
    GRID_INICIAL.cells[111] = &INICIAL_GENTRY_19_4;
    INICIAL_GENTRY_20_4.next = GRID_INICIAL.cells[104];
    GRID_INICIAL.cells[104] = &INICIAL_GENTRY_20_4;
    INICIAL_GENTRY_21_4.next = GRID_INICIAL.cells[105];
    GRID_INICIAL.cells[105] = &INICIAL_GENTRY_21_4;
    INICIAL_GENTRY_22_4.next = GRID_INICIAL.cells[106];
    GRID_INICIAL.cells[106] = &INICIAL_GENTRY_22_4;
    INICIAL_GENTRY_23_4.next = GRID_INICIAL.cells[107];
    GRID_INICIAL.cells[107] = &INICIAL_GENTRY_23_4;
    INICIAL_GENTRY_24_4.next = GRID_INICIAL.cells[100];
    GRID_INICIAL.cells[100] = &INICIAL_GENTRY_24_4;
    INICIAL_GENTRY_25_4.next = GRID_INICIAL.cells[101];
    GRID_INICIAL.cells[101] = &INICIAL_GENTRY_25_4;
    INICIAL_GENTRY_26_4.next = GRID_INICIAL.cells[102];
    GRID_INICIAL.cells[102] = &INICIAL_GENTRY_26_4;
    INICIAL_GENTRY_27_4.next = GRID_INICIAL.cells[103];
    GRID_INICIAL.cells[103] = &INICIAL_GENTRY_27_4;
    INICIAL_GENTRY_28_4.next = GRID_INICIAL.cells[96];
    GRID_INICIAL.cells[96] = &INICIAL_GENTRY_28_4;
    INICIAL_GENTRY_29_4.next = GRID_INICIAL.cells[97];
    GRID_INICIAL.cells[97] = &INICIAL_GENTRY_29_4;
    INICIAL_GENTRY_30_4.next = GRID_INICIAL.cells[98];
    GRID_INICIAL.cells[98] = &INICIAL_GENTRY_30_4;
    INICIAL_GENTRY_31_4.next = GRID_INICIAL.cells[99];
    GRID_INICIAL.cells[99] = &INICIAL_GENTRY_31_4;
    INICIAL_GENTRY_32_4.next = GRID_INICIAL.cells[92];
    GRID_INICIAL.cells[92] = &INICIAL_GENTRY_32_4;
    INICIAL_GENTRY_33_4.next = GRID_INICIAL.cells[93];
    GRID_INICIAL.cells[93] = &INICIAL_GENTRY_33_4;
    INICIAL_GENTRY_34_4.next = GRID_INICIAL.cells[94];
    GRID_INICIAL.cells[94] = &INICIAL_GENTRY_34_4;
    INICIAL_GENTRY_35_4.next = GRID_INICIAL.cells[95];
    GRID_INICIAL.cells[95] = &INICIAL_GENTRY_35_4;
    INICIAL_GENTRY_36_4.next = GRID_INICIAL.cells[88];
    GRID_INICIAL.cells[88] = &INICIAL_GENTRY_36_4;
    INICIAL_GENTRY_39_4.next = GRID_INICIAL.cells[91];
    GRID_INICIAL.cells[91] = &INICIAL_GENTRY_39_4;
    INICIAL_GENTRY_0_5.next = GRID_INICIAL.cells[155];
    GRID_INICIAL.cells[155] = &INICIAL_GENTRY_0_5;
    INICIAL_GENTRY_39_5.next = GRID_INICIAL.cells[188];
    GRID_INICIAL.cells[188] = &INICIAL_GENTRY_39_5;
    INICIAL_GENTRY_0_6.next = GRID_INICIAL.cells[186];
    GRID_INICIAL.cells[186] = &INICIAL_GENTRY_0_6;
    INICIAL_GENTRY_39_6.next = GRID_INICIAL.cells[157];
    GRID_INICIAL.cells[157] = &INICIAL_GENTRY_39_6;
    INICIAL_GENTRY_0_7.next = GRID_INICIAL.cells[217];
    GRID_INICIAL.cells[217] = &INICIAL_GENTRY_0_7;
    INICIAL_GENTRY_39_7.next = GRID_INICIAL.cells[254];
    GRID_INICIAL.cells[254] = &INICIAL_GENTRY_39_7;
    INICIAL_GENTRY_0_8.next = GRID_INICIAL.cells[248];
    GRID_INICIAL.cells[248] = &INICIAL_GENTRY_0_8;
    INICIAL_GENTRY_3_8.next = GRID_INICIAL.cells[251];
    GRID_INICIAL.cells[251] = &INICIAL_GENTRY_3_8;
    INICIAL_GENTRY_4_8.next = GRID_INICIAL.cells[252];
    GRID_INICIAL.cells[252] = &INICIAL_GENTRY_4_8;
    INICIAL_GENTRY_5_8.next = GRID_INICIAL.cells[253];
    GRID_INICIAL.cells[253] = &INICIAL_GENTRY_5_8;
    INICIAL_GENTRY_6_8.next = GRID_INICIAL.cells[254];
    GRID_INICIAL.cells[254] = &INICIAL_GENTRY_6_8;
    INICIAL_GENTRY_7_8.next = GRID_INICIAL.cells[255];
    GRID_INICIAL.cells[255] = &INICIAL_GENTRY_7_8;
    INICIAL_GENTRY_8_8.next = GRID_INICIAL.cells[240];
    GRID_INICIAL.cells[240] = &INICIAL_GENTRY_8_8;
    INICIAL_GENTRY_9_8.next = GRID_INICIAL.cells[241];
    GRID_INICIAL.cells[241] = &INICIAL_GENTRY_9_8;
    INICIAL_GENTRY_10_8.next = GRID_INICIAL.cells[242];
    GRID_INICIAL.cells[242] = &INICIAL_GENTRY_10_8;
    INICIAL_GENTRY_11_8.next = GRID_INICIAL.cells[243];
    GRID_INICIAL.cells[243] = &INICIAL_GENTRY_11_8;
    INICIAL_GENTRY_12_8.next = GRID_INICIAL.cells[244];
    GRID_INICIAL.cells[244] = &INICIAL_GENTRY_12_8;
    INICIAL_GENTRY_13_8.next = GRID_INICIAL.cells[245];
    GRID_INICIAL.cells[245] = &INICIAL_GENTRY_13_8;
    INICIAL_GENTRY_14_8.next = GRID_INICIAL.cells[246];
    GRID_INICIAL.cells[246] = &INICIAL_GENTRY_14_8;
    INICIAL_GENTRY_15_8.next = GRID_INICIAL.cells[247];
    GRID_INICIAL.cells[247] = &INICIAL_GENTRY_15_8;
    INICIAL_GENTRY_16_8.next = GRID_INICIAL.cells[232];
    GRID_INICIAL.cells[232] = &INICIAL_GENTRY_16_8;
    INICIAL_GENTRY_17_8.next = GRID_INICIAL.cells[233];
    GRID_INICIAL.cells[233] = &INICIAL_GENTRY_17_8;
    INICIAL_GENTRY_18_8.next = GRID_INICIAL.cells[234];
    GRID_INICIAL.cells[234] = &INICIAL_GENTRY_18_8;
    INICIAL_GENTRY_19_8.next = GRID_INICIAL.cells[235];
    GRID_INICIAL.cells[235] = &INICIAL_GENTRY_19_8;
    INICIAL_GENTRY_20_8.next = GRID_INICIAL.cells[236];
    GRID_INICIAL.cells[236] = &INICIAL_GENTRY_20_8;
    INICIAL_GENTRY_21_8.next = GRID_INICIAL.cells[237];
    GRID_INICIAL.cells[237] = &INICIAL_GENTRY_21_8;
    INICIAL_GENTRY_22_8.next = GRID_INICIAL.cells[238];
    GRID_INICIAL.cells[238] = &INICIAL_GENTRY_22_8;
    INICIAL_GENTRY_23_8.next = GRID_INICIAL.cells[239];
    GRID_INICIAL.cells[239] = &INICIAL_GENTRY_23_8;
    INICIAL_GENTRY_24_8.next = GRID_INICIAL.cells[224];
    GRID_INICIAL.cells[224] = &INICIAL_GENTRY_24_8;
    INICIAL_GENTRY_25_8.next = GRID_INICIAL.cells[225];
    GRID_INICIAL.cells[225] = &INICIAL_GENTRY_25_8;
    INICIAL_GENTRY_26_8.next = GRID_INICIAL.cells[226];
    GRID_INICIAL.cells[226] = &INICIAL_GENTRY_26_8;
    INICIAL_GENTRY_27_8.next = GRID_INICIAL.cells[227];
    GRID_INICIAL.cells[227] = &INICIAL_GENTRY_27_8;
    INICIAL_GENTRY_28_8.next = GRID_INICIAL.cells[228];
    GRID_INICIAL.cells[228] = &INICIAL_GENTRY_28_8;
    INICIAL_GENTRY_29_8.next = GRID_INICIAL.cells[229];
    GRID_INICIAL.cells[229] = &INICIAL_GENTRY_29_8;
    INICIAL_GENTRY_30_8.next = GRID_INICIAL.cells[230];
    GRID_INICIAL.cells[230] = &INICIAL_GENTRY_30_8;
    INICIAL_GENTRY_31_8.next = GRID_INICIAL.cells[231];
    GRID_INICIAL.cells[231] = &INICIAL_GENTRY_31_8;
    INICIAL_GENTRY_32_8.next = GRID_INICIAL.cells[216];
    GRID_INICIAL.cells[216] = &INICIAL_GENTRY_32_8;
    INICIAL_GENTRY_33_8.next = GRID_INICIAL.cells[217];
    GRID_INICIAL.cells[217] = &INICIAL_GENTRY_33_8;
    INICIAL_GENTRY_34_8.next = GRID_INICIAL.cells[218];
    GRID_INICIAL.cells[218] = &INICIAL_GENTRY_34_8;
    INICIAL_GENTRY_35_8.next = GRID_INICIAL.cells[219];
    GRID_INICIAL.cells[219] = &INICIAL_GENTRY_35_8;
    INICIAL_GENTRY_36_8.next = GRID_INICIAL.cells[220];
    GRID_INICIAL.cells[220] = &INICIAL_GENTRY_36_8;
    INICIAL_GENTRY_37_8.next = GRID_INICIAL.cells[221];
    GRID_INICIAL.cells[221] = &INICIAL_GENTRY_37_8;
    INICIAL_GENTRY_38_8.next = GRID_INICIAL.cells[222];
    GRID_INICIAL.cells[222] = &INICIAL_GENTRY_38_8;
    INICIAL_GENTRY_39_8.next = GRID_INICIAL.cells[223];
    GRID_INICIAL.cells[223] = &INICIAL_GENTRY_39_8;
    INICIAL_GENTRY_0_9.next = GRID_INICIAL.cells[279];
    GRID_INICIAL.cells[279] = &INICIAL_GENTRY_0_9;
    INICIAL_GENTRY_39_9.next = GRID_INICIAL.cells[304];
    GRID_INICIAL.cells[304] = &INICIAL_GENTRY_39_9;
    INICIAL_GENTRY_0_10.next = GRID_INICIAL.cells[310];
    GRID_INICIAL.cells[310] = &INICIAL_GENTRY_0_10;
    INICIAL_GENTRY_39_10.next = GRID_INICIAL.cells[273];
    GRID_INICIAL.cells[273] = &INICIAL_GENTRY_39_10;
    INICIAL_GENTRY_0_11.next = GRID_INICIAL.cells[341];
    GRID_INICIAL.cells[341] = &INICIAL_GENTRY_0_11;
    INICIAL_GENTRY_39_11.next = GRID_INICIAL.cells[370];
    GRID_INICIAL.cells[370] = &INICIAL_GENTRY_39_11;
    INICIAL_GENTRY_0_12.next = GRID_INICIAL.cells[372];
    GRID_INICIAL.cells[372] = &INICIAL_GENTRY_0_12;
    INICIAL_GENTRY_1_12.next = GRID_INICIAL.cells[373];
    GRID_INICIAL.cells[373] = &INICIAL_GENTRY_1_12;
    INICIAL_GENTRY_2_12.next = GRID_INICIAL.cells[374];
    GRID_INICIAL.cells[374] = &INICIAL_GENTRY_2_12;
    INICIAL_GENTRY_3_12.next = GRID_INICIAL.cells[375];
    GRID_INICIAL.cells[375] = &INICIAL_GENTRY_3_12;
    INICIAL_GENTRY_4_12.next = GRID_INICIAL.cells[368];
    GRID_INICIAL.cells[368] = &INICIAL_GENTRY_4_12;
    INICIAL_GENTRY_5_12.next = GRID_INICIAL.cells[369];
    GRID_INICIAL.cells[369] = &INICIAL_GENTRY_5_12;
    INICIAL_GENTRY_6_12.next = GRID_INICIAL.cells[370];
    GRID_INICIAL.cells[370] = &INICIAL_GENTRY_6_12;
    INICIAL_GENTRY_7_12.next = GRID_INICIAL.cells[371];
    GRID_INICIAL.cells[371] = &INICIAL_GENTRY_7_12;
    INICIAL_GENTRY_8_12.next = GRID_INICIAL.cells[380];
    GRID_INICIAL.cells[380] = &INICIAL_GENTRY_8_12;
    INICIAL_GENTRY_9_12.next = GRID_INICIAL.cells[381];
    GRID_INICIAL.cells[381] = &INICIAL_GENTRY_9_12;
    INICIAL_GENTRY_10_12.next = GRID_INICIAL.cells[382];
    GRID_INICIAL.cells[382] = &INICIAL_GENTRY_10_12;
    INICIAL_GENTRY_11_12.next = GRID_INICIAL.cells[383];
    GRID_INICIAL.cells[383] = &INICIAL_GENTRY_11_12;
    INICIAL_GENTRY_12_12.next = GRID_INICIAL.cells[376];
    GRID_INICIAL.cells[376] = &INICIAL_GENTRY_12_12;
    INICIAL_GENTRY_13_12.next = GRID_INICIAL.cells[377];
    GRID_INICIAL.cells[377] = &INICIAL_GENTRY_13_12;
    INICIAL_GENTRY_15_12.next = GRID_INICIAL.cells[379];
    GRID_INICIAL.cells[379] = &INICIAL_GENTRY_15_12;
    INICIAL_GENTRY_16_12.next = GRID_INICIAL.cells[356];
    GRID_INICIAL.cells[356] = &INICIAL_GENTRY_16_12;
    INICIAL_GENTRY_17_12.next = GRID_INICIAL.cells[357];
    GRID_INICIAL.cells[357] = &INICIAL_GENTRY_17_12;
    INICIAL_GENTRY_18_12.next = GRID_INICIAL.cells[358];
    GRID_INICIAL.cells[358] = &INICIAL_GENTRY_18_12;
    INICIAL_GENTRY_19_12.next = GRID_INICIAL.cells[359];
    GRID_INICIAL.cells[359] = &INICIAL_GENTRY_19_12;
    INICIAL_GENTRY_20_12.next = GRID_INICIAL.cells[352];
    GRID_INICIAL.cells[352] = &INICIAL_GENTRY_20_12;
    INICIAL_GENTRY_21_12.next = GRID_INICIAL.cells[353];
    GRID_INICIAL.cells[353] = &INICIAL_GENTRY_21_12;
    INICIAL_GENTRY_22_12.next = GRID_INICIAL.cells[354];
    GRID_INICIAL.cells[354] = &INICIAL_GENTRY_22_12;
    INICIAL_GENTRY_23_12.next = GRID_INICIAL.cells[355];
    GRID_INICIAL.cells[355] = &INICIAL_GENTRY_23_12;
    INICIAL_GENTRY_24_12.next = GRID_INICIAL.cells[364];
    GRID_INICIAL.cells[364] = &INICIAL_GENTRY_24_12;
    INICIAL_GENTRY_25_12.next = GRID_INICIAL.cells[365];
    GRID_INICIAL.cells[365] = &INICIAL_GENTRY_25_12;
    INICIAL_GENTRY_26_12.next = GRID_INICIAL.cells[366];
    GRID_INICIAL.cells[366] = &INICIAL_GENTRY_26_12;
    INICIAL_GENTRY_27_12.next = GRID_INICIAL.cells[367];
    GRID_INICIAL.cells[367] = &INICIAL_GENTRY_27_12;
    INICIAL_GENTRY_28_12.next = GRID_INICIAL.cells[360];
    GRID_INICIAL.cells[360] = &INICIAL_GENTRY_28_12;
    INICIAL_GENTRY_29_12.next = GRID_INICIAL.cells[361];
    GRID_INICIAL.cells[361] = &INICIAL_GENTRY_29_12;
    INICIAL_GENTRY_30_12.next = GRID_INICIAL.cells[362];
    GRID_INICIAL.cells[362] = &INICIAL_GENTRY_30_12;
    INICIAL_GENTRY_31_12.next = GRID_INICIAL.cells[363];
    GRID_INICIAL.cells[363] = &INICIAL_GENTRY_31_12;
    INICIAL_GENTRY_32_12.next = GRID_INICIAL.cells[340];
    GRID_INICIAL.cells[340] = &INICIAL_GENTRY_32_12;
    INICIAL_GENTRY_33_12.next = GRID_INICIAL.cells[341];
    GRID_INICIAL.cells[341] = &INICIAL_GENTRY_33_12;
    INICIAL_GENTRY_34_12.next = GRID_INICIAL.cells[342];
    GRID_INICIAL.cells[342] = &INICIAL_GENTRY_34_12;
    INICIAL_GENTRY_35_12.next = GRID_INICIAL.cells[343];
    GRID_INICIAL.cells[343] = &INICIAL_GENTRY_35_12;
    INICIAL_GENTRY_39_12.next = GRID_INICIAL.cells[339];
    GRID_INICIAL.cells[339] = &INICIAL_GENTRY_39_12;
    INICIAL_GENTRY_0_13.next = GRID_INICIAL.cells[403];
    GRID_INICIAL.cells[403] = &INICIAL_GENTRY_0_13;
    INICIAL_GENTRY_39_13.next = GRID_INICIAL.cells[436];
    GRID_INICIAL.cells[436] = &INICIAL_GENTRY_39_13;
    INICIAL_GENTRY_0_14.next = GRID_INICIAL.cells[434];
    GRID_INICIAL.cells[434] = &INICIAL_GENTRY_0_14;
    INICIAL_GENTRY_39_14.next = GRID_INICIAL.cells[405];
    GRID_INICIAL.cells[405] = &INICIAL_GENTRY_39_14;
    INICIAL_GENTRY_0_15.next = GRID_INICIAL.cells[465];
    GRID_INICIAL.cells[465] = &INICIAL_GENTRY_0_15;
    INICIAL_GENTRY_39_15.next = GRID_INICIAL.cells[502];
    GRID_INICIAL.cells[502] = &INICIAL_GENTRY_39_15;
    INICIAL_GENTRY_0_16.next = GRID_INICIAL.cells[496];
    GRID_INICIAL.cells[496] = &INICIAL_GENTRY_0_16;
    INICIAL_GENTRY_39_16.next = GRID_INICIAL.cells[471];
    GRID_INICIAL.cells[471] = &INICIAL_GENTRY_39_16;
    INICIAL_GENTRY_0_17.next = GRID_INICIAL.cells[527];
    GRID_INICIAL.cells[527] = &INICIAL_GENTRY_0_17;
    INICIAL_GENTRY_39_17.next = GRID_INICIAL.cells[552];
    GRID_INICIAL.cells[552] = &INICIAL_GENTRY_39_17;
    INICIAL_GENTRY_0_18.next = GRID_INICIAL.cells[558];
    GRID_INICIAL.cells[558] = &INICIAL_GENTRY_0_18;
    INICIAL_GENTRY_9_18.next = GRID_INICIAL.cells[551];
    GRID_INICIAL.cells[551] = &INICIAL_GENTRY_9_18;
    INICIAL_GENTRY_10_18.next = GRID_INICIAL.cells[548];
    GRID_INICIAL.cells[548] = &INICIAL_GENTRY_10_18;
    INICIAL_GENTRY_11_18.next = GRID_INICIAL.cells[549];
    GRID_INICIAL.cells[549] = &INICIAL_GENTRY_11_18;
    INICIAL_GENTRY_12_18.next = GRID_INICIAL.cells[546];
    GRID_INICIAL.cells[546] = &INICIAL_GENTRY_12_18;
    INICIAL_GENTRY_13_18.next = GRID_INICIAL.cells[547];
    GRID_INICIAL.cells[547] = &INICIAL_GENTRY_13_18;
    INICIAL_GENTRY_14_18.next = GRID_INICIAL.cells[544];
    GRID_INICIAL.cells[544] = &INICIAL_GENTRY_14_18;
    INICIAL_GENTRY_15_18.next = GRID_INICIAL.cells[545];
    GRID_INICIAL.cells[545] = &INICIAL_GENTRY_15_18;
    INICIAL_GENTRY_16_18.next = GRID_INICIAL.cells[574];
    GRID_INICIAL.cells[574] = &INICIAL_GENTRY_16_18;
    INICIAL_GENTRY_17_18.next = GRID_INICIAL.cells[575];
    GRID_INICIAL.cells[575] = &INICIAL_GENTRY_17_18;
    INICIAL_GENTRY_39_18.next = GRID_INICIAL.cells[521];
    GRID_INICIAL.cells[521] = &INICIAL_GENTRY_39_18;
    INICIAL_GENTRY_0_19.next = GRID_INICIAL.cells[589];
    GRID_INICIAL.cells[589] = &INICIAL_GENTRY_0_19;
    INICIAL_GENTRY_39_19.next = GRID_INICIAL.cells[618];
    GRID_INICIAL.cells[618] = &INICIAL_GENTRY_39_19;
    INICIAL_GENTRY_0_20.next = GRID_INICIAL.cells[620];
    GRID_INICIAL.cells[620] = &INICIAL_GENTRY_0_20;
    INICIAL_GENTRY_39_20.next = GRID_INICIAL.cells[587];
    GRID_INICIAL.cells[587] = &INICIAL_GENTRY_39_20;
    INICIAL_GENTRY_0_21.next = GRID_INICIAL.cells[651];
    GRID_INICIAL.cells[651] = &INICIAL_GENTRY_0_21;
    INICIAL_GENTRY_39_21.next = GRID_INICIAL.cells[684];
    GRID_INICIAL.cells[684] = &INICIAL_GENTRY_39_21;
    INICIAL_GENTRY_0_22.next = GRID_INICIAL.cells[682];
    GRID_INICIAL.cells[682] = &INICIAL_GENTRY_0_22;
    INICIAL_GENTRY_39_22.next = GRID_INICIAL.cells[653];
    GRID_INICIAL.cells[653] = &INICIAL_GENTRY_39_22;
    INICIAL_GENTRY_0_23.next = GRID_INICIAL.cells[713];
    GRID_INICIAL.cells[713] = &INICIAL_GENTRY_0_23;
    INICIAL_GENTRY_39_23.next = GRID_INICIAL.cells[750];
    GRID_INICIAL.cells[750] = &INICIAL_GENTRY_39_23;
    INICIAL_GENTRY_0_24.next = GRID_INICIAL.cells[744];
    GRID_INICIAL.cells[744] = &INICIAL_GENTRY_0_24;
    INICIAL_GENTRY_19_24.next = GRID_INICIAL.cells[763];
    GRID_INICIAL.cells[763] = &INICIAL_GENTRY_19_24;
    INICIAL_GENTRY_20_24.next = GRID_INICIAL.cells[764];
    GRID_INICIAL.cells[764] = &INICIAL_GENTRY_20_24;
    INICIAL_GENTRY_21_24.next = GRID_INICIAL.cells[765];
    GRID_INICIAL.cells[765] = &INICIAL_GENTRY_21_24;
    INICIAL_GENTRY_22_24.next = GRID_INICIAL.cells[766];
    GRID_INICIAL.cells[766] = &INICIAL_GENTRY_22_24;
    INICIAL_GENTRY_23_24.next = GRID_INICIAL.cells[767];
    GRID_INICIAL.cells[767] = &INICIAL_GENTRY_23_24;
    INICIAL_GENTRY_24_24.next = GRID_INICIAL.cells[752];
    GRID_INICIAL.cells[752] = &INICIAL_GENTRY_24_24;
    INICIAL_GENTRY_25_24.next = GRID_INICIAL.cells[753];
    GRID_INICIAL.cells[753] = &INICIAL_GENTRY_25_24;
    INICIAL_GENTRY_26_24.next = GRID_INICIAL.cells[754];
    GRID_INICIAL.cells[754] = &INICIAL_GENTRY_26_24;
    INICIAL_GENTRY_27_24.next = GRID_INICIAL.cells[755];
    GRID_INICIAL.cells[755] = &INICIAL_GENTRY_27_24;
    INICIAL_GENTRY_28_24.next = GRID_INICIAL.cells[756];
    GRID_INICIAL.cells[756] = &INICIAL_GENTRY_28_24;
    INICIAL_GENTRY_29_24.next = GRID_INICIAL.cells[757];
    GRID_INICIAL.cells[757] = &INICIAL_GENTRY_29_24;
    INICIAL_GENTRY_30_24.next = GRID_INICIAL.cells[758];
    GRID_INICIAL.cells[758] = &INICIAL_GENTRY_30_24;
    INICIAL_GENTRY_39_24.next = GRID_INICIAL.cells[719];
    GRID_INICIAL.cells[719] = &INICIAL_GENTRY_39_24;
    INICIAL_GENTRY_0_25.next = GRID_INICIAL.cells[775];
    GRID_INICIAL.cells[775] = &INICIAL_GENTRY_0_25;
    INICIAL_GENTRY_18_25.next = GRID_INICIAL.cells[789];
    GRID_INICIAL.cells[789] = &INICIAL_GENTRY_18_25;
    INICIAL_GENTRY_19_25.next = GRID_INICIAL.cells[788];
    GRID_INICIAL.cells[788] = &INICIAL_GENTRY_19_25;
    INICIAL_GENTRY_20_25.next = GRID_INICIAL.cells[787];
    GRID_INICIAL.cells[787] = &INICIAL_GENTRY_20_25;
    INICIAL_GENTRY_21_25.next = GRID_INICIAL.cells[786];
    GRID_INICIAL.cells[786] = &INICIAL_GENTRY_21_25;
    INICIAL_GENTRY_22_25.next = GRID_INICIAL.cells[785];
    GRID_INICIAL.cells[785] = &INICIAL_GENTRY_22_25;
    INICIAL_GENTRY_23_25.next = GRID_INICIAL.cells[784];
    GRID_INICIAL.cells[784] = &INICIAL_GENTRY_23_25;
    INICIAL_GENTRY_24_25.next = GRID_INICIAL.cells[799];
    GRID_INICIAL.cells[799] = &INICIAL_GENTRY_24_25;
    INICIAL_GENTRY_25_25.next = GRID_INICIAL.cells[798];
    GRID_INICIAL.cells[798] = &INICIAL_GENTRY_25_25;
    INICIAL_GENTRY_26_25.next = GRID_INICIAL.cells[797];
    GRID_INICIAL.cells[797] = &INICIAL_GENTRY_26_25;
    INICIAL_GENTRY_27_25.next = GRID_INICIAL.cells[796];
    GRID_INICIAL.cells[796] = &INICIAL_GENTRY_27_25;
    INICIAL_GENTRY_28_25.next = GRID_INICIAL.cells[795];
    GRID_INICIAL.cells[795] = &INICIAL_GENTRY_28_25;
    INICIAL_GENTRY_29_25.next = GRID_INICIAL.cells[794];
    GRID_INICIAL.cells[794] = &INICIAL_GENTRY_29_25;
    INICIAL_GENTRY_30_25.next = GRID_INICIAL.cells[793];
    GRID_INICIAL.cells[793] = &INICIAL_GENTRY_30_25;
    INICIAL_GENTRY_39_25.next = GRID_INICIAL.cells[800];
    GRID_INICIAL.cells[800] = &INICIAL_GENTRY_39_25;
    INICIAL_GENTRY_0_26.next = GRID_INICIAL.cells[806];
    GRID_INICIAL.cells[806] = &INICIAL_GENTRY_0_26;
    INICIAL_GENTRY_17_26.next = GRID_INICIAL.cells[823];
    GRID_INICIAL.cells[823] = &INICIAL_GENTRY_17_26;
    INICIAL_GENTRY_18_26.next = GRID_INICIAL.cells[820];
    GRID_INICIAL.cells[820] = &INICIAL_GENTRY_18_26;
    INICIAL_GENTRY_19_26.next = GRID_INICIAL.cells[821];
    GRID_INICIAL.cells[821] = &INICIAL_GENTRY_19_26;
    INICIAL_GENTRY_20_26.next = GRID_INICIAL.cells[818];
    GRID_INICIAL.cells[818] = &INICIAL_GENTRY_20_26;
    INICIAL_GENTRY_21_26.next = GRID_INICIAL.cells[819];
    GRID_INICIAL.cells[819] = &INICIAL_GENTRY_21_26;
    INICIAL_GENTRY_22_26.next = GRID_INICIAL.cells[816];
    GRID_INICIAL.cells[816] = &INICIAL_GENTRY_22_26;
    INICIAL_GENTRY_23_26.next = GRID_INICIAL.cells[817];
    GRID_INICIAL.cells[817] = &INICIAL_GENTRY_23_26;
    INICIAL_GENTRY_24_26.next = GRID_INICIAL.cells[830];
    GRID_INICIAL.cells[830] = &INICIAL_GENTRY_24_26;
    INICIAL_GENTRY_25_26.next = GRID_INICIAL.cells[831];
    GRID_INICIAL.cells[831] = &INICIAL_GENTRY_25_26;
    INICIAL_GENTRY_39_26.next = GRID_INICIAL.cells[769];
    GRID_INICIAL.cells[769] = &INICIAL_GENTRY_39_26;
    INICIAL_GENTRY_0_27.next = GRID_INICIAL.cells[837];
    GRID_INICIAL.cells[837] = &INICIAL_GENTRY_0_27;
    INICIAL_GENTRY_16_27.next = GRID_INICIAL.cells[853];
    GRID_INICIAL.cells[853] = &INICIAL_GENTRY_16_27;
    INICIAL_GENTRY_17_27.next = GRID_INICIAL.cells[852];
    GRID_INICIAL.cells[852] = &INICIAL_GENTRY_17_27;
    INICIAL_GENTRY_18_27.next = GRID_INICIAL.cells[855];
    GRID_INICIAL.cells[855] = &INICIAL_GENTRY_18_27;
    INICIAL_GENTRY_19_27.next = GRID_INICIAL.cells[854];
    GRID_INICIAL.cells[854] = &INICIAL_GENTRY_19_27;
    INICIAL_GENTRY_20_27.next = GRID_INICIAL.cells[849];
    GRID_INICIAL.cells[849] = &INICIAL_GENTRY_20_27;
    INICIAL_GENTRY_21_27.next = GRID_INICIAL.cells[848];
    GRID_INICIAL.cells[848] = &INICIAL_GENTRY_21_27;
    INICIAL_GENTRY_22_27.next = GRID_INICIAL.cells[851];
    GRID_INICIAL.cells[851] = &INICIAL_GENTRY_22_27;
    INICIAL_GENTRY_23_27.next = GRID_INICIAL.cells[850];
    GRID_INICIAL.cells[850] = &INICIAL_GENTRY_23_27;
    INICIAL_GENTRY_24_27.next = GRID_INICIAL.cells[861];
    GRID_INICIAL.cells[861] = &INICIAL_GENTRY_24_27;
    INICIAL_GENTRY_25_27.next = GRID_INICIAL.cells[860];
    GRID_INICIAL.cells[860] = &INICIAL_GENTRY_25_27;
    INICIAL_GENTRY_39_27.next = GRID_INICIAL.cells[866];
    GRID_INICIAL.cells[866] = &INICIAL_GENTRY_39_27;
    INICIAL_GENTRY_0_28.next = GRID_INICIAL.cells[868];
    GRID_INICIAL.cells[868] = &INICIAL_GENTRY_0_28;
    INICIAL_GENTRY_15_28.next = GRID_INICIAL.cells[875];
    GRID_INICIAL.cells[875] = &INICIAL_GENTRY_15_28;
    INICIAL_GENTRY_16_28.next = GRID_INICIAL.cells[884];
    GRID_INICIAL.cells[884] = &INICIAL_GENTRY_16_28;
    INICIAL_GENTRY_17_28.next = GRID_INICIAL.cells[885];
    GRID_INICIAL.cells[885] = &INICIAL_GENTRY_17_28;
    INICIAL_GENTRY_18_28.next = GRID_INICIAL.cells[886];
    GRID_INICIAL.cells[886] = &INICIAL_GENTRY_18_28;
    INICIAL_GENTRY_19_28.next = GRID_INICIAL.cells[887];
    GRID_INICIAL.cells[887] = &INICIAL_GENTRY_19_28;
    INICIAL_GENTRY_20_28.next = GRID_INICIAL.cells[880];
    GRID_INICIAL.cells[880] = &INICIAL_GENTRY_20_28;
    INICIAL_GENTRY_21_28.next = GRID_INICIAL.cells[881];
    GRID_INICIAL.cells[881] = &INICIAL_GENTRY_21_28;
    INICIAL_GENTRY_39_28.next = GRID_INICIAL.cells[835];
    GRID_INICIAL.cells[835] = &INICIAL_GENTRY_39_28;
    INICIAL_GENTRY_0_29.next = GRID_INICIAL.cells[899];
    GRID_INICIAL.cells[899] = &INICIAL_GENTRY_0_29;
    INICIAL_GENTRY_1_29.next = GRID_INICIAL.cells[898];
    GRID_INICIAL.cells[898] = &INICIAL_GENTRY_1_29;
    INICIAL_GENTRY_2_29.next = GRID_INICIAL.cells[897];
    GRID_INICIAL.cells[897] = &INICIAL_GENTRY_2_29;
    INICIAL_GENTRY_3_29.next = GRID_INICIAL.cells[896];
    GRID_INICIAL.cells[896] = &INICIAL_GENTRY_3_29;
    INICIAL_GENTRY_4_29.next = GRID_INICIAL.cells[903];
    GRID_INICIAL.cells[903] = &INICIAL_GENTRY_4_29;
    INICIAL_GENTRY_5_29.next = GRID_INICIAL.cells[902];
    GRID_INICIAL.cells[902] = &INICIAL_GENTRY_5_29;
    INICIAL_GENTRY_6_29.next = GRID_INICIAL.cells[901];
    GRID_INICIAL.cells[901] = &INICIAL_GENTRY_6_29;
    INICIAL_GENTRY_7_29.next = GRID_INICIAL.cells[900];
    GRID_INICIAL.cells[900] = &INICIAL_GENTRY_7_29;
    INICIAL_GENTRY_8_29.next = GRID_INICIAL.cells[907];
    GRID_INICIAL.cells[907] = &INICIAL_GENTRY_8_29;
    INICIAL_GENTRY_9_29.next = GRID_INICIAL.cells[906];
    GRID_INICIAL.cells[906] = &INICIAL_GENTRY_9_29;
    INICIAL_GENTRY_10_29.next = GRID_INICIAL.cells[905];
    GRID_INICIAL.cells[905] = &INICIAL_GENTRY_10_29;
    INICIAL_GENTRY_11_29.next = GRID_INICIAL.cells[904];
    GRID_INICIAL.cells[904] = &INICIAL_GENTRY_11_29;
    INICIAL_GENTRY_12_29.next = GRID_INICIAL.cells[911];
    GRID_INICIAL.cells[911] = &INICIAL_GENTRY_12_29;
    INICIAL_GENTRY_13_29.next = GRID_INICIAL.cells[910];
    GRID_INICIAL.cells[910] = &INICIAL_GENTRY_13_29;
    INICIAL_GENTRY_14_29.next = GRID_INICIAL.cells[909];
    GRID_INICIAL.cells[909] = &INICIAL_GENTRY_14_29;
    INICIAL_GENTRY_15_29.next = GRID_INICIAL.cells[908];
    GRID_INICIAL.cells[908] = &INICIAL_GENTRY_15_29;
    INICIAL_GENTRY_16_29.next = GRID_INICIAL.cells[915];
    GRID_INICIAL.cells[915] = &INICIAL_GENTRY_16_29;
    INICIAL_GENTRY_17_29.next = GRID_INICIAL.cells[914];
    GRID_INICIAL.cells[914] = &INICIAL_GENTRY_17_29;
    INICIAL_GENTRY_18_29.next = GRID_INICIAL.cells[913];
    GRID_INICIAL.cells[913] = &INICIAL_GENTRY_18_29;
    INICIAL_GENTRY_19_29.next = GRID_INICIAL.cells[912];
    GRID_INICIAL.cells[912] = &INICIAL_GENTRY_19_29;
    INICIAL_GENTRY_20_29.next = GRID_INICIAL.cells[919];
    GRID_INICIAL.cells[919] = &INICIAL_GENTRY_20_29;
    INICIAL_GENTRY_21_29.next = GRID_INICIAL.cells[918];
    GRID_INICIAL.cells[918] = &INICIAL_GENTRY_21_29;
    INICIAL_GENTRY_22_29.next = GRID_INICIAL.cells[917];
    GRID_INICIAL.cells[917] = &INICIAL_GENTRY_22_29;
    INICIAL_GENTRY_23_29.next = GRID_INICIAL.cells[916];
    GRID_INICIAL.cells[916] = &INICIAL_GENTRY_23_29;
    INICIAL_GENTRY_24_29.next = GRID_INICIAL.cells[923];
    GRID_INICIAL.cells[923] = &INICIAL_GENTRY_24_29;
    INICIAL_GENTRY_25_29.next = GRID_INICIAL.cells[922];
    GRID_INICIAL.cells[922] = &INICIAL_GENTRY_25_29;
    INICIAL_GENTRY_26_29.next = GRID_INICIAL.cells[921];
    GRID_INICIAL.cells[921] = &INICIAL_GENTRY_26_29;
    INICIAL_GENTRY_27_29.next = GRID_INICIAL.cells[920];
    GRID_INICIAL.cells[920] = &INICIAL_GENTRY_27_29;
    INICIAL_GENTRY_28_29.next = GRID_INICIAL.cells[927];
    GRID_INICIAL.cells[927] = &INICIAL_GENTRY_28_29;
    INICIAL_GENTRY_29_29.next = GRID_INICIAL.cells[926];
    GRID_INICIAL.cells[926] = &INICIAL_GENTRY_29_29;
    INICIAL_GENTRY_30_29.next = GRID_INICIAL.cells[925];
    GRID_INICIAL.cells[925] = &INICIAL_GENTRY_30_29;
    INICIAL_GENTRY_31_29.next = GRID_INICIAL.cells[924];
    GRID_INICIAL.cells[924] = &INICIAL_GENTRY_31_29;
    INICIAL_GENTRY_32_29.next = GRID_INICIAL.cells[931];
    GRID_INICIAL.cells[931] = &INICIAL_GENTRY_32_29;
    INICIAL_GENTRY_33_29.next = GRID_INICIAL.cells[930];
    GRID_INICIAL.cells[930] = &INICIAL_GENTRY_33_29;
    INICIAL_GENTRY_34_29.next = GRID_INICIAL.cells[929];
    GRID_INICIAL.cells[929] = &INICIAL_GENTRY_34_29;
    INICIAL_GENTRY_35_29.next = GRID_INICIAL.cells[928];
    GRID_INICIAL.cells[928] = &INICIAL_GENTRY_35_29;
    INICIAL_GENTRY_36_29.next = GRID_INICIAL.cells[935];
    GRID_INICIAL.cells[935] = &INICIAL_GENTRY_36_29;
    INICIAL_GENTRY_37_29.next = GRID_INICIAL.cells[934];
    GRID_INICIAL.cells[934] = &INICIAL_GENTRY_37_29;
    INICIAL_GENTRY_38_29.next = GRID_INICIAL.cells[933];
    GRID_INICIAL.cells[933] = &INICIAL_GENTRY_38_29;
    INICIAL_GENTRY_39_29.next = GRID_INICIAL.cells[932];
    GRID_INICIAL.cells[932] = &INICIAL_GENTRY_39_29;
}

typedef enum {
    AREA_INICIAL,
    AREA_COUNT,
} AreaId;

static Grid *_grids[] = {
    [AREA_INICIAL] = &GRID_INICIAL,
};

static EntityList *_entidades[] = {
    [AREA_INICIAL] = &ENTIDADES_INICIAL,
};

static Grid* get_grid(AreaId id){
    if(id>=AREA_COUNT) return NULL;
    return _grids[id];
}

static EntityList* get_entidades(AreaId id){
    if(id>=AREA_COUNT) return NULL;
    return _entidades[id];
}

static void maps_init(void){
    map_init_INICIAL();
}
