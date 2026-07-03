#ifndef __JTAG_C__
#define __JTAG_C__

#include <stdint.h>

/* ================================================================== */
/*  JTAG-UART                                                           */
/* ================================================================== */
#define UART_BASE   0xFF201000
static volatile uint32_t * const uart = (volatile uint32_t *) UART_BASE;
#define UART_RVALID (1 << 15)

static char uart_read_char(void)
{
    uint32_t d = uart[0];
    if (d & UART_RVALID) return (char)(d & 0xFF);
    return 0;
}

static void uart_write_char(char c)
{
    while ((uart[1] >> 16) == 0);
    uart[0] = (uint32_t)c;
}

static void uart_print(const char *s)
{
    while (*s) uart_write_char(*s++);
}

static void uart_print_int(int n)
{
    char buf[12]; int i = 10; buf[11] = '\0';
    if (n == 0) { uart_write_char('0'); return; }
    if (n < 0)  { uart_write_char('-'); n = -n; }
    while (n > 0 && i >= 0) { buf[i--] = '0' + (n % 10); n /= 10; }
    uart_print(buf + i + 1);
}

#endif