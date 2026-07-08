#include <stddef.h>
#include <stdint.h>
#include "../include/structs.h"
#include "../include/grid.h"

#define ROWS 240
#define COLS 320

static void print_on_screen(uint16_t pixel, int pos_x, int pos_y);

static void print_sprite(Sprite sprite, int ofx, int ofy, int screen_x, int screen_y);

static void print_game(Grid *grid, Coordinates coord_samus, int cell_size);
