#include "../../../include/physics.h"
#include "../../../include/uart.h"

Intent player_input(Grid *grid, Entity *self) {
    Intent intent = {0};

	char key = uart_read_char();
    if (key == 'a') intent.ax = -3;
    if (key == 'd') intent.ax =  3;
    if (key == 'w') intent.ay = -32;  // pulo — physics aplica gravidade
    if (key == 'f') {
        // spawn projétil
    }
    return intent;
}
