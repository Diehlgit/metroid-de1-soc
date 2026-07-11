#pragma once
#include "../../../include/entity.h"

typedef struct {

} morcego_data;

Entity *morcego_create(int x, int y, int h_dir, int v_dir);
void morcego_collision(Entity *self, Entity *other, Grid *g, EntityList *l);
