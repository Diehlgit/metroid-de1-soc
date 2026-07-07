#ifndef __VGA_C__
#define __VGA_C__

#include "sprites.h"
#include "maps.h"

// sempre aponta pro back buffer atual
static volatile uint16_t (*tela)[LWIDTH];

#ifdef RUNNING_LINUX
static volatile uint32_t *pixel_ctrl_ptr = NULL;
static void *vga_mem_virtual_c8 = NULL;
static void *vga_mem_virtual_c0 = NULL;
#else
static volatile uint32_t *const pixel_ctrl_ptr = (volatile uint32_t *) 0xFF203020;
#endif

/* ================================================================== */
/*  FUNÇÕES DE DESENHO                                                */
/* ================================================================== */

/*
 * Desenha um sprite na posição em PIXELS (px, py).
 * Pixels TRANS são ignorados (transparência).
 * mirror_h=1 espelha horizontalmente (para olhar à esquerda).
 */
static void draw_sprite(const Sprite *spr, int px, int py, int mirror_h)
{
    int brow, bcol, r, c;
    for (brow = 0; brow < spr->by; brow++) {
        for (bcol = 0; bcol < spr->bx; bcol++) {
            int bi = brow * spr->bx + (mirror_h ? (spr->bx - 1 - bcol) : bcol);
            const uint16_t *bloco = spr->blocos[bi];
            int base_r = py + brow * BSIZE;
            int base_c = px + bcol * BSIZE;
            for (r = 0; r < BSIZE; r++) {
                for (c = 0; c < BSIZE; c++) {
                    int sc = mirror_h ? (BSIZE - 1 - c) : c;
                    uint16_t cor = bloco[r * BSIZE + sc];
                    int pr = base_r + r;
                    int pc = base_c + c;
                    if (cor != TRANS && pr >= 0 && pr < ROWS && pc >= 0 && pc < COLS)
                        tela[pr][pc] = cor;
                }
            }
        }
    }
}

/* Apaga a área de um sprite com pixels pretos. */
static void clear_sprite(const Sprite *spr, int px, int py)
{
    int brow, bcol, r, c;
    for (brow = 0; brow < spr->by; brow++) {
        for (bcol = 0; bcol < spr->bx; bcol++) {
            int base_r = py + brow * BSIZE;
            int base_c = px + bcol * BSIZE;
            for (r = 0; r < BSIZE; r++) {
                for (c = 0; c < BSIZE; c++) {
                    int pr = base_r + r;
                    int pc = base_c + c;
                    if (pr >= 0 && pr < ROWS && pc >= 0 && pc < COLS)
                        tela[pr][pc] = BLACK;
                }
            }
        }
    }
}

/* Desenha um bloco de mapa na grade (brow, bcol). */
static void draw_map_block(int brow, int bcol, const uint16_t bloco[BLOCK_PIXELS])
{
    int r, c;
    int pr = brow * BSIZE, pc = bcol * BSIZE;
    for (r = 0; r < BSIZE; r++)
        for (c = 0; c < BSIZE; c++)
            tela[pr + r][pc + c] = bloco[r * BSIZE + c];
}

/* Limpa toda a tela. */
static void clear_screen(void)
{
    int r, c;
    for (r = 0; r < ROWS; r++)
        for (c = 0; c < COLS; c++)
            tela[r][c] = BLACK;
}

/* troca os buffers de desenho*/
static void swap_buffers() {
    *pixel_ctrl_ptr = 1; // solicita a troca de buffers pra placa

#ifdef RUNNING_LINUX
    usleep(16666); // espera o sincronismo vertical
    
    uint32_t current_front = *pixel_ctrl_ptr;
    if (current_front == 0xC0000000) {
        tela = (volatile uint16_t (*)[LWIDTH]) vga_mem_virtual_c8;
    } else {
        tela = (volatile uint16_t (*)[LWIDTH]) vga_mem_virtual_c0;
    }
    #else
        while ((*(pixel_ctrl_ptr + 3) & 0x1) != 0);
        tela = (volatile uint16_t (*)[LWIDTH]) *(pixel_ctrl_ptr + 1);
    #endif
}

/* ================================================================== */
/*  IMPRESSÃO DO MAPA                                                   */
/* ================================================================== */
static void print_mapa(void)
{
    int r, c;
    for (r = 0; r < GROWS; r++)
        for (c = 0; c < GCOLS; c++)
            draw_map_block(r, c, MAPA[r][c] ? blk_tijolo : blk_vazio);
}

#endif