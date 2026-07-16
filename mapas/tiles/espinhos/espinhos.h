/* AUTO-GERADO por generate_entities.py — não edite */
#pragma once
#include "../../../include/entity.h"

extern State espinhos_normal;

typedef enum {
    ESPINHOS_NORMAL,
} espinhosStates;

typedef struct {
    int spawn_x;
    int spawn_y;
    espinhosStates ent_state;
} espinhos_data;

Entity *espinhos_create(int x, int y, int spawn_x, int spawn_y);
void espinhos_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
