#pragma once
#include "../../../include/entity.h"

typedef struct {
    int    hp;
    int    max_jumps;
    int    jumps_remaining;
    State* tipo_arma;
    bool   item_bola;
    bool   invulnerable;
} samus_data;

static State balling;
static State hit;
static State idle;
static State jumping;
static State kneeling;
static State walking;

Entity *samus_create(int x, int y, int h_dir, int v_dir);
void samus_collision(Entity *self, Entity *other, Grid *g, EntityList *l);
