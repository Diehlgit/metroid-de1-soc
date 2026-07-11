#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "porta_sprites.h"
#include "porta.h"

void porta_collision(Entity *self, Entity *other, Grid *g, EntityList *l){}

typedef enum {
    IDLE,
} porta_state;

static State idle = {
    .id                    = IDLE,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_idle,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};

static porta_data _porta_data_pool[1024];
static int _porta_data_count = 0;

Entity *porta_create(int x, int y){
    Entity *e = entity_alloc();
    porta_data *d = &_porta_data_pool[_porta_data_count++];

    *d = (porta_data){

    };

    e->position     = (Coordinates){y, x};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_DOOR;
    e->orientation  = (Orientation){ RIGHT, UP};
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 16, 16 } },
        .get_cells  = get_rectangle_cells,
    };
    e->data           = d;
    e->sm.current_state = &idle;
    e->sm.transition    = NULL;
    e->on_collision     = porta_collision;
    return e;
};
