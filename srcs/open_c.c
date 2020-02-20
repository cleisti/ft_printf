/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:54:59 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/19 15:44:49 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		c_null(t_args *ptr)
{
	char	*str;
	
	ptr->w -= 1;
	if (ptr->w < 2)
	{
		ft_putchar('\0');
		return (1);
	}
	else
	{
		str = ft_strnew(ptr->w);
		ft_memset(str, ' ', ptr->w);
		if (ptr->flag[1] == 1 || ptr->w <= 1)
		{
			ft_putchar('\0');
			ft_putstr(str);
		}
		else
		{
			ft_putstr(str);
			ft_putchar('\0');
		}
	}
	return (ft_strlen(str));
}

int				open_c(va_list args, t_args *ptr)
{
	char	*str;
	char	c;

	if (!(c = va_arg(args, int)))
		ptr->null = 1;
	if (ptr->null == 0)
	{
		if (ptr->w < 2)
		{
			ft_putchar(c);
			return (1);
		}
		else
		{
			str = ft_strnew(ptr->w);
			ft_memset(str, ' ', ptr->w);
			if (ptr->flag[1] == 1 || ptr->w <= 1)
				str[0] = c;
			else
				str[ptr->w - 1] = c;
			ft_putstr(str);
		}
		return (ft_strlen(str));
	}
	return (c_null(ptr));
}

int				open_percentage(t_args *ptr)
{
	char	*str;

//	printf("flag[3]: %d\n", ptr->flag[3]);
	if (ptr->w > 1)
	{
		str = ft_strnew(ptr->w);
		if (ptr->flag[3] == 1)
			ft_memset(str, '0', ptr->w);
		else
			ft_memset(str, ' ', ptr->w);
		if (ptr->flag[1] == 1)
			str[0] = '%';
		else
			str[ptr->w - 1] = '%';
	}
	else
		str = ft_strdup("%");
	return (print_string(str));
}
