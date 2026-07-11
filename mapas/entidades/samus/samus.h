#pragma once
#include "../../../include/entity.h"

typedef struct {
    int  hp;
    int  max_jumps;
    int  jumps_remaining;
    int  dano_arma;
    bool item_bola;
    bool item_arma;
    bool invulnerable;
} samus_data;

Entity *samus_create(int x, int y, int h_dir, int v_dir);
void samus_collision(Entity *self, Entity *other, Grid *g, EntityList *l);
