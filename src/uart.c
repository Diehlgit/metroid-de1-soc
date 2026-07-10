#define _GNU_SOURCE

#include "../include/uart.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <linux/input.h>
#include <stdint.h>

#define KEYBOARD_DEVICE "/dev/input/event0"

static int keyboard_fd = -1;

static volatile char last_key = 0;


static void keyboard_handler(int sig) {
    struct input_event ev;

    while(read(keyboard_fd, &ev, sizeof(ev)) > 0) {

        if(ev.type == EV_KEY && ev.value == 1) {

            switch(ev.code) {
                case KEY_A:
                    last_key='a';
                    break;

                case KEY_D:
                    last_key='d';
                    break;

                case KEY_W:
                    last_key='w';
                    break;

                case KEY_F:
                    last_key='f';
                    break;

                default:
                    break;
            }
        }
    }
}


int uart_init(void) {
    keyboard_fd = open(
        KEYBOARD_DEVICE,
        O_RDONLY | O_NONBLOCK
    );

    if(keyboard_fd < 0) {
        perror("keyboard");
        return -1;
    }

    struct sigaction sa;

    sa.sa_handler = keyboard_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;


    if(sigaction(SIGIO,&sa,NULL)<0) {
        perror("sigaction");
        return -1;
    }

    fcntl(
        keyboard_fd,
        F_SETOWN,
        getpid()
    );

    int flags = fcntl(
        keyboard_fd,
        F_GETFL
    );

    fcntl(
        keyboard_fd,
        F_SETFL,
        flags | FASYNC | O_NONBLOCK
    );

    return 0;
}



char uart_read_char(void) {
    char c = last_key;
    last_key = 0;
    return c;
}

void uart_write_char(char c) {
    putchar(c);
    fflush(stdout);
}


void uart_print(const char *s) {
    printf("%s",s);
    fflush(stdout);
}

void uart_print_int(int n) {
    printf("%d",n);
    fflush(stdout);
}
