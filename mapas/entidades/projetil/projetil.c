#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "projetil_sprites.h"
#include "projetil.h"

Animation *projetil_get_animation(Entity *e){
    projetil_data *d = (projetil_data *)e->data;
    switch(d->ent_state){
        case PROJETIL_BASE:
            return &anim_base_move;
        break;

        case PROJETIL_SUPER:
            return &anim_super_move;
        break;

        case PROJETIL_VENENO:
            return &anim_veneno_move;
        break;
    }
}

void projetil_collision(Entity *self, Entity *other, Grid **g, EntityList *l){
    projetil_data *pd = (projetil_data *)self->data;

	if(other == pd->shooter) {
		//printf("colidu consigo mesmo\n");
		return;
	}

    switch(other->type){
        case ENTITY_ITEM || ENTITY_TILE || ENTITY_TRANSITION:
            self->should_destroy = 1;
		break;

		default:
		    if(!other->invulnerable){
                other->hp -= pd->dano;
                if(other->hp <= 0){
                    other->should_destroy = 1;
                } else {
                    other->hit = true;
                    other->sm.move_transition(other, HIT);
                }
                self->should_destroy = 1;
			}
    }
}

static Intent base_input(Grid **grid, Entity *self) {
    Intent intent = {0};
    return intent;
}
State projetil_base = {
    .id                   = PROJETIL_BASE,
    .allowed_transitions  = {},
    .count                = 0,
    .evaluate_entry       = NULL,
    .evaluate_exit        = NULL,
    .decide_input         = base_input,
};

Intent projetil_ai(Grid **grid, Entity *self) {
    State *s = self->sm.current_state;
    if (s->decide_input)
        return s->decide_input(grid, self);
    return (Intent){0};
}

static projetil_data _projetil_data_pool[1024];
static int _projetil_data_count = 0;

Entity *projetil_create(Entity *shooter, projetilStates tipo){
    Entity *e = entity_alloc();
    projetil_data *d = &_projetil_data_pool[_projetil_data_count++];

    *d = (projetil_data){
        .ent_state = tipo,
        .shooter = shooter,
    };

    switch(tipo){
        case PROJETIL_BASE:
            d->dano = 2;
        break;

        case PROJETIL_SUPER:
            d->dano = 4;
        break;

        case PROJETIL_VENENO:
            d->dano = 4;
        break;
    }

    int shot_x;
    if(shooter->orientation.h_direction == RIGHT){
        shot_x = shooter->position.x + shooter->hitbox.data.rectangle.width;
    } else {
        shot_x = shooter->position.x;
    }

    int shot_y;
    if(shooter->orientation.v_direction == UP){
        shot_y = shooter->position.y + (shooter->hitbox.data.rectangle.height/4);
    } else {
        shot_y = shooter->position.x - (shooter->hitbox.data.rectangle.height/4);
    }

    e->position     = (Coordinates){shot_x, shot_y};

    if(shooter->orientation.h_direction == RIGHT){
        e->velocity.x = 5;
    } else  {
        e->velocity.x = -5;
    }

    e->type         = ENTITY_PROJECTILE;
    e->orientation  = (Orientation){ shooter->orientation.h_direction, shooter->orientation.v_direction};
    e->hp           = 10;
    e->invulnerable = true;
    e->hit          = false;
    e->mv_state     = MOVE;
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 4, 4 } },
        .get_cells  = get_rectangle_cells,
    };
    e->data         = d;
    e->sm.current_state = &projetil_base;
    e->sm.transition    = generic_transition;
    e->sm.move_transition = NULL;
    e->sm.get_animation = &projetil_get_animation;
    e->on_collision     = projetil_collision;
    return e;
};
