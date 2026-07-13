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

typedef enum {
    SAMUS_BALLING,
    SAMUS_HIT,
    SAMUS_IDLE,
    SAMUS_JUMPING,
    SAMUS_KNEELING,
    SAMUS_WALKING,
} samus_state;

extern State samus_balling;
extern State samus_hit;
extern State samus_idle;
extern State samus_jumping;
extern State samus_kneeling;
extern State samus_walking;

Entity *samus_create(int x, int y, int h_dir, int v_dir);
void samus_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
