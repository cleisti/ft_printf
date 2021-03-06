/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_mods.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:42:30 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/24 16:05:35 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*open_h(va_list args, t_args *ptr)
{
	unsigned short	us;
	short			sh;
	char			*str;

	if (ptr->mod == 3)
	{
		sh = va_arg(args, int);
		ptr->neg = (sh < 0) ? 1 : 0;
		str = ft_itoa(sh);
		return (str);
	}
	else
	{
		us = va_arg(args, int);
		if (us == 0)
			ptr->flag[0] = 0;
		if (ptr->mod == 5)
			str = ft_uitoa_base(us, 10);
		else if (ptr->mod == 4)
			str = ft_uitoa_base(us, 8);
		else
			str = ft_uitoa_base(us, 16);
		return (str);
	}
}

char	*open_hh(va_list args, t_args *ptr)
{
	unsigned char	uc;
	char			c;
	int				nb;
	char			*str;

	if (ptr->mod == 3)
	{
		c = va_arg(args, int);
		nb = c;
		ptr->neg = (nb < 0) ? 1 : 0;
		return (ft_itoa(nb));
	}
	else
	{
		uc = va_arg(args, int);
		nb = uc;
		ptr->flag[0] = (nb == 0) ? 0 : ptr->flag[0];
		if (ptr->mod == 5)
			str = ft_uitoa_base(uc, 10);
		else if (ptr->mod == 4)
			str = ft_uitoa_base(uc, 8);
		else
			str = ft_uitoa_base(nb, 16);
		return (str);
	}
}

char	*open_l(va_list args, t_args *ptr)
{
	unsigned long	ul;
	long			lo;
	char			*str;

	if (ptr->mod == 3)
	{
		lo = va_arg(args, long);
		ptr->neg = (lo < 0) ? 1 : 0;
		str = ft_itoa(lo);
		return (str);
	}
	else
	{
		ul = va_arg(args, unsigned long);
		if (ul == 0)
			ptr->flag[0] = 0;
		if (ptr->mod == 5)
			str = ft_uitoa_base(ul, 10);
		else if (ptr->mod == 4)
			str = ft_uitoa_base(ul, 8);
		else
			str = ft_uitoa_base(ul, 16);
		return (str);
	}
}

char	*open_ll(va_list args, t_args *ptr)
{
	unsigned long long	ull;
	long long			ll;
	char				*str;

	if (ptr->mod == 3)
	{
		ll = va_arg(args, long long);
		ptr->neg = (ll < 0) ? 1 : 0;
		str = ft_itoa(ll);
		return (str);
	}
	else
	{
		ull = va_arg(args, unsigned long long);
		ptr->flag[0] = (ull != 0 && ptr->flag[0] == 1) ? 1 : 0;
		if (ptr->mod == 5)
			str = ft_uitoa_base(ull, 10);
		else if (ptr->mod == 4)
			str = ft_uitoa_base(ull, 8);
		else
			str = ft_uitoa_base(ull, 16);
		return (str);
	}
}
