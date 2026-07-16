/* AUTO-GERADO por generate_entities.py — não edite */
#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "estalactite_sprites.h"
#include "estalactite.h"

Animation *estalactite_get_animation(Entity *e) {
    return &anim_normal_idle;
}

bool estalactite_move_transition(Entity *self, MovementState next) {
    estalactite_data *d = (estalactite_data *)self->data;
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

void estalactite_collision(Entity *self, Entity *other, Grid **g, EntityList *l) {
    (void)self; (void)other; (void)g; (void)l;
}

/* ── estado: normal ── */
static bool normal_evaluate_entry(Entity *self) { (void)self; return true; }
static bool normal_evaluate_exit (Entity *self) { (void)self; return true; }

static Intent normal_input(Grid **grid, Entity *self) {
    (void)grid; (void)self;
    Intent intent = {0};
    return intent;
}

State estalactite_normal = {
    .id                  = ESTALACTITE_NORMAL,
    .allowed_transitions = {},
    .count               = 0,
    .evaluate_entry      = normal_evaluate_entry,
    .evaluate_exit       = normal_evaluate_exit,
    .decide_input        = normal_input,
};

Intent estalactite_ai(Grid **grid, Entity *self) {
    State *s = self->sm.current_state;
    if (s && s->decide_input) return s->decide_input(grid, self);
    return (Intent){0};
}

static estalactite_data _estalactite_data_pool[1024];
static int _estalactite_data_count = 0;

Entity *estalactite_create(int x, int y) {
    Entity *e = entity_alloc();
    estalactite_data *d = &_estalactite_data_pool[_estalactite_data_count++];

    *d = (estalactite_data){
        .ent_state = ESTALACTITE_NORMAL,
    };

    e->position     = (Coordinates){x, y};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_TILE;
    e->orientation  = (Orientation){ RIGHT, UP };
    e->hp           = 10;
    e->invulnerable = false;
    e->hit          = false;
    e->mv_state     = IDLE;
    e->hitbox       = (Hitbox){
        .type      = HITBOX_RECTANGLE,
        .data      = { .rectangle={ 16, 32 } },
        .get_cells = get_rectangle_cells,
    };
    e->data               = d;
    e->sm.current_state   = &estalactite_normal;
    e->sm.transition      = NULL;
    e->sm.move_transition = &estalactite_move_transition;
    e->sm.get_animation   = &estalactite_get_animation;
    e->on_collision       = estalactite_collision;
    return e;
}
