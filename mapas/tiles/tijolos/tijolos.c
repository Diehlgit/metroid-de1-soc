#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "tijolos_sprites.h"
#include "tijolos.h"

State tijolos_idle = {
    .id                    = TIJOLOS_IDLE,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_idle,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};

static tijolos_data _tijolos_data_pool[1024];
static int _tijolos_data_count = 0;

Entity *tijolos_create(int x, int y){
    Entity *e = entity_alloc();
    tijolos_data *d = &_tijolos_data_pool[_tijolos_data_count++];

    *d = (tijolos_data){

    };

    e->position     = (Coordinates){x, y};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_TILE;
    e->orientation  = (Orientation){ RIGHT, UP};
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 16, 16 } },
        .get_cells  = get_rectangle_cells,
    };
    e->data           = d;
    e->sm.current_state = &tijolos_idle;
    e->sm.transition    = NULL;
    e->on_collision     = NULL;
    return e;
};
