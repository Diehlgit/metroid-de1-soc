#ifndef __ENTITIES_C__
#define __ENTITIES_C__

#include "sprites.h"
#include "maps.h"
#include "vga.c"

static int colide_mapa(int px, int py, int w, int h);

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
        /* Bateu na cabeca */
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

#endif