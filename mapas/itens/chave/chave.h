#pragma once
#include "../../../include/entity.h"

extern State chave_normal;

typedef enum {
    CHAVE_NORMAL,
} chaveStates;

typedef struct {
    chaveStates ent_state;
} chave_data;

Entity *chave_create(int x, int y);
void chave_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
