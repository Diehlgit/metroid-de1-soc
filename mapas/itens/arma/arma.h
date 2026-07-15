#pragma once
#include "../../../include/entity.h"

extern State arma_normal;

typedef enum {
    ARMA_NORMAL,
} armaStates;

typedef struct {
    armaStates ent_state;
} arma_data;

Entity *arma_create(int x, int y);
void arma_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
