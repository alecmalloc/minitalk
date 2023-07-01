/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:37:45 by aeastman          #+#    #+#             */
/*   Updated: 2023/07/01 15:09:47 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	writehex(unsigned int hex, char hextype)
{
	int	write_len;

	write_len = 0;
	if (hex >= 16)
	{
		write_len += writehex(hex / 16, hextype);
		write_len += writehex(hex % 16, hextype);
	}
	else
	{
		if (hex <= 9)
			write_len += writechar(hex + '0');
		else
		{
			if (hextype == 'x')
				write_len += writechar(hex - 10 + 'a');
			else if (hextype == 'X')
				write_len += writechar(hex - 10 + 'A');
		}
	}
	return (write_len);
}

int	writehexrouter(unsigned int hex, char hextype)
{
	int	write_len;

	write_len = 0;
	if (hex == 0)
		write_len += write(1, "0", 1);
	else
		write_len += writehex(hex, hextype);
	return (write_len);
}

int	num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int num)
{
	char	*str;
	int		len;

	len = num_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (num != 0)
	{
		str[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int num)
{
	char	*str;
	int		len;

	len = num_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (num != 0)
	{
		str[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

int	writeint(int num)
{
	int		write_len;
	char	*str;

	write_len = 0;
	if (num == 0)
		write_len += write(1, "0", 1);
	else if (num == -2147483648)
		write_len += write(1, "-2147483648", 11);
	else
	{
		if (num < 0)
		{
			num *= -1;
			write_len = write(1, "-", 1);
		}
		str = ft_itoa(num);
		write_len += writestr(str);
		free(str);
	}
	return (write_len);
}

int	writeuint(unsigned int num)
{	
	int		write_len;
	char	*str;

	write_len = 0;
	if (num == 0)
		write_len = write(1, "0", 1);
	else
	{
		str = ft_uitoa(num);
		write_len += writestr(str);
		free(str);
	}
	return (write_len);
}

int	writepercent(void)
{
	return (write(1, "%", 1));
}

int	writeptr(unsigned long long ptr)
{
	int	write_len;

	write_len = 0;
	if (ptr >= 16)
	{
		write_len += writeptr(ptr / 16);
		write_len += writeptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			write_len += writechar(ptr + '0');
		else
			write_len += writechar(ptr - 10 + 'a');
	}
	return (write_len);
}

int	writeptrrouter(unsigned long long ptr)
{
	int	write_len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	write_len = 0;
	write_len += write(1, "0x", 2);
	write_len += writeptr(ptr);
	return (write_len);
}

int	writechar(int c)
{
	return (write(1, &c, 1));
}

int	writestr(char *str)
{
	int	i;
	int	write_len;

	i = 0;
	write_len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != 0)
	{
		write_len += write(1, &str[i], 1);
		i++;
	}
	return (write_len);
}