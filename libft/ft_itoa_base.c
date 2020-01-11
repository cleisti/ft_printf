/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:52:28 by marvin            #+#    #+#             */
/*   Updated: 2020/01/10 13:52:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int value, int base, int neg)
{
	unsigned int size;

	size = 1;
	if (neg)
		size++;
	while (value / base != 0)
	{
		value /= base;
		size++;
	}
	return (size);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	char	*vals;
	int		size;
	int		neg;

	vals = "0123456789ABCDEF";
	neg = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (value < 0 && base == 10)
		neg = 1;
	size = count_len(value, base, neg);
	if (!(str = ft_strnew(sizeof(size + 1))))
		return (NULL);
	str[size--] = '\0';
	while (value)
	{
		str[size] = vals[value % base];
		value /= base;
		size--;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
