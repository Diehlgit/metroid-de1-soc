#pragma once
#include "../../../include/entity.h"

typedef struct {

} scorpion_data;

typedef enum {
    SCORPION_IDLE,
    SCORPION_SHOOTING,
    SCORPION_WALKING,
} scorpion_state;

extern State scorpion_idle;
extern State scorpion_shooting;
extern State scorpion_walking;

Entity *scorpion_create(int x, int y, int h_dir, int v_dir);
void scorpion_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
