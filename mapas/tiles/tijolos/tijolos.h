#pragma once
#include "../../../include/entity.h"

typedef struct {

} tijolos_data;

typedef enum {
    TIJOLOS_IDLE,
} tijolos_state;

extern State tijolos_idle;

Entity *tijolos_create(int x, int y);
void tijolos_collision(Entity *self, Entity *other, Grid *g, EntityList *l);
