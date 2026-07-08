#include "../include/basics.h"
#include "../include/entity.h"
#include "../include/grid.h"
#include "../include/physics.h"

#define GRAVITY 2

static int is_solid(struct Entity *e) {
    return e->type == ENTITY_TILE  ||
           e->type == ENTITY_WALL;
}

// Testa movimento num eixo, retorna 1 se livre, 0 se bloqueado
// Dispara on_collision nas entidades encontradas
static int try_move(Grid *g, struct Entity *mover, int new_x, int new_y) {
    Coordinates next_pos = { new_x, new_y };
    CellList cells = mover->hitbox.get_cells(&mover->hitbox, next_pos, g->cell_size);
    EntityList hit = grid_query_by_cells(g, cells);

    int blocked = 0;
    for (int i = 0; i < hit.count; i++) {
        struct Entity *other = hit.ents[i];
        if (other == mover) continue;
        if (is_solid(other)) {
            blocked = 1;
        } else {
            // não bloqueia, mas dispara callbacks
            if (other->on_collision) other->on_collision(other, mover);
            if (mover->on_collision) mover->on_collision(mover, other);
        }
    }
    return !blocked;
}

void physics_step(Grid *g, struct Entity *e, Intent intent) {
    // 1. Movimento horizontal
    if (intent.dx != 0) {
        if (try_move(g, e, e->position.x + intent.dx, e->position.y)) {
            grid_remove_entity(g, e);
            e->position.x += intent.dx;
            grid_add_entity(g, e);
        }
    }

    // 2. Gravidade acumula no dy
    intent.dy += GRAVITY;

    // 3. Movimento vertical
    if (intent.dy != 0) {
        if (try_move(g, e, e->position.x, e->position.y + intent.dy)) {
            grid_remove_entity(g, e);
            e->position.y += intent.dy;
            grid_add_entity(g, e);
        }
    }
}
