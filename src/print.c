
#include <stddef.h>
#include <stdint.h>
#include "../include/basics.h"
#include "../include/entity.h"
#include "../include/grid.h"
#include "../include/print.h"

#define ROWS 240
#define COLS 320

#define GET_PIXEL_RU(sprite, x, y, w, h)  ((sprite)->pixels[(y) * (w) + (x)])
#define GET_PIXEL_LU(sprite, x, y, w, h)  ((sprite)->pixels[(y) * (w) + ((w)-1-(x))])
#define GET_PIXEL_RD(sprite, x, y, w, h)  ((sprite)->pixels[((h)-1-(y)) * (w) + (x)])
#define GET_PIXEL_LD(sprite, x, y, w, h)  ((sprite)->pixels[((h)-1-(y)) * (w) + ((w)-1-(x))])

void print_on_screen(volatile uint16_t (*buf)[LWIDTH], uint16_t pixel, int pos_x, int pos_y){
    if(pos_x < 0 || pos_x >= COLS || pos_y < 0 || pos_y >= ROWS) return;
    if(pixel == 0x8001) return;  // TRANS — não desenha
    buf[pos_y][pos_x] = pixel;
}

void print_sprite(volatile uint16_t (*buf)[LWIDTH], Sprite *sprite, int ofx, int ofy, int screen_x, int screen_y, Orientation o) {
    int pos_y  = screen_x;
    int pos_x  = screen_x;
    int largura = sprite->width;
    int altura  = sprite->height;

    // seleciona o índice de pixel uma única vez
    #define CALL_GET(fn) fn(sprite, x, y, largura, altura)

    int modo = (o.v_direction == DOWN ? 2 : 0) | (o.h_direction == LEFT ? 1 : 0);

    for (int y = ofy; y < altura; y++) {
        for (int x = ofx; x < largura; x++) {
            if (pos_x >= COLS) break;

            uint16_t pixel;
            switch (modo) {
                case 0: pixel = CALL_GET(GET_PIXEL_RU); break;
                case 1: pixel = CALL_GET(GET_PIXEL_LU); break;
                case 2: pixel = CALL_GET(GET_PIXEL_RD); break;
                case 3: pixel = CALL_GET(GET_PIXEL_LD); break;
            }

            print_on_screen(buf, pixel, pos_x, pos_y);
            pos_x++;
        }
        pos_x = screen_x;
        pos_y++;
        if (pos_y >= ROWS) break;
    }
    #undef CALL_GET
}

void print_game(volatile uint16_t (*buf)[LWIDTH], Grid *area, Coordinates pos_samus, int cell_size){
    int x0_tela;
    int y0_tela;

    if(pos_samus.x - 152 < 0){
        x0_tela = 0;
    } else if(pos_samus.x + 168 > area->width) {
        x0_tela = area->width - 320;
    } else {
        x0_tela = pos_samus.x - 152;
    }

    if (pos_samus.y - 120 < 0){
        y0_tela = 0;
    } else if(pos_samus.y + 120 > area->height) {
        y0_tela = area->height - 240;
    } else {
        y0_tela = pos_samus.y - 120;
    }

    Coordinates scree_pos = {.x = x0_tela, .y = y0_tela};
    EntityList entities_to_print = grid_query_region(area, scree_pos, 320, 240);

    for(int i = 0; i < entities_to_print.count; i++){
        Entity *e = entities_to_print.ents[i];

        int offset_x = 0;
        int offset_y = 0;

        int pos_x = e->position.x - x0_tela;
        int pos_y = e->position.y - y0_tela;

        if (pos_x < 0){
            offset_x = pos_x*(-1);
            pos_x = 0;
        }

        if (pos_y < 0){
            offset_y = pos_y*(-1);
            pos_y = 0;
        }

        print_sprite(buf, e->current_sprite, offset_x, offset_y, pos_x, pos_y, e->orientation);
    }
}
