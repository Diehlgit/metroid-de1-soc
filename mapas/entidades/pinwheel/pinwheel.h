#pragma once
#include "../../../include/entity.h"

typedef struct {

} pinwheel_data;

typedef enum {
    PINWHEEL_IDLE,
    PINWHEEL_WALKING,
} pinwheel_state;

extern State pinwheel_idle;
extern State pinwheel_walking;

Entity *pinwheel_create(int x, int y, int h_dir, int v_dir);
void pinwheel_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
