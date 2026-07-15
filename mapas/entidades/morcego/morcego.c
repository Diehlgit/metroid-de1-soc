#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "morcego_sprites.h"
#include "morcego.h"

Animation *morcego_get_animation(Entity *e){}

bool morcego_move_transition(Entity *self, MovementState next){
    morcego_data *d = (morcego_data *)self->data;
    MovementState current = self->mv_state;

    switch (next) {
        case IDLE:
            break;

        case MOVE:
            break;

        case AIRBORNE:
            break;

        case HIT:
            break;

        default:
            return false;
    }
    self->mv_state = next;
    return true;
}
void morcego_collision(Entity *self, Entity *other, Grid **g, EntityList *l){}

static bool normal_evaluate_entry(Entity *self) {}
static bool normal_evaluate_exit(Entity *self) {}

static Intent normal_input(Grid **grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
State morcego_normal = {
    .id                   = MORCEGO_NORMAL,
    .allowed_transitions  = {},
    .count                = 0,
    .evaluate_entry       = normal_evaluate_entry,
    .evaluate_exit        = normal_evaluate_exit,
    .decide_input         = normal_input,
};
Intent morcego_ai(Grid **grid, Entity *self) {
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
    e->hp           = 10;
    e->invulnerable = false;
    e->hit          = false;
    e->mv_state     = IDLE;
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 16, 8 } },
        .get_cells  = get_rectangle_cells,
    };
    e->data         = d;
    e->sm.current_state = &morcego_normal;
    e->sm.transition    = generic_transition;
    e->sm.move_transition = &morcego_move_transition;
    e->sm.get_animation = &morcego_get_animation;
    e->on_collision     = morcego_collision;
    return e;
};
