#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "samus.h"

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

static bool balling_evaluate_entry(Entity *self, State *current, State *next) {}
static bool balling_evaluate_exit(Entity *self, State *current, State *next) {}

static bool hit_evaluate_entry(Entity *self, State *current, State *next) {}
static bool hit_evaluate_exit(Entity *self, State *current, State *next) {}

static bool idle_evaluate_entry(Entity *self, State *current, State *next) {}
static bool idle_evaluate_exit(Entity *self, State *current, State *next) {}

static bool jumping_evaluate_entry(Entity *self, State *current, State *next) {}
static bool jumping_evaluate_exit(Entity *self, State *current, State *next) {}

static bool kneeling_evaluate_entry(Entity *self, State *current, State *next) {}
static bool kneeling_evaluate_exit(Entity *self, State *current, State *next) {}

static bool walking_evaluate_entry(Entity *self, State *current, State *next) {}
static bool walking_evaluate_exit(Entity *self, State *current, State *next) {}


static Intent default_input(Entity *self, char key) {
    Intent intent = {0};
    return intent;
}

static Intent balling_input(Entity *self, char key) {
    Intent intent = {0};
    return intent;
}
static Intent hit_input(Entity *self, char key) {
    Intent intent = {0};
    return intent;
}
static Intent idle_input(Entity *self, char key) {
    Intent intent = {0};
    return intent;
}
static Intent jumping_input(Entity *self, char key) {
    Intent intent = {0};
    return intent;
}
static Intent kneeling_input(Entity *self, char key) {
    Intent intent = {0};
    return intent;
}
static Intent walking_input(Entity *self, char key) {
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
};
static State hit = {
    .id                    = HIT,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_hit,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
};
static State idle = {
    .id                    = IDLE,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_idle,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
};
static State jumping = {
    .id                    = JUMPING,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_jumping,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
};
static State kneeling = {
    .id                    = KNEELING,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_kneeling,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
};
static State walking = {
    .id                    = WALKING,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_walking,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
};

Intent samus_ai(Grid *grid, Entity *self) {

    State *s = self->sm.current_state;
    if (s->handle_input)
        return s->handle_input(self);
    return (Intent){0};
}
void samus_collision(Entity *self, Entity *others){}
