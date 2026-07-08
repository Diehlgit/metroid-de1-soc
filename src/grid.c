#include "../include/grid.h"
#include <stdlib.h>

// Retorna a Cell em (row,col), criando se não existir
static Cell* grid_get_or_create(Grid *g, CellCoord c) {
    int h = grid_hash(c);
    GridEntry *e = g->cells[h];
    while (e) {
        if (e->key.row == c.row && e->key.col == c.col)
            return &e->cell;
        e = e->next;
    }
    // não encontrou — cria
    GridEntry *novo = malloc(sizeof(GridEntry));
    novo->key  = c;
    novo->cell.count = 0;
    novo->next = g->cells[h];
    g->cells[h] = novo;
    return &novo->cell;
}

static Cell* grid_get(Grid *g, CellCoord c) {
    int h = grid_hash(c);
    GridEntry *e = g->cells[h];
    while (e) {
        if (e->key.row == c.row && e->key.col == c.col)
            return &e->cell;
        e = e->next;
    }
    return NULL;  // célula vazia
}

void grid_add_entity(Grid *g, struct Entity *ent) {
    CellList ent_cells = ent->hitbox.get_cells(&ent->hitbox, ent->position, g->cell_size);

    for (int i = 0; i < ent_cells.count; i++) {
        Cell *cell = grid_get_or_create(g, ent_cells.cells[i]);
        if (cell->count < MAX_ENTS_PER_CELL)
            cell->ents[cell->count++] = ent;
    }
}

void grid_remove_entity(Grid *g, struct Entity *ent) {
    CellList ent_cells = ent->hitbox.get_cells(&ent->hitbox, ent->position, g->cell_size);

    for (int i = 0; i < ent_cells.count; i++) {
        Cell *cell = grid_get(g, ent_cells.cells[i]);
        if (!cell) continue;
        // remove por swap com o último elemento
        for (int j = 0; j < cell->count; j++) {
            if (cell->ents[j] == ent) {
                cell->ents[j] = cell->ents[--cell->count];
                break;
            }
        }
    }
}

EntityList grid_query_region(Grid *g, Coordinates pos, int width, int height) {
    EntityList result = {.count = 0};
    int cell_left   = pos.x / g->cell_size;
    int cell_right  = (pos.x + width  - 1) / g->cell_size;
    int cell_top    = pos.y / g->cell_size;
    int cell_bottom = (pos.y + height - 1) / g->cell_size;

    for (int row = cell_top; row <= cell_bottom; row++) {
        for (int col = cell_left; col <= cell_right; col++) {
            Cell *cell = grid_get(g, (CellCoord){col, row});
            if (!cell) continue;
            for (int i = 0; i < cell->count; i++) {
                // deduplicação: evita retornar a mesma entidade duas vezes
                struct Entity *e = cell->ents[i];
                int duplicado = 0;
                for (int j = 0; j < result.count; j++)
                    if (result.ents[j] == e) { duplicado = 1; break; }
                if (!duplicado && result.count < 256)
                    result.ents[result.count++] = e;
            }
        }
    }
    return result;
}

EntityList grid_query_by_cells(Grid *g, CellList list){
    EntityList result = {.count = 0};

    for(int i = 0; i < list.count; i++){
        Cell *cell = grid_get(g, list.cells[i]);
        if (!cell) continue;

        for(int j = 0; j < cell->count; j++){
            struct Entity *e = cell->ents[j];
            int duplicado = 0;
            for (int z = 0; z < result.count; z++)
                if (result.ents[z] == e) { duplicado = 1; break; }
            if (!duplicado && result.count < 256)
                result.ents[result.count++] = e;
        }
    }

    return result;
}
