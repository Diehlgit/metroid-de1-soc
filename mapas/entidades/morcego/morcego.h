#pragma once
#include "../../../include/entity.h"

extern State morcego_normal;

typedef enum {
    MORCEGO_NORMAL,
} morcegoStates;

typedef struct {
    morcegoStates ent_state;
} morcego_data;

Entity *morcego_create(int x, int y, int h_dir, int v_dir);
void morcego_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
