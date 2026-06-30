/*
 * Metroid-like — CPUlator / DE1-SoC (ARM Cortex-A9)
 * CIC0130 - Introdução aos Sistemas Embarcados — UnB
 *
 * Display : 320×240 pixels, blocos de 8×8
 * Grade   : 40×30 blocos
 */

#include <stdint.h>
#include <stdlib.h>   /* rand() */

/* ================================================================== */
/*  DISPLAY VGA                                                         */
/* ================================================================== */
#define VGA_BASE  0xC8000000
#define LWIDTH    512           /* largura física da linha (pixels)    */
#define COLS      320           /* colunas visíveis                    */
#define ROWS      240           /* linhas visíveis                     */

static volatile uint16_t (*tela)[LWIDTH] =
    (volatile uint16_t (*)[LWIDTH]) VGA_BASE;

/* ================================================================== */
/*  JTAG-UART                                                           */
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
#define GROWS  (ROWS / BSIZE)   /* 30                                  */

/* ================================================================== */
/*  SPRITE — struct pedida no enunciado                                 */
/*                                                                      */
/*  Cada bloco dentro do sprite é um array [8][8] de uint16_t.         */
/*  Para manter compatibilidade com o sistema de draw_sprite abaixo,   */
/*  armazenamos os blocos linearizados: bloco[i] = pixels[8*8] do      */
/*  bloco na posição (i / bx, i % bx) da grade do sprite.             */
/* ================================================================== */
#define BLOCK_PIXELS (BSIZE * BSIZE)  /* 64 pixels por bloco          */

typedef struct {
    int bx;              /* largura em blocos                          */
    int by;              /* altura em blocos                           */
    /* vetor de bx*by blocos; cada bloco tem BLOCK_PIXELS pixels       */
    const uint16_t (*blocos)[BLOCK_PIXELS];
} Sprite;

/* ================================================================== */
/*  DADOS DOS BLOCOS (8×8 pixels cada)                                  */
/* ================================================================== */

/* --- Blocos de Samus em pé, olhando para a direita --- */
/* Linha 0 do sprite (linha superior) */
static const uint16_t samus_cabeça[BLOCK_PIXELS] = {
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
/*  SPRITES (instâncias de Sprite)                                      */
/* ================================================================== */

/* Arrays de ponteiros para os blocos de cada sprite */
static const uint16_t (* const samus_blocos[2])[BLOCK_PIXELS] = {
    samus_cabeça,  samus_corpo,
};
static const Sprite SPR_SAMUS = { 1, 2, samus_blocos };

static const uint16_t (* const scorpio_blocos[2])[BLOCK_PIXELS] = {
    escorpiao_frente, escorpiao_tras,
};
static const Sprite SPR_SCORPIO = { 2, 1, scorpio_blocos };

static const uint16_t (* const projetil_blocos[1])[BLOCK_PIXELS] = {
    blk_projetil,
};
static const Sprite SPR_PROJETIL = { 1, 1, projetil_blocos };

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

/* ================================================================== */
/*  MAPA                                                                */
/*                                                                      */
/*  Valores: 0 = vazio (passa), 1 = tijolo (colide)                    */
/*  Grade 40 colunas × 30 linhas                                       */
/* ================================================================== */
static const uint8_t MAPA[GROWS][GCOLS] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

/* ================================================================== */
/*  COLISÃO COM O MAPA                                                  */
/*                                                                      */
/*  Recebe posição em pixels (px, py) e dimensão em pixels (w, h).     */
/*  Verifica os quatro cantos do retângulo.                             */
/*  Retorna 1 se colide com tijolo, 0 se livre.                        */
/* ================================================================== */
static int colide_mapa(int px, int py, int w, int h)
{
    /* Converte cada canto para coordenadas de bloco e consulta o mapa */
    int c0, c1, r0, r1;
    c0 = px / BSIZE;
    c1 = (px + w - 1) / BSIZE;
    r0 = py / BSIZE;
    r1 = (py + h - 1) / BSIZE;

    /* Garante limites */
    if (c0 < 0) c0 = 0; if (c1 >= GCOLS) c1 = GCOLS - 1;
    if (r0 < 0) r0 = 0; if (r1 >= GROWS) r1 = GROWS - 1;

    return MAPA[r0][c0] || MAPA[r0][c1] ||
           MAPA[r1][c0] || MAPA[r1][c1];
}

/* ================================================================== */
/*  ENTIDADES                                                           */
/* ================================================================== */

/* Tipos de entidade */
#define TIPO_SAMUS    0
#define TIPO_SCORPIO  1
#define TIPO_PROJETIL 2

/* Direções horizontais */
#define DIR_ESQ  0
#define DIR_DIR  1

/* Estados verticais */
#define VERT_CHAO   0   /* em pé no chão                               */
#define VERT_SUBINDO 1
#define VERT_CAINDO  2

/* Limite de entidades simultâneas */
#define MAX_ENTIDADES 16

typedef struct {
    int ativo;           /* 0 = slot livre                             */
    int tipo;            /* TIPO_*                                     */

    /* Posição e física */
    int x, y;           /* posição atual em pixels (canto sup-esq)    */
    int vx, vy;         /* velocidade em pixels por frame              */
    int no_chao;        /* 1 se está apoiado no chão                  */

    /* Atributos */
    int vida;
    int direcao;        /* DIR_ESQ ou DIR_DIR                         */
    int estado_vert;    /* VERT_*                                      */
    int jump_ticks;     /* frames restantes de subida do pulo         */
    int shoot_cd;       /* cooldown de disparo (frames)               */

    /* Para projéteis: quem atirou (TIPO_SAMUS ou TIPO_SCORPIO) */
    int dono;
    int dano;

    /* Sprite e tamanho em pixels */
    const Sprite *sprite;
    int w, h;           /* largura e altura em pixels                  */
} Entidade;

static Entidade entidades[MAX_ENTIDADES];
static int num_entidades = 0;

/* ================================================================== */
/*  GERENCIAMENTO DA LISTA DE ENTIDADES                                 */
/* ================================================================== */

static void entidade_remove(int i)
{
    /* Apaga da tela e marca slot como inativo */
    clear_sprite(entidades[i].sprite, entidades[i].x, entidades[i].y);
    entidades[i].ativo = 0;
}

static int entidade_add(int tipo, int x, int y, int vida,
                        int direcao, int dono, int dano,
                        const Sprite *spr, int w, int h)
{
    int i;
    for (i = 0; i < MAX_ENTIDADES; i++) {
        if (!entidades[i].ativo) {
            Entidade *e = &entidades[i];
            e->ativo       = 1;
            e->tipo        = tipo;
            e->x           = x;
            e->y           = y;
            e->vx          = 0;
            e->vy          = 0;
            e->no_chao     = 0;
            e->vida        = vida;
            e->direcao     = direcao;
            e->estado_vert = VERT_CAINDO;
            e->jump_ticks  = 0;
            e->shoot_cd    = 0;
            e->dono        = dono;
            e->dano        = dano;
            e->sprite      = spr;
            e->w           = w;
            e->h           = h;
            if (i >= num_entidades) num_entidades = i + 1;
            return i;
        }
    }
    return -1;  /* lista cheia */
}

/* ================================================================== */
/*  FÍSICA — aplica velocidade e gravidade                              */
/* ================================================================== */
#define GRAVIDADE    1      /* aceleração vertical (pixels/frame²)     */
#define VX_ANDAR     3      /* velocidade horizontal do jogador        */
#define VY_PULO     -8      /* velocidade inicial do pulo              */
#define VX_SCORPIO   1      /* velocidade do escorpião                 */
#define VX_PROJETIL  5      /* velocidade do projétil                  */
#define VY_MAX       8      /* velocidade vertical máxima de queda     */

/*
 * Move a entidade respeitando a colisão.
 * Separa eixo X e eixo Y — técnica clássica para evitar
 * que o personagem "grude" nas quinas.
 */
static void aplica_fisica(Entidade *e)
{
    int nx, ny;

    /* --- Eixo X --- */
    nx = e->x + e->vx;
    if (colide_mapa(nx, e->y, e->w, e->h)) {
        e->vx = 0;          /* para na parede                         */
        nx = e->x;
    }
    e->x = nx;

    /* --- Eixo Y --- */
    ny = e->y + e->vy;
    if (e->vy >= 0 && colide_mapa(e->x, ny, e->w, e->h)) {
        /* Bateu no chão ou teto por baixo */
        e->vy     = 0;
        e->no_chao = 1;
        ny        = e->y;   /* mantém posição anterior                */
    } else if (e->vy < 0 && colide_mapa(e->x, ny, e->w, e->h)) {
        /* Bateu na cabeça */
        e->vy        = 0;
        e->jump_ticks = 0;
        ny           = e->y;
    } else {
        e->no_chao = 0;
    }
    e->y = ny;

    /* Gravidade — acumula vy até VY_MAX */
    if (!e->no_chao) {
        e->vy += GRAVIDADE;
        if (e->vy > VY_MAX) e->vy = VY_MAX;
    } else {
        if (e->vy > 0) e->vy = 0;
    }

    /* Limites da tela */
    if (e->x < 0) e->x = 0;
    if (e->x + e->w > COLS) e->x = COLS - e->w;
    if (e->y < 0) e->y = 0;
    if (e->y + e->h > ROWS) e->y = ROWS - e->h;
}

/* ================================================================== */
/*  IA DO JOGADOR — lê teclado via UART                                 */
/* ================================================================== */
static void ia_samus(Entidade *e, char key)
{
    /* Friction horizontal: desacelera ao não pressionar nada */
    e->vx = 0;

    if (key == 'a' || key == 'A') {
        e->vx     = -VX_ANDAR;
        e->direcao = DIR_ESQ;
    } else if (key == 'd' || key == 'D') {
        e->vx     = VX_ANDAR;
        e->direcao = DIR_DIR;
    }

    /* Pulo: só pode pular quando está no chão */
    if ((key == 'w' || key == 'W') && e->no_chao) {
        e->vy     = VY_PULO;
        e->no_chao = 0;
    }

    /* Tiro: tecla 'f' — cooldown de 10 frames */
    if ((key == 'f' || key == 'F') && e->shoot_cd == 0) {
        int bx = (e->direcao == DIR_DIR) ? (e->x + e->w) : (e->x - BSIZE);
        int by = e->y + e->h / 2 - BSIZE / 2;
        int vproj = (e->direcao == DIR_DIR) ? VX_PROJETIL : -VX_PROJETIL;
        int idx = entidade_add(TIPO_PROJETIL, bx, by, 1,
                               e->direcao, TIPO_SAMUS, 1,
                               &SPR_PROJETIL, BSIZE, BSIZE);
        if (idx >= 0) entidades[idx].vx = vproj;
        e->shoot_cd = 10;
    }
    if (e->shoot_cd > 0) e->shoot_cd--;
}

/* ================================================================== */
/*  IA DO ESCORPIÃO                                                   */
/*                                                                    */
/*  Patrulha horizontalmente. Se a Samus estiver no mesmo nível Y     */
/*  e a menos de 80 pixels, para e atira.                             */
/* ================================================================== */
static void ia_scorpio(Entidade *e, const Entidade *samus)
{
    int dist_x, na_linha;

    dist_x  = samus->x - e->x;
    na_linha = (samus->y < e->y + e->h) && (samus->y + samus->h > e->y);

    if (na_linha && dist_x > -80 && dist_x < 80) {
        /* Atira na direção da Samus */
        e->vx = 0;
        e->direcao = (dist_x >= 0) ? DIR_DIR : DIR_ESQ;

        if (e->shoot_cd == 0) {
            int bx = (e->direcao == DIR_DIR) ? (e->x + e->w) : (e->x - BSIZE);
            int by = e->y + e->h / 2 - BSIZE / 2;
            int vproj = (e->direcao == DIR_DIR) ? VX_PROJETIL : -VX_PROJETIL;
            int idx = entidade_add(TIPO_PROJETIL, bx, by, 1,
                                   e->direcao, TIPO_SCORPIO, 1,
                                   &SPR_PROJETIL, BSIZE, BSIZE);
            if (idx >= 0) entidades[idx].vx = vproj;
            e->shoot_cd = 30;
        }
    } else {
        /* Patrulha */
        if (e->direcao == DIR_DIR) {
            e->vx = VX_SCORPIO;
        } else {
            e->vx = -VX_SCORPIO;
        }
        /* Inverte na parede */
        if (colide_mapa(e->x + e->vx, e->y, e->w, e->h)) {
            e->vx     = -e->vx;
            e->direcao = (e->direcao == DIR_DIR) ? DIR_ESQ : DIR_DIR;
        }
    }

    if (e->shoot_cd > 0) e->shoot_cd--;
}

/* ================================================================== */
/*  IA DO PROJÉTIL                                                      */
/* ================================================================== */
static void ia_projetil(Entidade *e, int idx)
{
    /* Colisão com mapa — projétil morre na parede */
    if (colide_mapa(e->x + e->vx, e->y, e->w, e->h)) {
        entidade_remove(idx);
        return;
    }
    /* Fora da tela */
    if (e->x < 0 || e->x >= COLS) {
        entidade_remove(idx);
        return;
    }
}

/* ================================================================== */
/*  COLISÃO ENTIDADE × ENTIDADE                                        */
/* ================================================================== */
static int rect_colide(const Entidade *a, const Entidade *b)
{
    return a->x < b->x + b->w &&
           a->x + a->w > b->x &&
           a->y < b->y + b->h &&
           a->y + a->h > b->y;
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

/* ================================================================== */
/*  INICIALIZAÇÃO                                                       */
/* ================================================================== */
static void game_init(void)
{
    int i;

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

        /* ---- 1. Lê input ---- */
        key = uart_read_char();

        /* ---- 2. Itera sobre entidades: IA + física ---- */
        for (i = 0; i < num_entidades; i++) {
            Entidade *e = &entidades[i];
            if (!e->ativo) continue;

            /* Apaga posição atual antes de mover */
            clear_sprite(e->sprite, e->x, e->y);

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

        /* HUD: vida no terminal */
        uart_print("\rVida: ");
        uart_print_int(samus->vida);
        uart_print("   ");

        /* Delay simples */
        {
            volatile unsigned long d;
            for (d = 0; d < 500000UL; d++);
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
