#include "../../../include/physics.h"
#include "../../../include/uart.h"
#include "../../../generated/entidades.h"
#include <stdio.h>

extern void projectile_collision(struct Entity *, struct Entity *);
extern Intent projectile_intent(Grid *grid, struct Entity *self);

static Entity projectile_pool[64];
static int projectile_pool_index = 0;
static int projectile_cooldown = 0;

#define PROJECTILE_VELOCITY 6
#define PROJECTILE_COOLDOWN_FRAMES 60

Intent player_input(Grid *grid, Entity *self) {
    Intent intent = {0};

    if (projectile_cooldown > 0) {
        projectile_cooldown--;
    }

    char key = uart_read_char();
    if (key == 'a') {
        intent.ax = -3;
        self->facing = LEFT;
    }
    if (key == 'd') {
        intent.ax = 3;
        self->facing = RIGHT;
    }
    if (key == 'w') intent.ay = -32;  // pulo — physics aplica gravidade

    if (key == 'f' && projectile_cooldown == 0) {
        Entity *proj = &projectile_pool[projectile_pool_index++ % 64];
        int dir = (self->facing == LEFT) ? -1 : 1;

        *proj = (Entity){
            .position = {
                self->position.x + (dir > 0 ? 16 : -8),
                self->position.y + 12
            },
            .velocity = { dir * PROJECTILE_VELOCITY, 0 },
            .type = ENTITY_PROJECTILE,
            .hitbox = {
                .type = HITBOX_CIRCLE,
                .data = { .circle = { 8 } },
                .get_cells = get_circle_cells,
            },
            .current_sprite = &SPRITE_SAMUS_PROJECTILE,
            .facing = self->facing,
            .should_destroy = 0,
            .think = projectile_intent,
            .on_collision = projectile_collision,
        };

        projectile_cooldown = PROJECTILE_COOLDOWN_FRAMES;
        intent.spawn_count = 1;
        intent.spawns[0] = proj;
    }

    return intent;
}
