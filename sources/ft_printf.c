/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 22:54:05 by marvin            #+#    #+#             */
/*   Updated: 2020/01/07 13:31:27 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(void arg, char c)
{
	if (c == c)
		ft_putchar((char)arg);
	if (c == s)
		ft_putstr((char*)arg);
	if (c == d || c == i)
		ft_putnbr((int)arg);
}

char	*type(char c)
{
	if (c == c)
		return (char);
	if (c == s)
		return (char *);
	if (c == d || c == i)
		return (int);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	char	*traverse;
	va_list	args;
	int		i;

	traverse = (char*)format;
	va_start(args, format);
	i = 0;
	while (traverse[i])
	{
		if (traverse[i] == '%')
			print_arg(va_arg(args, type(traverse[i + 1), traverse[i + 1]);
		ft_putchar(traverse[i]);
		i++;
	}
	va_end(args);
	return (0);
	
}
