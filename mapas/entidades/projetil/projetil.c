#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "projetil.h"

void projetil_collision(Entity *self, Entity *others){}

typedef enum {
    MOVING,
} projetil_state;

static State moving;

static bool moving_evaluate_entry(Entity *self, State *next) {}
static bool moving_evaluate_exit(Entity *self, State *next) {}


static Intent default_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}

static Intent moving_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}

static State moving = {
    .id                    = MOVING,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_moving,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};

Intent projetil_ai(Grid *grid, Entity *self) {
    State *s = self->sm.current_state;
    if (s->decide_input)
        return s->decide_input(grid, self);
    return (Intent){0};
}

const Entity *projetil_create(int x, int y, int h_dir, int v_dir){
    Entity *e = entity_alloc();
    e->position     = (Coordinates){y, x};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_PROJECTILE;
    e->orientation  = (Orientation){ h_dir, v_dir};
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 4, 4 } },
        .get_cells  = get_rectangle_cells,
    };
    e->sm.current_state = &moving;
    e->sm.transition    = generic_transition;
    e->on_collision     = projetil_collision;
    return e;
};
