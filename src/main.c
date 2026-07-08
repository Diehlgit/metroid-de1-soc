#include <stdint.h>
#include "../include/structs.h"
#include "../include/print.h"
#include "../include/physics.h"
#include "../generated/maps.h"

#include <stdlib.h>   /* rand() */

/* ================================================================== */
/*  DISPLAY VGA                                                       */
/* ================================================================== */
#define VGA_BASE  0xC8000000
#define LWIDTH    512           /* largura física da linha (pixels)   */
#define COLS      320           /* colunas visíveis                   */
#define ROWS      240           /* linhas visíveis                    */

static volatile uint16_t (*tela)[LWIDTH] =
    (volatile uint16_t (*)[LWIDTH]) VGA_BASE;

/* ================================================================== */
/*  JTAG-UART                                                         */
/* ================================================================== */
#define UART_BASE   0xFF201000
static volatile uint32_t * const uart = (volatile uint32_t *) UART_BASE;
#define UART_RVALID (1 << 15)

static char uart_read_char(void)
{
    uint32_t d = uart[0];
    if (d & UART_RVALID) return (char)(d & 0xFF);
    return 0;
}

static void uart_write_char(char c)
{
    while ((uart[1] >> 16) == 0);
    uart[0] = (uint32_t)c;
}

static void uart_print(const char *s)
{
    while (*s) uart_write_char(*s++);
}

static void uart_print_int(int n)
{
    char buf[12]; int i = 10; buf[11] = '\0';
    if (n == 0) { uart_write_char('0'); return; }
    if (n < 0)  { uart_write_char('-'); n = -n; }
    while (n > 0 && i >= 0) { buf[i--] = '0' + (n % 10); n /= 10; }
    uart_print(buf + i + 1);
}

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

        if (it->dx || it->dy)
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
    uart_print("\r\n*** METROID — CIC0130 UnB ***\r\n");

    // Cria a entidade Player
    Entity Samus = {
        .position       = { 152,120 },
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

    EntityList entidades = {
        .ents = {&Samus},
        .count = 1,
    };

    // Pega a área e as outras entidades
    maps_init();
    Grid *area = get_grid(AREA_STARTING_AREA);
    EntityList *entidades_area = get_entidades(AREA_STARTING_AREA);

    for (int i = 0; i < entidades_area->count; i++) {
        entidades.ents[entidades.count++] = entidades_area->ents[i];
    }

    while (1) {
        Coordinates samus_pos = entidades.ents[0]->position;
        print_game(area, samus_pos, CELL_SIZE);
        game_loop(area, &entidades);

        uart_print("Pressione qualquer tecla para reiniciar...\r\n");
        while (!uart_read_char());
    }
    return 0;
}
