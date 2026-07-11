#pragma once
#include "../../../include/entity.h"

typedef struct {

} scorpion_data;

Entity *scorpion_create(int x, int y, int h_dir, int v_dir);
void scorpion_collision(Entity *self, Entity *other, Grid *g, EntityList *l);
