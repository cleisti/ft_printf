/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:27:55 by cleisti           #+#    #+#             */
/*   Updated: 2019/11/06 17:38:36 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_len(int nb)
{
	unsigned int size;

	size = 1;
	if (nb < 0)
		size++;
	while (nb / 10 != 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		neg;
	int		size;

	neg = (n < 0);
	size = count_len(n);
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	size--;
	if (n == 0)
		str[size] = '0';
	while (size >= 0)
	{
		str[size--] = (n < 0) ? '0' - n % 10 : n % 10 + '0';
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
