#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "../../../include/uart.h"
#include "../../../include/switch.h"
#include "../../../generated/entidades.h"
#include "../../tiles/transicao/transicao.h"
#include "../projetil/projetil.h"
#include "samus_sprites.h"
#include "samus.h"
#include <stdio.h>

void samus_collision(Entity *self, Entity *other, Grid **g, EntityList *l){
    switch(other->type){
        case(ENTITY_TRANSITION):
            transicao_data *d = (transicao_data *)other->data;
            AreaId id = d->destino;
            *g = switch_area(id, self, l);

            self->position.x = d->spawn_x;
            self->position.y = d->spawn_y;
            break;

        default:
            break;
    }
}

bool evaluate_jump_condition(Entity *self){
    samus_data *d = (samus_data *)self->data;
    if(self->sm.current_state->id == SAMUS_JUMPING){
        if(d->jumps_remaining <= 0){
            return false;
        }
    }
    d->jumps_remaining -= 1;
    return true;
}

static bool balling_evaluate_entry(Entity *self, State *next) {
    samus_data *d = (samus_data *)self->data;
    printf("item_bola = %d\n", ((samus_data *)self->data)->item_bola);
    if(d->item_bola != false){
        self->hitbox.data.rectangle.height  = 16;
        self->position.y += 16;
        return true;
    }
    return false;
}
static bool balling_evaluate_exit(Entity *self, State *next) {
    self->hitbox.data.rectangle.height  = 32;
    self->position.y -= 16;
    return true;
}

static bool hit_evaluate_entry(Entity *self, State *next) {
    samus_data *d = (samus_data *)self->data;
    d->item_bola = false;
    d->tipo_arma = &projetil_normal;
    d->invulnerable = true;
    return true;
}
static bool hit_evaluate_exit(Entity *self, State *next) {
    samus_data *d = (samus_data *)self->data;
    d->invulnerable = false;
    return true;
}

static bool idle_evaluate_entry(Entity *self, State *next) {}
static bool idle_evaluate_exit(Entity *self, State *next) {}


static bool kneeling_evaluate_entry(Entity *self, State *next) {
    self->hitbox.data.rectangle.height = 16;
    self->position.y += 16;
    return true;
}
static bool kneeling_evaluate_exit(Entity *self, State *next) {
    self->hitbox.data.rectangle.height = 32;
    self->position.y -= 16;
    return true;
}

static bool walking_evaluate_entry(Entity *self, State *next) {}
static bool walking_evaluate_exit(Entity *self, State *next) {}

static Intent default_input(Grid **grid, Entity *self) {
    Intent intent = {0};
    char key = uart_read_char();
    if (key == 'w') {
        if( evaluate_jump_condition(self)) {
            self->sm.transition(self, &samus_jumping);
            intent.ay = -16;
        }
    }
    if (key == 'a') { intent.ax = -2;  self->orientation.h_direction = LEFT;  self->sm.transition(self, &samus_walking); }
    if (key == 's') { self->sm.transition(self, &samus_kneeling); }
    if (key == 'd') { intent.ax =  2;  self->orientation.h_direction = RIGHT; self->sm.transition(self, &samus_walking); }
    if (key == 'e') { self->sm.transition(self, &samus_balling); }
    if (key == 'f') {
        samus_data *d = (samus_data *)self->data;
        Entity *p = projetil_create(self, d->tipo_arma);
        //printf("%p\n", (void *)p);
        intent.spawns[intent.spawn_count++] = p;
    }
    if (!key)        self->sm.transition(self, &samus_idle);
    return intent;
}

static Intent balling_input(Grid **grid, Entity *self) {
    Intent intent = {0};
    char key = uart_read_char();
    if (key == 'w') {
        if( evaluate_jump_condition(self)) {
            intent.ay = -16;
        }
    }
    if (key == 'a') { intent.ax = -2; self->orientation.h_direction = LEFT; }
    if (key == 'd') { intent.ax =  2; self->orientation.h_direction = RIGHT; }
    if (key == 'e') { self->sm.transition(self, &samus_idle); }
    return intent;
}
static Intent hit_input(Grid **grid, Entity *self) {
    Intent intent = {0};
    return intent;
}

static Intent jumping_input(Grid **grid, Entity *self) {
    Intent intent = {0};
    char key = uart_read_char();
    if (key == 'w') {
        if( evaluate_jump_condition(self)) {
            self->sm.transition(self, &samus_jumping);
            intent.ay = -16;
        }
    }
    if (key == 'a') { intent.ax = -2;  self->orientation.h_direction = LEFT; }
    if (key == 'd') { intent.ax =  2;  self->orientation.h_direction = RIGHT; }
    if (key == 'e') { self->sm.transition(self, &samus_balling); }
    if (key == 'f') {
        samus_data *d = (samus_data *)self->data;
        intent.spawns[intent.spawn_count++] = projetil_create(self, d->tipo_arma);
    }
    if (!key)        self->sm.transition(self, &samus_idle);
    return intent;
}
static Intent kneeling_input(Grid **grid, Entity *self) {
    Intent intent = {0};
    char key = uart_read_char();
    if (key == 'f') {
        samus_data *d = (samus_data *)self->data;
        intent.spawns[intent.spawn_count++] = projetil_create(self, d->tipo_arma);
    }
    if (key == 's') { self->sm.transition(self, &samus_idle); }
    return intent;
}
static Intent walking_input(Grid **grid, Entity *self) {
    Intent intent = {0};
    char key = uart_read_char();
    if (key == 'w') {
        if(self->sm.transition(self, &samus_jumping)){
            intent.ay = -16;
        }
    }
    if (key == 'a') { intent.ax = -2;  self->orientation.h_direction = LEFT; }
    if (key == 'd') { intent.ax =  2;  self->orientation.h_direction = RIGHT; }
    if (key == 'e') { self->sm.transition(self, &samus_balling); }
    if (key == 'f') {
        samus_data *d = (samus_data *)self->data;
        intent.spawns[intent.spawn_count++] = projetil_create(self, d->tipo_arma);
    }
    if (!key)        self->sm.transition(self, &samus_idle);
    return intent;
}

State samus_balling = {
    .id                   = SAMUS_BALLING,
    .allowed_transitions  = {&samus_idle, &samus_hit},
    .count                = 2,
    .animation            = &anim_balling,
    .evaluate_entry       = &balling_evaluate_entry,
    .evaluate_exit        = &balling_evaluate_exit,
    .decide_input         = &balling_input,
};
State samus_hit = {
    .id                   = SAMUS_HIT,
    .allowed_transitions  = {&samus_idle},
    .count                = 1,
    .animation            = &anim_hit,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = &hit_input,
};
State samus_idle = {
    .id                   = SAMUS_IDLE,
    .allowed_transitions  = { &samus_walking, &samus_kneeling, &samus_jumping, &samus_balling, &samus_hit },
    .count                = 5,
    .animation            = &anim_idle,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = &default_input,
};
State samus_jumping = {
    .id                    = SAMUS_JUMPING,
    .allowed_transitions  = {&samus_idle, &samus_hit, &samus_balling, &samus_jumping},
    .count                = 4,
    .animation            = &anim_jumping,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = &jumping_input,
};
State samus_kneeling = {
    .id                    = SAMUS_KNEELING,
    .allowed_transitions  = { &samus_idle },
    .count                = 1,
    .animation            = &anim_kneeling,
    .evaluate_entry       = &kneeling_evaluate_entry,
    .evaluate_exit        = &kneeling_evaluate_exit,
    .decide_input         = &kneeling_input,
};
State samus_walking = {
    .id                    = SAMUS_WALKING,
    .allowed_transitions  = {&samus_idle, &samus_hit, &samus_balling, &samus_jumping},
    .count                = 4,
    .animation            = &anim_walking,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = &default_input,
};

Intent samus_ai(Grid **grid, Entity *self) {
    State *s = self->sm.current_state;
    if (s->decide_input)
        return s->decide_input(grid, self);
    return (Intent){0};
}

static samus_data _samus_data_pool[1024];
static int _samus_data_count = 0;

Entity *samus_create(int x, int y, int h_dir, int v_dir){
    Entity *e = player_alloc();
    samus_data *d = &_samus_data_pool[_samus_data_count++];

    *d = (samus_data){
        .hp              = 100,
        .max_jumps       = 2,
        .jumps_remaining = 2,
        .item_bola       = false,
        .tipo_arma       = &projetil_normal,
        .invulnerable    = false,
    };

    e->position     = (Coordinates){x, y};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_PLAYER;
    e->orientation  = (Orientation){ h_dir, v_dir};
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 16, 32 } },
        .get_cells  = get_rectangle_cells,
    };
    e->data           = d;
    e->sm.current_state = &samus_idle;
    e->sm.transition    = generic_transition;
    e->on_collision     = samus_collision;
    return e;
};
