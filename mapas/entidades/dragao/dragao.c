#include "dragao.h"
#include "../../../include/entity.h"
#include "../../../include/physics.h"
#include "../projetil/projetil.h"
#include "dragao_sprites.h"
#include "dragao_sprites.h"

Animation *dragao_get_animation(Entity *e){
    return &anim_normal_move;
}

bool dragao_move_transition(Entity *self, MovementState next){
    return true;
}
void dragao_collision(Entity *self, Entity *other, Grid **g, EntityList *l){}

static bool normal_evaluate_entry(Entity *self) {}
static bool normal_evaluate_exit(Entity *self) {}

static Intent normal_input(Grid **grid, Entity *self) {
    Intent intent = {0};
    Coordinates search;
	int w, h, m;
	int x = self->position.x;
	int y = self->position.y;

	if(x - (5 * CELL_SIZE) < 0) {search.x = 0;}
	else {search.x = x - (5*CELL_SIZE);}

	if(x + (10 * CELL_SIZE) > (*grid)->width) w = (*grid)->width - x;
	else w = 10 * CELL_SIZE;

	EntityList l = grid_query_region(*grid, search, w, self->hitbox.data.rectangle.height);

	int found = 0;
	for (int i=0; i<l.count; i++) {
		if (l.ents[i]->type == ENTITY_PLAYER) {
			found = 1;
			intent.spawns[intent.spawn_count++] = projetil_create(self, PROJETIL_VENENO);
			break;
		}
	}
	intent.ay = 16;
    return intent;
}
State dragao_normal = {
    .id                   = DRAGAO_NORMAL,
    .allowed_transitions  = {},
    .count                = 0,
    .evaluate_entry       = normal_evaluate_entry,
    .evaluate_exit        = normal_evaluate_exit,
    .decide_input         = normal_input,
};
Intent dragao_ai(Grid **grid, Entity *self) {
    State *s = self->sm.current_state;
    if (s->decide_input)
        return s->decide_input(grid, self);
    return (Intent){0};
}

static dragao_data _pinwheel_data_pool[1024];
static int _pinwheel_data_count = 0;

Entity *dragao_create(int x, int y, int h_dir, int v_dir){
    Entity *e = entity_alloc();
    dragao_data *d = &_pinwheel_data_pool[_pinwheel_data_count++];

    *d = (dragao_data){
    };

    e->position     = (Coordinates){x, y};
    e->velocity     = (Coordinates){0, 0};
    e->type         = ENTITY_ENEMY;
    e->orientation  = (Orientation){ h_dir, v_dir};
    e->hp           = 25;
    e->invulnerable = false;
    e->hit          = false;
    e->mv_state     = IDLE;
    e->hitbox       = (Hitbox){
        .type       = HITBOX_RECTANGLE,
        .data       = { .rectangle={ 48, 48 } },
        .get_cells  = get_rectangle_cells,
    };
    e->data         = d;
    e->sm.current_state = &dragao_normal;
    e->sm.transition    = generic_transition;
    e->sm.move_transition = &dragao_move_transition;
    e->sm.get_animation = &dragao_get_animation;
    e->on_collision     = dragao_collision;
    return e;
};
