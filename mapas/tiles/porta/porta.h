#pragma once
#include "../../../include/entity.h"

typedef struct {

} porta_data;

typedef enum {
    PORTA_IDLE,
} porta_state;

extern State porta_idle;

Entity *porta_create(int x, int y);
void porta_collision(Entity *self, Entity *other, Grid *g, EntityList *l);
