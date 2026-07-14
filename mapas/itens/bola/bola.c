#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "../../entidades/samus/samus.h"
#include "bola_sprites.h"
#include "bola.h"

void bola_collision(Entity *self, Entity *other, Grid **g, EntityList *l){
    switch(other->type){
        case(ENTITY_PLAYER):
            {samus_data *d = (samus_data *)other->data;
            d->item_bola = true;
            self->should_destroy = 1;
            break;}
        default:
            break;
    }
}

State bola_idle = {
    .id                   = BOLA_IDLE,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_idle,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};

static bola_data _bola_data_pool[1024];
static int _bola_data_count = 0;

Entity *bola_create(int x, int y){
    Entity *e = entity_alloc();
    bola_data *d = &_bola_data_pool[_bola_data_count++];

    *d = (bola_data){

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
    e->sm.current_state = &bola_idle;
    e->sm.transition    = NULL;
    e->on_collision     = bola_collision;
    return e;
};
