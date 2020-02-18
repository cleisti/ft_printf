/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:03:41 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/18 15:33:28 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*open_cl(va_list args, t_args *ptr)
{
	char		*get;
	long double	ld;

	ld = va_arg(args, long double);
	get = ft_ftoa(ld, ptr->prec_w);
	return (get);
}

char	*open_f(va_list args, t_args *ptr)
{
	long double	f;
	char		*str;
	int			len;

	if (ptr->len_mod == -1 || ptr->len_mod == 10)
	{
		f = va_arg(args, double);
//		printf("prec_w: %d\n", ptr->prec_w);
		str = (ptr->prec == 1) ? ft_ftoa(f, ptr->prec_w) : ft_ftoa(f, 6);
	}
	else if (ptr->len_mod == 12)
		str = open_cl(args, ptr);
	len = ft_strlen(str);
	
	if (ptr->w > (int)ft_strlen(str))
		str = set_width(str, ptr, ptr->neg);
	return (str);
}
