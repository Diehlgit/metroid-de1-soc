#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "porta_sprites.h"
#include "porta.h"

Animation *porta_get_animation(Entity *e){
    return &anim_closed_idle;
}

void porta_collision(Entity *self, Entity *other, Grid **g, EntityList *l){}

State porta_closed = {
    .id                    = PORTA_CLOSED,
    .allowed_transitions  = {},
    .count                = 0,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};
State porta_open = {
    .id                    = PORTA_OPEN,
    .allowed_transitions  = {},
    .count                = 0,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};
static porta_data _porta_data_pool[1024];
static int _porta_data_count = 0;

Entity *porta_create(int x, int y){
    Entity *e = entity_alloc();
    porta_data *d = &_porta_data_pool[_porta_data_count++];

    *d = (porta_data){
    };

    e->position     = (Coordinates){x, y};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_DOOR;
    e->orientation  = (Orientation){ RIGHT, UP};
    e->hp           = 10;
    e->invulnerable = true;
    e->hit          = false;
    e->mv_state     = IDLE;
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 16, 16 } },
        .get_cells  = get_rectangle_cells,
    };
    e->data         = d;
    e->sm.current_state = &porta_closed;
    e->sm.transition    = NULL;
    e->sm.move_transition = NULL;
    e->sm.get_animation = &porta_get_animation;
    e->on_collision     = porta_collision;
    return e;
};
