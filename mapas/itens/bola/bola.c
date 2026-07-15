#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "../../entidades/samus/samus.h"
#include "bola_sprites.h"
#include "bola.h"

Animation *bola_get_animation(Entity *e){
    return &anim_bola;
}
void bola_collision(Entity *self, Entity *other, Grid **g, EntityList *l){
    switch(other->type){
        case(ENTITY_PLAYER):
            ((samus_data *)other->data)->item_bola = true;
            grid_remove_entity(*g, self);
            break;
        default:
            break;
    }
}

State bola_normal = {
    .id                   = BOLA_NORMAL,
    .allowed_transitions  = {},
    .count                = 0,
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
    e->orientation  = (Orientation){ RIGHT, UP };
    e->hp           = 10;
    e->invulnerable = true;
    e->hit          = false;
    e->mv_state     = IDLE;
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 16, 32 } },
        .get_cells  = get_rectangle_cells,
    };
    e->data         = d;
    e->sm.current_state = &bola_normal;
    e->sm.transition    = NULL;
    e->sm.get_animation = &bola_get_animation;
    e->on_collision     = bola_collision;
    return e;
};
