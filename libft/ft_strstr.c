/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:15:52 by cleisti           #+#    #+#             */
/*   Updated: 2019/11/06 12:03:50 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int save;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			save = i;
			while (haystack[i] == needle[j] && needle[j] != '\0')
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
