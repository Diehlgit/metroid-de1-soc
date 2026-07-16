/* AUTO-GERADO por generate_entities.py — não edite */
#pragma once
#include "../../../include/entity.h"

extern State estalactite_normal;

typedef enum {
    ESTALACTITE_NORMAL,
} estalactiteStates;

typedef struct {
    estalactiteStates ent_state;
} estalactite_data;

Entity *estalactite_create(int x, int y);
void estalactite_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
