#pragma once
#include "../../../include/entity.h"

typedef struct {

} chave_data;

typedef enum {
    CHAVE_IDLE,
} chave_state;

extern State chave_idle;

Entity *chave_create(int x, int y);
void chave_collision(Entity *self, Entity *other, Grid *g, EntityList *l);
