#include "../../../include/physics.h"
#include "../../../generated/entidades.h"

Intent projectile_intent(Grid *grid, Entity *self) {
    Intent intent = {0};

    if (self->should_destroy) {
        intent.destroy_self = 1;
    }

    return intent;
}
