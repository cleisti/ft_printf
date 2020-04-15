/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:21:04 by cleisti           #+#    #+#             */
/*   Updated: 2019/11/08 17:49:11 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size, size_t old)
{
	void	*new;

	if (ptr == NULL)
	{
		if (!(new = (void*)malloc(size)))
			return (NULL);
		free(ptr);
	}
	else
	{
		if (!(new = (void*)malloc(size)))
			return (NULL);
		ft_memcpy(new, ptr, old);
		free(ptr);
	}
	return (new);
}
