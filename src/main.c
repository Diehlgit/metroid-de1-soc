#include <stdint.h>
#include "../include/basics.h"
#include "../include/entity.h"
#include "../include/print.h"
#include "../include/physics.h"
#include "../generated/maps.h"
#include "../include/vga.h"
#ifdef RUNNING_LINUX
#include "../include/input_linux.h"
#endif

#include <stdlib.h>   /* rand() */

/* ================================================================== */
/*  GAME LOOP                                                         */
/* ================================================================== */

#define CELL_SIZE 16

static void game_loop(Grid *g, EntityList *list) {
    Intent intents[256];
    for (int i = 0; i < list->count; i++) {
        struct Entity *e = list->ents[i];
        intents[i] = e->think ? e->think(g, e) : (Intent){0};
    }

    // aplica tudo depois
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
            // swap com o último para remover da lista
            list->ents[i] = list->ents[--list->count];
            i--;  // revisita essa posição
        }
    }
}

int main(void) {
    #ifdef RUNNING_LINUX
        if (input_init() < 0)
            return 1;
    #endif

    if (vga_init() < 0)
        return 1;

    // Cria a entidade Player
    Entity Samus = {
        .position       = { 16,16 },
        .type           = ENTITY_PLAYER,
        .hitbox         = {
            .type      = HITBOX_RECTANGLE,
            .data      = { .rectangle={ 16, 32 } },
            .get_cells = get_rectangle_cells,
        },
        .current_sprite = &SPRITE_SAMUS,
        .think          = player_input,
        .on_collision   = samus_collision,
    };

    maps_init();
    Grid *area = get_grid(AREA_INICIAL);
    EntityList *ents_area   = get_entidades(AREA_INICIAL);

    EntityList entidades = { .ents = {&Samus}, .count = 1 };
    for (int i = 0; i < ents_area->count; i++) {
        entidades.ents[entidades.count++] = ents_area->ents[i];
    }

    grid_add_entity(area, &Samus);
    swap_buffers();

    while (1) {
        // desenha sempre no buffer invisível
        Coordinates samus_pos = entidades.ents[0]->position;
        print_game(tela, area, samus_pos, CELL_SIZE);

        // lógica
        game_loop(area, &entidades);

        // exibe o que foi desenhado e libera o outro buffer para o próximo frame
        swap_buffers();
    }
    return 0;
}
