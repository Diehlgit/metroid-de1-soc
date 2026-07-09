
#include <stddef.h>
#include <stdint.h>
#include "../include/basics.h"
#include "../include/entity.h"
#include "../include/grid.h"
#include "../include/print.h"

#define ROWS 240
#define COLS 320
#define GET_PIXEL(sprite, x, y) ((sprite)->pixels[(y) * (sprite)->width + (x)])

void print_on_screen(volatile uint16_t (*buf)[LWIDTH], uint16_t pixel, int pos_x, int pos_y){
    if(pos_x < 0 || pos_x >= COLS || pos_y < 0 || pos_y >= ROWS) return;
    if(pixel == 0x8001) return;  // TRANS — não desenha
    buf[pos_y][pos_x] = pixel;
}


void print_sprite(volatile uint16_t (*buf)[LWIDTH], Sprite *sprite, int ofx, int ofy, int screen_x, int screen_y){
    int pos_y = screen_y;
    int pos_x = screen_x;

    for(int y = 0 + ofy; y < sprite->height; y++){
        for(int x = 0 + ofx; x < sprite->width; x++){
            if(pos_x >= COLS) break;
            uint16_t pixel = GET_PIXEL(sprite, x, y);
            print_on_screen(buf, pixel, pos_x, pos_y);
            pos_x++;
        }
        pos_x = screen_x;
        pos_y ++;
        if(pos_y >= ROWS) break;
    }
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

        print_sprite(buf, e->current_sprite, offset_x, offset_y, pos_x, pos_y);
    }
}
