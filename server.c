/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:26:08 by aeastman          #+#    #+#             */
/*   Updated: 2023/07/01 16:27:08 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

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
    ft_printf("PID: %d \n", pid);

    while (1) {
        signal(SIGUSR1, bit_get);
        signal(SIGUSR2, bit_get);
        pause();
    }

}