#pragma once
#include "../../../include/entity.h"

typedef struct {

} morcego_data;

typedef enum {
    MORCEGO_IDLE,
} morcego_state;

extern State morcego_idle;

Entity *morcego_create(int x, int y, int h_dir, int v_dir);
void morcego_collision(Entity *self, Entity *other, Grid *g, EntityList *l);
