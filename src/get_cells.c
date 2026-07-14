#include "../include/basics.h"

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

    int cell_left   = (pos.x - rad) / cell_size;
    int cell_right  = (pos.x + rad) / cell_size;
    int cell_top    = (pos.y - rad) / cell_size;
    int cell_bottom = (pos.y + rad) / cell_size;

    for (int row = cell_top; row <= cell_bottom; row++) {
        for (int col = cell_left; col <= cell_right; col++) {
            int cell_center_x = col * cell_size + cell_size / 2;
            int cell_center_y = row * cell_size + cell_size / 2;
            int dx = cell_center_x - pos.x;
            int dy = cell_center_y - pos.y;

            if (dx * dx + dy * dy <= rad * rad) {
                list.cells[list.count++] = (CellCoord){col, row};
            }
        }
    }

    return list;
}

CellList get_triangle_cells(Hitbox *self, Coordinates coord, int cell_size){
    CellList list = {.count = 0};
    Triangle *tri = &self->data.triangle;

    return list;
}
