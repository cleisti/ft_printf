/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:32:14 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/20 16:31:23 by cleisti          ###   ########.fr       */
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

static char		*after(long double f, int i, int prec)
{
	char			*str;
	int				len;
	long double		a;
	long double		b;

	if (f > 0.0 && f > i)
		a = f - i;
	else
		a = i - f;
//	else
//		a = f - (int)f;
	a = (a < 0.0) ? a *= -1 : a;
	b = a;
//	printf("a: %Lf\n", a);
	if (a == 0.0)
		str = zero_prec(prec);
	else
	{
		a *= ft_pow(10, prec);
		b *= ft_pow(10, prec + 1);
		printf("a: '%Lf' | b: '%Lf' | b - a: %Lf\n", a, b, (b - a) * 0.0000001);
		a += (b - a) * 0.0000001;
//		b = ft_log10(a, prec);
//		a = a + (b - a);
//		a = ft_log10(a, prec);
//		printf("(int)a: '%d' | a: %Lf\n", (int)a, a);
//		if (a - (int)a > 0.0 && a - (int)a < 0.9)
//			a += 1;
		str = ft_itoa(a);
		len = ft_strlen(str);
		if (len < prec)
			str = ft_strjoin(zero_prec(prec - len), str);
//		printf("aft: '%s'\n", str);
	}
	return (str);
}

char			*ft_ftoa(long double f, int prec)
{
	char		*str;
	char		*bef;
	int			i;

	prec = (prec < 0) ? 0 : prec;
	if (prec <= 15)
		f = (f > 0.0) ? f + 0.1 / ft_pow(10, prec) : f - 0.5 / ft_pow(10, prec);
//	printf("\nf: %Lf | (int)f: %d\n", f, (int)f);
//	f = (f > 0.0) ? f + 0.000001 : f - 0.000001;
	if (f > 0.0)
		i = (f - (int)f + 0.5 >= 1 && prec) ? (int)f : f + 0.5;
	else
		i = (f + (int)f - 0.5 <= -1 && prec) ? (int)f : f - 0.5;
//	printf("i: %d\n", i);
	bef = (f < 0.0 && f > -1) ? ft_strjoin("-", ft_itoa(i)) : ft_itoa(i);
//	printf("bf: '%s'\n", bef);
	if (prec == 0)
		return (bef);
//	(f < 0) ? f *= -1 : 0;
//	printf("f: %Lf i: %d\n", f, i);
	
//	a = (f > 0.0 && f > i) ? f - i : i - f;
//	printf("A: %Lf\n", a);
//	printf("\na: '%Lf' | int(f): %d\n", a, (int)f);
	str = ft_strjoin(bef, ".");
	ft_strcat(str, after(f, i, prec));
	free(bef);
	return (str);
}
