#include "../include/structs.h"

CellList get_rectangle_cells(Hitbox *self, Coordinates pos, int cell_size) {
    CellList list = {.count = 0};
    Rectangle *rec = &self->data.rectangle;

    int cell_left   = pos.x / cell_size;
    int cell_right  = (pos.x + rec->width  - 1) / cell_size;

    int cell_top    = pos.y / cell_size;
    int cell_bottom = (pos.y + rec->height - 1) / cell_size;

    for (int row = cell_top; row <= cell_bottom; row++) {
        for (int col = cell_left; col <= cell_right; col++) {
            list.cells[list.count++] = (CellCoord){col, row};
        }
    }
    return list;
}

CellList get_circle_cells(Hitbox *self, Coordinates pos, int cell_size){
    CellList list = {.count = 0};
    Circle *cir = &self->data.circle;
    int rad = cir->radius;

    int min_x = pos.x - rad;
    int max_x = pos.x + rad;

    int min_y = pos.y - rad;
    int max_y = pos.y + rad;

    for(int y = min_y; y < max_y; y++){
        for(int x = min_x; x < max_x; x++){

        }
    }

    return list;
}

CellList get_triangle_cells(Hitbox *self, Coordinates coord, int cell_size){
    CellList list = {.count = 0};
    Triangle *tri = &self->data.triangle;

    return list;
}
