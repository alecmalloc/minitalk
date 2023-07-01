/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeastman <aeastman@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:27:54 by aeastman          #+#    #+#             */
/*   Updated: 2023/07/01 16:27:58 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	writepercent(void);
int	writeuint(unsigned int num);
int	writeint(int num);
int	writelargeint(int num);
int	writechar(int c);
int	writestr(char *str);
int	writehexrouter(unsigned int hex, char hextype);
int	writehex(unsigned int hex, char hextype);
int	ft_printf(const char *input, ...);
int	writeptrrouter(unsigned long long ptr);

#endif
