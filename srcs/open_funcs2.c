/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:23:20 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/27 17:28:26 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*open_o(va_list args, t_args *ptr)
{
	int		nb;
	char	*str;
	char	*get;

	nb = va_arg(args, int);
	get = base_string(nb, 8, ptr);
	if (ptr->prec_w > (int)ft_strlen(get))
		get = add_zeros(get, ptr->prec_w, ptr->neg);
	if (ptr->w > (int)ft_strlen(get))
		str = set_width(get, ptr, ptr->neg);
	else
		str = ft_strdup(get);
	free(get);
	return (str);
}

char	*open_u(va_list args, t_args *ptr)
{
	unsigned int	u;
	char			*get;
	char			*str;

	u = va_arg(args, unsigned int);
	get = ft_itoa(u);
	if (ptr->prec_w > (int)ft_strlen(get))
		get = add_zeros(get, ptr->prec_w, ptr->neg);
	if (ptr->w > (int)ft_strlen(get))
		str = set_width(get, ptr, ptr->neg);
	else
		str = ft_strdup(get);
	free(get);
	return (str);
}

char	*open_x(va_list args, t_args *ptr)
{
	unsigned long long	nb;
	char				*str;
	char				*get;

	if (ptr->len_mod == -1)
	{
		nb = va_arg(args, unsigned long long);
		get = base_string(nb, 16, ptr);
	}
	else
		get = convert(args, ptr);
	if (ptr->prec_w > (int)ft_strlen(get))
		get = add_zeros(get, ptr->prec_w, ptr->neg);
	if (ptr->w > (int)ft_strlen(get))
		str = set_width(get, ptr, ptr->neg);
	else
		str = ft_strdup(get);
	free(get);
	return (str);
}

char	*open_f(va_list args, t_args *ptr)
{
	long double	f;
	char		*get;
	char		*str;

	if (ptr->len_mod == -1 || ptr->len_mod == 10)
	{
		f = va_arg(args, double);
		get = ft_ftoa(f, ptr->prec_w);
	}
	else
		get = convert(args, ptr);
	if (ptr->w > (int)ft_strlen(get))
		str = set_width(get, ptr, ptr->neg);
	else
		str = ft_strdup(get);
	free(get);
	return (str);
}
