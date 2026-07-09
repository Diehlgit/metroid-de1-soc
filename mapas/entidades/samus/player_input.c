#include "../../../include/physics.h"
#include "../../../include/uart.h"

Intent player_input(Grid *grid, Entity *self) {
    Intent intent = {0};
    char key = uart_read_char();
    if (key == 'a') intent.dx = -2;
    if (key == 'd') intent.dx =  2;
    if (key == 'w') intent.dy = -8;  // pulo — physics aplica gravidade
    if (key == 'f') {
        // spawn projétil
    }
    return intent;
}
