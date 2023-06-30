#include "minitalk.h"
#include <stdio.h> // fix and add own printf btw printf -> ft_printf

void sigusr_handler(int signum) {
    printf("Recieved SIGUSR: %d \n", signum);
}

int main()
{
    int pid;

    pid = getpid();
    printf("pid: %d \n", pid);

    while (1) {
        signal(SIGUSR1, sigusr_handler);
        signal(SIGUSR2, sigusr_handler);
        usleep(100000);
    }

}