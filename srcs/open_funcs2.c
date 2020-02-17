/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:23:20 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/13 18:29:20 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*open_f(va_list args, t_args *ptr)
{
	long double	f;
	char		*str;

	if (ptr->len_mod == -1 || ptr->len_mod == 10)
	{
		f = va_arg(args, double);
		str = ft_ftoa(f, ptr->prec_w);
	}
	else
		str = convert(args, ptr);
	if (ptr->w > (int)ft_strlen(str))
		str = set_width(str, ptr, ptr->neg);
	return (str);
}
