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

void physics_step(Grid *g, struct Entity *e, Intent intent);
