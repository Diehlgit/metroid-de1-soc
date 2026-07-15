#include <stdint.h>
#include "../include/basics.h"
#include "../include/grid.h"
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

#define TARGET_FPS 30
#define FRAME_MS   (1000 / TARGET_FPS)
Grid *area = NULL;
static AreaId area_atual = AREA_PUZZLE;

Grid* switch_area(AreaId id, Entity *player, EntityList *ents_list) {
    // 1. reseta o grid da área anterior se houver
    Grid *old = get_grid(area_atual);
    if (old) grid_reset(old);

    // 2. atualiza a área atual
    area_atual = id;

    // 3. reseta o pool — libera todas as entidades dinâmicas
    entity_pool_reset();

    // 4. zera a EntityList do mapa antes de chamar map_init
    EntityList *map_list = get_entidades(id);
    map_list->count = 0;

    // 5. carrega a nova área — map_init re-encadeia os tiles no grid
    Grid *new_area = load_area(id);  // agora map_add_entity começa do zero

    // 6. reconstrói a lista de entidades
    ents_list->count = 0;
    ents_list->ents[ents_list->count++] = player;
    for (int i = 0; i < map_list->count; i++) {
        if (ents_list->count < 256)
            ents_list->ents[ents_list->count++] = map_list->ents[i];
    }

    // 7. adiciona o player no novo grid
    grid_add_entity(new_area, player);
    return new_area;
}

static void game_loop(Grid **g, EntityList *list){
    printf("Entity count = %d\n", list->count);

    for (int i = 0; i < list->count; i++) {
        printf("%d: %p type=%d\n",
               i,
               (void*)list->ents[i],
               list->ents[i]->mv_state);
    }

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

        // adiciona spawns ao final da lista — fora do range atual, não afeta iteração
        for (int s = 0; s < it->spawn_count; s++) {
            printf("spawn: %p\n", (void*)it->spawns[s]->type);
            if (list->count < 256) {
                list->ents[list->count++] = it->spawns[s];
                grid_add_entity(*g, it->spawns[s]);
            }
        }

        // no game_loop, após physics_step
        if (!e->should_destroy) {
            printf("removendo %p\n", e);
            Animation *anim = e->sm.current_state ? e->sm.get_animation(e) : NULL;
            if (anim && anim->frame_duration > 0) {
                e->frame_timer++;
                if (e->frame_timer >= anim->frame_count * anim->frame_duration)
                    e->frame_timer = 0;
            }
        }
    }

    // FASE 3: remove todos os should_destroy de uma vez, iterando de trás para frente
    for (int i = list->count - 1; i >= 0; i--) {
        Entity *e = list->ents[i];
        if (!e->should_destroy) continue;
        grid_remove_entity(*g, e);
        // swap com o último — não desloca tudo, O(1)
        list->ents[i] = list->ents[--list->count];
        list->ents[list->count] = NULL;
    }
}

int main(void) {
    if (vga_init() < 0) return 1;
    //if (uart_init() < 0) return 1;

    clear_screen(0x0000);

    EntityList entidades = { .count = 0 };
    Entity *Samus = samus_create(32, 16, RIGHT, UP);
    Grid *area = switch_area(area_atual, Samus, &entidades);

	while (1) {
        uint64_t frame_start = SDL_GetTicks64();

        clear_screen(0x0000);
        Coordinates samus_pos = entidades.ents[0]->position;
        print_game(tela, area, samus_pos, CELL_SIZE);
        swap_buffers();
        game_loop(&area, &entidades);


        uint64_t frame_end  = SDL_GetTicks64();
        uint64_t frame_time = frame_end - frame_start;
        if (frame_time < FRAME_MS)
            SDL_Delay(FRAME_MS - frame_time);  // espera o resto do frame

        float dt = (SDL_GetTicks64() - frame_start) / 1000.0f;
    }
    return 0;
}
