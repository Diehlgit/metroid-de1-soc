#pragma once
#include "../../../include/entity.h"

extern State dragao_normal;

typedef enum {
    DRAGAO_NORMAL,
} dragaoStates;

typedef struct {
    dragaoStates ent_state;
} dragao_data;

Entity *dragao_create(int x, int y, int h_dir, int v_dir);
void dragao_collision(Entity *self, Entity *other, Grid **g, EntityList *l);
