#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "voador.h"

typedef enum {
    IDLE,
} voador_state;

static State idle;

static bool idle_evaluate_entry(Entity *self, State *current, State *next) {}
static bool idle_evaluate_exit(Entity *self, State *current, State *next) {}


static Intent default_input(Entity *self, char key) {
    Intent intent = {0};
    return intent;
}

static Intent idle_input(Entity *self, char key) {
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
};

Intent voador_ai(Grid *grid, Entity *self) {

    State *s = self->sm.current_state;
    if (s->handle_input)
        return s->handle_input(self);
    return (Intent){0};
}
void voador_collision(Entity *self, Entity *others){}
