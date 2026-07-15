#pragma once
#include "../../../include/entity.h"

extern State bola_normal;

typedef enum {
    BOLA_NORMAL,
} bolaStates;

typedef struct {
    bolaStates ent_state;
} bola_data;

Entity *bola_create(int x, int y);
void bola_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
