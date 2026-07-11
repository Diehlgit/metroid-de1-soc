#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "metal_sprites.h"
#include "metal.h"

void metal_collision(Entity *self, Entity *other, Grid *g, EntityList *l){}

typedef enum {
    IDLE,
} metal_state;

static State idle = {
    .id                    = IDLE,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_idle,
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

    e->position     = (Coordinates){y, x};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_TILE;
    e->orientation  = (Orientation){ RIGHT, UP};
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 16, 16 } },
        .get_cells  = get_rectangle_cells,
    };
    e->data           = d;
    e->sm.current_state = &idle;
    e->sm.transition    = NULL;
    e->on_collision     = metal_collision;
    return e;
};
