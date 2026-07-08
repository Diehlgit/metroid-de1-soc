#include <stdint.h>
#include "../include/basics.h"
#include "../include/entity.h"
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

// Os dois buffers são regiões diferentes da mesma memória física
static volatile uint16_t (*buffer[2])[LWIDTH] = {
    (volatile uint16_t (*)[LWIDTH]) VGA_BASE,                        // buffer 0
    (volatile uint16_t (*)[LWIDTH])(VGA_BASE + ROWS * LWIDTH * 2),  // buffer 1
};

static int buf_draw    = 0;  // onde print_game() escreve
static int buf_display = 1;  // o que está na tela agora

#define PIXEL_CTRL_BASE  0xFF203020

static volatile uint32_t *pixel_ctrl =
    (volatile uint32_t *) PIXEL_CTRL_BASE;

static void swap_buffers(void) {
    // diz ao controlador para exibir o buffer que acabou de ser desenhado
    pixel_ctrl[1] = (uint32_t) buffer[buf_draw];

    // aguarda o controlador terminar o frame atual (bit S do status)
    pixel_ctrl[0] = 1;
    while (pixel_ctrl[3] & 0x1);  // espera bit S zerar

    // troca os índices
    int tmp    = buf_draw;
    buf_draw   = buf_display;
    buf_display = tmp;
}

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

    maps_init();
    Grid *area = get_grid(AREA_INICIAL);
    EntityList *ents_area   = get_entidades(AREA_INICIAL);

    EntityList entidades = { .ents = {&Samus}, .count = 1 };
    for (int i = 0; i < ents_area->count; i++) {
        entidades.ents[entidades.count++] = ents_area->ents[i];
    }

    grid_add_entity(area, &Samus);

    while (1) {
        // desenha sempre no buffer invisível
        Coordinates samus_pos = entidades.ents[0]->position;
        print_game(buffer[buf_draw], area, samus_pos, CELL_SIZE);

        // lógica
        game_loop(area, &entidades);

        // exibe o que foi desenhado e libera o outro buffer para o próximo frame
        swap_buffers();
    }
    return 0;
}
