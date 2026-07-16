/* AUTO-GERADO por generate_entities.py — não edite */
#pragma once
#include "../../../include/entity.h"

extern State porta_closed;
extern State porta_open;

typedef enum {
    PORTA_CLOSED,
    PORTA_OPEN,
} portaStates;

typedef struct {
    int array_pos;
    portaStates ent_state;
} porta_data;

Entity *porta_create(int x, int y, int array_pos);
void porta_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
