/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:11:52 by cleisti           #+#    #+#             */
/*   Updated: 2019/12/13 19:08:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!(s))
		return (NULL);
	str = (char*)malloc(sizeof(char) * len + 1);
	if (!(str))
		return (NULL);
	ft_strncpy(str, &s[start], len);
	str[len] = '\0';
	return (str);
}
