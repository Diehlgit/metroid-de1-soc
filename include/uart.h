#pragma once
#include <stdint.h>
char uart_read_char(void);
void uart_write_char(char c);
void uart_print(const char *s);
void uart_print_int(int n);
