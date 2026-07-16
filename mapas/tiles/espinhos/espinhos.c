/* AUTO-GERADO por generate_entities.py — não edite */
#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "../../entidades/samus/samus.h"
#include "espinhos_sprites.h"
#include "espinhos.h"

Animation *espinhos_get_animation(Entity *e) {
    return &anim_normal_idle;
}

bool espinhos_move_transition(Entity *self, MovementState next) {
    espinhos_data *d = (espinhos_data *)self->data;
    (void)d;
    switch (next) {
        case IDLE:
            break;
        case MOVE:
            break;
        case AIRBORNE:
            break;
        case HIT:
            break;
        default: return false;
    }
    self->mv_state = next;
    return true;
}

void espinhos_collision(Entity *self, Entity *other, Grid **g, EntityList *l){
    switch(other->type){
        case(ENTITY_PLAYER):
            other->position.y = ((espinhos_data *)self->data)->spawn_y;
            other->position.x = ((espinhos_data *)self->data)->spawn_x;
            other->hp -= 10;
            break;

        default:
            break;
    }
}

/* ── estado: normal ── */
static bool normal_evaluate_entry(Entity *self) { (void)self; return true; }
static bool normal_evaluate_exit (Entity *self) { (void)self; return true; }

static Intent normal_input(Grid **grid, Entity *self) {
    (void)grid; (void)self;
    Intent intent = {0};
    return intent;
}

State espinhos_normal = {
    .id                  = ESPINHOS_NORMAL,
    .allowed_transitions = {},
    .count               = 0,
    .evaluate_entry      = normal_evaluate_entry,
    .evaluate_exit       = normal_evaluate_exit,
    .decide_input        = normal_input,
};

Intent espinhos_ai(Grid **grid, Entity *self) {
    State *s = self->sm.current_state;
    if (s && s->decide_input) return s->decide_input(grid, self);
    return (Intent){0};
}

static espinhos_data _espinhos_data_pool[1024];
static int _espinhos_data_count = 0;

Entity *espinhos_create(int x, int y, int spawn_x, int spawn_y) {
    Entity *e = entity_alloc();
    espinhos_data *d = &_espinhos_data_pool[_espinhos_data_count++];

    *d = (espinhos_data){
        .spawn_x = spawn_x,
        .spawn_y = spawn_y,
        .ent_state = ESPINHOS_NORMAL,
    };

    e->position     = (Coordinates){x, y};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_TRANSITION;
    e->orientation  = (Orientation){ RIGHT, UP };
    e->hp           = 10;
    e->invulnerable = false;
    e->hit          = false;
    e->mv_state     = IDLE;
    e->hitbox       = (Hitbox){
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 16 } },
        .get_cells = get_rectangle_cells,
    };
    e->data               = d;
    e->sm.current_state   = &espinhos_normal;
    e->sm.transition      = NULL;
    e->sm.move_transition = &espinhos_move_transition;
    e->sm.get_animation   = &espinhos_get_animation;
    e->on_collision       = espinhos_collision;
    return e;
}
