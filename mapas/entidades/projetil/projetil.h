#pragma once
#include "../../../include/entity.h"

typedef struct {
    int dano;
} projetil_data;

static State normal;
static State super;
static State veneno;

Entity *projetil_create(Entity *shooter, State *state);
void projetil_collision(Entity *self, Entity *other, Grid *g, EntityList *l);
