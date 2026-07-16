#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "scorpion_sprites.h"
#include "scorpion.h"
#include "../../../include/grid.h"
#include <stdio.h>

Animation *scorpion_get_animation(Entity *e){
    switch (e->mv_state) {
        case IDLE:
            return &anim_normal_idle;
        break;
        case MOVE:
            return &anim_normal_move;
        break;

        default:
            return &anim_normal_idle;
        break;
    }
}

bool scorpion_move_transition(Entity *self, MovementState next){
    scorpion_data *d = (scorpion_data *)self->data;
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
void scorpion_collision(Entity *self, Entity *other, Grid **g, EntityList *l){
    switch(other->type){
        case ENTITY_PLAYER:
            if(!other->invulnerable){
		printf("SAMUS HP:%d\n",other->hp);
		fflush(stdout);
                other->hp -= 1;
                if(other->hp <= 0){
                    other->should_destroy = 1;
                } else {
                    other->hit = true;
                    //other->sm.move_transition(other, HIT);
                }
            }
		break;

		default:
		break;
    }
}

static bool normal_evaluate_entry(Entity *self) {}
static bool normal_evaluate_exit(Entity *self) {}

static Intent normal_input(Grid **grid, Entity *self) {
    scorpion_data *d = self->data;

    if (d->ai_timer > 0)
        d->ai_timer--;
    else {
        d->ai_timer = 10;   // pensa novamente em 10 frames

        Intent intent = {0};
    	Coordinates search = {.y = self->position.y};
    	int w, m;
    	int x = self->position.x;

    	switch (self->orientation.h_direction) {
    		case RIGHT:
    		{
    			search.x = x;
    		    if (x + (5 * CELL_SIZE) > (*grid)->width) w = (*grid)->width - x;
    			else w = 5 * CELL_SIZE;
    			m = 1;
    			break;
    		}
    		case LEFT:
    		{
    			if(x - (5 * CELL_SIZE) < 0) {search.x = 0;}
    		    else {search.x = x - (5 * CELL_SIZE);}
    			w = 5 * CELL_SIZE;
    			m = -1;
    			break;
    		}
    	}

    	EntityList l = grid_query_region(*grid, search, w, CELL_SIZE);

    	int found = 0;
    	for (int i=0; i<l.count; i++) {
    		if (l.ents[i]->type == ENTITY_PLAYER) {
    			found = 1;

                if (d->chasing)
                    intent.ax = 4 * m;
                else
                    intent.ax = 1 * m;
    			break;
    		}
    	}

        if (found) {
            d->chasing = 1;
        } else {
            d->chasing = 0;
            self->orientation.h_direction =
                (self->orientation.h_direction == LEFT) ? RIGHT : LEFT;
        }
	return intent;
    }
}

State scorpion_normal = {
    .id                   = SCORPION_NORMAL,
    .allowed_transitions  = {},
    .count                = 0,
    .evaluate_entry       = normal_evaluate_entry,
    .evaluate_exit        = normal_evaluate_exit,
    .decide_input         = normal_input,
};

Intent scorpion_ai(Grid **grid, Entity *self) {
    State *s = self->sm.current_state;
    if (s->decide_input)
        return s->decide_input(grid, self);
    return (Intent){0};
}

static scorpion_data _scorpion_data_pool[1024];
static int _scorpion_data_count = 0;

Entity *scorpion_create(int x, int y, int h_dir, int v_dir){
    Entity *e = entity_alloc();
    scorpion_data *d = &_scorpion_data_pool[_scorpion_data_count++];

    *d = (scorpion_data){
        d->ai_timer = 10
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
        .data       = { .rectangle={ 16, 16} },
        .get_cells  = get_rectangle_cells,
    };
    e->data         = d;
    e->sm.current_state = &scorpion_normal;
    e->sm.transition    = generic_transition;
    e->sm.move_transition = &scorpion_move_transition;
    e->sm.get_animation = &scorpion_get_animation;
    e->on_collision     = scorpion_collision;
    return e;
};
