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
            if (mover->type == ENTITY_PROJECTILE) {
                mover->should_destroy = 1;
            }
            blocked = 1;
        } else {
            if (other->on_collision) other->on_collision(other, mover);
            if (mover->on_collision) mover->on_collision(mover, other);
        }
    }
    return !blocked;
}

void physics_step(Grid *g, struct Entity *e, Intent intent)
{

    if (e->should_destroy) {
        grid_remove_entity(g, e);
        return;
    }

	// ajustamos a velocidade da entidade de acordo com a aceleração da intenção
	// na coordenada x o que mata a velocidade é a fricção
	e->velocity.x = clampi(e->velocity.x + intent.ax, -MAX_VEL, MAX_VEL);	
	
	//uart_print("antes: x=");
    //uart_print_int(e->position.x);
    //uart_print("\n");

	if (try_move(g, e, e->position.x + e->velocity.x, e->position.y)) {
        grid_remove_entity(g, e);
    	e->position.x += e->velocity.x;
        if (!e->should_destroy) {
            grid_add_entity(g, e);
        }
    } else {
		e->velocity.x = 0;
	}

    if (e->should_destroy) {
        grid_remove_entity(g, e);
        return;
    }
    
    //uart_print(" y=");
    //uart_print_int(e->position.y);
    //uart_print("\n");

    // aceleração vertical 
    if (e->type != ENTITY_PROJECTILE)
        e->velocity.y = clampi(e->velocity.y + GRAVITY + intent.ay, -MAX_VEL, MAX_VEL);

    //uart_print("dy=");
    //uart_print_int(intent.dy);
    //uart_print("\n");

	int on_ground = 0;

	if (try_move(g, e, e->position.x, e->position.y + e->velocity.y)) {
    	grid_remove_entity(g, e);
        e->position.y += e->velocity.y;
        if (!e->should_destroy) {
            grid_add_entity(g, e);
        }
    } else {
		if (e->velocity.y > 0) on_ground = 1;
		e->velocity.y = 0;
	}

    if (e->should_destroy) {
        grid_remove_entity(g, e);
        return;
    }

	if (on_ground) {
		if (e->velocity.x > 0) e->velocity.x -= FRICTION;
		if (e->velocity.x < 0) e->velocity.x += FRICTION;
	}

    //uart_print("depois: x=");
    //uart_print_int(e->position.x);
    //uart_print(" y=");
    //uart_print_int(e->position.y);
    //uart_print("\n");
}



/* void physics_step(Grid *g, struct Entity *e, Intent intent) {
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
    }*/
