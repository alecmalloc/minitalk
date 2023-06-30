#include "minitalk.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
	{
		i++;
	}
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (sign * nb);
}

void bit_send(int pid, char a)
{
    int bit;

    bit = 0;
    while (bit < 8)
	{
		if ((a & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(700);
		bit++;
	}
}

int main(int argc, char *argv[])
{
    int i;
    int pid;

    if (argc < 3) {
        printf("ERROR: please include PID and string\n");
        return (1);
    }
    else if (argc > 3) {
        printf("ERROR: please only include PID and string\n");
        return (1);
    }
    i = 0;
    pid = ft_atoi(argv[1]);
    while (argv[2][i] != '\0')
    {
        bit_send(pid, argv[2][i]);
        i++;
    }
}