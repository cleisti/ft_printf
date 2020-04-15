/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:23:28 by cleisti           #+#    #+#             */
/*   Updated: 2019/11/10 11:39:32 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	if (!(s))
		return (NULL);
	j = ft_strlen((char*)s);
	while (ft_isspace(s[i]))
		i++;
	while (ft_isspace(s[j - 1]))
		j--;
	if (i > j)
		return (ft_strdup(""));
	len = j - i;
	str = ft_strnew((size_t)len + 1);
	if (!(str))
		return (NULL);
	str = ft_strsub(s, i, len);
	str[len] = '\0';
	return (str);
}
