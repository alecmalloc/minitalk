#include "minitalk.h"
#include <stdio.h>


int main()
{
    int pid;

    while(1)
    {
        pid = getpid();
        printf("pid: %d", pid);
        pause();
    }
}