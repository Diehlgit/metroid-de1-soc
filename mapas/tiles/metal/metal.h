#pragma once
#include "../../../include/entity.h"

typedef struct {

} metal_data;

Entity *metal_create(int x, int y);
void metal_collision(Entity *self, Entity *other, Grid *g, EntityList *l);
