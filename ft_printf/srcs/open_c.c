/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:54:59 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/24 17:36:16 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		c_null(t_args *ptr)
{
	char	*str;
	int		len;

	ptr->w = (ptr->w > 0) ? ptr->w - 1 : ptr->w;
	if (ptr->w == 0)
	{
		ft_putchar('\0');
		return (1);
	}
	str = ft_strnew(ptr->w);
	ft_memset(str, ' ', ptr->w);
	if (ptr->flag[1])
	{
		ft_putchar('\0');
		ft_putstr(str);
	}
	else
	{
		ft_putstr(str);
		ft_putchar('\0');
	}
	len = ft_strlen(str);
	free(str);
	return (len + 1);
}

int				open_c(va_list args, t_args *ptr)
{
	char	*str;
	char	c;

	if (!(c = va_arg(args, int)))
		return (c_null(ptr));
	if (ptr->w < 2)
	{
		ft_putchar(c);
		return (1);
	}
	else
	{
		str = ft_strnew(ptr->w);
		ft_memset(str, ' ', ptr->w);
		if (ptr->flag[1] || ptr->w <= 1)
			str[0] = c;
		else
			str[ptr->w - 1] = c;
	}
	return (print_string(str));
}

int				open_percentage(t_args *ptr)
{
	char	*str;

	if (ptr->w > 1)
	{
		str = ft_strnew(ptr->w);
		if (ptr->flag[3])
			ft_memset(str, '0', ptr->w);
		else
			ft_memset(str, ' ', ptr->w);
		if (ptr->flag[1])
			str[0] = '%';
		else
			str[ptr->w - 1] = '%';
	}
	else
		str = ft_strdup("%");
	return (print_string(str));
}
