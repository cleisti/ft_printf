/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:32:14 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/18 15:40:52 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		*zero_prec(int prec)
{
	char	*str;

	str = ft_strnew(prec);
	ft_memset(str, '0', prec);
	return (str);
}

char			*ft_ftoa(long double f, int prec)
{
	char		*str;
	char		*bef;
	char		*aft;
	long double	a;

	prec = (prec < 0) ? 0 : prec;
	bef = ft_itoa((int)f);
	if (prec == 0)
		return (bef);
	(f < 0) ? f *= -1 : 0;
	a = f - (int)f;
	if (a > 0.0)
	{
		a = a * ft_pow(10, prec);
		aft = ft_itoa(a);
	}
	else
		aft = zero_prec(prec);
	str = ft_strjoin(bef, ".");
	ft_strcat(str, aft);
	free(bef);
	free(aft);
	return (str);
}
