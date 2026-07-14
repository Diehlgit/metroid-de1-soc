#ifndef GRID_H
#define GRID_H

#include "basics.h"
#include "entity.h"

#define MAX_ENTS_PER_CELL 16
#define MAX_GRID_CELLS 1024

typedef struct {
    struct Entity *ents[MAX_ENTS_PER_CELL];
    int count;
} Cell;

typedef struct GridEntry {
    CellCoord key;
    Cell cell;
    struct GridEntry *next;
} GridEntry;

struct Grid {
    GridEntry *cells[MAX_GRID_CELLS];
    int height;
    int width;
    int cell_size;
};

static int grid_hash(CellCoord c) {
    return ((c.row * 31) ^ c.col) & (MAX_GRID_CELLS - 1);
}

void grid_add_entity(Grid *g, struct Entity *ent);
void grid_remove_entity(Grid *g, struct Entity *ent);

EntityList grid_query_region(Grid *g, Coordinates pos,
                             int width, int height);

EntityList grid_query_by_cells(Grid *g, CellList list);

void grid_reset(Grid *g);
#endif
