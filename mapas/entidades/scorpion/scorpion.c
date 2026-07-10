#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "scorpion.h"

void scorpion_collision(Entity *self, Entity *others){}

typedef enum {
    IDLE,
    SHOOTING,
    WALKING,
} scorpion_state;

static State idle;
static State shooting;
static State walking;

static bool idle_evaluate_entry(Entity *self, State *next) {}
static bool idle_evaluate_exit(Entity *self, State *next) {}

static bool shooting_evaluate_entry(Entity *self, State *next) {}
static bool shooting_evaluate_exit(Entity *self, State *next) {}

static bool walking_evaluate_entry(Entity *self, State *next) {}
static bool walking_evaluate_exit(Entity *self, State *next) {}


static Intent default_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}

static Intent idle_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
static Intent shooting_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
static Intent walking_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}

static State idle = {
    .id                    = IDLE,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_idle,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};
static State shooting = {
    .id                    = SHOOTING,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_shooting,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};
static State walking = {
    .id                    = WALKING,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_walking,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};

Intent scorpion_ai(Grid *grid, Entity *self) {
    State *s = self->sm.current_state;
    if (s->decide_input)
        return s->decide_input(grid, self);
    return (Intent){0};
}

const Entity *scorpion_create(int x, int y, int h_dir, int v_dir){
    Entity *e = entity_alloc();
    e->position     = (Coordinates){y, x};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_ENEMY;
    e->orientation  = (Orientation){ h_dir, v_dir};
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 32, 16 } },
        .get_cells  = get_rectangle_cells,
    };
    e->sm.current_state = &idle;
    e->sm.transition    = generic_transition;
    e->on_collision     = scorpion_collision;
    return e;
};
