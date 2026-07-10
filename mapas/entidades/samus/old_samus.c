#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "../../../include/uart.h"
#include "samus.h"

typedef enum {
    IDLE,
    KNEELING,
    WALKING,
    JUMPING,
    BALLING,
    HIT
} samus_state;

// 1. Declara todos os estados
static State idle;
static State walking;
static State kneeling;
static State jumping;
static State balling;
static State hit;

// 2. funções de transição
static bool kneeling_evaluate_entry(Entity *self, State *current, State *next) {
    self->hitbox.data.rectangle.height  = 16;
    self->position.y += 16;
    return true;
}

static bool kneeling_evaluate_exit(Entity *self, State *current, State *next) {
    self->hitbox.data.rectangle.height  = 32;
    self->position.y -= 16;
    return true;
}

static bool idle_evaluate_entry(Entity *self, State *current, State *next) {
    return true;
}

static bool jumping_evaluate_entry(Entity *self, State *current, State *next) {
    return current != &balling;
}

// 3. Inicializa as funções de handle_input
static Intent kneeling_input(Entity *self, char key) {
    Intent intent = {0};
    if (key == 'f') { /* spawn projétil agachado */ }
    if (!key)        self->sm.transition(self, &idle);
    return intent;
}

static Intent balling_input(Entity *self, char key) {
    Intent intent = {0};
    if (key == 'w') { intent.dy = -16; }
    if (key == 'a') { intent.dx = -2; self->orientation.h_direction = LEFT; }
    if (key == 'd') { intent.dx =  2; self->orientation.h_direction = RIGHT; }
    if (!key)        self->sm.transition(self, &idle);
    return intent;
}

static Intent default_input(Entity *self, char key) {
    Intent intent = {0};
    if (key == 'w') { intent.dy = -16; self->sm.transition(self, &jumping); }
    if (key == 'a') { intent.dx = -2;  self->orientation.h_direction = LEFT;  self->sm.transition(self, &walking); }
    if (key == 'd') { intent.dx =  2;  self->orientation.h_direction = RIGHT; self->sm.transition(self, &walking); }
    if (key == 's') { self->sm.transition(self, &kneeling); }
    if (key == 'f') { /* spawn projétil */ }
    if (!key)        self->sm.transition(self, &idle);
    return intent;
}

// 4. inicializa com ponteiros já conhecidos
static State idle = {
    .id                   = IDLE,
    .allowed_transitions  = { &walking, &kneeling, &jumping, &balling, &hit },
    .count                = 5,
    .animation            = &anim_idle,
    .evaluate_entry       = idle_evaluate_entry,
    .evaluate_exit        = NULL,
    .handle_input         = default_input,
};

static State kneeling = {
    .id              = KNEELING,
    .allowed_transitions = { &idle },
    .count           = 1,
    .animation       = &anim_kneeling,
    .evaluate_entry  = kneeling_evaluate_entry,
    .evaluate_exit   = kneeling_evaluate_exit,
    .handle_input    = kneeling_input,
};

static State walking = {
    .id                   = WALKING,
    .allowed_transitions  = { &idle, &jumping, &hit },
    .count                = 3,
    .animation            = &anim_walking,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
};

static State jumping = {
    .id                   = JUMPING,
    .allowed_transitions  = { &idle, &hit },
    .count                = 2,
    .animation            = &anim_jumping,
    .evaluate_entry       = jumping_evaluate_entry,
    .evaluate_exit        = NULL,
};

// 4. Declara a função de Intenção
Intent samus_ai(Grid *grid, Entity *self) {
    char key = uart_read_char();
    State *s = self->sm.current_state;
    if (s->handle_input)
        return s->handle_input(self, key);
    return (Intent){0};
}

// 5. Declara a função de Colisão
void samus_collision(Entity *self, Entity *others){

}
