#include "../include/entity.h"

// entity.c
#define ENTITY_POOL_SIZE 128
static Entity _pool[ENTITY_POOL_SIZE];
static int    _pool_count = 0;

Entity *entity_alloc(void) {
    if (_pool_count >= ENTITY_POOL_SIZE) return NULL;
    return &_pool[_pool_count++];
}

void entity_pool_reset(void) {
    _pool_count = 0;
}
