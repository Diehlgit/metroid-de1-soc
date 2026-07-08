#include <stddef.h>
#include <stdint.h>
#include "../include/structs.h"
#include "../include/grid.h"

#define ROWS 240
#define COLS 320
#define GET_PIXEL(sprite, x, y) ((sprite).pixels[(y) * (sprite).width + (x)])

static void print_on_screen(uint16_t pixel, int pos_x, int pos_y){

}

static void print_sprite(Sprite sprite, int ofx, int ofy, int screen_x, int screen_y){
    int pos_y = screen_y;
    int pos_x = screen_x;

    for(int y = 0 + ofy; y < sprite.height; y++){
        for(int x = 0 + ofx; x < sprite.width; x++){
            if(pos_x >= COLS) break;
            uint16_t pixel = GET_PIXEL(sprite, x, y);
            print_on_screen(pixel, pos_x, pos_y);
            pos_x++;
        }
        pos_x = screen_x;
        pos_y ++;
        if(pos_y >= ROWS) break;
    }
}

static void print_game(Grid *grid, Coordinates coord_samus, int cell_size){
    int x_samus = coord_samus.x;
    int y_samus = coord_samus.y;

    int x0_tela = x_samus - 152;
    int y0_tela = y_samus - 120;

    int pbx = (x_samus - 152)/cell_size;
    int pby = (y_samus - 120)/cell_size;
    int ubx = (x_samus + 168)/cell_size;
    int uby = (y_samus + 120)/cell_size;

    int screen_offset_x = x0_tela - pbx*cell_size;
    int screen_offset_y = y0_tela - pby*cell_size;

    int ofx, ofy, screen_x, screen_y;

    for(int i = pby; i < uby; i++){
        for(int j = pbx; j < ubx; j++){

        }
    }
}
