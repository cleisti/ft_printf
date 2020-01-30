/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_mods.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:42:30 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/30 16:04:58 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*open_h(va_list args, t_args *ptr)
{
	unsigned short	us;
	char			*str;
	short			sh;

	if (ptr->mod == 3)
	{
		sh = va_arg(args, int);
		ptr->neg = (sh < 0);
		str = ft_itoa(sh);
		return (str);
	}
	else
	{
		us = va_arg(args, int);
		str = ft_itoa(us);
		return (str);
	}
}

char	*open_hh(va_list args, t_args *ptr)
{
	unsigned char	uc;
	char			*str;
	char			c;
	int				nb;

	if (ptr->mod == 3)
	{
		c = va_arg(args, int);
		nb = c;
		str = ft_itoa(nb);
		return (str);
	}
	else
	{
		uc = va_arg(args, int);
		nb = uc;
		str = base_string(nb, 16, ptr);
		return (str);
	}
}

char	*open_l(va_list args, t_args *ptr)
{
	char			*str;
	long			lo;
	unsigned long	ul;

	if (ptr->mod == 3)
	{
		lo = va_arg(args, long);
		ptr->neg = (lo < 0);
		str = ft_itoa(lo);
		return (str);
	}
	else
	{
		ul = va_arg(args, unsigned long);
		str = base_string(ul, 16, ptr);
		return (str);
	}
}

char	*open_ll(va_list args, t_args *ptr)
{
	char				*str;
	long long			ll;
	unsigned long long	ull;

	if (ptr->mod == 3)
	{
		ll = va_arg(args, long long);
		ptr->neg = (ll < 0);
		str = ft_itoa(ll);
		return (str);
	}
	else
	{
		ull = va_arg(args, unsigned long long);
		str = base_string(ull, 16, ptr);
		return (str);
	}
}

char	*open_cl(va_list args, t_args *ptr)
{
	char		*get;
	long double	ld;

	ld = va_arg(args, long double);
	get = ft_ftoa(ld, ptr->prec_w);
	return (get);
}
