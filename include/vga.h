#pragma once
#include "basics.h"
#include <stdint.h>

extern volatile uint16_t (*tela)[LWIDTH];
void clear_screen(uint16_t color);
int vga_init(void);
void swap_buffers(void);
void display_score(int score);
void display_live(int live);
