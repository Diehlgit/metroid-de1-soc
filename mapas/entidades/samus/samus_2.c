#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "../../../include/uart.h"
#include "samus.h"

void samus_collision(Entity *self, Entity *others){}

typedef enum {
    BALLING,
    HIT,
    IDLE,
    JUMPING,
    KNEELING,
    WALKING,
} samus_state;

static State balling;
static State hit;
static State idle;
static State jumping;
static State kneeling;
static State walking;

static bool balling_evaluate_entry(Entity *self, State *next) {
    if(self->data.itens.bola != false){
        self->hitbox.data.rectangle.height  = 16;
        self->position.y -= 16;
        return true;
    }
    return false;
}
static bool balling_evaluate_exit(Entity *self, State *next) {
    return true;
}

static bool hit_evaluate_entry(Entity *self, State *next) {
    self->data.itens.bola = false;
    self->data.double_jump = false;
    self->data.invulnerable = true;
    return true;
}
static bool hit_evaluate_exit(Entity *self, State *next) {
    self->data.invulnerable = false;
    return true;
}

static bool idle_evaluate_entry(Entity *self, State *next) {}
static bool idle_evaluate_exit(Entity *self, State *next) {}

static bool jumping_evaluate_entry(Entity *self, State *next) {
    if(self->sm.current_state->id == JUMPING){
        if(self->data.double_jump == true){
            return true;
        } else {
            return false;
        }
    }
    return true;
}
static bool jumping_evaluate_exit(Entity *self, State *next) {}

static bool kneeling_evaluate_entry(Entity *self, State *next) {
    self->hitbox.data.rectangle.height  = 16;
    self->position.y += 16;
    return true;
}
static bool kneeling_evaluate_exit(Entity *self, State *next) {
    self->hitbox.data.rectangle.height  = 16;
    self->position.y -= 16;
    return true;
}

static bool walking_evaluate_entry(Entity *self, State *next) {}
static bool walking_evaluate_exit(Entity *self, State *next) {}


static Intent default_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    char key = uart_read_char();
    if (key == 'w') { intent.ay = -16; self->sm.transition(self, &jumping); }
    if (key == 'a') { intent.ax = -2;  self->orientation.h_direction = LEFT;  self->sm.transition(self, &walking); }
    if (key == 's') { self->sm.transition(self, &kneeling); }
    if (key == 'd') { intent.ax =  2;  self->orientation.h_direction = RIGHT; self->sm.transition(self, &walking); }
    if (key == 'e') { self->sm.transition(self, &balling); }
    if (key == 'f') {
        Entity projetil;
        intent.spawns[intent.spawn_count++] = &projetil;
    }
    if (!key)        self->sm.transition(self, &idle);
    return intent;
}

static Intent balling_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    char key = uart_read_char();
    if (key == 'w') { intent.ay = -16; }
    if (key == 'a') { intent.ax = -2; self->orientation.h_direction = LEFT; }
    if (key == 'd') { intent.ax =  2; self->orientation.h_direction = RIGHT; }
    if (!key)        self->sm.transition(self, &idle);
    return intent;
}
static Intent hit_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
static Intent idle_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
static Intent jumping_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
static Intent kneeling_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    char key = uart_read_char();
    if (key == 'f') {
        Entity projetil;
        intent.spawns[intent.spawn_count++] = &projetil;
    }
    if (!key)        self->sm.transition(self, &idle);
    return intent;
}
static Intent walking_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    return intent;
}

static State balling = {
    .id                    = BALLING,
    .allowed_transitions  = {&idle, &hit},
    .count                = 2,
    .animation            = &anim_balling,
    .evaluate_entry       = &balling_evaluate_entry,
    .evaluate_exit        = NULL,
    .decide_input         = &balling_input,
};
static State hit = {
    .id                    = HIT,
    .allowed_transitions  = {&idle},
    .count                = 1,
    .animation            = &anim_hit,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = &hit_input,
};
static State idle = {
    .id                    = IDLE,
    .allowed_transitions  = { &walking, &kneeling, &jumping, &balling, &hit },
    .count                = 5,
    .animation            = &anim_idle,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = &default_input,
};
static State jumping = {
    .id                    = JUMPING,
    .allowed_transitions  = {&idle, &hit, &balling},
    .count                = 3,
    .animation            = &anim_jumping,
    .evaluate_entry       = &jumping_evaluate_entry,
    .evaluate_exit        = NULL,
    .decide_input         = &jumping_input,
};
static State kneeling = {
    .id                    = KNEELING,
    .allowed_transitions  = { &idle },
    .count                = 1,
    .animation            = &anim_kneeling,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = &kneeling_input,
};
static State walking = {
    .id                    = WALKING,
    .allowed_transitions  = {&idle, &hit, &balling, &jumping},
    .count                = 4,
    .animation            = &anim_walking,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = &default_input,
};

Intent samus_ai(Grid *grid, Entity *self) {
    State *s = self->sm.current_state;
    if (s->decide_input)
        return s->decide_input(grid, self);
    return (Intent){0};
}

const Entity *samus_create(int x, int y, int h_dir, int v_dir){
    Entity *e = entity_alloc();
    e->position     = (Coordinates){y, x};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_PLAYER;
    e->orientation  = (Orientation){ h_dir, v_dir};
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 16, 32 } },
        .get_cells  = get_rectangle_cells,
    };
    e->sm.current_state = &idle;
    e->sm.transition    = generic_transition;
    e->on_collision     = samus_collision;
    return e;
};
