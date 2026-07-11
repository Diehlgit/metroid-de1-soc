#pragma once
#include "../../../generated/maps.h"
#include "../../../include/entity.h"

typedef struct {
    AreaId destino;
    int    spawn_x;
    int    spawn_y;
} transicao_data;

Entity *transicao_create(int x, int y);
void transicao_collision(Entity *self, Entity *other, Grid *g, EntityList *l);
