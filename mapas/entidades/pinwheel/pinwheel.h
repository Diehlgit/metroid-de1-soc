#pragma once
#include "../../../include/entity.h"

typedef struct {

} pinwheel_data;

Entity *pinwheel_create(int x, int y, int h_dir, int v_dir);
void pinwheel_collision(Entity *self, Entity *other, Grid *g, EntityList *l);
