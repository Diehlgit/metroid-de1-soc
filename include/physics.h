#include "entity.h"
#include "grid.h"
#define MAX_SPAWNS 8

struct Intent {
	// intenção de movimento (aceleração) — (0,0) = sem movimento
	// velocidade (dx, dy) agora é uma propriedade da struct Entity
	int ax;
 	int ay;

    // entidades a criar nesse frame
    struct Entity *spawns[MAX_SPAWNS];
    int spawn_count;

    // pedir remoção de si mesmo (ex: mina após explodir)
    int destroy_self;
};

int is_solid(struct Entity *e);

static int try_move(struct Entity *mover, int new_x, int new_y, Grid **g, EntityList *l);

void physics_step(struct Entity *e, Intent intent, Grid **g, EntityList *l);
