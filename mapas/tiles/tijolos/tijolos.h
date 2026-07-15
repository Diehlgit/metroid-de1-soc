#pragma once
#include "../../../include/entity.h"

extern State tijolos_normal;

typedef enum {
    TIJOLOS_NORMAL,
} tijolosStates;

typedef struct {
    tijolosStates ent_state;
} tijolos_data;

Entity *tijolos_create(int x, int y);
void tijolos_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
