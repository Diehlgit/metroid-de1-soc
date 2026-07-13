#pragma once
#include "../../../include/entity.h"

typedef struct {

} arma_data;

typedef enum {
    ARMA_IDLE,
} arma_state;

extern State arma_idle;

Entity *arma_create(int x, int y);
void arma_collision(Entity *self, Entity *other, Grid *g, EntityList *l);
