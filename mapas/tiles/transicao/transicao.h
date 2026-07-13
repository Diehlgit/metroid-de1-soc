#pragma once
#include "../../../include/area_id.h"
#include "../../../include/entity.h"

typedef struct {
    AreaId destino;
    int    spawn_x;
    int    spawn_y;
} transicao_data;

typedef enum {
    TRANSICAO_OPEN,
} transicao_state;

extern State transicao_open;

Entity *transicao_create(int x, int y, AreaId id, int player_x, int player_y);
void transicao_collision(Entity *self, Entity *other, Grid *g, EntityList *l);
