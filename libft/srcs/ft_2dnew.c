/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 12:54:03 by camilla           #+#    #+#             */
/*   Updated: 2020/04/10 13:31:39 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function that returns a new null-terminated 2D array of size y*x.
*/

char	**ft_2dnew(int y_size, int x_size)
{
	char	**map;
	int		i;

	if (!(map = (char**)malloc(sizeof(char*) * y_size + 1)))
		return NULL;
	i = 0;
	while (i < y_size)
	{
		map[i] = ft_strnew(x_size);
		i++;
	}
	map[i] = NULL;
	return (map);
}
