#include "../../../include/entity.h"

void projectile_collision(Entity *self, Entity *others) {
    if (others->type == ENTITY_WALL
     || others->type == ENTITY_ENEMY
     || others->type == ENTITY_TILE){
        self->should_destroy = 1;
    }
}
