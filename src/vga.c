#include <SDL2/SDL.h>
#include <stdint.h>
#include "../include/basics.h"

static SDL_Window   *window   = NULL;
static SDL_Renderer *renderer = NULL;
static SDL_Texture  *texture  = NULL;

// buffer em RAM — tela aponta para cá
static uint16_t framebuffer[ROWS][LWIDTH];

volatile uint16_t (*tela)[LWIDTH];

int vga_init(void) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Metroid",
                 SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                 COLS, ROWS, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // RGB565 — mesmo formato dos seus sprites
    texture = SDL_CreateTexture(renderer,
                  SDL_PIXELFORMAT_RGB565,
                  SDL_TEXTUREACCESS_STREAMING,
                  COLS, ROWS);

    tela = framebuffer;
    return 0;
}

void swap_buffers(void) {
    // copia framebuffer para a textura e exibe
    // pitch = bytes por linha = LWIDTH * 2
    SDL_UpdateTexture(texture, NULL, framebuffer, LWIDTH * 2);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void clear_screen(uint16_t color) {
    for (int y = 0; y < ROWS; y++)
        for (int x = 0; x < COLS; x++)
            tela[y][x] = color;
}
