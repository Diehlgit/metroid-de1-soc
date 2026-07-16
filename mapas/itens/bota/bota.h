#pragma once
#include "../../../include/entity.h"

extern State bota_normal;

typedef enum {
    BOTA_NORMAL,
} botaStates;

typedef struct {
    botaStates ent_state;
} bota_data;

Entity *bota_create(int x, int y);
void bota_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
