/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:44:10 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/17 11:49:41 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strbcpy(char *dst, const char *src)
{
	int		len;
	int		i;

	len = ft_strlen(dst);
	i = ft_strlen(src);
	while (len && i)
	{
		dst[len - 1] = src[i - 1];
		len--;
		i--;
	}
	return (dst);
}
