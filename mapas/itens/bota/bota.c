#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "../../entidades/samus/samus.h"
#include "bota_sprites.h"
#include "bota.h"

Animation *bota_get_animation(Entity *e){
    return &anim_normal_idle;
}
void bota_collision(Entity *self, Entity *other, Grid **g, EntityList *l){
    switch(other->type){
        case(ENTITY_PLAYER):
            ((samus_data *)other->data)->max_jumps = 2;
            grid_remove_entity(*g, self);
            break;
        default:
            break;
    }
}

State bota_normal = {
    .id                   = BOTA_NORMAL,
    .allowed_transitions  = {},
    .count                = 0,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};
static bota_data _bola_data_pool[1024];
static int _bola_data_count = 0;

Entity *bota_create(int x, int y){
    Entity *e = entity_alloc();
    bota_data *d = &_bola_data_pool[_bola_data_count++];

    *d = (bota_data){
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
    e->sm.current_state = &bota_normal;
    e->sm.transition    = NULL;
    e->sm.get_animation = &bota_get_animation;
    e->on_collision     = bota_collision;
    return e;
};
