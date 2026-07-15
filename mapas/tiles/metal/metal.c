#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "metal_sprites.h"
#include "metal.h"

Animation *metal_get_animation(Entity *e){
    return &anim_normal_idle;
}

void metal_collision(Entity *self, Entity *other, Grid **g, EntityList *l){}

State metal_normal = {
    .id                    = METAL_NORMAL,
    .allowed_transitions  = {},
    .count                = 0,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};
static metal_data _metal_data_pool[1024];
static int _metal_data_count = 0;

Entity *metal_create(int x, int y){
    Entity *e = entity_alloc();
    metal_data *d = &_metal_data_pool[_metal_data_count++];

    *d = (metal_data){
    };

    e->position     = (Coordinates){x, y};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_TILE;
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
    e->sm.current_state = &metal_normal;
    e->sm.transition    = NULL;
    e->sm.move_transition = NULL;
    e->sm.get_animation = &metal_get_animation;
    e->on_collision     = metal_collision;
    return e;
};
