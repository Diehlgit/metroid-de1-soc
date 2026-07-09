#ifndef ENTITY_H
#define ENTITY_H

#include "basics.h"

/*==========================================================
 * Sprite & Animation
 *==========================================================*/

typedef struct {
    int height;
    int width;
    uint16_t *pixels;
} Sprite;

typedef struct {

} Animation;

/*==========================================================
 * Entity
 *==========================================================*/

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

typedef struct Entity Entity;

typedef struct {
    int current_state;          // int genérico para guardar qualquer enum
    void (*transition)(struct Entity *self, int event);
} StateMachine;

typedef struct Grid Grid;
typedef struct Intent Intent;

typedef enum {
    RIGHT,
    LEFT
} h_directions;

typedef enum {
    UP,
    DOWN
} v_directions;

struct Entity {
  Coordinates position;
  EntityType type;
  Hitbox hitbox;
  Sprite *current_sprite;
  Intent (*think)(Grid *grid, struct Entity *self);
  void (*on_collision)(struct Entity *self, struct Entity *other);
};

typedef struct {
    struct Entity *ents[256];
    int count;
} EntityList;

#endif
