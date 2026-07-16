/* AUTO-GERADO por generate_entities.py — não edite */
#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "porta_sprites.h"
#include "porta.h"

Animation *porta_get_animation(Entity *e) {
    return &anim_closed_idle;
}

void porta_collision(Entity *self, Entity *other, Grid **g, EntityList *l) {}

/* ── estado: closed ── */
static bool closed_evaluate_entry(Entity *self) { (void)self; return true; }
static bool closed_evaluate_exit (Entity *self) { (void)self; return true; }

static Intent closed_input(Grid **grid, Entity *self) {
    (void)grid; (void)self;
    Intent intent = {0};
    return intent;
}

State porta_closed = {
    .id                  = PORTA_CLOSED,
    .allowed_transitions = {},
    .count               = 0,
    .evaluate_entry      = closed_evaluate_entry,
    .evaluate_exit       = closed_evaluate_exit,
    .decide_input        = closed_input,
};

/* ── estado: open ── */
static bool open_evaluate_entry(Entity *self) { (void)self; return true; }
static bool open_evaluate_exit (Entity *self) { (void)self; return true; }

static Intent open_input(Grid **grid, Entity *self) {
    (void)grid; (void)self;
    Intent intent = {0};
    return intent;
}

State porta_open = {
    .id                  = PORTA_OPEN,
    .allowed_transitions = {},
    .count               = 0,
    .evaluate_entry      = open_evaluate_entry,
    .evaluate_exit       = open_evaluate_exit,
    .decide_input        = open_input,
};

Intent porta_ai(Grid **grid, Entity *self) {
    State *s = self->sm.current_state;
    if (s && s->decide_input) return s->decide_input(grid, self);
    return (Intent){0};
}

static porta_data _porta_data_pool[1024];
static int _porta_data_count = 0;

Entity *porta_create(int x, int y, int array_pos) {
    Entity *e = entity_alloc();
    porta_data *d = &_porta_data_pool[_porta_data_count++];

    *d = (porta_data){
        .array_pos = array_pos,
        .ent_state = PORTA_CLOSED,
    };

    e->position     = (Coordinates){x, y};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_DOOR;
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
    e->sm.current_state   = &porta_closed;
    e->sm.transition      = NULL;
    e->sm.move_transition = NULL;
    e->sm.get_animation   = &porta_get_animation;
    e->on_collision       = porta_collision;
    return e;
}
