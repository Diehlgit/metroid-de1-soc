#pragma once
#include "../../../include/entity.h"

extern State porta_closed;
extern State porta_open;

typedef enum {
    PORTA_CLOSED,
    PORTA_OPEN,
} portaStates;

typedef struct {
    portaStates ent_state;
} porta_data;

Entity *porta_create(int x, int y);
void porta_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
