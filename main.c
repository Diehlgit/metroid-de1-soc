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

#ifdef RUNNING_LINUX
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <signal.h>
#include <linux/input.h>
#define HW_REGS_BASE          0xFF200000
#define HW_REGS_SPAN          0x00005000 // Cobre a UART (1000) e o VGA (3020)
#define HW_REGS_MASK          (HW_REGS_SPAN - 1)

#define VGA_BUFFER_SPAN       (512 * 240 * 2) // Largura física * altura * 2 bytes (RGB565)
#define KEYBOARD_DEVICE "/dev/input/event0"

int keyboard_fd = -1;

int init_linux_memory(void) {
    int fd = open("/dev/mem", (O_RDWR | O_SYNC));
    if (fd < 0) {
        perror("Erro ao abrir /dev/mem");
        return -1;
    }

    void *virtual_base = mmap(NULL, HW_REGS_SPAN, (PROT_READ | PROT_WRITE), MAP_SHARED, fd, HW_REGS_BASE);
    if (virtual_base == MAP_FAILED) {
        perror("Erro no mmap da ponte LW");
        close(fd);
        return -1;
    }
    
    uart = (volatile uint32_t *)((char *)virtual_base + ((UART_BASE) & HW_REGS_MASK));
    pixel_ctrl_ptr = (volatile uint32_t *)((char *)virtual_base + (0xFF203020 & HW_REGS_MASK));

    // Mapeia as duas regiões possíveis do frame buffer
    vga_mem_virtual_c8 = mmap(NULL, VGA_BUFFER_SPAN, (PROT_READ | PROT_WRITE), MAP_SHARED, fd, 0xC8000000);
    vga_mem_virtual_c0 = mmap(NULL, VGA_BUFFER_SPAN, (PROT_READ | PROT_WRITE), MAP_SHARED, fd, 0xC0000000);

    if (vga_mem_virtual_c8 == MAP_FAILED || vga_mem_virtual_c0 == MAP_FAILED) {
        perror("Erro no mmap do Frame Buffer");
        close(fd);
        return -1;
    }

    close(fd);
    return 0;
}

void keyboard_handler(int signum) {
    struct input_event ev;
    
    while (read(keyboard_fd, &ev, sizeof(struct input_event)) > 0) {
        // ev.type == EV_KEY indica evento de teclado
        // ev.value == 1 indica tecla pressionada (0 = solta, 2 = repetindo) // usar dps
        if (ev.type == EV_KEY && (ev.value == 1)) {
            switch (ev.code) {
                case KEY_A: last_key = 'a'; break;
                case KEY_D: last_key = 'd'; break;
                case KEY_W: last_key = 'w'; break;
                case KEY_F: last_key = 'f'; break;
                default:    last_key = 0;   break;
            }
        }
    }
}

int init_linux_input(void) {
    keyboard_fd = open(KEYBOARD_DEVICE, O_RDONLY | O_NONBLOCK);
    if (keyboard_fd < 0) {
        perror("Erro ao abrir dispositivo de teclado");
        return -1;
    }

    // 2. Configura a estrutura sigaction para o SIGIO
    struct sigaction sa;
    sa.sa_handler = keyboard_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0; // Conforme especificado pelo professor
    
    if (sigaction(SIGIO, &sa, NULL) < 0) {
        perror("Erro ao configurar sigaction");
        return -1;
    }

    // 3. Define o seu processo atual como o dono do arquivo (para receber o sinal)
    fcntl(keyboard_fd, F_SETOWN, getpid());
    
    // 4. Ativa os flags de input assíncrono (FASYNC) e não-bloqueante no arquivo
    int flags = fcntl(keyboard_fd, F_GETFL);
    fcntl(keyboard_fd, F_SETFL, flags | FASYNC | O_NONBLOCK);

    return 0;
}

#endif

/* ================================================================== */
/*  INICIALIZAÇÃO                                                       */
/* ================================================================== */
static void game_init(void)
{
    int i;
    printf("entrou game init\n");
    #ifdef RUNNING_LINUX
    *pixel_ctrl_ptr = 0xC0000000;
    tela = (volatile uint16_t (*)[LWIDTH]) vga_mem_virtual_c8;
    #else
    uint32_t current_front_buffer = *pixel_ctrl_ptr;
    if (current_front_buffer == 0xC0000000) {
        *(pixel_ctrl_ptr + 1) = 0xC8000000;
    } else {
        *(pixel_ctrl_ptr + 1) = 0xC0000000;
    }
    tela = (volatile uint16_t (*)[LWIDTH]) *(pixel_ctrl_ptr + 1);
    #endif

    printf("terminou inicialização telas\n");

    #ifndef RUNNING_LINUX
    tela = (volatile uint16_t (*)[LWIDTH]) *(pixel_ctrl_ptr + 1);
    #endif

    clear_screen();
    printf("limpou tela\n");

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
    printf("printou mapa\n");

    for (i = 0; i < num_entidades; i++) {
        Entidade *e = &entidades[i];
        if (!e->ativo) {continue;}
        printf("printou entidade");
        draw_sprite(e->sprite, e->x, e->y,
                    e->direcao == DIR_ESQ ? 1 : 0);
    }


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

    printf("entrou game loop\n");
    while (1) {
        #ifdef RUNNING_LINUX
        #else
        tela = (volatile uint16_t (*)[LWIDTH]) *(pixel_ctrl_ptr + 1);
        #endif

        /* ---- 1. Lê input ---- */
        key = uart_read_char();
        printf("KEY PRESSIONADA: %c", key);

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
int main(void) {
    printf("antes de tudo\n");
    #ifdef RUNNING_LINUX
    if (init_linux_memory() < 0) {
        return 1;
    }

    printf("antes de input\n");

    if (init_linux_input() < 0) {
        return 1;
    }

    printf("antes de init linux\n");
    #endif

    uart_print("\r\n*** METROID — CIC0130 UnB ***\r\n");

    printf("antes do while\n");
    while (1) {
        game_init();
        game_loop();

        uart_print("Pressione qualquer tecla para reiniciar...\r\n");
        while (!uart_read_char());
    }
    return 0;
}
