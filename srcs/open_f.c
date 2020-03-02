/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:03:41 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/24 17:05:34 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*open_cl(va_list args, t_args *ptr)
{
	char		*str;
	long double	ld;

	ld = va_arg(args, long double);
	ptr->neg = (ld < 0.0) ? 1 : 0;
	str = (ptr->prec == 1) ? ft_ftoa(ld, ptr->prec_w, ptr->flag[0])
							: ft_ftoa(ld, 6, ptr->flag[0]);
	return (str);
}

static char		*f_psz(char *get, t_args *ptr, int neg)
{
	char	*str;
	int		len;

	if (ptr->flag[3])
	{
		len = ptr->w - ft_strlen(get);
		str = ft_strnew(ptr->w);
		ft_memset(str, '0', ptr->w);
		ft_strcpy(str + len + neg, get + neg);
		str[0] = (ptr->neg) ? '-' : str[0];
	}
	else
	{
		str = ft_strnew(ft_strlen(get) + 1);
		ft_memset(str, ' ', ft_strlen(get) + 1);
		ft_strcpy(str + 1, get);
	}
	str[0] = (ptr->flag[2]) ? '+' : str[0];
	str[0] = (ptr->flag[4]) ? ' ' : str[0];
	free(get);
	return (str);
}

static char		*f_width(char *get, t_args *ptr)
{
	char	*str;

	str = ft_strnew(ptr->w);
	ft_memset(str, ' ', ptr->w);
	if (ptr->flag[1])
		ft_strncpy(str, get, ft_strlen(get));
	else
		ft_strbcpy(str, get);
	free(get);
	return (str);
}

static void		set_flags(t_args *ptr, int len)
{
	if (ptr->flag[3])
		ptr->flag[3] = (ptr->w <= len) ? 0 : 1;
	if (ptr->flag[4])
		ptr->flag[4] = (ptr->neg) ? 0 : 1;
	if (ptr->flag[2])
		ptr->flag[2] = (ptr->neg) ? 0 : 1;
}

int				open_f(va_list args, t_args *ptr)
{
	long double	f;
	char		*str;
	int			len;

	if (ptr->len_mod == -1 || ptr->len_mod == 3)
	{
		f = va_arg(args, double);
		ptr->neg = (f < 0.0) ? 1 : 0;
		str = (ptr->prec) ? ft_ftoa(f, ptr->prec_w, ptr->flag[0])
								: ft_ftoa(f, 6, ptr->flag[0]);
	}
	else if (ptr->len_mod == 4)
		str = open_cl(args, ptr);
	len = ft_strlen(str);
	set_flags(ptr, len);
	if ((ptr->w > len && ptr->flag[3]) || ptr->flag[2]
		|| ptr->flag[4])
		str = f_psz(str, ptr, ptr->neg);
	len = ft_strlen(str);
	if (ptr->w > len)
		str = f_width(str, ptr);
	return (print_string(str));
}
