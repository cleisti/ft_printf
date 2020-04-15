/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:26:59 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/10 13:51:18 by marvin           ###   ########.fr       */
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
			return (&cdst[i + 1]);
		}
		i++;
	}
	return (NULL);
}
