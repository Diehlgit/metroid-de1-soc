#include <stdint.h>
#include "../include/basics.h"
#include "../include/entity.h"
#include "../include/print.h"
#include "../include/physics.h"
#include "../generated/maps.h"
#include "../include/vga.h"
#include "../include/switch.h"
#include <SDL2/SDL.h>

/* ================================================================== */
/*  GAME LOOP                                                         */
/* ================================================================== */

#define TARGET_FPS 60
#define FRAME_MS   (1000 / TARGET_FPS)
static AreaId area_atual = AREA_INICIAL;


Grid* switch_area(AreaId id, Entity *player, EntityList *ents_list) {
    // 1. reseta o grid da área anterior se houver
    Grid *old = get_grid(area_atual);
    if (old) grid_reset(old);

    // 2. atualiza a área atual
    area_atual = id;

    // 3. reseta o pool — libera todas as entidades dinâmicas
    entity_pool_reset();

    // 4. carrega a nova área — map_init re-encadeia os tiles no grid
    Grid *new_area = load_area(id);

    // 5. reconstrói a lista de entidades
    ents_list->count = 0;
    ents_list->ents[ents_list->count++] = player;  // player sempre índice 0

    EntityList *ents_area = get_entidades(id);
    for (int i = 0; i < ents_area->count; i++) {
        if (ents_list->count < 256)
            ents_list->ents[ents_list->count++] = ents_area->ents[i];
    }

    // 6. adiciona o player no novo grid
    grid_add_entity(new_area, player);

    return new_area;
}

static void game_loop(Grid *g, EntityList *list) {
    // FASE 1: coleta intents — nenhuma modificação na lista
    Intent intents[256];
    for (int i = 0; i < list->count; i++) {
        struct Entity *e = list->ents[i];
        intents[i] = e->sm.current_state->decide_input ? e->sm.current_state->decide_input(g, e) : (Intent){0};
    }

    // FASE 2: aplica física e spawns — pode setar should_destroy, não remove ainda
    for (int i = 0; i < list->count; i++) {
        struct Entity *e  = list->ents[i];
        if(e->should_destroy) continue;

        Intent *it = &intents[i];
        physics_step(e, *it, g, list);

        // no game_loop, após physics_step
        if (!e->should_destroy) {
            Animation *anim = e->sm.current_state ? e->sm.current_state->animation : NULL;
            if (anim && anim->frame_duration > 0) {
                e->frame_timer++;
                if (e->frame_timer >= anim->frame_count * anim->frame_duration)
                    e->frame_timer = 0;
            }
        }

        // adiciona spawns ao final da lista — fora do range atual, não afeta iteração
        for (int s = 0; s < it->spawn_count; s++) {
            if (list->count < 256) {
                list->ents[list->count++] = it->spawns[s];
                grid_add_entity(g, it->spawns[s]);
            }
        }
    }

    // FASE 3: remove todos os should_destroy de uma vez, iterando de trás para frente
    for (int i = list->count - 1; i >= 0; i--) {
        Entity *e = list->ents[i];
        if (!e->should_destroy) continue;
        grid_remove_entity(g, e);
        // swap com o último — não desloca tudo, O(1)
        list->ents[i] = list->ents[--list->count];
        list->ents[list->count] = NULL;
    }
}

int main(void) {
    if (vga_init() < 0) return 1;
    //if (uart_init() < 0) return 1;

    clear_screen(0x0000);

    EntityList entidades;
    Entity *Samus = samus_create(16, 16, RIGHT, UP);
    Grid *area = switch_area(area_atual, Samus, &entidades);

	while (1) {
        uint64_t frame_start = SDL_GetTicks64();


        clear_screen(0x0000);
        Coordinates samus_pos = entidades.ents[0]->position;
        print_game(tela, area, samus_pos, CELL_SIZE);
        swap_buffers();
        game_loop(area, &entidades);


        uint64_t frame_end  = SDL_GetTicks64();
        uint64_t frame_time = frame_end - frame_start;
        if (frame_time < FRAME_MS)
            SDL_Delay(FRAME_MS - frame_time);  // espera o resto do frame

        float dt = (SDL_GetTicks64() - frame_start) / 1000.0f;
    }
    return 0;
}
