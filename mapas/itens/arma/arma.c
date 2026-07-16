#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "../../entidades/samus/samus.h"
#include "arma_sprites.h"
#include "arma.h"

Animation *arma_get_animation(Entity *e){
    return &anim_normal_idle;
}
void arma_collision(Entity *self, Entity *other, Grid **g, EntityList *l){
    switch(other->type){
        case(ENTITY_PLAYER):
            ((samus_data *)other->data)->tipo_arma = PROJETIL_SUPER;
            grid_remove_entity(*g, self);
            break;
        default:
            break;
    }
}
bool arma_move_transition(Entity *self, MovementState next){
    return true;
}
static Intent gun_input(Grid **grid, Entity *self) {
    Intent intent = {0};
    return intent;
}

State arma_normal = {
    .id                   = ARMA_NORMAL,
    .allowed_transitions  = {},
    .count                = 0,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = &gun_input,
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
    e->sm.current_state = &arma_normal;
    e->sm.transition    = NULL;
    e->sm.get_animation = &arma_get_animation;
    e->sm.move_transition = &arma_move_transition;
    e->on_collision     = arma_collision;
    return e;
};
