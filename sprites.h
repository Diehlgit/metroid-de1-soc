#ifndef __SPRITES_H__
#define __SPRITES_H__

#include <stdint.h>
#include "constraints.h"

/* --- Blocos de Samus em pé, olhando para a direita --- */
/* Linha 0 do sprite (linha superior) */
static const uint16_t samus_cabeca[BLOCK_PIXELS] = {
    TRANS,  TRANS,  RED,    RED,    RED,    RED,    TRANS,  TRANS,
    TRANS,  RED,    RED,    RED,    GREEN,  GREEN,  GREEN,  TRANS,
    TRANS,  RED,    RED,    RED,    RED,    RED,    RED,    TRANS,
    TRANS,  TRANS,  RED,    RED,    RED,    RED,    TRANS,  TRANS,
    TRANS,  TRANS,  YELLOW, YELLOW, YELLOW, TRANS,  TRANS,  TRANS,
    TRANS,  YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, TRANS,  TRANS,
    TRANS,  YELLOW, RED,    RED,    YELLOW, BLUE,   BLUE,   GREEN,
    TRANS,  YELLOW, YELLOW, RED,    RED,    BLUE,   BLUE,   GREEN,
};
static const uint16_t samus_corpo[BLOCK_PIXELS] = {
    TRANS,  YELLOW, YELLOW, YELLOW, RED,    RED,    BLUE,   TRANS,
    TRANS,  YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, TRANS,  TRANS,
    TRANS,  YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, TRANS,  TRANS,
    TRANS,  YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, TRANS,  TRANS,
    TRANS,  YELLOW, YELLOW, TRANS,  YELLOW, YELLOW, TRANS,  TRANS,
    TRANS,  YELLOW, YELLOW, TRANS,  YELLOW, YELLOW, TRANS,  TRANS,
    TRANS,  YELLOW, RED,    TRANS,  YELLOW, RED,    TRANS,  TRANS,
    TRANS,  RED,    RED,    TRANS,  RED,    RED,    TRANS,  TRANS,
};


/* --- Blocos do Escorpião (inimigo) 2×2 blocos --- */
static const uint16_t escorpiao_frente[BLOCK_PIXELS] = {
    TRANS,  TRANS,  BROWN,  BROWN,  TRANS,  TRANS,  TRANS,  TRANS,
    TRANS,  BROWN,  RED,    RED,    BROWN,  TRANS,  TRANS,  TRANS,
    BROWN,  RED,    RED,    RED,    RED,    BROWN,  TRANS,  TRANS,
    BROWN,  RED,    WHITE,  RED,    WHITE,  RED,    BROWN,  TRANS,
    BROWN,  RED,    RED,    RED,    RED,    RED,    BROWN,  TRANS,
    TRANS,  BROWN,  RED,    RED,    RED,    BROWN,  TRANS,  TRANS,
    TRANS,  TRANS,  BROWN,  BROWN,  BROWN,  TRANS,  TRANS,  TRANS,
    TRANS,  TRANS,  TRANS,  BROWN,  BROWN,  TRANS,  TRANS,  TRANS,
};
static const uint16_t escorpiao_tras[BLOCK_PIXELS] = {
    TRANS,  TRANS,  TRANS,  TRANS,  BROWN,  BROWN,  TRANS,  TRANS,
    TRANS,  TRANS,  TRANS,  BROWN,  RED,    RED,    BROWN,  TRANS,
    TRANS,  TRANS,  BROWN,  RED,    RED,    RED,    RED,    BROWN,
    TRANS,  BROWN,  RED,    RED,    RED,    RED,    RED,    BROWN,
    TRANS,  BROWN,  RED,    RED,    RED,    RED,    RED,    BROWN,
    TRANS,  TRANS,  BROWN,  RED,    RED,    RED,    BROWN,  TRANS,
    TRANS,  TRANS,  TRANS,  BROWN,  BROWN,  TRANS,  TRANS,  TRANS,
    TRANS,  TRANS,  BROWN,  BROWN,  TRANS,  TRANS,  TRANS,  TRANS,
};

/* --- Projétil 1×1 bloco --- */
static const uint16_t blk_projetil[BLOCK_PIXELS] = {
    TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,
    TRANS,  TRANS,  YELLOW, YELLOW, TRANS,  TRANS,  TRANS,  TRANS,
    TRANS,  YELLOW, ORANGE, ORANGE, YELLOW, TRANS,  TRANS,  TRANS,
    TRANS,  YELLOW, ORANGE, WHITE,  ORANGE, YELLOW, TRANS,  TRANS,
    TRANS,  YELLOW, ORANGE, ORANGE, YELLOW, TRANS,  TRANS,  TRANS,
    TRANS,  TRANS,  YELLOW, YELLOW, TRANS,  TRANS,  TRANS,  TRANS,
    TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,
    TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,  TRANS,
};

/* --- Bloco de tijolo (mapa) --- */
static const uint16_t blk_tijolo[BLOCK_PIXELS] = {
    DKGRAY, DKGRAY, DKGRAY, DKGRAY, DKGRAY, DKGRAY, DKGRAY, DKGRAY,
    DKGRAY, LTGRAY, LTGRAY, LTGRAY, DKGRAY, LTGRAY, LTGRAY, DKGRAY,
    DKGRAY, LTGRAY, GRAY,   LTGRAY, DKGRAY, LTGRAY, GRAY,   DKGRAY,
    DKGRAY, LTGRAY, LTGRAY, LTGRAY, DKGRAY, LTGRAY, LTGRAY, DKGRAY,
    DKGRAY, DKGRAY, DKGRAY, DKGRAY, DKGRAY, DKGRAY, DKGRAY, DKGRAY,
    DKGRAY, LTGRAY, LTGRAY, LTGRAY, LTGRAY, LTGRAY, LTGRAY, DKGRAY,
    DKGRAY, LTGRAY, GRAY,   LTGRAY, LTGRAY, GRAY,   LTGRAY, DKGRAY,
    DKGRAY, DKGRAY, DKGRAY, DKGRAY, DKGRAY, DKGRAY, DKGRAY, DKGRAY,
};

/* --- Bloco vazio (fundo) --- */
static const uint16_t blk_vazio[BLOCK_PIXELS] = {
    BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
    BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
    BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
    BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
    BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
    BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
    BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
    BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,
};

/* ================================================================== */
/*  SPRITE — struct pedida no enunciado                                 */
/*                                                                      */
/*  Cada bloco dentro do sprite é um array [8][8] de uint16_t.         */
/*  Para manter compatibilidade com o sistema de draw_sprite abaixo,   */
/*  armazenamos os blocos linearizados: bloco[i] = pixels[8*8] do      */
/*  bloco na posição (i / bx, i % bx) da grade do sprite.             */
/* ================================================================== */

typedef struct {
    int bx;              /* largura em blocos                          */
    int by;              /* altura em blocos                           */
    /* vetor de bx*by blocos; cada bloco AGORA tem tamanho "variável"       */
    const uint16_t **blocos;
} Sprite;

/* ================================================================== */
/*  SPRITES (instâncias de Sprite)                                      */
/* ================================================================== */

/* Arrays de ponteiros para os blocos de cada sprite */
static const uint16_t *samus_blocos[2] = {
    samus_cabeca,  samus_corpo,
};
static const Sprite SPR_SAMUS = { 1, 2, (const uint16_t **)samus_blocos };

static const uint16_t *scorpio_blocos[2] = {
    escorpiao_frente, escorpiao_tras,
};
static const Sprite SPR_SCORPIO = { 2, 1, (const uint16_t **)scorpio_blocos };

static const uint16_t *projetil_blocos[1] = {
    blk_projetil,
};
static const Sprite SPR_PROJETIL = { 1, 1, (const uint16_t **)projetil_blocos };

#endif