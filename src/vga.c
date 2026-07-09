#include "../include/vga.h"

#ifdef RUNNING_LINUX

#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define FRAME_BUFFER0 0xC0000000
#define FRAME_BUFFER1 0xC0100000

#define HW_REGS_BASE 0xFF200000
#define HW_REGS_SPAN 0x00005000
#define HW_REGS_MASK (HW_REGS_SPAN - 1)

#define VGA_BUFFER_SPAN (512 * 240 * 2)

static volatile uint32_t *pixel_ctrl_ptr = NULL;
static void *vga_mem_virtual_c8 = NULL;
static void *vga_mem_virtual_c0 = NULL;

#else

static volatile uint32_t *const pixel_ctrl_ptr =
    (volatile uint32_t *)0xFF203020;

#endif


volatile uint16_t (*tela)[LWIDTH];


int vga_init(void)
{
#ifdef RUNNING_LINUX

    int fd = open("/dev/mem", O_RDWR | O_SYNC);

    if (fd < 0) {
        perror("open /dev/mem");
        return -1;
    }


    void *virtual_base =
        mmap(NULL,
             HW_REGS_SPAN,
             PROT_READ | PROT_WRITE,
             MAP_SHARED,
             fd,
             HW_REGS_BASE);


    if (virtual_base == MAP_FAILED) {
        perror("mmap HW");
        close(fd);
        return -1;
    }


    pixel_ctrl_ptr =
        (volatile uint32_t *)
        ((char *)virtual_base +
        (0xFF203020 & HW_REGS_MASK));


    vga_mem_virtual_c8 =
        mmap(NULL,
             VGA_BUFFER_SPAN,
             PROT_READ | PROT_WRITE,
             MAP_SHARED,
             fd,
             FRAME_BUFFER1);


    vga_mem_virtual_c0 =
        mmap(NULL,
             VGA_BUFFER_SPAN,
             PROT_READ | PROT_WRITE,
             MAP_SHARED,
             fd,
             FRAME_BUFFER0);


    if (vga_mem_virtual_c8 == MAP_FAILED ||
        vga_mem_virtual_c0 == MAP_FAILED) {

        perror("mmap framebuffer");
        close(fd);
        return -1;
    }


    /*
       Escolhe inicialmente o buffer de desenho
    */
    tela = (volatile uint16_t (*)[LWIDTH])vga_mem_virtual_c8;


    close(fd);

#endif

    return 0;
}


void swap_buffers(void)
{
#ifdef RUNNING_LINUX

    *pixel_ctrl_ptr = 1;

    while (*(pixel_ctrl_ptr + 3) & 1);


    uint32_t back_addr = *(pixel_ctrl_ptr + 1);


    tela =
        (back_addr == FRAME_BUFFER1)
        ?
        (volatile uint16_t (*)[LWIDTH])vga_mem_virtual_c8
        :
        (volatile uint16_t (*)[LWIDTH])vga_mem_virtual_c0;


#else

    *pixel_ctrl_ptr = 1;

    while ((*(pixel_ctrl_ptr + 3) & 1));

    tela =
        (volatile uint16_t (*)[LWIDTH])*(pixel_ctrl_ptr + 1);

#endif
}
