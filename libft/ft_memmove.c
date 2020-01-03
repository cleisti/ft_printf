/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:51:48 by cleisti           #+#    #+#             */
/*   Updated: 2019/11/07 11:11:41 by cleisti          ###   ########.fr       */
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
