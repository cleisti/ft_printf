/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:23:20 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/05 18:04:39 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*open_o(va_list args, t_args *ptr)
{
	long long	nb;
	char		*str;
	char		*get;

	if (ptr->len_mod == -1)
	{
		nb = va_arg(args, long long);
		get = ft_itoa_base(nb, 8);
		get = base_string(get, ptr);
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

char	*open_u(va_list args, t_args *ptr)
{
	unsigned int	u;
	char			*get;
	char			*str;

	if (ptr->len_mod == -1)
	{
		u = va_arg(args, unsigned int);
		get = ft_itoa(u);
		get = base_string(get, ptr);
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

char	*open_x(va_list args, t_args *ptr)
{
	unsigned int	nb;
	char			*str;
	char			*get;

	if (ptr->len_mod == -1)
	{
		nb = va_arg(args, unsigned int);
		if (nb == 0)
			return (get = ft_strdup(""));
		get = ft_uitoa_base(nb, 16);
		get = base_string(get, ptr);
	}
	else
		get = convert(args, ptr);
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
