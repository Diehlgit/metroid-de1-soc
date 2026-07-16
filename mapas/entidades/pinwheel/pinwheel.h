#pragma once
#include "../../../include/entity.h"

extern State pinwheel_normal;

typedef enum {
    PINWHEEL_NORMAL,
} pinwheelStates;

typedef struct {
    pinwheelStates ent_state;
	int ai_timer;
} pinwheel_data;

Entity *pinwheel_create(int x, int y, int h_dir, int v_dir);
void pinwheel_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
