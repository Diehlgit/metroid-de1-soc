/* AUTO-GERADO por generate_entities.py — não edite */
#pragma once
#include "../../../include/entity.h"

extern State metal_normal;

typedef enum {
    METAL_NORMAL,
} metalStates;

typedef struct {
    metalStates ent_state;
} metal_data;

Entity *metal_create(int x, int y);
void metal_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
