#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "../../entidades/projetil/projetil.h"
#include "../../entidades/samus/samus.h"
#include "arma_sprites.h"
#include "arma.h"

void arma_collision(Entity *self, Entity *other, Grid *g, EntityList *l){
    switch(other->type){
        case(ENTITY_PLAYER):
            samus_data *d = (samus_data *)other->data;
            d->tipo_arma = &projetil_super;
            break;
        default:
            break;
    }
}

State arma_idle = {
    .id                   = ARMA_IDLE,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_idle,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};

static arma_data _arma_data_pool[1024];
static int _arma_data_count = 0;

Entity *arma_create(int x, int y){
    Entity *e = entity_alloc();
    arma_data *d = &_arma_data_pool[_arma_data_count++];

    *d = (arma_data){

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
    e->sm.current_state = &arma_idle;
    e->sm.transition    = NULL;
    e->on_collision     = arma_collision;
    return e;
}
