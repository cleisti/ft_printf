 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:13:37 by cleisti           #+#    #+#             */
/*   Updated: 2019/11/06 12:03:17 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!(s1) || !(s2))
		return (NULL);
	i = ft_strlen((char*)s1);
	j = ft_strlen((char*)s2);
	str = ft_strnew(i + j + 1);
	ft_strncpy(str, s1, i);
	ft_strncpy(&str[i], s2, j);
	str[i + j] = '\0';
	return (str);
}
