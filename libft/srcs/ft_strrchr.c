/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:58:50 by cleisti           #+#    #+#             */
/*   Updated: 2019/11/06 12:03:42 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*ptr;

	i = ft_strlen((char*)s);
	while (i >= 0)
	{
		if (s[i] == c)
		{
			ptr = &s[i];
			return ((char*)ptr);
		}
		i--;
	}
	return (0);
}
