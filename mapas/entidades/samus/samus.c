#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "samus_sprites.h"
#include "samus.h"

void samus_collision(Entity *self, Entity *other, Grid *g, EntityList *l){}

typedef enum {
    BALLING,
    HIT,
    IDLE,
    JUMPING,
    KNEELING,
    WALKING,
} samus_state;

static State balling;
static State hit;
static State idle;
static State jumping;
static State kneeling;
static State walking;

static bool balling_evaluate_entry(Entity *self, State *next) {}
static bool balling_evaluate_exit(Entity *self, State *next) {}

static bool hit_evaluate_entry(Entity *self, State *next) {}
static bool hit_evaluate_exit(Entity *self, State *next) {}

static bool idle_evaluate_entry(Entity *self, State *next) {}
static bool idle_evaluate_exit(Entity *self, State *next) {}

static bool jumping_evaluate_entry(Entity *self, State *next) {}
static bool jumping_evaluate_exit(Entity *self, State *next) {}

static bool kneeling_evaluate_entry(Entity *self, State *next) {}
static bool kneeling_evaluate_exit(Entity *self, State *next) {}

static bool walking_evaluate_entry(Entity *self, State *next) {}
static bool walking_evaluate_exit(Entity *self, State *next) {}

static Intent balling_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
static Intent hit_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
static Intent idle_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
static Intent jumping_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
static Intent kneeling_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
static Intent walking_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
static State balling = {
    .id                    = BALLING,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_balling,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};
static State hit = {
    .id                    = HIT,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_hit,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};
static State idle = {
    .id                    = IDLE,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_idle,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};
static State jumping = {
    .id                    = JUMPING,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_jumping,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};
static State kneeling = {
    .id                    = KNEELING,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_kneeling,
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
Intent samus_ai(Grid *grid, Entity *self) {
    State *s = self->sm.current_state;
    if (s->decide_input)
        return s->decide_input(grid, self);
    return (Intent){0};
}

static samus_data _samus_data_pool[];
static int _samus_data_count = 0;

Entity *samus_create(int x, int y, int h_dir, int v_dir){
    Entity *e = entity_alloc();
    samus_data *d = &_samus_data_pool[_samus_data_count++];

    *d = (samus_data){

    };

    e->position     = (Coordinates){y, x};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_PLAYER;
    e->orientation  = (Orientation){ h_dir, v_dir};
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 16, 32 } },
        .get_cells  = get_rectangle_cells,
    };
    e->data           = d;
    e->sm.current_state = &idle;
    e->sm.transition    = generic_transition;
    e->on_collision     = samus_collision;
    return e;
};
