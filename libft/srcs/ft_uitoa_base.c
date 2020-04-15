/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:35:12 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/13 14:32:10 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_len(unsigned long long value, int base)
{
	unsigned int size;

	size = 1;
	if (value == 0)
		return (size);
	while (value / base != 0)
	{
		value /= base;
		size++;
	}
	return (size);
}

char		*ft_uitoa_base(unsigned long long value, int base)
{
	char	*str;
	char	*vals;
	int		size;

	vals = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	size = count_len(value, base);
	str = ft_strnew(size);
	str[size] = '\0';
	size--;
	if (value == 0)
		str[0] = '0';
	else
	{
		while (value)
		{
			str[size] = vals[value % base];
			value /= base;
			size--;
		}
	}
	return (str);
}
