#include "../include/entity.h"

// entity.c
#define ENTITY_POOL_SIZE 128
static Entity _pool[ENTITY_POOL_SIZE];
static int    _pool_count = 0;

void remove_entity(Entity *e, EntityList *list) {
    if (e == NULL || list == NULL) return;

    for (int i = 0; i < list->count; i++) {
        if (list->ents[i] == e) {

            // Desloca os elementos para preencher o espaço
            for (int j = i; j < list->count - 1; j++) {
                list->ents[j] = list->ents[j + 1];
            }

            list->ents[list->count - 1] = NULL;
            list->count--;

            return;
        }
    }
}

Entity *entity_alloc(void) {
    if (_pool_count >= ENTITY_POOL_SIZE) return NULL;
    return &_pool[_pool_count++];
}

void entity_pool_reset(void) {
    _pool_count = 0;
}
