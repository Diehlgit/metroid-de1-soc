#ifndef __CONSTRAINTS_H__
#define __CONSTRAINTS_H__

/* ================================================================== */
/*  CORES RGB565                                                        */
/* ================================================================== */
#define BLACK    0x0000
#define WHITE    0xFFFF
#define RED      0xF800
#define GREEN    0x07E0
#define BLUE     0x001F
#define GRAY     0x8410
#define YELLOW   0xFFE0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define ORANGE   0xFC00
#define DKGREEN  0x03E0
#define DKGRAY   0x4208
#define LTGRAY   0xC618
#define BROWN    0x8200
#define TRANS    0x8001  /* cor usada como transparente — não desenhada */

/* ================================================================== */
/*  GRADE DE BLOCOS 8×8                                                 */
/* ================================================================== */
#define BSIZE  8          /* pixels por bloco                          */
#define GCOLS  (COLS / BSIZE)   /* 40                                  */
#define GROWS  (ROWS / BSIZE)   /* 30                                   */
#define BLOCK_PIXELS (BSIZE * BSIZE)  /* 64 pixels por bloco          */

/* ================================================================== */
/*  DISPLAY VGA                                                         */
/* ================================================================== */
#define VGA_BASE  0xC8000000
#define LWIDTH    512           /* largura física da linha (pixels)    */
#define COLS      320           /* colunas visíveis                    */
#define ROWS      240           /* linhas visíveis                     */


/* ================================================================== */
/*  FÍSICA — aplica velocidade e gravidade                              */
/* ================================================================== */
#define GRAVIDADE    1      /* aceleração vertical (pixels/frame²)     */
#define VX_ANDAR     3      /* velocidade horizontal do jogador        */
#define VY_PULO     -8      /* velocidade inicial do pulo              */
#define VX_SCORPIO   1      /* velocidade do escorpião                 */
#define VX_PROJETIL  5      /* velocidade do projétil                  */
#define VY_MAX       8      /* velocidade vertical máxima de queda     */

#endif