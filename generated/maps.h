/* AUTO-GERADO por generate_mapas.py — não edite */
#pragma once
#include <stdint.h>
#include "../include/basics.h"
#include "../include/entity.h"
#include "../include/grid.h"
#include "../include/area_id.h"
#include "tiles.h"
#include "itens.h"
#include "entidades.h"

static void map_add_tile(Grid *grid, Entity *ent) {
    if (!ent) return;
    grid_add_entity(grid, ent);
}
static void map_add_entity( Grid *grid, EntityList *list, Entity *ent) {
    if (!ent) return;
    grid_add_entity(grid, ent);
    list->ents[list->count++] = ent;
}
/* ──────────────────────────────────────────────────────────── */
/* Área: inicial */
/* ──────────────────────────────────────────────────────────── */

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
map_add_tile(&GRID_INICIAL, tijolos_create(0,0));
map_add_tile(&GRID_INICIAL, tijolos_create(16,0));
map_add_tile(&GRID_INICIAL, tijolos_create(32,0));
map_add_tile(&GRID_INICIAL, tijolos_create(48,0));
map_add_tile(&GRID_INICIAL, tijolos_create(64,0));
map_add_tile(&GRID_INICIAL, tijolos_create(80,0));
map_add_tile(&GRID_INICIAL, tijolos_create(96,0));
map_add_tile(&GRID_INICIAL, tijolos_create(112,0));
map_add_tile(&GRID_INICIAL, tijolos_create(128,0));
map_add_tile(&GRID_INICIAL, tijolos_create(144,0));
map_add_tile(&GRID_INICIAL, tijolos_create(160,0));
map_add_tile(&GRID_INICIAL, tijolos_create(176,0));
map_add_tile(&GRID_INICIAL, tijolos_create(192,0));
map_add_tile(&GRID_INICIAL, tijolos_create(208,0));
map_add_tile(&GRID_INICIAL, tijolos_create(224,0));
map_add_tile(&GRID_INICIAL, tijolos_create(240,0));
map_add_tile(&GRID_INICIAL, tijolos_create(256,0));
map_add_tile(&GRID_INICIAL, tijolos_create(272,0));
map_add_tile(&GRID_INICIAL, tijolos_create(288,0));
map_add_tile(&GRID_INICIAL, tijolos_create(304,0));
map_add_tile(&GRID_INICIAL, tijolos_create(320,0));
map_add_tile(&GRID_INICIAL, tijolos_create(336,0));
map_add_tile(&GRID_INICIAL, tijolos_create(352,0));
map_add_tile(&GRID_INICIAL, tijolos_create(368,0));
map_add_tile(&GRID_INICIAL, tijolos_create(384,0));
map_add_tile(&GRID_INICIAL, tijolos_create(400,0));
map_add_tile(&GRID_INICIAL, tijolos_create(416,0));
map_add_tile(&GRID_INICIAL, tijolos_create(432,0));
map_add_tile(&GRID_INICIAL, tijolos_create(448,0));
map_add_tile(&GRID_INICIAL, tijolos_create(464,0));
map_add_tile(&GRID_INICIAL, tijolos_create(480,0));
map_add_tile(&GRID_INICIAL, tijolos_create(496,0));
map_add_tile(&GRID_INICIAL, tijolos_create(512,0));
map_add_tile(&GRID_INICIAL, tijolos_create(528,0));
map_add_tile(&GRID_INICIAL, tijolos_create(544,0));
map_add_tile(&GRID_INICIAL, tijolos_create(560,0));
map_add_tile(&GRID_INICIAL, tijolos_create(576,0));
map_add_tile(&GRID_INICIAL, tijolos_create(592,0));
map_add_tile(&GRID_INICIAL, tijolos_create(608,0));
map_add_tile(&GRID_INICIAL, tijolos_create(624,0));
map_add_tile(&GRID_INICIAL, tijolos_create(0,16));
map_add_tile(&GRID_INICIAL, tijolos_create(624,16));
map_add_tile(&GRID_INICIAL, tijolos_create(0,32));
map_add_tile(&GRID_INICIAL, tijolos_create(624,32));
map_add_tile(&GRID_INICIAL, tijolos_create(0,48));
map_add_tile(&GRID_INICIAL, tijolos_create(624,48));
map_add_tile(&GRID_INICIAL, tijolos_create(0,64));
map_add_tile(&GRID_INICIAL, tijolos_create(16,64));
map_add_tile(&GRID_INICIAL, tijolos_create(32,64));
map_add_tile(&GRID_INICIAL, tijolos_create(48,64));
map_add_tile(&GRID_INICIAL, tijolos_create(64,64));
map_add_tile(&GRID_INICIAL, tijolos_create(80,64));
map_add_tile(&GRID_INICIAL, tijolos_create(96,64));
map_add_tile(&GRID_INICIAL, tijolos_create(112,64));
map_add_tile(&GRID_INICIAL, tijolos_create(128,64));
map_add_tile(&GRID_INICIAL, tijolos_create(144,64));
map_add_tile(&GRID_INICIAL, tijolos_create(160,64));
map_add_tile(&GRID_INICIAL, tijolos_create(176,64));
map_add_tile(&GRID_INICIAL, tijolos_create(192,64));
map_add_tile(&GRID_INICIAL, tijolos_create(208,64));
map_add_tile(&GRID_INICIAL, tijolos_create(224,64));
map_add_tile(&GRID_INICIAL, tijolos_create(240,64));
map_add_tile(&GRID_INICIAL, tijolos_create(256,64));
map_add_tile(&GRID_INICIAL, tijolos_create(272,64));
map_add_tile(&GRID_INICIAL, tijolos_create(288,64));
map_add_tile(&GRID_INICIAL, tijolos_create(304,64));
map_add_tile(&GRID_INICIAL, tijolos_create(320,64));
map_add_tile(&GRID_INICIAL, tijolos_create(336,64));
map_add_tile(&GRID_INICIAL, tijolos_create(352,64));
map_add_tile(&GRID_INICIAL, tijolos_create(368,64));
map_add_tile(&GRID_INICIAL, tijolos_create(384,64));
map_add_tile(&GRID_INICIAL, tijolos_create(400,64));
map_add_tile(&GRID_INICIAL, tijolos_create(416,64));
map_add_tile(&GRID_INICIAL, tijolos_create(432,64));
map_add_tile(&GRID_INICIAL, tijolos_create(448,64));
map_add_tile(&GRID_INICIAL, tijolos_create(464,64));
map_add_tile(&GRID_INICIAL, tijolos_create(480,64));
map_add_tile(&GRID_INICIAL, tijolos_create(496,64));
map_add_tile(&GRID_INICIAL, tijolos_create(512,64));
map_add_tile(&GRID_INICIAL, tijolos_create(528,64));
map_add_tile(&GRID_INICIAL, tijolos_create(544,64));
map_add_tile(&GRID_INICIAL, tijolos_create(560,64));
map_add_tile(&GRID_INICIAL, tijolos_create(576,64));
map_add_tile(&GRID_INICIAL, tijolos_create(624,64));
map_add_tile(&GRID_INICIAL, tijolos_create(0,80));
map_add_tile(&GRID_INICIAL, tijolos_create(624,80));
map_add_tile(&GRID_INICIAL, tijolos_create(0,96));
map_add_tile(&GRID_INICIAL, tijolos_create(624,96));
map_add_tile(&GRID_INICIAL, tijolos_create(0,112));
map_add_tile(&GRID_INICIAL, tijolos_create(624,112));
map_add_tile(&GRID_INICIAL, tijolos_create(0,128));
map_add_tile(&GRID_INICIAL, tijolos_create(48,128));
map_add_tile(&GRID_INICIAL, tijolos_create(64,128));
map_add_tile(&GRID_INICIAL, tijolos_create(80,128));
map_add_tile(&GRID_INICIAL, tijolos_create(96,128));
map_add_tile(&GRID_INICIAL, tijolos_create(112,128));
map_add_tile(&GRID_INICIAL, tijolos_create(128,128));
map_add_tile(&GRID_INICIAL, tijolos_create(144,128));
map_add_tile(&GRID_INICIAL, tijolos_create(160,128));
map_add_tile(&GRID_INICIAL, tijolos_create(176,128));
map_add_tile(&GRID_INICIAL, tijolos_create(192,128));
map_add_tile(&GRID_INICIAL, tijolos_create(208,128));
map_add_tile(&GRID_INICIAL, tijolos_create(224,128));
map_add_tile(&GRID_INICIAL, tijolos_create(240,128));
map_add_tile(&GRID_INICIAL, tijolos_create(256,128));
map_add_tile(&GRID_INICIAL, tijolos_create(272,128));
map_add_tile(&GRID_INICIAL, tijolos_create(288,128));
map_add_tile(&GRID_INICIAL, tijolos_create(304,128));
map_add_tile(&GRID_INICIAL, tijolos_create(320,128));
map_add_tile(&GRID_INICIAL, tijolos_create(336,128));
map_add_tile(&GRID_INICIAL, tijolos_create(352,128));
map_add_tile(&GRID_INICIAL, tijolos_create(368,128));
map_add_tile(&GRID_INICIAL, tijolos_create(384,128));
map_add_tile(&GRID_INICIAL, tijolos_create(400,128));
map_add_tile(&GRID_INICIAL, tijolos_create(416,128));
map_add_tile(&GRID_INICIAL, tijolos_create(432,128));
map_add_tile(&GRID_INICIAL, tijolos_create(448,128));
map_add_tile(&GRID_INICIAL, tijolos_create(464,128));
map_add_tile(&GRID_INICIAL, tijolos_create(480,128));
map_add_tile(&GRID_INICIAL, tijolos_create(496,128));
map_add_tile(&GRID_INICIAL, tijolos_create(512,128));
map_add_tile(&GRID_INICIAL, tijolos_create(528,128));
map_add_tile(&GRID_INICIAL, tijolos_create(544,128));
map_add_tile(&GRID_INICIAL, tijolos_create(560,128));
map_add_tile(&GRID_INICIAL, tijolos_create(576,128));
map_add_tile(&GRID_INICIAL, tijolos_create(592,128));
map_add_tile(&GRID_INICIAL, tijolos_create(608,128));
map_add_tile(&GRID_INICIAL, tijolos_create(624,128));
map_add_tile(&GRID_INICIAL, tijolos_create(0,144));
map_add_tile(&GRID_INICIAL, tijolos_create(624,144));
map_add_tile(&GRID_INICIAL, tijolos_create(0,160));
map_add_tile(&GRID_INICIAL, tijolos_create(624,160));
map_add_tile(&GRID_INICIAL, tijolos_create(0,176));
map_add_tile(&GRID_INICIAL, tijolos_create(624,176));
map_add_tile(&GRID_INICIAL, tijolos_create(0,192));
map_add_tile(&GRID_INICIAL, tijolos_create(16,192));
map_add_tile(&GRID_INICIAL, tijolos_create(32,192));
map_add_tile(&GRID_INICIAL, tijolos_create(48,192));
map_add_tile(&GRID_INICIAL, tijolos_create(64,192));
map_add_tile(&GRID_INICIAL, tijolos_create(80,192));
map_add_tile(&GRID_INICIAL, tijolos_create(96,192));
map_add_tile(&GRID_INICIAL, tijolos_create(112,192));
map_add_tile(&GRID_INICIAL, tijolos_create(128,192));
map_add_tile(&GRID_INICIAL, tijolos_create(144,192));
map_add_tile(&GRID_INICIAL, tijolos_create(160,192));
map_add_tile(&GRID_INICIAL, tijolos_create(176,192));
map_add_tile(&GRID_INICIAL, tijolos_create(192,192));
map_add_tile(&GRID_INICIAL, tijolos_create(208,192));
map_add_tile(&GRID_INICIAL, tijolos_create(240,192));
map_add_tile(&GRID_INICIAL, tijolos_create(256,192));
map_add_tile(&GRID_INICIAL, tijolos_create(272,192));
map_add_tile(&GRID_INICIAL, tijolos_create(288,192));
map_add_tile(&GRID_INICIAL, tijolos_create(304,192));
map_add_tile(&GRID_INICIAL, tijolos_create(320,192));
map_add_tile(&GRID_INICIAL, tijolos_create(336,192));
map_add_tile(&GRID_INICIAL, tijolos_create(352,192));
map_add_tile(&GRID_INICIAL, tijolos_create(368,192));
map_add_tile(&GRID_INICIAL, tijolos_create(384,192));
map_add_tile(&GRID_INICIAL, tijolos_create(400,192));
map_add_tile(&GRID_INICIAL, tijolos_create(416,192));
map_add_tile(&GRID_INICIAL, tijolos_create(432,192));
map_add_tile(&GRID_INICIAL, tijolos_create(448,192));
map_add_tile(&GRID_INICIAL, tijolos_create(464,192));
map_add_tile(&GRID_INICIAL, tijolos_create(480,192));
map_add_tile(&GRID_INICIAL, tijolos_create(496,192));
map_add_tile(&GRID_INICIAL, tijolos_create(512,192));
map_add_tile(&GRID_INICIAL, tijolos_create(528,192));
map_add_tile(&GRID_INICIAL, tijolos_create(544,192));
map_add_tile(&GRID_INICIAL, tijolos_create(560,192));
map_add_tile(&GRID_INICIAL, tijolos_create(624,192));
map_add_tile(&GRID_INICIAL, tijolos_create(0,208));
map_add_tile(&GRID_INICIAL, tijolos_create(624,208));
map_add_tile(&GRID_INICIAL, tijolos_create(0,224));
map_add_tile(&GRID_INICIAL, tijolos_create(624,224));
map_add_tile(&GRID_INICIAL, tijolos_create(0,240));
map_add_tile(&GRID_INICIAL, tijolos_create(624,240));
map_add_tile(&GRID_INICIAL, tijolos_create(0,256));
map_add_tile(&GRID_INICIAL, tijolos_create(624,256));
map_add_tile(&GRID_INICIAL, tijolos_create(0,272));
map_add_tile(&GRID_INICIAL, tijolos_create(624,272));
map_add_tile(&GRID_INICIAL, tijolos_create(0,288));
map_add_tile(&GRID_INICIAL, tijolos_create(144,288));
map_add_tile(&GRID_INICIAL, tijolos_create(160,288));
map_add_tile(&GRID_INICIAL, tijolos_create(176,288));
map_add_tile(&GRID_INICIAL, tijolos_create(192,288));
map_add_tile(&GRID_INICIAL, tijolos_create(208,288));
map_add_tile(&GRID_INICIAL, tijolos_create(224,288));
map_add_tile(&GRID_INICIAL, tijolos_create(240,288));
map_add_tile(&GRID_INICIAL, tijolos_create(256,288));
map_add_tile(&GRID_INICIAL, tijolos_create(272,288));
map_add_tile(&GRID_INICIAL, tijolos_create(624,288));
map_add_tile(&GRID_INICIAL, tijolos_create(0,304));
map_add_tile(&GRID_INICIAL, tijolos_create(624,304));
map_add_tile(&GRID_INICIAL, tijolos_create(0,320));
map_add_tile(&GRID_INICIAL, tijolos_create(624,320));
map_add_tile(&GRID_INICIAL, tijolos_create(0,336));
map_add_tile(&GRID_INICIAL, tijolos_create(624,336));
map_add_tile(&GRID_INICIAL, tijolos_create(0,352));
map_add_tile(&GRID_INICIAL, tijolos_create(624,352));
map_add_tile(&GRID_INICIAL, tijolos_create(0,368));
map_add_tile(&GRID_INICIAL, tijolos_create(624,368));
map_add_tile(&GRID_INICIAL, tijolos_create(0,384));
map_add_tile(&GRID_INICIAL, tijolos_create(304,384));
map_add_tile(&GRID_INICIAL, tijolos_create(320,384));
map_add_tile(&GRID_INICIAL, tijolos_create(336,384));
map_add_tile(&GRID_INICIAL, tijolos_create(352,384));
map_add_tile(&GRID_INICIAL, tijolos_create(368,384));
map_add_tile(&GRID_INICIAL, tijolos_create(384,384));
map_add_tile(&GRID_INICIAL, tijolos_create(400,384));
map_add_tile(&GRID_INICIAL, tijolos_create(416,384));
map_add_tile(&GRID_INICIAL, tijolos_create(432,384));
map_add_tile(&GRID_INICIAL, tijolos_create(448,384));
map_add_tile(&GRID_INICIAL, tijolos_create(464,384));
map_add_tile(&GRID_INICIAL, tijolos_create(480,384));
map_add_tile(&GRID_INICIAL, tijolos_create(624,384));
map_add_tile(&GRID_INICIAL, tijolos_create(0,400));
map_add_tile(&GRID_INICIAL, tijolos_create(288,400));
map_add_tile(&GRID_INICIAL, tijolos_create(304,400));
map_add_tile(&GRID_INICIAL, tijolos_create(320,400));
map_add_tile(&GRID_INICIAL, tijolos_create(336,400));
map_add_tile(&GRID_INICIAL, tijolos_create(352,400));
map_add_tile(&GRID_INICIAL, tijolos_create(368,400));
map_add_tile(&GRID_INICIAL, tijolos_create(384,400));
map_add_tile(&GRID_INICIAL, tijolos_create(400,400));
map_add_tile(&GRID_INICIAL, tijolos_create(416,400));
map_add_tile(&GRID_INICIAL, tijolos_create(432,400));
map_add_tile(&GRID_INICIAL, tijolos_create(448,400));
map_add_tile(&GRID_INICIAL, tijolos_create(464,400));
map_add_tile(&GRID_INICIAL, tijolos_create(480,400));
map_add_tile(&GRID_INICIAL, tijolos_create(624,400));
map_add_tile(&GRID_INICIAL, tijolos_create(0,416));
map_add_tile(&GRID_INICIAL, tijolos_create(272,416));
map_add_tile(&GRID_INICIAL, tijolos_create(288,416));
map_add_tile(&GRID_INICIAL, tijolos_create(304,416));
map_add_tile(&GRID_INICIAL, tijolos_create(320,416));
map_add_tile(&GRID_INICIAL, tijolos_create(336,416));
map_add_tile(&GRID_INICIAL, tijolos_create(352,416));
map_add_tile(&GRID_INICIAL, tijolos_create(368,416));
map_add_tile(&GRID_INICIAL, tijolos_create(384,416));
map_add_tile(&GRID_INICIAL, tijolos_create(400,416));
map_add_tile(&GRID_INICIAL, tijolos_create(624,416));
map_add_tile(&GRID_INICIAL, tijolos_create(0,432));
map_add_tile(&GRID_INICIAL, tijolos_create(256,432));
map_add_tile(&GRID_INICIAL, tijolos_create(272,432));
map_add_tile(&GRID_INICIAL, tijolos_create(288,432));
map_add_tile(&GRID_INICIAL, tijolos_create(304,432));
map_add_tile(&GRID_INICIAL, tijolos_create(320,432));
map_add_tile(&GRID_INICIAL, tijolos_create(336,432));
map_add_tile(&GRID_INICIAL, tijolos_create(352,432));
map_add_tile(&GRID_INICIAL, tijolos_create(368,432));
map_add_tile(&GRID_INICIAL, tijolos_create(384,432));
map_add_tile(&GRID_INICIAL, tijolos_create(400,432));
map_add_tile(&GRID_INICIAL, tijolos_create(624,432));
map_add_tile(&GRID_INICIAL, tijolos_create(0,448));
map_add_tile(&GRID_INICIAL, tijolos_create(240,448));
map_add_tile(&GRID_INICIAL, tijolos_create(256,448));
map_add_tile(&GRID_INICIAL, tijolos_create(272,448));
map_add_tile(&GRID_INICIAL, tijolos_create(288,448));
map_add_tile(&GRID_INICIAL, tijolos_create(304,448));
map_add_tile(&GRID_INICIAL, tijolos_create(320,448));
map_add_tile(&GRID_INICIAL, tijolos_create(336,448));
map_add_tile(&GRID_INICIAL, tijolos_create(624,448));
map_add_tile(&GRID_INICIAL, tijolos_create(0,464));
map_add_tile(&GRID_INICIAL, tijolos_create(16,464));
map_add_tile(&GRID_INICIAL, tijolos_create(32,464));
map_add_tile(&GRID_INICIAL, tijolos_create(48,464));
map_add_tile(&GRID_INICIAL, tijolos_create(64,464));
map_add_tile(&GRID_INICIAL, tijolos_create(80,464));
map_add_tile(&GRID_INICIAL, tijolos_create(96,464));
map_add_tile(&GRID_INICIAL, tijolos_create(112,464));
map_add_tile(&GRID_INICIAL, tijolos_create(128,464));
map_add_tile(&GRID_INICIAL, tijolos_create(144,464));
map_add_tile(&GRID_INICIAL, tijolos_create(160,464));
map_add_tile(&GRID_INICIAL, tijolos_create(176,464));
map_add_tile(&GRID_INICIAL, tijolos_create(192,464));
map_add_tile(&GRID_INICIAL, tijolos_create(208,464));
map_add_tile(&GRID_INICIAL, tijolos_create(224,464));
map_add_tile(&GRID_INICIAL, tijolos_create(240,464));
map_add_tile(&GRID_INICIAL, tijolos_create(256,464));
map_add_tile(&GRID_INICIAL, tijolos_create(272,464));
map_add_tile(&GRID_INICIAL, tijolos_create(288,464));
map_add_tile(&GRID_INICIAL, tijolos_create(304,464));
map_add_tile(&GRID_INICIAL, tijolos_create(320,464));
map_add_tile(&GRID_INICIAL, tijolos_create(336,464));
map_add_tile(&GRID_INICIAL, tijolos_create(352,464));
map_add_tile(&GRID_INICIAL, tijolos_create(368,464));
map_add_tile(&GRID_INICIAL, tijolos_create(384,464));
map_add_tile(&GRID_INICIAL, tijolos_create(400,464));
map_add_tile(&GRID_INICIAL, tijolos_create(416,464));
map_add_tile(&GRID_INICIAL, tijolos_create(432,464));
map_add_tile(&GRID_INICIAL, tijolos_create(448,464));
map_add_tile(&GRID_INICIAL, tijolos_create(464,464));
map_add_tile(&GRID_INICIAL, tijolos_create(480,464));
map_add_tile(&GRID_INICIAL, tijolos_create(496,464));
map_add_tile(&GRID_INICIAL, tijolos_create(512,464));
map_add_tile(&GRID_INICIAL, tijolos_create(528,464));
map_add_tile(&GRID_INICIAL, tijolos_create(544,464));
map_add_tile(&GRID_INICIAL, tijolos_create(560,464));
map_add_tile(&GRID_INICIAL, tijolos_create(576,464));
map_add_tile(&GRID_INICIAL, tijolos_create(592,464));
map_add_tile(&GRID_INICIAL, tijolos_create(608,464));
map_add_tile(&GRID_INICIAL, tijolos_create(624,464));
};

/* ──────────────────────────────────────────────────────────── */
/* Área: puzzle */
/* ──────────────────────────────────────────────────────────── */

static EntityList ENTIDADES_PUZZLE = {
    .ents = {  },
    .count = 0,
};

static Grid GRID_PUZZLE = {
    .cells     = { NULL },
    .height    = 240,
    .width     = 320,
    .cell_size = 16,
};

static void map_init_PUZZLE(void) {
map_add_tile(&GRID_PUZZLE, tijolos_create(0,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(16,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(32,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(48,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(64,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(80,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(96,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(112,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(128,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(144,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(160,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(176,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(192,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(208,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(224,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(240,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(256,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(272,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(288,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(304,0));
map_add_tile(&GRID_PUZZLE, tijolos_create(0,16));
map_add_tile(&GRID_PUZZLE, transicao_create(304,16, AREA_INICIAL, 16, 16));
map_add_tile(&GRID_PUZZLE, tijolos_create(0,32));
map_add_tile(&GRID_PUZZLE, transicao_create(304,32, AREA_INICIAL, 16, 16));
map_add_tile(&GRID_PUZZLE, tijolos_create(0,48));
map_add_tile(&GRID_PUZZLE, transicao_create(304,48, AREA_INICIAL, 16, 16));
map_add_tile(&GRID_PUZZLE, tijolos_create(0,64));
map_add_tile(&GRID_PUZZLE, tijolos_create(16,64));
map_add_tile(&GRID_PUZZLE, tijolos_create(32,64));
map_add_tile(&GRID_PUZZLE, tijolos_create(48,64));
map_add_tile(&GRID_PUZZLE, tijolos_create(64,64));
map_add_tile(&GRID_PUZZLE, tijolos_create(80,64));
map_add_tile(&GRID_PUZZLE, tijolos_create(96,64));
map_add_tile(&GRID_PUZZLE, tijolos_create(112,64));
map_add_tile(&GRID_PUZZLE, tijolos_create(128,64));
map_add_tile(&GRID_PUZZLE, metal_create(176,64));
map_add_tile(&GRID_PUZZLE, tijolos_create(192,64));
map_add_tile(&GRID_PUZZLE, tijolos_create(208,64));
map_add_tile(&GRID_PUZZLE, tijolos_create(224,64));
map_add_tile(&GRID_PUZZLE, tijolos_create(240,64));
map_add_tile(&GRID_PUZZLE, tijolos_create(256,64));
map_add_tile(&GRID_PUZZLE, tijolos_create(272,64));
map_add_tile(&GRID_PUZZLE, tijolos_create(288,64));
map_add_tile(&GRID_PUZZLE, tijolos_create(304,64));
map_add_tile(&GRID_PUZZLE, tijolos_create(0,80));
map_add_tile(&GRID_PUZZLE, tijolos_create(128,80));
map_add_tile(&GRID_PUZZLE, tijolos_create(192,80));
map_add_tile(&GRID_PUZZLE, tijolos_create(288,80));
map_add_tile(&GRID_PUZZLE, tijolos_create(304,80));
map_add_tile(&GRID_PUZZLE, tijolos_create(0,96));
map_add_tile(&GRID_PUZZLE, tijolos_create(128,96));
map_add_tile(&GRID_PUZZLE, metal_create(144,96));
map_add_tile(&GRID_PUZZLE, tijolos_create(192,96));
map_add_tile(&GRID_PUZZLE, tijolos_create(304,96));
map_add_tile(&GRID_PUZZLE, tijolos_create(0,112));
map_add_tile(&GRID_PUZZLE, tijolos_create(128,112));
map_add_tile(&GRID_PUZZLE, tijolos_create(192,112));
map_add_tile(&GRID_PUZZLE, metal_create(208,112));
map_add_tile(&GRID_PUZZLE, porta_create(304,112));
map_add_tile(&GRID_PUZZLE, tijolos_create(0,128));
map_add_tile(&GRID_PUZZLE, tijolos_create(128,128));
map_add_tile(&GRID_PUZZLE, metal_create(176,128));
map_add_tile(&GRID_PUZZLE, tijolos_create(192,128));
map_add_tile(&GRID_PUZZLE, tijolos_create(208,128));
map_add_tile(&GRID_PUZZLE, tijolos_create(224,128));
map_add_tile(&GRID_PUZZLE, tijolos_create(240,128));
map_add_tile(&GRID_PUZZLE, porta_create(304,128));
map_add_tile(&GRID_PUZZLE, tijolos_create(0,144));
map_add_tile(&GRID_PUZZLE, metal_create(112,144));
map_add_tile(&GRID_PUZZLE, tijolos_create(128,144));
map_add_tile(&GRID_PUZZLE, tijolos_create(192,144));
map_add_tile(&GRID_PUZZLE, tijolos_create(208,144));
map_add_tile(&GRID_PUZZLE, tijolos_create(224,144));
map_add_tile(&GRID_PUZZLE, tijolos_create(240,144));
map_add_tile(&GRID_PUZZLE, tijolos_create(256,144));
map_add_tile(&GRID_PUZZLE, porta_create(304,144));
map_add_tile(&GRID_PUZZLE, tijolos_create(0,160));
map_add_tile(&GRID_PUZZLE, metal_create(64,160));
map_add_tile(&GRID_PUZZLE, tijolos_create(80,160));
map_add_tile(&GRID_PUZZLE, tijolos_create(96,160));
map_add_tile(&GRID_PUZZLE, tijolos_create(112,160));
map_add_tile(&GRID_PUZZLE, tijolos_create(128,160));
map_add_tile(&GRID_PUZZLE, metal_create(144,160));
map_add_tile(&GRID_PUZZLE, tijolos_create(192,160));
map_add_tile(&GRID_PUZZLE, tijolos_create(208,160));
map_add_tile(&GRID_PUZZLE, tijolos_create(224,160));
map_add_tile(&GRID_PUZZLE, metal_create(304,160));
map_add_tile(&GRID_PUZZLE, tijolos_create(0,176));
map_add_tile(&GRID_PUZZLE, metal_create(48,176));
map_add_tile(&GRID_PUZZLE, tijolos_create(64,176));
map_add_tile(&GRID_PUZZLE, tijolos_create(80,176));
map_add_tile(&GRID_PUZZLE, tijolos_create(208,176));
map_add_tile(&GRID_PUZZLE, metal_create(288,176));
map_add_tile(&GRID_PUZZLE, tijolos_create(304,176));
map_add_tile(&GRID_PUZZLE, tijolos_create(0,192));
map_add_tile(&GRID_PUZZLE, tijolos_create(48,192));
map_add_tile(&GRID_PUZZLE, tijolos_create(64,192));
map_add_tile(&GRID_PUZZLE, metal_create(160,192));
map_add_tile(&GRID_PUZZLE, metal_create(272,192));
map_add_tile(&GRID_PUZZLE, tijolos_create(288,192));
map_add_tile(&GRID_PUZZLE, tijolos_create(304,192));
map_add_tile(&GRID_PUZZLE, tijolos_create(0,208));
map_add_tile(&GRID_PUZZLE, tijolos_create(16,208));
map_add_tile(&GRID_PUZZLE, metal_create(96,208));
map_add_tile(&GRID_PUZZLE, metal_create(160,208));
map_add_tile(&GRID_PUZZLE, metal_create(176,208));
map_add_tile(&GRID_PUZZLE, metal_create(256,208));
map_add_tile(&GRID_PUZZLE, tijolos_create(272,208));
map_add_tile(&GRID_PUZZLE, tijolos_create(288,208));
map_add_tile(&GRID_PUZZLE, tijolos_create(304,208));
map_add_tile(&GRID_PUZZLE, tijolos_create(0,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(16,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(32,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(48,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(64,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(80,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(96,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(112,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(128,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(144,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(160,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(176,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(192,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(208,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(224,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(240,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(256,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(272,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(288,224));
map_add_tile(&GRID_PUZZLE, tijolos_create(304,224));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, bola_create(208,96));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, arma_create(112,128));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, pinwheel_create(10,2, RIGHT, UP));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, scorpion_create(6,3, RIGHT, UP));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, scorpion_create(12,3, RIGHT, UP));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, scorpion_create(18,3, RIGHT, UP));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, pinwheel_create(16,6, RIGHT, UP));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, pinwheel_create(3,8, RIGHT, UP));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, pinwheel_create(6,8, RIGHT, UP));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, scorpion_create(15,13, RIGHT, UP));
};

static Grid *_grids[] = {
    [AREA_INICIAL] = &GRID_INICIAL,
    [AREA_PUZZLE] = &GRID_PUZZLE,
};

static EntityList *_entidades[] = {
    [AREA_INICIAL] = &ENTIDADES_INICIAL,
    [AREA_PUZZLE] = &ENTIDADES_PUZZLE,
};

static Grid* get_grid(AreaId id){
    if(id>=AREA_COUNT) return NULL;
    return _grids[id];
}

static EntityList* get_entidades(AreaId id){
    if(id>=AREA_COUNT) return NULL;
    return _entidades[id];
}

typedef void (*MapInitFn)(void);

static MapInitFn _map_init[] = {
    [AREA_INICIAL] = map_init_INICIAL,
    [AREA_PUZZLE] = map_init_PUZZLE,
};

static Grid *load_area(AreaId id) {
    if(id >= AREA_COUNT) return NULL;
    _map_init[id]();
    return _grids[id];
}
