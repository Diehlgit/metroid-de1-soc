#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "../../entidades/samus/samus.h"
#include "chave_sprites.h"
#include "chave.h"

Animation *chave_get_animation(Entity *e){
    return &anim_normal_idle;
}
void chave_collision(Entity *self, Entity *other, Grid **g, EntityList *l){
    switch(other->type){
        case(ENTITY_PLAYER):
            ((samus_data *)other->data)->keys[((chave_data *)self->data)->array_pos] = true;
            grid_remove_entity(*g, self);
            break;
        default:
            break;
    }
}

State chave_normal = {
    .id                   = CHAVE_NORMAL,
    .allowed_transitions  = {},
    .count                = 0,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};
static chave_data _chave_data_pool[1024];
static int _chave_data_count = 0;

Entity *chave_create(int x, int y, int array_pos){
    Entity *e = entity_alloc();
    chave_data *d = &_chave_data_pool[_chave_data_count++];

    *d = (chave_data){
        .array_pos = array_pos
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
    e->sm.current_state = &chave_normal;
    e->sm.transition    = NULL;
    e->sm.get_animation = &chave_get_animation;
    e->on_collision     = chave_collision;
    return e;
};
