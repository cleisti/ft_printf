/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:51:26 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/30 16:04:39 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long long value, int base, int neg)
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

char		*ft_itoa_base(long long value, int base)
{
	char	*str;
	char	*vals;
	int		size;
	int		neg;

	vals = "0123456789abcdef";
	neg = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (value < 0 && base == 10)
		neg = 1;
	size = count_len(value, base, neg);
	str = ft_strnew(sizeof(size + 1));
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
