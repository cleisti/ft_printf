/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:26:59 by cleisti           #+#    #+#             */
/*   Updated: 2019/11/06 12:02:04 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cdst;
	unsigned char	*csrc;

	i = 0;
	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	while (i < n)
	{
		if (csrc[i] != (unsigned char)c)
			cdst[i] = csrc[i];
		if (csrc[i] == (unsigned char)c)
		{
			cdst[i] = (unsigned char)c;
			return (&dst[i + 1]);
		}
		i++;
	}
	return (NULL);
}
