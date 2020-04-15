/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:32:14 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/24 17:31:00 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double		r(long double f, int prec)
{
	long double		r;
	int				i;

	r = 0.5;
	i = 0;
	if (f < 0)
		r *= -1;
	while (i < prec)
	{
		r /= 10.0;
		i++;
	}
	return (r);
}

static char				*after(long double f, int prec)
{
	char	*str;
	int		i;
	int		num;

	num = prec;
	str = ft_strnew(prec + 1);
	str[0] = '.';
	i = 1;
	while (prec > 0)
	{
		f *= 10;
		str[i] = (int)f + '0';
		f -= (int)f;
		prec--;
		i++;
	}
	f *= 10;
	if (num > 18 && f >= 5.0)
		str[i - 1]++;
	return (str);
}

char					*ft_ftoa(long double f, int prec, int p)
{
	long	num;
	char	*str;
	char	*bef;
	char	*aft;

	f = f + r(f, prec);
	num = f;
	bef = (f < 0.0 && f > -1.0) ? ft_strjoin("-", ft_itoa(num))
								: ft_itoa(num);
	f = (f < 0.0) ? f *= -1 : f;
	if (!(p) && !(prec))
		return (bef);
	f -= (num < 0) ? -num : num;
	aft = after(f, prec);
	str = ft_strjoin(bef, aft);
	free(bef);
	free(aft);
	return (str);
}
