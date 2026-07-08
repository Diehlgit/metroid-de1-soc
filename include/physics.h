#include "grid.h"
#define MAX_SPAWNS 8

struct Intent {
    // intenção de movimento — (0,0) = sem movimento
    int dx;
    int dy;

    // entidades a criar nesse frame
    struct Entity *spawns[MAX_SPAWNS];
    int spawn_count;

    // pedir remoção de si mesmo (ex: mina após explodir)
    int destroy_self;
};

void physics_step(Grid *g, struct Entity *e, Intent intent);
