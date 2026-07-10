#include <stddef.h>
#include <stdint.h>
#include "basics.h"
#include "grid.h"

void print_on_screen(volatile uint16_t (*buf)[LWIDTH], uint16_t pixel, int pos_x, int pos_y);
void print_sprite(volatile uint16_t (*buf)[LWIDTH], Sprite *sprite, int ofx, int ofy, int screen_x, int screen_y,  orientation o);
void print_game(volatile uint16_t (*buf)[LWIDTH], Grid *area, Coordinates cam, int cell_size);
