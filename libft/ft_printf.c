/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:14:10 by aeastman          #+#    #+#             */
/*   Updated: 2023/07/01 15:09:44 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// resources and links
// https://www.techtarget.com/whatis/definition/hexadecimal
// https://www.youtube.com/watch?v=4EJay-6Bioo -- Khan academy Hexadecimal video

int	router(char letter, va_list args)
{
	int	write_len;

	write_len = 0;
	if (letter == 'd' || letter == 'i')
		write_len += writeint(va_arg(args, int));
	else if (letter == 'c')
		write_len += writechar(va_arg(args, int));
	else if (letter == 's')
		write_len += writestr(va_arg(args, char *));
	else if (letter == '%')
		write_len += writepercent();
	else if (letter == 'u')
		write_len += writeuint(va_arg(args, unsigned int));
	else if (letter == 'x' || letter == 'X')
		write_len += writehexrouter(va_arg(args, unsigned int), letter);
	else if (letter == 'p')
		write_len += writeptrrouter(va_arg(args, unsigned long long));
	return (write_len);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int		write_len;
	va_list	args;

	va_start(args, input);
	i = 0;
	write_len = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			write_len += router(input[i + 1], args);
			i += 2;
		}
		else
		{
			write_len += writechar(input[i]);
			i++;
		}
	}
	va_end(args);
	return (write_len);
}