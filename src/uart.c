#include <stdio.h>
#include "../include/uart.h"

#define UART_BASE   0xFF201000
#define UART_RVALID (1 << 15)
static volatile char last_key = 0;

#ifdef RUNNING_LINUX
static volatile uint32_t *uart = NULL;
#else
static volatile uint32_t * const uart = (volatile uint32_t *) UART_BASE;
#endif

char uart_read_char(void) {
#ifdef RUNNING_LINUX
    char tecla = last_key;
    last_key = 0;
    return tecla;
#else
    uint32_t d = uart[0];
    if (d & UART_RVALID)
        return (char)(d & 0xFF);

    return 0;

#endif
}


void uart_write_char(char c)
{
#ifdef RUNNING_LINUX

    printf("%c", c);
    fflush(stdout);

#else

    while ((uart[1] >> 16) == 0);

    uart[0] = (uint32_t)c;

#endif
}


void uart_print(const char *s)
{
#ifdef RUNNING_LINUX

    printf("%s", s);
    fflush(stdout);

#else

    while (*s)
        uart_write_char(*s++);

#endif
}


void uart_print_int(int n)
{
    char buf[12];
    int i = 10;

    buf[11] = '\0';

    if (n == 0) {
        uart_write_char('0');
        return;
    }

    if (n < 0) {
        uart_write_char('-');
        n = -n;
    }

    while (n > 0 && i >= 0) {
        buf[i--] = '0' + (n % 10);
        n /= 10;
    }

    uart_print(buf + i + 1);
}


#ifdef RUNNING_LINUX

void uart_set_key(char c)
{
    last_key = c;
}

#endif
