#ifndef STRUCTS_H
#define STRUCTS_H

#include <stddef.h>
#include <stdint.h>

#define CELL_SIZE 16

/*==========================================================
 * Coordenadas
 *==========================================================*/

typedef struct {
    int x;
    int y;
} Coordinates;

typedef struct { // redundante
    int col;
    int row;
} CellCoord;

typedef struct {
    CellCoord cells[128];
    int count;
} CellList;

/*==========================================================
 * Formas primitivas
 *==========================================================*/

typedef enum {
    HITBOX_RECTANGLE,
    HITBOX_CIRCLE,
    HITBOX_TRIANGLE
} HitboxType;

typedef struct Rectangle {
    int width;
    int height;
} Rectangle;

typedef struct Circle {
    int radius;
} Circle;

typedef struct Triangle {
    int width;
    int height;
} Triangle;

typedef struct Hitbox {
    HitboxType type;
    union {
        Rectangle rectangle;
        Circle circle;
        Triangle triangle;
    } data;
    CellList (*get_cells)(struct Hitbox *self, Coordinates coord, int cell_size);
} Hitbox;

CellList get_rectangle_cells(Hitbox *self, Coordinates pos, int cell_size);

CellList get_circle_cells(Hitbox *self, Coordinates pos, int cell_size);

CellList get_triangle_cells(Hitbox *self, Coordinates coord, int cell_size);

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

struct Entity {
  Coordinates position;
  EntityType type;
  Hitbox hitbox;
  Sprite *current_sprite;
  Intent (*think)(Grid *grid, struct Entity *self);
  void (*on_collision)(struct Entity *self, struct Entity *other);
};

struct OldEntity {
    Coordinates position;
    EntityType type;
    Hitbox hitbox;
    StateMachine sm;
    uint8_t current_frame;
    uint8_t frame_timer;
    void *data;               // dados específicos do tipo — PlayerData*, BossData*, etc.
    void (*think)(struct Entity *self);
    void (*on_collision)(struct Entity *self, struct Entity *other);
};

typedef struct {
    struct Entity *ents[256];
    int count;
} EntityList;

#endif
