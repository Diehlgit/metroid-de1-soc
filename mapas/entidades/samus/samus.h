#pragma once
#include "../../../include/entity.h"
#include "../projetil/projetil.h"

extern State samus_ball;
extern State samus_kneel;
extern State samus_normal;

typedef enum {
    SAMUS_BALL,
    SAMUS_KNEEL,
    SAMUS_NORMAL,
} samusStates;

typedef struct {
    int jumps_remaining;
    int max_jumps;
    bool item_bola;
    bool atirando;
    projetilStates tipo_arma;
    samusStates ent_state;
} samus_data;

Entity *samus_create(int x, int y, int h_dir, int v_dir);
void samus_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
