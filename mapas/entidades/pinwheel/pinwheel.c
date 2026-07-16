#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "../projetil/projetil.h"
#include "pinwheel_sprites.h"
#include "pinwheel.h"

Animation *pinwheel_get_animation(Entity *e){
    return &anim_normal_move;
}

bool pinwheel_move_transition(Entity *self, MovementState next){
    pinwheel_data *d = (pinwheel_data *)self->data;
    MovementState current = self->mv_state;

    switch (next) {
        case IDLE:
            break;

        case MOVE:
            break;

        case AIRBORNE:
            break;

        case HIT:
            break;

        default:
            return false;
    }
    self->mv_state = next;
    return true;
}
void pinwheel_collision(Entity *self, Entity *other, Grid **g, EntityList *l){}

static bool normal_evaluate_entry(Entity *self) {}
static bool normal_evaluate_exit(Entity *self) {}
static Intent normal_input(Grid **grid, Entity *self) {
    pinwheel_data *d = self->data;

    if (d->ai_timer > 0){
        d->ai_timer--;
		return (Intent){0};
	} else {
        d->ai_timer = 10;
static Intent normal_input(Grid **grid, Entity *self) {
    pinwheel_data *d = self->data;

    if (d->ai_timer > 0)
        d->ai_timer--;
    else {
        d->ai_timer = 60;

        Intent intent = {0};
        Coordinates search = {.y = self->position.y};
        int w, m;
        int x = self->position.x;

        switch (self->orientation.h_direction) {
            case RIGHT:
            {
                search.x = x;
                if (x + (10 * CELL_SIZE) > (*grid)->width) w = (*grid)->width - x;
                else w = 10 * CELL_SIZE;
                m = 1;
                break;
            }
            case LEFT:
            {
                if (x - (10 * CELL_SIZE) < 0) {search.x = 0;}
                else {search.x = x - (10 * CELL_SIZE);}
                w = 10 * CELL_SIZE;
                m = -1;
                break;
            }
        }

        EntityList l = grid_query_region(*grid, search, w, self->hitbox.data.rectangle.height);

        int found = 0;
        for (int i = 0; i < l.count; i++) {
            if (l.ents[i]->type == ENTITY_PLAYER) {
                found = 1;
                intent.spawns[intent.spawn_count++] = projetil_create(self, PROJETIL_VENENO);
                break;
            }
        }

        return intent;
    }
}
State pinwheel_normal = {
    .id                   = PINWHEEL_NORMAL,
    .allowed_transitions  = {},
    .count                = 0,
    .evaluate_entry       = normal_evaluate_entry,
    .evaluate_exit        = normal_evaluate_exit,
    .decide_input         = normal_input,
};
Intent pinwheel_ai(Grid **grid, Entity *self) {
    State *s = self->sm.current_state;
    if (s->decide_input)
        return s->decide_input(grid, self);
    return (Intent){0};
}

static pinwheel_data _pinwheel_data_pool[1024];
static int _pinwheel_data_count = 0;

Entity *pinwheel_create(int x, int y, int h_dir, int v_dir){
    Entity *e = entity_alloc();
    pinwheel_data *d = &_pinwheel_data_pool[_pinwheel_data_count++];

    *d = (pinwheel_data){
    	d->ai_timer = 60
	};

    e->position     = (Coordinates){x, y};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_ENEMY;
    e->orientation  = (Orientation){ h_dir, v_dir};
    e->hp           = 10;
    e->invulnerable = false;
    e->hit          = false;
    e->mv_state     = IDLE;
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 32, 32 } },
        .get_cells  = get_rectangle_cells,
    };
    e->data         = d;
    e->sm.current_state = &pinwheel_normal;
    e->sm.transition    = generic_transition;
    e->sm.move_transition = &pinwheel_move_transition;
    e->sm.get_animation = &pinwheel_get_animation;
    e->on_collision     = pinwheel_collision;
    return e;
};
