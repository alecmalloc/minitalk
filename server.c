#include "minitalk.h"
#include <stdio.h> // fix and add own printf btw printf -> ft_printf

void	bit_get(int signal)
{
	static int	bit;
	static int	i;
    
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int main()
{
    int pid;

    pid = getpid();
    printf("PID: %d \n", pid);

    while (1) {
        signal(SIGUSR1, bit_get);
        signal(SIGUSR2, bit_get);
        pause();
    }

}