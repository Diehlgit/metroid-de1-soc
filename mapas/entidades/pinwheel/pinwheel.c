#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "pinwheel_sprites.h"
#include "pinwheel.h"

void pinwheel_collision(Entity *self, Entity *other, Grid **g, EntityList *l){}

static bool idle_evaluate_entry(Entity *self, State *next) {}
static bool idle_evaluate_exit(Entity *self, State *next) {}

static bool walking_evaluate_entry(Entity *self, State *next) {}
static bool walking_evaluate_exit(Entity *self, State *next) {}

static Intent idle_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
static Intent walking_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
State pinwheel_idle = {
    .id                    = PINWHEEL_IDLE,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_idle,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};
State pinwheel_walking = {
    .id                    = PINWHEEL_WALKING,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_walking,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};
Intent pinwheel_ai(Grid *grid, Entity *self) {
    State *s = self->sm.current_state;
    if (s->decide_input)
        return s->decide_input(grid, self);
    return (Intent){0};
}

static pinwheel_data _pinwheel_data_pool[1024];
static int _pinwheel_data_count = 0;

Entity *pinwheel_create(int x, int y, int h_dir, int v_dir){
    Entity *e = entity_alloc();
    pinwheel_data *d = &_pinwheel_data_pool[_pinwheel_data_count++];

    *d = (pinwheel_data){

    };

    e->position     = (Coordinates){x, y};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_ENEMY;
    e->orientation  = (Orientation){ h_dir, v_dir};
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 32, 32 } },
        .get_cells  = get_rectangle_cells,
    };
    e->data           = d;
    e->sm.current_state = &pinwheel_idle;
    e->sm.transition    = generic_transition;
    e->on_collision     = pinwheel_collision;
    return e;
};
