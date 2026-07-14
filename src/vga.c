#include "../include/vga.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>

#define FRAME_BUFFER0 0xC0000000
#define FRAME_BUFFER1 0xC8000000

#define PIXEL_CTRL_BASE 0xFF203020

#define HW_REGS_BASE 0xFF200000
#define HW_REGS_SPAN 0x200000 
#define HW_REGS_MASK (HW_REGS_SPAN-1)

#define VGA_BUFFER_SPAN (512*240*2)

#define HEX3_HEX0_OFFSET 0x00000020 // primeiros 4 displays
#define HEX5_HEX4_OFFSET 0x00000030 // os outros 2

static volatile uint32_t *pixel_ctrl_ptr;

static volatile uint32_t *hex3_hex0_ptr;
static volatile uint32_t *hex5_hex4_ptr;

static void *vga_mem_virtual_c0;
static void *vga_mem_virtual_c8;

static const uint8_t sete_seg_table[] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

volatile uint16_t (*tela)[LWIDTH];

int vga_init(void) {
    int fd=open("/dev/mem", O_RDWR | O_SYNC);

    if(fd < 0) {
        perror("/dev/mem");
        return -1;
    }

    void *hw=mmap(
        NULL,
        HW_REGS_SPAN,
        PROT_READ|PROT_WRITE,
        MAP_SHARED,
        fd,
        HW_REGS_BASE
    );

    if(hw == MAP_FAILED) {
        perror("hw mmap");
        return -1;
    }

    pixel_ctrl_ptr = (uint32_t*)((char*)hw + (PIXEL_CTRL_BASE & HW_REGS_MASK));

    hex3_hex0_ptr = (uint32_t*)((char*)hw + HEX3_HEX0_OFFSET);
    hex5_hex4_ptr = (uint32_t*)((char*)hw + HEX5_HEX4_OFFSET);

    vga_mem_virtual_c0=mmap(
        NULL,
        VGA_BUFFER_SPAN,
        PROT_READ|PROT_WRITE,
        MAP_SHARED,
        fd,
        FRAME_BUFFER0
    );


    vga_mem_virtual_c8=mmap(
        NULL,
        VGA_BUFFER_SPAN,
        PROT_READ|PROT_WRITE,
        MAP_SHARED,
        fd,
        FRAME_BUFFER1
    );


    if(vga_mem_virtual_c0==MAP_FAILED ||vga_mem_virtual_c8==MAP_FAILED) {
        perror("framebuffer mmap");
        return -1;
    }

    *pixel_ctrl_ptr = FRAME_BUFFER0;
    *(pixel_ctrl_ptr+1)=FRAME_BUFFER1;


    tela = (volatile uint16_t (*)[LWIDTH]) vga_mem_virtual_c8;
    close(fd);

    return 0;
}

void clear_screen(uint16_t color) {
    for(int y=0;y<ROWS;y++) {
        for(int x=0;x<COLS;x++) {
            tela[y][x]=color;
        }
    }
}

static int no_buffer1 = 1;

void swap_buffers(void) {
    if (tela == (volatile uint16_t (*)[LWIDTH]) vga_mem_virtual_c8) {
        *(pixel_ctrl_ptr + 1) = FRAME_BUFFER1;
    } else {
        *(pixel_ctrl_ptr + 1) = FRAME_BUFFER0;
    }
    printf("BUFFER:%u\n", *(pixel_ctrl_ptr + 1));
    fflush(stdout);
    *pixel_ctrl_ptr = 1;

    while ((*(pixel_ctrl_ptr + 3)) & 1);

    if (tela == (volatile uint16_t (*)[LWIDTH]) vga_mem_virtual_c8) {
        tela = (volatile uint16_t (*)[LWIDTH]) vga_mem_virtual_c0;
    } else {
        tela = (volatile uint16_t (*)[LWIDTH]) vga_mem_virtual_c8;
    }
}

void display_score(int score) {
    if (!hex3_hex0_ptr) return;
    
    if (score > 9999) score = 9999;
    if (score < 0) score = 0;

    int digito_0 = score % 10;
    int digito_1 = (score / 10) % 10;
    int digito_2 = (score / 100) % 10;
    int digito_3 = (score / 1000) % 10;

    uint32_t valor_registrador = (sete_seg_table[digito_3] << 24) |
                                 (sete_seg_table[digito_2] << 16) |
                                 (sete_seg_table[digito_1] << 8)  |
                                 (sete_seg_table[digito_0]);

    *hex3_hex0_ptr = valor_registrador;
}

void display_live(int live) {
    if (!hex5_hex4_ptr) return;
    
    if (live > 99) live = 99;
    if (live < 0) live = 0;

    int digito_4 = live % 10;
    int digito_5 = (live / 10) % 10;

    uint32_t valor_registrador = (sete_seg_table[digito_5] << 8) |
                                 (sete_seg_table[digito_4]);

    *hex5_hex4_ptr = valor_registrador;
}
