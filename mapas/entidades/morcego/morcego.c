#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "morcego_sprites.h"
#include "morcego.h"

void morcego_collision(Entity *self, Entity *other, Grid *g, EntityList *l){}

static bool idle_evaluate_entry(Entity *self, State *next) {}
static bool idle_evaluate_exit(Entity *self, State *next) {}

static Intent idle_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
State morcego_idle = {
    .id                    = MORCEGO_IDLE,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_idle,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};
Intent morcego_ai(Grid *grid, Entity *self) {
    State *s = self->sm.current_state;
    if (s->decide_input)
        return s->decide_input(grid, self);
    return (Intent){0};
}

static morcego_data _morcego_data_pool[1024];
static int _morcego_data_count = 0;

Entity *morcego_create(int x, int y, int h_dir, int v_dir){
    Entity *e = entity_alloc();
    morcego_data *d = &_morcego_data_pool[_morcego_data_count++];

    *d = (morcego_data){

    };

    e->position     = (Coordinates){x, y};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_ENEMY;
    e->orientation  = (Orientation){ h_dir, v_dir};
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 16, 8 } },
        .get_cells  = get_rectangle_cells,
    };
    e->data           = d;
    e->sm.current_state = &morcego_idle;
    e->sm.transition    = generic_transition;
    e->on_collision     = morcego_collision;
    return e;
};
