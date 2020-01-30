/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:35:12 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/23 16:27:21 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_len(unsigned long long value, int base)
{
	unsigned int size;

	size = 1;
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
	if (!(str = ft_strnew(sizeof(size + 1))))
		return (NULL);
	str[size] = '\0';
	size--;
	while (value)
	{
		str[size] = vals[value % base];
		value /= base;
		size--;
	}
	return (str);
}
