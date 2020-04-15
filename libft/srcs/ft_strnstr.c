/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:15:31 by cleisti           #+#    #+#             */
/*   Updated: 2019/11/06 12:03:39 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	save;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			save = i;
			while (haystack[i] == needle[j] && needle[j] != '\0' && i < len)
			{
				if (needle[j + 1] == '\0')
					return ((char*)&haystack[save]);
				i++;
				j++;
			}
			i = save;
		}
		i++;
	}
	return (NULL);
}
