#pragma once
#include "../../../include/area_id.h"
#include "../../../include/entity.h"

extern State transicao_open;

typedef enum {
    TRANSICAO_OPEN,
} transicaoStates;

typedef struct {
    AreaId destino;
    int spawn_x;
    int spawn_y;
    transicaoStates ent_state;
} transicao_data;

Entity *transicao_create(int x, int y, AreaId destino, int spawn_x, int spawn_y);
void transicao_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
