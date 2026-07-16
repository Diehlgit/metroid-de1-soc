#pragma once
#include "../../../include/entity.h"

extern State scorpion_normal;

typedef enum {
    SCORPION_NORMAL,
} scorpionStates;

typedef struct {
    int ai_timer;
    int chasing;
    scorpionStates ent_state;
} scorpion_data;

Entity *scorpion_create(int x, int y, int h_dir, int v_dir);
void scorpion_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
