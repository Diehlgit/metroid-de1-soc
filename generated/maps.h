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
/* Área: boss */
/* ──────────────────────────────────────────────────────────── */

static EntityList ENTIDADES_BOSS = {
    .ents = {  },
    .count = 0,
};

static Grid GRID_BOSS = {
    .cells     = { NULL },
    .height    = 240,
    .width     = 320,
    .cell_size = 16,
};

static void map_init_BOSS(void) {
map_add_tile(&GRID_BOSS, tijolos_create(0,0));
map_add_tile(&GRID_BOSS, tijolos_create(16,0));
map_add_tile(&GRID_BOSS, tijolos_create(32,0));
map_add_tile(&GRID_BOSS, tijolos_create(48,0));
map_add_tile(&GRID_BOSS, tijolos_create(64,0));
map_add_tile(&GRID_BOSS, tijolos_create(80,0));
map_add_tile(&GRID_BOSS, tijolos_create(96,0));
map_add_tile(&GRID_BOSS, tijolos_create(112,0));
map_add_tile(&GRID_BOSS, tijolos_create(128,0));
map_add_tile(&GRID_BOSS, tijolos_create(144,0));
map_add_tile(&GRID_BOSS, tijolos_create(160,0));
map_add_tile(&GRID_BOSS, tijolos_create(176,0));
map_add_tile(&GRID_BOSS, tijolos_create(192,0));
map_add_tile(&GRID_BOSS, tijolos_create(208,0));
map_add_tile(&GRID_BOSS, tijolos_create(224,0));
map_add_tile(&GRID_BOSS, tijolos_create(240,0));
map_add_tile(&GRID_BOSS, tijolos_create(256,0));
map_add_tile(&GRID_BOSS, tijolos_create(272,0));
map_add_tile(&GRID_BOSS, tijolos_create(288,0));
map_add_tile(&GRID_BOSS, tijolos_create(304,0));
map_add_tile(&GRID_BOSS, tijolos_create(0,16));
map_add_tile(&GRID_BOSS, metal_create(32,16));
map_add_tile(&GRID_BOSS, metal_create(64,16));
map_add_tile(&GRID_BOSS, metal_create(96,16));
map_add_tile(&GRID_BOSS, metal_create(112,16));
map_add_tile(&GRID_BOSS, metal_create(128,16));
map_add_tile(&GRID_BOSS, metal_create(160,16));
map_add_tile(&GRID_BOSS, metal_create(192,16));
map_add_tile(&GRID_BOSS, metal_create(224,16));
map_add_tile(&GRID_BOSS, metal_create(240,16));
map_add_tile(&GRID_BOSS, metal_create(256,16));
map_add_tile(&GRID_BOSS, metal_create(288,16));
map_add_tile(&GRID_BOSS, tijolos_create(304,16));
map_add_tile(&GRID_BOSS, tijolos_create(0,32));
map_add_tile(&GRID_BOSS, metal_create(32,32));
map_add_tile(&GRID_BOSS, metal_create(48,32));
map_add_tile(&GRID_BOSS, metal_create(64,32));
map_add_tile(&GRID_BOSS, metal_create(96,32));
map_add_tile(&GRID_BOSS, metal_create(128,32));
map_add_tile(&GRID_BOSS, metal_create(160,32));
map_add_tile(&GRID_BOSS, metal_create(176,32));
map_add_tile(&GRID_BOSS, metal_create(192,32));
map_add_tile(&GRID_BOSS, metal_create(224,32));
map_add_tile(&GRID_BOSS, metal_create(256,32));
map_add_tile(&GRID_BOSS, metal_create(288,32));
map_add_tile(&GRID_BOSS, tijolos_create(304,32));
map_add_tile(&GRID_BOSS, tijolos_create(0,48));
map_add_tile(&GRID_BOSS, metal_create(32,48));
map_add_tile(&GRID_BOSS, metal_create(64,48));
map_add_tile(&GRID_BOSS, metal_create(96,48));
map_add_tile(&GRID_BOSS, metal_create(112,48));
map_add_tile(&GRID_BOSS, metal_create(128,48));
map_add_tile(&GRID_BOSS, metal_create(160,48));
map_add_tile(&GRID_BOSS, metal_create(192,48));
map_add_tile(&GRID_BOSS, metal_create(224,48));
map_add_tile(&GRID_BOSS, metal_create(240,48));
map_add_tile(&GRID_BOSS, metal_create(256,48));
map_add_tile(&GRID_BOSS, tijolos_create(304,48));
map_add_tile(&GRID_BOSS, tijolos_create(0,64));
map_add_tile(&GRID_BOSS, metal_create(32,64));
map_add_tile(&GRID_BOSS, metal_create(64,64));
map_add_tile(&GRID_BOSS, metal_create(96,64));
map_add_tile(&GRID_BOSS, metal_create(128,64));
map_add_tile(&GRID_BOSS, metal_create(160,64));
map_add_tile(&GRID_BOSS, metal_create(192,64));
map_add_tile(&GRID_BOSS, metal_create(224,64));
map_add_tile(&GRID_BOSS, metal_create(256,64));
map_add_tile(&GRID_BOSS, metal_create(288,64));
map_add_tile(&GRID_BOSS, tijolos_create(304,64));
map_add_tile(&GRID_BOSS, tijolos_create(0,80));
map_add_tile(&GRID_BOSS, tijolos_create(304,80));
map_add_tile(&GRID_BOSS, tijolos_create(0,96));
map_add_tile(&GRID_BOSS, tijolos_create(304,96));
map_add_tile(&GRID_BOSS, tijolos_create(0,112));
map_add_tile(&GRID_BOSS, tijolos_create(304,112));
map_add_tile(&GRID_BOSS, tijolos_create(0,128));
map_add_tile(&GRID_BOSS, tijolos_create(304,128));
map_add_tile(&GRID_BOSS, tijolos_create(0,144));
map_add_tile(&GRID_BOSS, tijolos_create(304,144));
map_add_tile(&GRID_BOSS, tijolos_create(0,160));
map_add_tile(&GRID_BOSS, tijolos_create(304,160));
map_add_tile(&GRID_BOSS, tijolos_create(0,176));
map_add_tile(&GRID_BOSS, metal_create(80,176));
map_add_tile(&GRID_BOSS, metal_create(96,176));
map_add_tile(&GRID_BOSS, metal_create(112,176));
map_add_tile(&GRID_BOSS, metal_create(192,176));
map_add_tile(&GRID_BOSS, metal_create(208,176));
map_add_tile(&GRID_BOSS, metal_create(224,176));
map_add_tile(&GRID_BOSS, tijolos_create(304,176));
map_add_tile(&GRID_BOSS, tijolos_create(0,192));
map_add_tile(&GRID_BOSS, tijolos_create(304,192));
map_add_tile(&GRID_BOSS, tijolos_create(0,208));
map_add_tile(&GRID_BOSS, tijolos_create(304,208));
map_add_tile(&GRID_BOSS, tijolos_create(0,224));
map_add_tile(&GRID_BOSS, tijolos_create(16,224));
map_add_tile(&GRID_BOSS, tijolos_create(32,224));
map_add_tile(&GRID_BOSS, tijolos_create(48,224));
map_add_tile(&GRID_BOSS, tijolos_create(64,224));
map_add_tile(&GRID_BOSS, tijolos_create(80,224));
map_add_tile(&GRID_BOSS, tijolos_create(96,224));
map_add_tile(&GRID_BOSS, tijolos_create(112,224));
map_add_tile(&GRID_BOSS, tijolos_create(128,224));
map_add_tile(&GRID_BOSS, tijolos_create(144,224));
map_add_tile(&GRID_BOSS, tijolos_create(160,224));
map_add_tile(&GRID_BOSS, tijolos_create(176,224));
map_add_tile(&GRID_BOSS, tijolos_create(192,224));
map_add_tile(&GRID_BOSS, tijolos_create(208,224));
map_add_tile(&GRID_BOSS, tijolos_create(224,224));
map_add_tile(&GRID_BOSS, tijolos_create(240,224));
map_add_tile(&GRID_BOSS, tijolos_create(256,224));
map_add_tile(&GRID_BOSS, tijolos_create(272,224));
map_add_tile(&GRID_BOSS, tijolos_create(288,224));
map_add_tile(&GRID_BOSS, tijolos_create(304,224));
map_add_entity(&GRID_BOSS, &ENTIDADES_BOSS, pinwheel_create(96,96, RIGHT, UP));
map_add_entity(&GRID_BOSS, &ENTIDADES_BOSS, pinwheel_create(160,96, RIGHT, UP));
map_add_entity(&GRID_BOSS, &ENTIDADES_BOSS, pinwheel_create(224,96, RIGHT, UP));
};

/* ──────────────────────────────────────────────────────────── */
/* Área: corredor */
/* ──────────────────────────────────────────────────────────── */

static EntityList ENTIDADES_CORREDOR = {
    .ents = {  },
    .count = 0,
};

static Grid GRID_CORREDOR = {
    .cells     = { NULL },
    .height    = 480,
    .width     = 640,
    .cell_size = 16,
};

static void map_init_CORREDOR(void) {
map_add_tile(&GRID_CORREDOR, tijolos_create(0,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(16,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(32,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(48,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(64,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(80,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(96,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(112,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(128,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(144,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(160,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(176,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(192,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(208,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(224,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(240,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(256,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(272,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(288,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(304,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(320,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(336,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(352,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(368,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(384,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(400,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(416,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(432,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(448,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(464,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(480,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(496,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(512,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(528,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(544,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(560,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(576,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(592,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(608,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(624,0));
map_add_tile(&GRID_CORREDOR, tijolos_create(0,16));
map_add_tile(&GRID_CORREDOR, transicao_create(608,16,AREA_NAVE,512,112));
map_add_tile(&GRID_CORREDOR, tijolos_create(624,16));
map_add_tile(&GRID_CORREDOR, tijolos_create(0,32));
map_add_tile(&GRID_CORREDOR, transicao_create(608,32,AREA_NAVE,512,112));
map_add_tile(&GRID_CORREDOR, tijolos_create(624,32));
map_add_tile(&GRID_CORREDOR, tijolos_create(0,48));
map_add_tile(&GRID_CORREDOR, transicao_create(608,48,AREA_NAVE,512,112));
map_add_tile(&GRID_CORREDOR, tijolos_create(624,48));
map_add_tile(&GRID_CORREDOR, tijolos_create(0,64));
map_add_tile(&GRID_CORREDOR, transicao_create(608,64,AREA_NAVE,512,112));
map_add_tile(&GRID_CORREDOR, tijolos_create(624,64));
map_add_tile(&GRID_CORREDOR, tijolos_create(0,80));
map_add_tile(&GRID_CORREDOR, transicao_create(608,80,AREA_NAVE,512,112));
map_add_tile(&GRID_CORREDOR, tijolos_create(624,80));
map_add_tile(&GRID_CORREDOR, tijolos_create(0,96));
map_add_tile(&GRID_CORREDOR, transicao_create(608,96,AREA_NAVE,512,112));
map_add_tile(&GRID_CORREDOR, tijolos_create(624,96));
map_add_tile(&GRID_CORREDOR, tijolos_create(0,112));
map_add_tile(&GRID_CORREDOR, transicao_create(608,112,AREA_NAVE,512,112));
map_add_tile(&GRID_CORREDOR, tijolos_create(624,112));
map_add_tile(&GRID_CORREDOR, tijolos_create(0,128));
map_add_tile(&GRID_CORREDOR, transicao_create(608,128,AREA_NAVE,512,112));
map_add_tile(&GRID_CORREDOR, tijolos_create(624,128));
map_add_tile(&GRID_CORREDOR, tijolos_create(0,144));
map_add_tile(&GRID_CORREDOR, transicao_create(608,144,AREA_NAVE,512,112));
map_add_tile(&GRID_CORREDOR, tijolos_create(624,144));
map_add_tile(&GRID_CORREDOR, tijolos_create(0,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(16,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(32,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(48,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(64,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(80,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(96,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(112,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(128,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(144,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(160,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(176,160));
map_add_tile(&GRID_CORREDOR, metal_create(272,160));
map_add_tile(&GRID_CORREDOR, metal_create(288,160));
map_add_tile(&GRID_CORREDOR, metal_create(384,160));
map_add_tile(&GRID_CORREDOR, metal_create(400,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(496,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(512,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(528,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(544,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(560,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(576,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(592,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(608,160));
map_add_tile(&GRID_CORREDOR, tijolos_create(624,160));
map_add_tile(&GRID_CORREDOR, transicao_create(0,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(16,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(32,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(48,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(64,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(80,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(96,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(112,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(128,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(144,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(160,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(176,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(192,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(208,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(224,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(240,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(256,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(272,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(288,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(304,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(320,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(336,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(352,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(368,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(384,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(400,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(416,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(432,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(448,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(464,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(480,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(496,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(512,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(528,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(544,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(560,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(576,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(592,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(608,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, transicao_create(624,336,AREA_CORREDOR,48,144));
map_add_tile(&GRID_CORREDOR, bola_create(288,144));
map_add_tile(&GRID_CORREDOR, arma_create(528,144));
};

/* ──────────────────────────────────────────────────────────── */
/* Área: nave */
/* ──────────────────────────────────────────────────────────── */

static EntityList ENTIDADES_NAVE = {
    .ents = {  },
    .count = 0,
};

static Grid GRID_NAVE = {
    .cells     = { NULL },
    .height    = 480,
    .width     = 640,
    .cell_size = 16,
};

static void map_init_NAVE(void) {
map_add_tile(&GRID_NAVE, tijolos_create(0,0));
map_add_tile(&GRID_NAVE, tijolos_create(16,0));
map_add_tile(&GRID_NAVE, tijolos_create(32,0));
map_add_tile(&GRID_NAVE, tijolos_create(48,0));
map_add_tile(&GRID_NAVE, tijolos_create(64,0));
map_add_tile(&GRID_NAVE, tijolos_create(80,0));
map_add_tile(&GRID_NAVE, tijolos_create(96,0));
map_add_tile(&GRID_NAVE, tijolos_create(112,0));
map_add_tile(&GRID_NAVE, tijolos_create(128,0));
map_add_tile(&GRID_NAVE, tijolos_create(144,0));
map_add_tile(&GRID_NAVE, tijolos_create(160,0));
map_add_tile(&GRID_NAVE, tijolos_create(176,0));
map_add_tile(&GRID_NAVE, tijolos_create(192,0));
map_add_tile(&GRID_NAVE, tijolos_create(208,0));
map_add_tile(&GRID_NAVE, tijolos_create(224,0));
map_add_tile(&GRID_NAVE, tijolos_create(240,0));
map_add_tile(&GRID_NAVE, tijolos_create(256,0));
map_add_tile(&GRID_NAVE, tijolos_create(272,0));
map_add_tile(&GRID_NAVE, tijolos_create(288,0));
map_add_tile(&GRID_NAVE, tijolos_create(304,0));
map_add_tile(&GRID_NAVE, tijolos_create(320,0));
map_add_tile(&GRID_NAVE, tijolos_create(336,0));
map_add_tile(&GRID_NAVE, tijolos_create(352,0));
map_add_tile(&GRID_NAVE, tijolos_create(368,0));
map_add_tile(&GRID_NAVE, tijolos_create(384,0));
map_add_tile(&GRID_NAVE, tijolos_create(400,0));
map_add_tile(&GRID_NAVE, tijolos_create(416,0));
map_add_tile(&GRID_NAVE, tijolos_create(432,0));
map_add_tile(&GRID_NAVE, tijolos_create(448,0));
map_add_tile(&GRID_NAVE, tijolos_create(464,0));
map_add_tile(&GRID_NAVE, tijolos_create(480,0));
map_add_tile(&GRID_NAVE, tijolos_create(496,0));
map_add_tile(&GRID_NAVE, tijolos_create(512,0));
map_add_tile(&GRID_NAVE, tijolos_create(528,0));
map_add_tile(&GRID_NAVE, tijolos_create(544,0));
map_add_tile(&GRID_NAVE, tijolos_create(560,0));
map_add_tile(&GRID_NAVE, tijolos_create(576,0));
map_add_tile(&GRID_NAVE, tijolos_create(592,0));
map_add_tile(&GRID_NAVE, tijolos_create(608,0));
map_add_tile(&GRID_NAVE, tijolos_create(624,0));
map_add_tile(&GRID_NAVE, tijolos_create(0,16));
map_add_tile(&GRID_NAVE, tijolos_create(624,16));
map_add_tile(&GRID_NAVE, tijolos_create(0,32));
map_add_tile(&GRID_NAVE, tijolos_create(624,32));
map_add_tile(&GRID_NAVE, tijolos_create(0,48));
map_add_tile(&GRID_NAVE, tijolos_create(352,48));
map_add_tile(&GRID_NAVE, tijolos_create(368,48));
map_add_tile(&GRID_NAVE, tijolos_create(384,48));
map_add_tile(&GRID_NAVE, tijolos_create(400,48));
map_add_tile(&GRID_NAVE, tijolos_create(416,48));
map_add_tile(&GRID_NAVE, tijolos_create(432,48));
map_add_tile(&GRID_NAVE, tijolos_create(448,48));
map_add_tile(&GRID_NAVE, tijolos_create(624,48));
map_add_tile(&GRID_NAVE, tijolos_create(0,64));
map_add_tile(&GRID_NAVE, tijolos_create(320,64));
map_add_tile(&GRID_NAVE, tijolos_create(336,64));
map_add_tile(&GRID_NAVE, tijolos_create(352,64));
map_add_tile(&GRID_NAVE, tijolos_create(448,64));
map_add_tile(&GRID_NAVE, tijolos_create(464,64));
map_add_tile(&GRID_NAVE, tijolos_create(480,64));
map_add_tile(&GRID_NAVE, tijolos_create(496,64));
map_add_tile(&GRID_NAVE, tijolos_create(512,64));
map_add_tile(&GRID_NAVE, tijolos_create(528,64));
map_add_tile(&GRID_NAVE, tijolos_create(544,64));
map_add_tile(&GRID_NAVE, tijolos_create(560,64));
map_add_tile(&GRID_NAVE, tijolos_create(576,64));
map_add_tile(&GRID_NAVE, tijolos_create(592,64));
map_add_tile(&GRID_NAVE, tijolos_create(608,64));
map_add_tile(&GRID_NAVE, tijolos_create(624,64));
map_add_tile(&GRID_NAVE, tijolos_create(0,80));
map_add_tile(&GRID_NAVE, tijolos_create(272,80));
map_add_tile(&GRID_NAVE, tijolos_create(288,80));
map_add_tile(&GRID_NAVE, tijolos_create(304,80));
map_add_tile(&GRID_NAVE, tijolos_create(320,80));
map_add_tile(&GRID_NAVE, tijolos_create(624,80));
map_add_tile(&GRID_NAVE, tijolos_create(0,96));
map_add_tile(&GRID_NAVE, tijolos_create(208,96));
map_add_tile(&GRID_NAVE, tijolos_create(224,96));
map_add_tile(&GRID_NAVE, tijolos_create(240,96));
map_add_tile(&GRID_NAVE, tijolos_create(256,96));
map_add_tile(&GRID_NAVE, tijolos_create(272,96));
map_add_tile(&GRID_NAVE, tijolos_create(624,96));
map_add_tile(&GRID_NAVE, tijolos_create(0,112));
map_add_tile(&GRID_NAVE, tijolos_create(144,112));
map_add_tile(&GRID_NAVE, tijolos_create(160,112));
map_add_tile(&GRID_NAVE, tijolos_create(176,112));
map_add_tile(&GRID_NAVE, tijolos_create(192,112));
map_add_tile(&GRID_NAVE, tijolos_create(208,112));
map_add_tile(&GRID_NAVE, tijolos_create(624,112));
map_add_tile(&GRID_NAVE, tijolos_create(0,128));
map_add_tile(&GRID_NAVE, tijolos_create(96,128));
map_add_tile(&GRID_NAVE, tijolos_create(112,128));
map_add_tile(&GRID_NAVE, tijolos_create(128,128));
map_add_tile(&GRID_NAVE, tijolos_create(144,128));
map_add_tile(&GRID_NAVE, tijolos_create(464,128));
map_add_tile(&GRID_NAVE, tijolos_create(480,128));
map_add_tile(&GRID_NAVE, tijolos_create(496,128));
map_add_tile(&GRID_NAVE, tijolos_create(512,128));
map_add_tile(&GRID_NAVE, tijolos_create(624,128));
map_add_tile(&GRID_NAVE, tijolos_create(0,144));
map_add_tile(&GRID_NAVE, tijolos_create(464,144));
map_add_tile(&GRID_NAVE, tijolos_create(480,144));
map_add_tile(&GRID_NAVE, tijolos_create(496,144));
map_add_tile(&GRID_NAVE, tijolos_create(512,144));
map_add_tile(&GRID_NAVE, tijolos_create(528,144));
map_add_tile(&GRID_NAVE, tijolos_create(544,144));
map_add_tile(&GRID_NAVE, tijolos_create(624,144));
map_add_tile(&GRID_NAVE, tijolos_create(0,160));
map_add_tile(&GRID_NAVE, tijolos_create(16,160));
map_add_tile(&GRID_NAVE, metal_create(288,160));
map_add_tile(&GRID_NAVE, metal_create(304,160));
map_add_tile(&GRID_NAVE, metal_create(320,160));
map_add_tile(&GRID_NAVE, tijolos_create(464,160));
map_add_tile(&GRID_NAVE, metal_create(496,160));
map_add_tile(&GRID_NAVE, metal_create(512,160));
map_add_tile(&GRID_NAVE, metal_create(528,160));
map_add_tile(&GRID_NAVE, tijolos_create(544,160));
map_add_tile(&GRID_NAVE, tijolos_create(624,160));
map_add_tile(&GRID_NAVE, tijolos_create(0,176));
map_add_tile(&GRID_NAVE, tijolos_create(16,176));
map_add_tile(&GRID_NAVE, tijolos_create(32,176));
map_add_tile(&GRID_NAVE, metal_create(288,176));
map_add_tile(&GRID_NAVE, metal_create(320,176));
map_add_tile(&GRID_NAVE, tijolos_create(464,176));
map_add_tile(&GRID_NAVE, metal_create(512,176));
map_add_tile(&GRID_NAVE, tijolos_create(544,176));
map_add_tile(&GRID_NAVE, tijolos_create(624,176));
map_add_tile(&GRID_NAVE, tijolos_create(0,192));
map_add_tile(&GRID_NAVE, tijolos_create(16,192));
map_add_tile(&GRID_NAVE, tijolos_create(32,192));
map_add_tile(&GRID_NAVE, tijolos_create(48,192));
map_add_tile(&GRID_NAVE, metal_create(240,192));
map_add_tile(&GRID_NAVE, metal_create(368,192));
map_add_tile(&GRID_NAVE, tijolos_create(464,192));
map_add_tile(&GRID_NAVE, transicao_create(512,192,AREA_CORREDOR,48,144));
map_add_tile(&GRID_NAVE, tijolos_create(544,192));
map_add_tile(&GRID_NAVE, tijolos_create(608,192));
map_add_tile(&GRID_NAVE, tijolos_create(624,192));
map_add_tile(&GRID_NAVE, tijolos_create(0,208));
map_add_tile(&GRID_NAVE, tijolos_create(16,208));
map_add_tile(&GRID_NAVE, tijolos_create(32,208));
map_add_tile(&GRID_NAVE, tijolos_create(48,208));
map_add_tile(&GRID_NAVE, tijolos_create(64,208));
map_add_tile(&GRID_NAVE, tijolos_create(80,208));
map_add_tile(&GRID_NAVE, tijolos_create(96,208));
map_add_tile(&GRID_NAVE, tijolos_create(112,208));
map_add_tile(&GRID_NAVE, tijolos_create(128,208));
map_add_tile(&GRID_NAVE, tijolos_create(144,208));
map_add_tile(&GRID_NAVE, tijolos_create(160,208));
map_add_tile(&GRID_NAVE, metal_create(176,208));
map_add_tile(&GRID_NAVE, metal_create(192,208));
map_add_tile(&GRID_NAVE, metal_create(208,208));
map_add_tile(&GRID_NAVE, metal_create(224,208));
map_add_tile(&GRID_NAVE, metal_create(384,208));
map_add_tile(&GRID_NAVE, metal_create(400,208));
map_add_tile(&GRID_NAVE, metal_create(416,208));
map_add_tile(&GRID_NAVE, metal_create(432,208));
map_add_tile(&GRID_NAVE, metal_create(448,208));
map_add_tile(&GRID_NAVE, tijolos_create(464,208));
map_add_tile(&GRID_NAVE, transicao_create(512,208,AREA_CORREDOR,48,144));
map_add_tile(&GRID_NAVE, tijolos_create(544,208));
map_add_tile(&GRID_NAVE, tijolos_create(624,208));
map_add_tile(&GRID_NAVE, tijolos_create(0,224));
map_add_tile(&GRID_NAVE, porta_create(464,224));
map_add_tile(&GRID_NAVE, transicao_create(512,224,AREA_CORREDOR,48,144));
map_add_tile(&GRID_NAVE, tijolos_create(544,224));
map_add_tile(&GRID_NAVE, tijolos_create(560,224));
map_add_tile(&GRID_NAVE, tijolos_create(624,224));
map_add_tile(&GRID_NAVE, tijolos_create(0,240));
map_add_tile(&GRID_NAVE, tijolos_create(288,240));
map_add_tile(&GRID_NAVE, tijolos_create(304,240));
map_add_tile(&GRID_NAVE, tijolos_create(320,240));
map_add_tile(&GRID_NAVE, porta_create(464,240));
map_add_tile(&GRID_NAVE, metal_create(512,240));
map_add_tile(&GRID_NAVE, tijolos_create(544,240));
map_add_tile(&GRID_NAVE, tijolos_create(624,240));
map_add_tile(&GRID_NAVE, tijolos_create(0,256));
map_add_tile(&GRID_NAVE, tijolos_create(272,256));
map_add_tile(&GRID_NAVE, tijolos_create(288,256));
map_add_tile(&GRID_NAVE, tijolos_create(304,256));
map_add_tile(&GRID_NAVE, tijolos_create(320,256));
map_add_tile(&GRID_NAVE, tijolos_create(336,256));
map_add_tile(&GRID_NAVE, porta_create(464,256));
map_add_tile(&GRID_NAVE, metal_create(496,256));
map_add_tile(&GRID_NAVE, metal_create(512,256));
map_add_tile(&GRID_NAVE, metal_create(528,256));
map_add_tile(&GRID_NAVE, tijolos_create(544,256));
map_add_tile(&GRID_NAVE, tijolos_create(608,256));
map_add_tile(&GRID_NAVE, tijolos_create(624,256));
map_add_tile(&GRID_NAVE, tijolos_create(0,272));
map_add_tile(&GRID_NAVE, tijolos_create(160,272));
map_add_tile(&GRID_NAVE, metal_create(176,272));
map_add_tile(&GRID_NAVE, metal_create(192,272));
map_add_tile(&GRID_NAVE, metal_create(208,272));
map_add_tile(&GRID_NAVE, metal_create(224,272));
map_add_tile(&GRID_NAVE, metal_create(240,272));
map_add_tile(&GRID_NAVE, metal_create(256,272));
map_add_tile(&GRID_NAVE, metal_create(272,272));
map_add_tile(&GRID_NAVE, metal_create(288,272));
map_add_tile(&GRID_NAVE, metal_create(304,272));
map_add_tile(&GRID_NAVE, tijolos_create(320,272));
map_add_tile(&GRID_NAVE, tijolos_create(336,272));
map_add_tile(&GRID_NAVE, tijolos_create(352,272));
map_add_tile(&GRID_NAVE, tijolos_create(368,272));
map_add_tile(&GRID_NAVE, tijolos_create(384,272));
map_add_tile(&GRID_NAVE, tijolos_create(400,272));
map_add_tile(&GRID_NAVE, tijolos_create(416,272));
map_add_tile(&GRID_NAVE, tijolos_create(432,272));
map_add_tile(&GRID_NAVE, tijolos_create(448,272));
map_add_tile(&GRID_NAVE, tijolos_create(464,272));
map_add_tile(&GRID_NAVE, tijolos_create(480,272));
map_add_tile(&GRID_NAVE, tijolos_create(496,272));
map_add_tile(&GRID_NAVE, tijolos_create(512,272));
map_add_tile(&GRID_NAVE, tijolos_create(528,272));
map_add_tile(&GRID_NAVE, tijolos_create(544,272));
map_add_tile(&GRID_NAVE, tijolos_create(624,272));
map_add_tile(&GRID_NAVE, tijolos_create(0,288));
map_add_tile(&GRID_NAVE, tijolos_create(144,288));
map_add_tile(&GRID_NAVE, tijolos_create(160,288));
map_add_tile(&GRID_NAVE, tijolos_create(320,288));
map_add_tile(&GRID_NAVE, tijolos_create(528,288));
map_add_tile(&GRID_NAVE, tijolos_create(544,288));
map_add_tile(&GRID_NAVE, tijolos_create(560,288));
map_add_tile(&GRID_NAVE, tijolos_create(624,288));
map_add_tile(&GRID_NAVE, tijolos_create(0,304));
map_add_tile(&GRID_NAVE, tijolos_create(128,304));
map_add_tile(&GRID_NAVE, tijolos_create(144,304));
map_add_tile(&GRID_NAVE, tijolos_create(624,304));
map_add_tile(&GRID_NAVE, tijolos_create(0,320));
map_add_tile(&GRID_NAVE, tijolos_create(112,320));
map_add_tile(&GRID_NAVE, tijolos_create(128,320));
map_add_tile(&GRID_NAVE, metal_create(464,320));
map_add_tile(&GRID_NAVE, tijolos_create(608,320));
map_add_tile(&GRID_NAVE, tijolos_create(624,320));
map_add_tile(&GRID_NAVE, tijolos_create(0,336));
map_add_tile(&GRID_NAVE, tijolos_create(96,336));
map_add_tile(&GRID_NAVE, tijolos_create(112,336));
map_add_tile(&GRID_NAVE, tijolos_create(192,336));
map_add_tile(&GRID_NAVE, tijolos_create(208,336));
map_add_tile(&GRID_NAVE, tijolos_create(224,336));
map_add_tile(&GRID_NAVE, tijolos_create(240,336));
map_add_tile(&GRID_NAVE, tijolos_create(256,336));
map_add_tile(&GRID_NAVE, tijolos_create(272,336));
map_add_tile(&GRID_NAVE, tijolos_create(288,336));
map_add_tile(&GRID_NAVE, tijolos_create(304,336));
map_add_tile(&GRID_NAVE, tijolos_create(320,336));
map_add_tile(&GRID_NAVE, tijolos_create(336,336));
map_add_tile(&GRID_NAVE, tijolos_create(352,336));
map_add_tile(&GRID_NAVE, tijolos_create(368,336));
map_add_tile(&GRID_NAVE, tijolos_create(384,336));
map_add_tile(&GRID_NAVE, tijolos_create(400,336));
map_add_tile(&GRID_NAVE, tijolos_create(416,336));
map_add_tile(&GRID_NAVE, tijolos_create(432,336));
map_add_tile(&GRID_NAVE, tijolos_create(448,336));
map_add_tile(&GRID_NAVE, tijolos_create(464,336));
map_add_tile(&GRID_NAVE, tijolos_create(480,336));
map_add_tile(&GRID_NAVE, tijolos_create(496,336));
map_add_tile(&GRID_NAVE, tijolos_create(512,336));
map_add_tile(&GRID_NAVE, tijolos_create(528,336));
map_add_tile(&GRID_NAVE, tijolos_create(544,336));
map_add_tile(&GRID_NAVE, tijolos_create(560,336));
map_add_tile(&GRID_NAVE, tijolos_create(576,336));
map_add_tile(&GRID_NAVE, tijolos_create(592,336));
map_add_tile(&GRID_NAVE, tijolos_create(608,336));
map_add_tile(&GRID_NAVE, tijolos_create(624,336));
map_add_tile(&GRID_NAVE, tijolos_create(0,352));
map_add_tile(&GRID_NAVE, tijolos_create(80,352));
map_add_tile(&GRID_NAVE, tijolos_create(96,352));
map_add_tile(&GRID_NAVE, tijolos_create(176,352));
map_add_tile(&GRID_NAVE, tijolos_create(192,352));
map_add_tile(&GRID_NAVE, tijolos_create(464,352));
map_add_tile(&GRID_NAVE, tijolos_create(624,352));
map_add_tile(&GRID_NAVE, tijolos_create(0,368));
map_add_tile(&GRID_NAVE, tijolos_create(16,368));
map_add_tile(&GRID_NAVE, tijolos_create(32,368));
map_add_tile(&GRID_NAVE, tijolos_create(48,368));
map_add_tile(&GRID_NAVE, tijolos_create(64,368));
map_add_tile(&GRID_NAVE, tijolos_create(80,368));
map_add_tile(&GRID_NAVE, tijolos_create(96,368));
map_add_tile(&GRID_NAVE, tijolos_create(160,368));
map_add_tile(&GRID_NAVE, tijolos_create(176,368));
map_add_tile(&GRID_NAVE, tijolos_create(192,368));
map_add_tile(&GRID_NAVE, tijolos_create(464,368));
map_add_tile(&GRID_NAVE, tijolos_create(624,368));
map_add_tile(&GRID_NAVE, tijolos_create(0,384));
map_add_tile(&GRID_NAVE, tijolos_create(144,384));
map_add_tile(&GRID_NAVE, tijolos_create(160,384));
map_add_tile(&GRID_NAVE, tijolos_create(176,384));
map_add_tile(&GRID_NAVE, tijolos_create(192,384));
map_add_tile(&GRID_NAVE, metal_create(320,384));
map_add_tile(&GRID_NAVE, metal_create(336,384));
map_add_tile(&GRID_NAVE, tijolos_create(464,384));
map_add_tile(&GRID_NAVE, transicao_create(528,384,AREA_BOSS,48,208));
map_add_tile(&GRID_NAVE, transicao_create(544,384,AREA_BOSS,48,208));
map_add_tile(&GRID_NAVE, transicao_create(560,384,AREA_BOSS,48,208));
map_add_tile(&GRID_NAVE, transicao_create(576,384,AREA_BOSS,48,208));
map_add_tile(&GRID_NAVE, tijolos_create(624,384));
map_add_tile(&GRID_NAVE, tijolos_create(0,400));
map_add_tile(&GRID_NAVE, tijolos_create(80,400));
map_add_tile(&GRID_NAVE, tijolos_create(96,400));
map_add_tile(&GRID_NAVE, tijolos_create(112,400));
map_add_tile(&GRID_NAVE, tijolos_create(128,400));
map_add_tile(&GRID_NAVE, tijolos_create(144,400));
map_add_tile(&GRID_NAVE, tijolos_create(160,400));
map_add_tile(&GRID_NAVE, tijolos_create(176,400));
map_add_tile(&GRID_NAVE, tijolos_create(192,400));
map_add_tile(&GRID_NAVE, metal_create(224,400));
map_add_tile(&GRID_NAVE, metal_create(240,400));
map_add_tile(&GRID_NAVE, metal_create(384,400));
map_add_tile(&GRID_NAVE, metal_create(400,400));
map_add_tile(&GRID_NAVE, metal_create(416,400));
map_add_tile(&GRID_NAVE, tijolos_create(464,400));
map_add_tile(&GRID_NAVE, transicao_create(528,400,AREA_BOSS,48,208));
map_add_tile(&GRID_NAVE, transicao_create(544,400,AREA_BOSS,48,208));
map_add_tile(&GRID_NAVE, transicao_create(560,400,AREA_BOSS,48,208));
map_add_tile(&GRID_NAVE, transicao_create(576,400,AREA_BOSS,48,208));
map_add_tile(&GRID_NAVE, tijolos_create(624,400));
map_add_tile(&GRID_NAVE, tijolos_create(0,416));
map_add_tile(&GRID_NAVE, metal_create(16,416));
map_add_tile(&GRID_NAVE, porta_create(464,416));
map_add_tile(&GRID_NAVE, transicao_create(528,416,AREA_BOSS,48,208));
map_add_tile(&GRID_NAVE, transicao_create(544,416,AREA_BOSS,48,208));
map_add_tile(&GRID_NAVE, transicao_create(560,416,AREA_BOSS,48,208));
map_add_tile(&GRID_NAVE, transicao_create(576,416,AREA_BOSS,48,208));
map_add_tile(&GRID_NAVE, tijolos_create(624,416));
map_add_tile(&GRID_NAVE, tijolos_create(0,432));
map_add_tile(&GRID_NAVE, metal_create(16,432));
map_add_tile(&GRID_NAVE, metal_create(32,432));
map_add_tile(&GRID_NAVE, metal_create(48,432));
map_add_tile(&GRID_NAVE, metal_create(304,432));
map_add_tile(&GRID_NAVE, metal_create(320,432));
map_add_tile(&GRID_NAVE, metal_create(336,432));
map_add_tile(&GRID_NAVE, metal_create(352,432));
map_add_tile(&GRID_NAVE, porta_create(464,432));
map_add_tile(&GRID_NAVE, transicao_create(528,432,AREA_BOSS,48,208));
map_add_tile(&GRID_NAVE, transicao_create(544,432,AREA_BOSS,48,208));
map_add_tile(&GRID_NAVE, transicao_create(560,432,AREA_BOSS,48,208));
map_add_tile(&GRID_NAVE, transicao_create(576,432,AREA_BOSS,48,208));
map_add_tile(&GRID_NAVE, tijolos_create(624,432));
map_add_tile(&GRID_NAVE, tijolos_create(0,448));
map_add_tile(&GRID_NAVE, metal_create(16,448));
map_add_tile(&GRID_NAVE, metal_create(32,448));
map_add_tile(&GRID_NAVE, metal_create(48,448));
map_add_tile(&GRID_NAVE, metal_create(64,448));
map_add_tile(&GRID_NAVE, porta_create(464,448));
map_add_tile(&GRID_NAVE, tijolos_create(624,448));
map_add_tile(&GRID_NAVE, tijolos_create(0,464));
map_add_tile(&GRID_NAVE, tijolos_create(16,464));
map_add_tile(&GRID_NAVE, tijolos_create(32,464));
map_add_tile(&GRID_NAVE, tijolos_create(48,464));
map_add_tile(&GRID_NAVE, tijolos_create(64,464));
map_add_tile(&GRID_NAVE, tijolos_create(80,464));
map_add_tile(&GRID_NAVE, tijolos_create(96,464));
map_add_tile(&GRID_NAVE, tijolos_create(112,464));
map_add_tile(&GRID_NAVE, tijolos_create(128,464));
map_add_tile(&GRID_NAVE, tijolos_create(144,464));
map_add_tile(&GRID_NAVE, tijolos_create(160,464));
map_add_tile(&GRID_NAVE, tijolos_create(176,464));
map_add_tile(&GRID_NAVE, tijolos_create(192,464));
map_add_tile(&GRID_NAVE, tijolos_create(208,464));
map_add_tile(&GRID_NAVE, tijolos_create(224,464));
map_add_tile(&GRID_NAVE, tijolos_create(240,464));
map_add_tile(&GRID_NAVE, tijolos_create(256,464));
map_add_tile(&GRID_NAVE, tijolos_create(272,464));
map_add_tile(&GRID_NAVE, tijolos_create(288,464));
map_add_tile(&GRID_NAVE, tijolos_create(304,464));
map_add_tile(&GRID_NAVE, tijolos_create(320,464));
map_add_tile(&GRID_NAVE, tijolos_create(336,464));
map_add_tile(&GRID_NAVE, tijolos_create(352,464));
map_add_tile(&GRID_NAVE, tijolos_create(368,464));
map_add_tile(&GRID_NAVE, tijolos_create(384,464));
map_add_tile(&GRID_NAVE, tijolos_create(400,464));
map_add_tile(&GRID_NAVE, tijolos_create(416,464));
map_add_tile(&GRID_NAVE, tijolos_create(432,464));
map_add_tile(&GRID_NAVE, tijolos_create(448,464));
map_add_tile(&GRID_NAVE, tijolos_create(464,464));
map_add_tile(&GRID_NAVE, tijolos_create(480,464));
map_add_tile(&GRID_NAVE, tijolos_create(496,464));
map_add_tile(&GRID_NAVE, tijolos_create(512,464));
map_add_tile(&GRID_NAVE, tijolos_create(528,464));
map_add_tile(&GRID_NAVE, tijolos_create(544,464));
map_add_tile(&GRID_NAVE, tijolos_create(560,464));
map_add_tile(&GRID_NAVE, tijolos_create(576,464));
map_add_tile(&GRID_NAVE, tijolos_create(592,464));
map_add_tile(&GRID_NAVE, tijolos_create(608,464));
map_add_tile(&GRID_NAVE, tijolos_create(624,464));
//map_add_tile(&GRID_NAVE, chave_create(576,48));
//map_add_tile(&GRID_NAVE, botas_create(32,352));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, morcego_create(256,48, RIGHT, UP));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, scorpion_create(528,48, RIGHT, UP));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, morcego_create(144,64, RIGHT, UP));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, morcego_create(304,128, RIGHT, UP));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, morcego_create(400,144, RIGHT, UP));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, scorpion_create(176,192, RIGHT, UP));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, scorpion_create(432,192, RIGHT, UP));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, morcego_create(80,256, RIGHT, UP));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, scorpion_create(192,256, RIGHT, UP));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, scorpion_create(416,256, RIGHT, UP));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, morcego_create(32,304, RIGHT, UP));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, pinwheel_create(192,304, RIGHT, UP));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, pinwheel_create(384,304, RIGHT, UP));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, scorpion_create(256,320, RIGHT, UP));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, scorpion_create(416,384, RIGHT, UP));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, scorpion_create(320,416, RIGHT, UP));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, pinwheel_create(160,432, RIGHT, UP));
map_add_entity(&GRID_NAVE, &ENTIDADES_NAVE, pinwheel_create(416,432, RIGHT, UP));
};

static Grid *_grids[] = {
    [AREA_BOSS] = &GRID_BOSS,
    [AREA_CORREDOR] = &GRID_CORREDOR,
    [AREA_NAVE] = &GRID_NAVE,
};

static EntityList *_entidades[] = {
    [AREA_BOSS] = &ENTIDADES_BOSS,
    [AREA_CORREDOR] = &ENTIDADES_CORREDOR,
    [AREA_NAVE] = &ENTIDADES_NAVE,
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
    [AREA_BOSS] = map_init_BOSS,
    [AREA_CORREDOR] = map_init_CORREDOR,
    [AREA_NAVE] = map_init_NAVE,
};

static Grid *load_area(AreaId id) {
    if(id >= AREA_COUNT) return NULL;
    _map_init[id]();
    return _grids[id];
}
