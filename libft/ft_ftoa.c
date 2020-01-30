/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:32:14 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/27 16:38:52 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_ftoa(long double f, int prec)
{
	char		*str;
	char		*bef;
	char		*aft;
	long double	a;

	bef = ft_itoa((int)f);
	(f < 0) ? f *= -1 : 0;
	a = f - (int)f;
	a = a * ft_pow(10, prec);
	aft = ft_itoa(a);
	str = ft_strjoin(bef, ".");
	ft_strcat(str, aft);
	free(bef);
	free(aft);
	return (str);
}
