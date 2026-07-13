#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "chave_sprites.h"
#include "chave.h"

void chave_collision(Entity *self, Entity *other, Grid *g, EntityList *l){}

State chave_idle = {
    .id                   = CHAVE_IDLE,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_idle,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};

static chave_data _chave_data_pool[1024];
static int _chave_data_count = 0;

Entity *chave_create(int x, int y){
    Entity *e = entity_alloc();
    chave_data *d = &_chave_data_pool[_chave_data_count++];

    *d = (chave_data){

    };

    e->position     = (Coordinates){x, y};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_ITEM;
    e->orientation  = (Orientation){ RIGHT, UP};
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 16, 32 } },
        .get_cells  = get_rectangle_cells,
    };
    e->data           = d;
    e->sm.current_state = &chave_idle;
    e->sm.transition    = NULL;
    e->on_collision     = chave_collision;
    return e;
};
