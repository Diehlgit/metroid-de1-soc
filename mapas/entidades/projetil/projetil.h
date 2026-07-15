#pragma once
#include "../../../include/entity.h"

extern State projetil_normal;
extern State projetil_super;
extern State projetil_veneno;

typedef enum {
    PROJETIL_BASE,
    PROJETIL_SUPER,
    PROJETIL_VENENO,
} projetilStates;

typedef struct {
    int dano;
    Entity *shooter;
    projetilStates ent_state;
} projetil_data;

Entity *projetil_create(Entity *shooter, projetilStates tipo);
void projetil_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
