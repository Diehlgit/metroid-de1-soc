#ifndef ENTITY_H
#define ENTITY_H

#include "basics.h"
#include <stdbool.h>

/*==========================================================
 * Data
 *==========================================================*/

typedef enum {
    RIGHT,
    LEFT
} h_directions;

typedef enum {
    UP,
    DOWN
} v_directions;

typedef struct {
    h_directions h_direction;
    v_directions v_direction;
} Orientation;

typedef enum {
    ENTITY_PLAYER,
    ENTITY_TILE,
    ENTITY_ENEMY,
    ENTITY_PROJECTILE,
    ENTITY_WALL,
    ENTITY_MINE,
    ENTITY_ITEM,
    ENTITY_DOOR
} EntityType;

/*==========================================================
 * Sprite & Animation
 *==========================================================*/

typedef struct {
    int height;
    int width;
    uint16_t *pixels;
} Sprite;

typedef struct {
    Sprite **frames;       // array de sprites
    int      frame_count;
    int      frame_duration;
    int      loops;          // 0 = em loop, 1 = toca uma vez
} Animation;


/*==========================================================
 * Entidade e Máquina de Estados
 *==========================================================*/
typedef struct Entity Entity;
typedef struct State State;
typedef struct Grid Grid;
typedef struct Intent Intent;

typedef bool (*StateGuard)(Entity *self, State *next);

typedef struct State {
    int                id;

    struct State       *allowed_transitions[8];
    int                 count;

    Animation          *animation;

    StateGuard evaluate_entry;
    StateGuard evaluate_exit;

    Intent (*decide_input)(Grid *grid, Entity *self);
} State;

typedef struct {
    State *current_state;
    void (*transition)(struct Entity *self, State *next);
} StateMachine;

struct Entity {
  Coordinates position;
  Coordinates velocity;
  EntityType type;
  Orientation orientation;
  Hitbox hitbox;
  int frame_timer;
  int should_destroy;
  void *data;
  StateMachine sm;
  void (*on_collision)(struct Entity *self, struct Entity *other);
};

typedef struct {
    struct Entity *ents[256];
    int count;
} EntityList;

static void generic_transition(Entity *self, State *next) {
    State *current = self->sm.current_state;
    if (!current || !next) return;

    // verifica se next está na lista de transições permitidas
    bool found = false;
    for (int i = 0; i < current->count; i++) {
        if (current->allowed_transitions[i] == next) {
            found = true;
            break;
        }
    }
    if (!found) return;

    // avalia guards
    if (current->evaluate_exit  && !current->evaluate_exit(self, next))  return;
    if (next->evaluate_entry    && !next->evaluate_entry(self, next))    return;

    self->sm.current_state = next;
    // animação será atualizada pelo animation_tick no próximo frame
}

Entity *entity_alloc(void);
void entity_pool_reset(void);

#endif
