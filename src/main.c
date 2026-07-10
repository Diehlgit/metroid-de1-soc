#include <stdint.h>
#include "../include/basics.h"
#include "../include/entity.h"
#include "../include/print.h"
#include "../include/physics.h"
#include "../generated/maps.h"
#include "../include/vga.h"
#include <SDL2/SDL.h>

/* ================================================================== */
/*  GAME LOOP                                                         */
/* ================================================================== */

#define TARGET_FPS 60
#define FRAME_MS   (1000 / TARGET_FPS)

Grid* game_init(Entity *player_ptr, EntityList *ents_list) {
    maps_init();

    // 1. Busca a área e o mapa
    Grid *area = get_grid(AREA_INICIAL);
    EntityList *ents_area = get_entidades(AREA_INICIAL);

    // 2. Configura os dados do Player diretamente no ponteiro seguro que veio do main
    *player_ptr = (Entity){
        .position       = { 16, 16 },
		.velocity 		= { 0, 0 },
		.type           = ENTITY_PLAYER,
        .facing         = RIGHT,
        .should_destroy = 0,
        .hitbox         = {
            .type      = HITBOX_RECTANGLE,
            .data      = { .rectangle = { 16, 32 } },
            .get_cells = get_rectangle_cells,
        },
        .current_sprite = &SPRITE_SAMUS,
        .think          = player_input,
        .on_collision   = samus_collision,
    };

    // 3. Adiciona o player no grid físico
    grid_add_entity(area, player_ptr);

    // 4. Inicializa a lista de entidades do loop limpando o contador
    ents_list->count = 0;
    ents_list->ents[ents_list->count++] = player_ptr;

    // 5. Copia as demais entidades do mapa
    for (int i = 0; i < ents_area->count; i++) {
        if (ents_list->count < 256) { // Proteção contra estouro de array
            ents_list->ents[ents_list->count++] = ents_area->ents[i];
        }
    }

    return area; // Retorna o ponteiro correto para o main salvar
}

static void game_loop(Grid *g, EntityList *list) {
    Intent intents[256];
	for (int i = 0; i < list->count; i++) {
        struct Entity *e = list->ents[i];
        intents[i] = e->think ? e->think(g, e) : (Intent){0};
    }

    for (int i = 0; i < list->count; i++) {
        struct Entity *e  = list->ents[i];
        Intent        *it = &intents[i];
        physics_step(g, e, *it);

        for (int s = 0; s < it->spawn_count; s++) {
            grid_add_entity(g, it->spawns[s]);
            if (list->count < 256)
                list->ents[list->count++] = it->spawns[s];
        }

        if (it->destroy_self) {
            grid_remove_entity(g, e);
            list->ents[i] = list->ents[--list->count];
            i--;
        }
    }
}

int main(void) {
    if (vga_init() < 0) return 1;
    //if (uart_init() < 0) return 1;

    clear_screen(0x0000);

    Entity Samus;
    EntityList entidades;
    Grid *area = game_init(&Samus, &entidades);

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
