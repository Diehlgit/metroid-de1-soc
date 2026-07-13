#pragma once
#include "../../../include/entity.h"

typedef struct {
    int dano;
	Entity *shooter;
} projetil_data;

typedef enum {
    PROJETIL_NORMAL,
    PROJETIL_SUPER,
    PROJETIL_VENENO,
} projetil_state;

extern State projetil_normal;
extern State projetil_super;
extern State projetil_veneno;

Entity *projetil_create(Entity *shooter, State *state);
void projetil_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
