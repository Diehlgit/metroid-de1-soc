#pragma once

#include <stdint.h>

#define LWIDTH 512

extern volatile uint16_t (*tela)[LWIDTH];

int vga_init(void);
void swap_buffers(void);
