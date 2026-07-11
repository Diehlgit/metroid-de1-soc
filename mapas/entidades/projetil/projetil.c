#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "../samus/samus.h"
#include "projetil_sprites.h"
#include "projetil.h"

void projetil_collision(Entity *self, Entity *other, Grid *g, EntityList *l){
    projetil_data *pd = (projetil_data *)self->data;

    switch(other->type){
        case ENTITY_PLAYER:
            samus_data *sd = (samus_data *)other->data;
            sd->hp -= pd->dano;
            other->sm.transition(other, &hit);
            self->should_destroy = 1;

        default:
            self->should_destroy = 1;
    }
}

typedef enum {
    NORMAL,
    SUPER,
    VENENO,
} projetil_state;

static bool normal_evaluate_entry(Entity *self, State *next) {}
static bool normal_evaluate_exit(Entity *self, State *next) {}

static bool super_evaluate_entry(Entity *self, State *next) {}
static bool super_evaluate_exit(Entity *self, State *next) {}

static bool veneno_evaluate_entry(Entity *self, State *next) {}
static bool veneno_evaluate_exit(Entity *self, State *next) {}

static Intent normal_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
static Intent super_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
static Intent veneno_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
static State normal = {
    .id                    = NORMAL,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_normal,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};
static State super = {
    .id                    = SUPER,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_super,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};
static State veneno = {
    .id                    = VENENO,
    .allowed_transitions  = {},
    .count                = 0,
    .animation            = &anim_veneno,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = NULL,
};
Intent projetil_ai(Grid *grid, Entity *self) {
    State *s = self->sm.current_state;
    if (s->decide_input)
        return s->decide_input(grid, self);
    return (Intent){0};
}

static projetil_data _projetil_data_pool[32];
static int _projetil_data_count = 0;

Entity *projetil_create(Entity *shooter, State *state){
    Entity *e = entity_alloc();
    projetil_data *d = &_projetil_data_pool[_projetil_data_count++];

    *d = (projetil_data){};

    switch(state->id){
        case NORMAL:
            d->dano = 2;
            break;
        case SUPER:
            d->dano = 4;
            break;
        case VENENO:
            d->dano = 4;
            break;
    }

    int shot_x;
    if(shooter->orientation.h_direction == RIGHT){
        int shot_x = shooter->position.x + shooter->hitbox.data.rectangle.width;
    } else {
        int shot_x = shooter->position.x + shooter->hitbox.data.rectangle.width;
    }

    int shot_y;
    if(shooter->orientation.v_direction == UP){
        int shot_y = shooter->position.y + (shooter->hitbox.data.rectangle.height/4);
    } else {
        int shot_y = shooter->position.x - (shooter->hitbox.data.rectangle.height/4);
    }

    e->position     = (Coordinates){shot_y, shot_x};
    e->velocity     = (Coordinates){0, 0};

    if(shooter->orientation.h_direction == RIGHT){
        e->velocity.x = 5;
    } else  {
        e->velocity.x = -5;
    }


    e->type         = ENTITY_PROJECTILE;
    e->orientation  = (Orientation){ shooter->orientation.h_direction, shooter->orientation.v_direction};
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 4, 4 } },
        .get_cells  = get_rectangle_cells,
    };
    e->data           = d;
    e->sm.current_state = state;
    e->sm.transition    = NULL;
    e->on_collision     = projetil_collision;
    return e;
};
