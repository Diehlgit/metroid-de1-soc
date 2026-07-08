#ifndef BASICS_H
#define BASICS_H

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

#endif
