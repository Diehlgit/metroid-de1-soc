#include "../../../include/entity.h"
#include "arma.h"

void arma_collision(Entity *self, Entity *others){}

typedef enum {
    IDLE,
} arma_state;

static State idle = {
    .id                    = IDLE,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_idle,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};

const Entity *arma_create(int x, int y){
    Entity *e = entity_alloc();
    e->position     = (Coordinates){y, x};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_ITEM;
    e->orientation  = (Orientation){ RIGHT, UP};
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 16, 32 } },
        .get_cells  = get_rectangle_cells,
    };
    e->sm.current_state = &idle;
    e->sm.transition    = NULL;
    e->on_collision     = arma_collision;
    return e;
};
