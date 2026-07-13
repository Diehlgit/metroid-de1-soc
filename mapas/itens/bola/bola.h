#pragma once
#include "../../../include/entity.h"

typedef struct {

} bola_data;

typedef enum {
    BOLA_IDLE,
} bola_state;

extern State bola_idle;

Entity *bola_create(int x, int y);
void bola_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
