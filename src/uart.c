#include <stdlib.h>
#include <SDL2/SDL.h>

char uart_read_char(void) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) exit(0);
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_a: return 'a';
                case SDLK_s: return 's';
                case SDLK_d: return 'd';
                case SDLK_w: return 'w';
                case SDLK_f: return 'f';
                case SDLK_ESCAPE: exit(0);
            }
        }
    }
    return 0;
}
