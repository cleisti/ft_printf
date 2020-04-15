/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:59:32 by cleisti           #+#    #+#             */
/*   Updated: 2019/11/06 12:02:41 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*ptr;

	i = 0;
	while (s[i] != '\0')
	{
		if (c == '\0' && s[i + 1] == '\0')
		{
			ptr = &s[i + 1];
			return ((char*)ptr);
		}
		if (s[i] == c)
		{
			ptr = &s[i];
			return ((char*)ptr);
		}
		i++;
	}
	return (0);
}
