/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:51:48 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/17 11:39:36 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	if (!(len) || dst == src)
		return (dst);
	if (dst < src)
	{
		printf("lol\n");
		ft_memcpy(dst, src, len);
		return (dst);
	}
	while (len)
	{
		cdst[len - 1] = csrc[len - 1];
		len--;
	}
	return (dst);
}
