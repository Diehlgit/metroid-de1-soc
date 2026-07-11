/* AUTO-GERADO por generate_mapas.py — não edite */
#pragma once
#include <stdint.h>
#include "../include/basics.h"
#include "../include/entity.h"
#include "../include/grid.h"
#include "tiles.h"
#include "itens.h"
#include "entidades.h"

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
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(1,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(2,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(3,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(4,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(5,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(6,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(7,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(8,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(9,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(10,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(11,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(12,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(13,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(14,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(15,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(16,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(17,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(18,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(19,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(20,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(21,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(22,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(23,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(24,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(25,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(26,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(27,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(28,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(29,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(30,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(31,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(32,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(33,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(34,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(35,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(36,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(37,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(38,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,0));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,1));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,1));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,2));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,2));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,3));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,3));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(1,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(2,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(3,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(4,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(5,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(6,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(7,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(8,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(9,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(10,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(11,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(12,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(13,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(14,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(15,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(16,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(17,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(18,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(19,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(20,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(21,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(22,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(23,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(24,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(25,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(26,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(27,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(28,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(29,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(30,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(31,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(32,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(33,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(34,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(35,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(36,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,4));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,5));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,5));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,6));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,6));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,7));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,7));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(3,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(4,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(5,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(6,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(7,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(8,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(9,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(10,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(11,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(12,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(13,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(14,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(15,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(16,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(17,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(18,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(19,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(20,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(21,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(22,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(23,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(24,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(25,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(26,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(27,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(28,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(29,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(30,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(31,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(32,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(33,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(34,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(35,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(36,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(37,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(38,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,8));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,9));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,9));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,10));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,10));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,11));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,11));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(1,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(2,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(3,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(4,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(5,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(6,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(7,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(8,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(9,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(10,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(11,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(12,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(13,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(15,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(16,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(17,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(18,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(19,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(20,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(21,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(22,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(23,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(24,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(25,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(26,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(27,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(28,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(29,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(30,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(31,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(32,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(33,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(34,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(35,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,12));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,13));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,13));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,14));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,14));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,15));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,15));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,16));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,16));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,17));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,17));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,18));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(9,18));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(10,18));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(11,18));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(12,18));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(13,18));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(14,18));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(15,18));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(16,18));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(17,18));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,18));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,19));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,19));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,20));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,20));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,21));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,21));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,22));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,22));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,23));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,23));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,24));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(19,24));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(20,24));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(21,24));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(22,24));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(23,24));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(24,24));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(25,24));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(26,24));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(27,24));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(28,24));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(29,24));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(30,24));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,24));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,25));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(18,25));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(19,25));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(20,25));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(21,25));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(22,25));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(23,25));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(24,25));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(25,25));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(26,25));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(27,25));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(28,25));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(29,25));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(30,25));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,25));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,26));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(17,26));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(18,26));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(19,26));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(20,26));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(21,26));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(22,26));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(23,26));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(24,26));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(25,26));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,26));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,27));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(16,27));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(17,27));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(18,27));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(19,27));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(20,27));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(21,27));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(22,27));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(23,27));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(24,27));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(25,27));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,27));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,28));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(15,28));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(16,28));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(17,28));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(18,28));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(19,28));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(20,28));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(21,28));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,28));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(0,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(1,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(2,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(3,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(4,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(5,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(6,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(7,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(8,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(9,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(10,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(11,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(12,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(13,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(14,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(15,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(16,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(17,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(18,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(19,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(20,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(21,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(22,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(23,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(24,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(25,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(26,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(27,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(28,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(29,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(30,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(31,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(32,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(33,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(34,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(35,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(36,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(37,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(38,29));
map_add_entity(&GRID_INICIAL, &ENTIDADES_INICIAL, tijolos_create(39,29));
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
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(0,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(1,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(2,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(3,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(4,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(5,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(6,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(7,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(8,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(9,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(10,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(11,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(12,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(13,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(14,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(15,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(16,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(17,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(18,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(19,0));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(0,1));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(0,2));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(0,3));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(0,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(1,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(2,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(3,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(4,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(5,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(6,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(7,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(8,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, metal_create(11,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(12,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(13,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(14,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(15,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(16,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(17,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(18,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(19,4));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(0,5));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(8,5));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(12,5));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(18,5));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(19,5));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(0,6));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(8,6));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, metal_create(9,6));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(12,6));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(19,6));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(0,7));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(8,7));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(12,7));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, metal_create(13,7));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, porta_create(19,7));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(0,8));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(8,8));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, metal_create(11,8));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(12,8));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(13,8));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(14,8));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(15,8));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, porta_create(19,8));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(0,9));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, metal_create(7,9));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(8,9));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(12,9));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(13,9));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(14,9));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(15,9));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(16,9));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, porta_create(19,9));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(0,10));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, metal_create(4,10));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(5,10));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(6,10));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(7,10));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(8,10));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, metal_create(9,10));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(12,10));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(13,10));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(14,10));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, metal_create(19,10));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(0,11));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, metal_create(3,11));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(4,11));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(5,11));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(13,11));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, metal_create(18,11));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(19,11));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(0,12));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(3,12));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(4,12));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, metal_create(10,12));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, metal_create(17,12));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(18,12));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(19,12));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(0,13));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(1,13));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, metal_create(6,13));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, metal_create(10,13));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, metal_create(11,13));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, metal_create(16,13));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(17,13));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(18,13));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(19,13));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(0,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(1,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(2,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(3,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(4,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(5,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(6,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(7,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(8,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(9,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(10,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(11,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(12,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(13,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(14,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(15,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(16,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(17,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(18,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, tijolos_create(19,14));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, bola_create(13,6));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, arma_create(7,8));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, pinwheel_create(10,2, RIGHT, UP));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, scorpion_create(6,3, RIGHT, UP));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, scorpion_create(12,3, RIGHT, UP));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, scorpion_create(18,3, RIGHT, UP));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, pinwheel_create(16,6, RIGHT, UP));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, pinwheel_create(3,8, RIGHT, UP));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, pinwheel_create(6,8, RIGHT, UP));
map_add_entity(&GRID_PUZZLE, &ENTIDADES_PUZZLE, scorpion_create(15,13, RIGHT, UP));
};

typedef enum {
    AREA_INICIAL,
    AREA_PUZZLE,
    AREA_COUNT,
} AreaId;

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
