#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "transicao_sprites.h"
#include "transicao.h"

State transicao_open = {
    .id                    = TRANSICAO_OPEN,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_open,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};

static transicao_data _transicao_data_pool[1024];
static int _transicao_data_count = 0;

Entity *transicao_create(int x, int y, AreaId id, int player_x, int player_y){
    Entity *e = entity_alloc();
    transicao_data *d = &_transicao_data_pool[_transicao_data_count++];

    *d = (transicao_data){
        .destino = id,
        .spawn_x = player_x,
        .spawn_y = player_y,
    };

    e->position     = (Coordinates){x, y};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_TRANSITION;
    e->orientation  = (Orientation){ RIGHT, UP};
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 16, 16 } },
        .get_cells  = get_rectangle_cells,
    };
    e->data           = d;
    e->sm.current_state = &transicao_open;
    e->sm.transition    = NULL;
    e->on_collision     = NULL;
    return e;
};
