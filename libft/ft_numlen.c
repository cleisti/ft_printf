/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:51:18 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/23 17:52:16 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen(long long nb)
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
