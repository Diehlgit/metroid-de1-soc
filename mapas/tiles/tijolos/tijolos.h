#pragma once
#include "../../../include/entity.h"

typedef struct {

} tijolos_data;

Entity *tijolos_create(int x, int y);
void tijolos_collision(Entity *self, Entity *other, Grid *g, EntityList *l);
