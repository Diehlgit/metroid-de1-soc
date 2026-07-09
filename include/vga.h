#pragma once

#include <stdint.h>
#define ROWS 240
#define COLS 320

#define LWIDTH 512

extern volatile uint16_t (*tela)[LWIDTH];
void clear_screen(uint16_t color);
int vga_init(void);
void swap_buffers(void);
