/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_mods.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:42:30 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/04 14:47:52 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*open_h(va_list args, t_args *ptr)
{
	unsigned short	us;
	char			*str;
	char			*get;
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
		if (us == 0)
			ptr->flag[0] = 0;
		if (ptr->mod == 5)
			get = ft_uitoa_base(us, 10);
		else if (ptr->mod == 4)
			get = ft_uitoa_base(us, 8);
		else
			get = ft_uitoa_base(us, 16);
		str = base_string(get, ptr);
		return (str);
	}
}

char	*open_hh(va_list args, t_args *ptr)
{
	unsigned char	uc;
	char			*str;
	char			*get;
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
		if (nb == 0)
			ptr->flag[0] = 0;
		if (ptr->mod == 5)
			get = ft_uitoa_base(uc, 10);
		else if (ptr->mod == 4)
			get = ft_uitoa_base(uc, 8);
		else
			get = ft_uitoa_base(nb, 16);
		return (base_string(get, ptr));
	}
}

char	*open_l(va_list args, t_args *ptr)
{
	char			*str;
	char			*get;
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
		if (ul == 0)
			ptr->flag[0] = 0;
		if (ptr->mod == 5)
			get = ft_uitoa_base(ul, 10);
		else if (ptr->mod == 4)
			get = ft_uitoa_base(ul, 8);
		else
			get = ft_uitoa_base(ul, 16);
		str = base_string(get, ptr);
		return (str);
	}
}

char	*open_ll(va_list args, t_args *ptr)
{
	char				*str;
	char				*get;
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
		if (ull == 0)
			ptr->flag[0] = 0;
		if (ptr->mod == 5)
			get = ft_uitoa_base(ull, 10);
		else if (ptr->mod == 4)
			get = ft_uitoa_base(ull, 8);
		else
			get = ft_uitoa_base(ull, 16);
		str = base_string(get, ptr);
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
