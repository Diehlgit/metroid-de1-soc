/*
 * Metroid-like — CPUlator / DE1-SoC (ARM Cortex-A9)
 * CIC0130 - Introdução aos Sistemas Embarcados — UnB
 *
 * Display : 320×240 pixels, blocos de 8×8
 * Grade   : 40×30 blocos
 */

#include <stdint.h>
#include <stdlib.h>   /* rand() */

#include "constraints.h"
#include "sprites.h"
#include "maps.h"
#include "entities.c"
#include "vga.c"
#include "jtag_uart.c"

/* ================================================================== */
/*  INICIALIZAÇÃO                                                       */
/* ================================================================== */
static void game_init(void)
{
    int i;

    uint32_t current_front_buffer = *pixel_ctrl_ptr;

    // evita que o buffer de desenho e o buffer que tá mostrando apontem para o mesmo lugar no início do jogo
    if (current_front_buffer == 0xC0000000) {
        *(pixel_ctrl_ptr + 1) = 0xC8000000;
    }
    else {
        *(pixel_ctrl_ptr + 1) = 0xC0000000;
    }

    tela = (volatile uint16_t (*)[LWIDTH]) *(pixel_ctrl_ptr + 1);

    clear_screen();

    /* Limpa lista de entidades */
    for (i = 0; i < MAX_ENTIDADES; i++) entidades[i].ativo = 0;
    num_entidades = 0;

    /* Samus — 2 blocos × 3 blocos = 16×24 pixels */
    entidade_add(TIPO_SAMUS,   24, 200, 5,
                 DIR_DIR, -1, 0, &SPR_SAMUS, 16, 24);

    /* Dois escorpiões — 2 blocos × 2 blocos = 16×16 pixels */
    entidade_add(TIPO_SCORPIO, 160, 200, 3,
                 DIR_ESQ, -1, 0, &SPR_SCORPIO, 16, 16);
    entidade_add(TIPO_SCORPIO, 260,  80, 3,
                 DIR_DIR, -1, 0, &SPR_SCORPIO, 16, 16);

    print_mapa();

    uart_print("\r\nMetroid — CIC0130 UnB\r\n");
    uart_print("a/d = mover | w = pular | f = atirar\r\n");
}

/* ================================================================== */
/*  LOOP PRINCIPAL                                                      */
/* ================================================================== */
static void game_loop(void)
{
    int i, j;
    char key;
    Entidade *samus = &entidades[0]; /* Samus é sempre a entidade 0   */

    while (1) {
        tela = (volatile uint16_t (*)[LWIDTH]) *(pixel_ctrl_ptr + 1);

        /* ---- 1. Lê input ---- */
        key = uart_read_char();

        /* ---- 2. Itera sobre entidades: IA + física ---- */
        for (i = 0; i < num_entidades; i++) {
            Entidade *e = &entidades[i];
            if (!e->ativo) continue;

            /* Executa IA da entidade */
            switch (e->tipo) {
                case TIPO_SAMUS:
                    ia_samus(e, key);
                    break;
                case TIPO_SCORPIO:
                    ia_scorpio(e, samus);
                    break;
                case TIPO_PROJETIL:
                    ia_projetil(e, i);
                    if (!e->ativo) continue;
                    break;
            }

            /* Aplica física (movimento + colisão com mapa) */
            aplica_fisica(e);
        }

        /* ---- 3. Colisões entidade × entidade ---- */
        for (i = 0; i < num_entidades; i++) {
            if (!entidades[i].ativo || entidades[i].tipo != TIPO_PROJETIL)
                continue;
            for (j = 0; j < num_entidades; j++) {
                if (!entidades[j].ativo) continue;
                if (i == j) continue;
                /* Projétil da Samus acerta inimigo */
                if (entidades[i].dono == TIPO_SAMUS &&
                    entidades[j].tipo == TIPO_SCORPIO &&
                    rect_colide(&entidades[i], &entidades[j])) {
                    entidades[j].vida -= entidades[i].dano;
                    entidade_remove(i);
                    if (entidades[j].vida <= 0) entidade_remove(j);
                    break;
                }
                /* Projétil do inimigo acerta Samus */
                if (entidades[i].dono == TIPO_SCORPIO &&
                    entidades[j].tipo == TIPO_SAMUS &&
                    rect_colide(&entidades[i], &entidades[j])) {
                    entidades[j].vida -= entidades[i].dano;
                    entidade_remove(i);
                    break;
                }
            }
        }

        /* Samus morreu? */
        if (!samus->ativo || samus->vida <= 0) {
            uart_print("\r\n=== GAME OVER ===\r\n");
            return;
        }

        /* ---- 4. Redesenha entidades na nova posição ---- */
        /*
         * Redesenha o mapa antes das entidades para cobrir rastros.
         * Em uma versão otimizada, redesenharia só as áreas afetadas.
         */
        print_mapa();

        for (i = 0; i < num_entidades; i++) {
            Entidade *e = &entidades[i];
            if (!e->ativo) continue;
            draw_sprite(e->sprite, e->x, e->y,
                        e->direcao == DIR_ESQ ? 1 : 0);
        }

        swap_buffers();

        /* HUD: vida no terminal */
        uart_print("\rVida: ");
        uart_print_int(samus->vida);
        uart_print("   ");

        /* Delay simples */
        {
            volatile unsigned long d;
            for (d = 0; d < 150UL; d++);
        }
    }
}

/* ================================================================== */
/*  MAIN                                                                */
/* ================================================================== */
int main(void)
{
    uart_print("\r\n*** METROID — CIC0130 UnB ***\r\n");

    while (1) {
        game_init();
        game_loop();

        uart_print("Pressione qualquer tecla para reiniciar...\r\n");
        while (!uart_read_char());
    }
    return 0;
}
