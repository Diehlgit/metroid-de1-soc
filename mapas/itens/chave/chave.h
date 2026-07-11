#pragma once
#include "../../../include/entity.h"

typedef struct {

} chave_data;

Entity *chave_create(int x, int y);
void chave_collision(Entity *self, Entity *other, Grid *g, EntityList *l);
