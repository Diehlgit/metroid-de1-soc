#include "../include/basics.h"
#include "../include/entity.h"
#include "../include/grid.h"
#include "../include/physics.h"
#include "../include/uart.h"
#include <stdio.h>

#define GRAVITY 1
#define FRICTION 1
#define MAX_VEL 8


static int clampi(int v, int lo, int hi) {
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static int is_solid(struct Entity *e) {
    return e->type == ENTITY_TILE;
}

// Testa movimento num eixo, retorna 1 se livre, 0 se bloqueado
// Dispara on_collision nas entidades encontradas
static int try_move(struct Entity *mover, int new_x, int new_y, Grid **g, EntityList *l) {
    Grid* gr = *g;
    Coordinates next_pos = { new_x, new_y };
    CellList cells = mover->hitbox.get_cells(&mover->hitbox, next_pos, gr->cell_size);
    EntityList hit = grid_query_by_cells(*g, cells);

    int blocked = 0;
    for (int i = 0; i < hit.count; i++) {
        struct Entity *other = hit.ents[i];
        if (other == mover) continue;
        if (is_solid(other)) {
            if (mover->type == ENTITY_PROJECTILE) {
                mover->should_destroy = 1;
            }
            blocked = 1;
        } else {
            if (mover->on_collision) mover->on_collision(mover, other, g, l);
            if (other->on_collision) other->on_collision(other, mover, g, l);
        }
    }
    return !blocked;
}

void physics_step(struct Entity *e, Intent intent, Grid **g, EntityList *l) {
	// ajustamos a velocidade da entidade de acordo com a aceleração da intenção
	// na coordenada x o que mata a velocidade é a fricção
	e->velocity.x = clampi(e->velocity.x + intent.ax, -MAX_VEL, MAX_VEL);

	if (try_move(e, e->position.x + e->velocity.x, e->position.y, g, l)) {
        grid_remove_entity(*g, e);
    	e->position.x += e->velocity.x;
        if (!e->should_destroy) {
            grid_add_entity(*g, e);
        }
    } else {
		e->velocity.x = 0;
	}

    // aceleração vertical
    if (e->type != ENTITY_PROJECTILE)
        e->velocity.y = clampi(e->velocity.y + GRAVITY + intent.ay, -MAX_VEL, MAX_VEL);


	int on_ground = 0;

	if (try_move(e, e->position.x, e->position.y + e->velocity.y, g, l)) {
    	grid_remove_entity(*g, e);
        e->position.y += e->velocity.y;
        if (!e->should_destroy) {
            grid_add_entity(*g, e);
        }
    } else {
		if (e->velocity.y > 0) on_ground = 1;
		e->velocity.y = 0;
	}

	if (on_ground) {
		if (e->velocity.x > 0) e->velocity.x -= FRICTION;
		if (e->velocity.x < 0) e->velocity.x += FRICTION;
	}
}
