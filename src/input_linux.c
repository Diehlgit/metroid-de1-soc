#ifdef RUNNING_LINUX

#include "../include/input_linux.h"
#include "../include/uart.h"

#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <linux/input.h>


static int keyboard_fd = -1;


static void keyboard_handler(int signum)
{
    struct input_event ev;

    while(read(keyboard_fd, &ev, sizeof(ev)) > 0)
    {
        if(ev.type == EV_KEY && ev.value == 1)
        {
            switch(ev.code)
            {
                case KEY_A:
                    uart_set_key('a');
                    break;

                case KEY_D:
                    uart_set_key('d');
                    break;

                case KEY_W:
                    uart_set_key('w');
                    break;

                case KEY_F:
                    uart_set_key('f');
                    break;
            }
        }
    }
}


int input_init(void)
{
    keyboard_fd = open("/dev/input/event0",
                       O_RDONLY | O_NONBLOCK);

    if(keyboard_fd < 0)
        return -1;


    struct sigaction sa;

    sa.sa_handler = keyboard_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGIO,&sa,NULL);


    fcntl(keyboard_fd,F_SETOWN,getpid());

    int flags = fcntl(keyboard_fd,F_GETFL);

    fcntl(keyboard_fd,
          F_SETFL,
          flags | FASYNC | O_NONBLOCK);

    return 0;
}

#endif
