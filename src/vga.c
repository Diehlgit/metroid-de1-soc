#include "../include/vga.h"

#ifdef RUNNING_LINUX

#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define FRAME_BUFFER0 0xC0000000
#define FRAME_BUFFER1 0xC0100000

#define PIXEL_CTRL_BASE 0xFF203020

#define HW_REGS_BASE 0xFF200000
#define HW_REGS_SPAN 0x5000
#define HW_REGS_MASK (HW_REGS_SPAN-1)

#define VGA_BUFFER_SPAN (512*240*2)

static volatile uint32_t *pixel_ctrl_ptr;

static void *vga_mem_virtual_c0;
static void *vga_mem_virtual_c8;

#endif


volatile uint16_t (*tela)[LWIDTH];

int vga_init(void) {
#ifdef RUNNING_LINUX

    int fd=open(
        "/dev/mem",
        O_RDWR | O_SYNC
    );


    if(fd<0)
    {
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


    if(hw==MAP_FAILED)
    {
        perror("hw mmap");
        return -1;
    }



    pixel_ctrl_ptr =
        (uint32_t*)((char*)hw +
        (PIXEL_CTRL_BASE & HW_REGS_MASK));



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


    if(vga_mem_virtual_c0==MAP_FAILED ||
       vga_mem_virtual_c8==MAP_FAILED)
    {
        perror("framebuffer mmap");
        return -1;
    }



    /*
       Front buffer = C0000000
       Back buffer  = C0100000
    */


    *pixel_ctrl_ptr = FRAME_BUFFER0;


    *(pixel_ctrl_ptr+1)=FRAME_BUFFER1;


    tela =
       (volatile uint16_t (*)[LWIDTH])
       vga_mem_virtual_c8;



    close(fd);

#endif


return 0;

}




void clear_screen(uint16_t color)
{

    for(int y=0;y<ROWS;y++)
    {
        for(int x=0;x<COLS;x++)
        {
            tela[y][x]=color;
        }
    }

}

static int no_buffer1 = 1;

void swap_buffers(void) {
#ifdef RUNNING_LINUX
    *pixel_ctrl_ptr = 1;
    while ((*(pixel_ctrl_ptr+3)) & 1);

    if (no_buffer1) {
        // acabou de exibir C8, agora desenha no C0
        *(pixel_ctrl_ptr+1) = FRAME_BUFFER0;
        tela = (volatile uint16_t (*)[LWIDTH]) vga_mem_virtual_c0;
        no_buffer1 = 0;
    } else {
        // acabou de exibir C0, agora desenha no C8
        *(pixel_ctrl_ptr+1) = FRAME_BUFFER1;
        tela = (volatile uint16_t (*)[LWIDTH]) vga_mem_virtual_c8;
        no_buffer1 = 1;
    }
#endif
}
