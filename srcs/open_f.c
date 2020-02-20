/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:03:41 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/19 15:11:47 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*open_cl(va_list args, t_args *ptr)
{
	char		*str;
	long double	ld;

	ld = va_arg(args, long double);
	str = ft_ftoa(ld, ptr->prec_w);
	return (str);
}

static char		*f_width(char *get, t_args *ptr)
{
	char	*str;

	str = ft_strnew(ptr->w);
	ft_memset(str, ' ', ptr->w);
	if (ptr->flag[1] == 1)
		ft_strncpy(str, get, ft_strlen(get));
	else
		ft_strbcpy(str, get);
	free(get);
	return (str);
}

int				open_f(va_list args, t_args *ptr)
{
	long double	f;
	char		*str;
	int			len;

	if (ptr->len_mod == -1 || ptr->len_mod == 2)
	{
		f = va_arg(args, double);
//		printf("prec_w: %d\n", ptr->prec_w);
		str = (ptr->prec == 1) ? ft_ftoa(f, ptr->prec_w) : ft_ftoa(f, 6);
//		printf("str: '%s'\n", str);
	}
	else if (ptr->len_mod == 4)
		str = open_cl(args, ptr);
	len = ft_strlen(str);
	if (ptr->w > len)
		str = f_width(str, ptr);
	return (print_string(str));
}
