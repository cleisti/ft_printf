/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_funcs1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:16 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/07 18:13:58 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*open_c(va_list args, t_args *ptr)
{
	char	*str;
	char	c;

	if (!(c = va_arg(args, int)))
		ptr->null = 1;
	if (ptr->w > 1)
		str = set_str(ptr);
	else
		str = ft_strnew(2);
	if (ptr->flag[1] == 1 || ptr->w <= 1)
		str[0] = c;
	else
		str[ptr->w - 1] = c;
	return (str);
}

char	*open_s(va_list args, t_args *ptr)
{
	char	*get;
	char	*str;
	int		len;

	if (!(get = va_arg(args, char *)))
		get = ft_strdup("(null)");
	len = ft_strlen(get);
	if (ptr->prec_w != -1 && ptr->prec_w < len)
		len = ptr->prec_w;
	if (ptr->w > len)
	{
		str = set_str(ptr);
		if (ptr->flag[1] == 1)
			ft_strncpy(str, get, len);
		else
			ft_strncpy(str + ptr->w - len, get, len);
	}
	else
		str = ft_strndup(get, len);
	return (str);
}

char	*open_p(va_list args, t_args *ptr)
{
	char				*get;
	char				*str;
	unsigned long long	u;

	u = va_arg(args, unsigned long long);
	get = (u == 0) ? ft_strdup("") : ft_uitoa_base(u, 16);
	get = base_string(get, ptr);
	str = ft_strdup(get);
	free(get);
	return (str);
}

char	*open_di(va_list args, t_args *ptr)
{
	char	*get;
	char	*str;
	int		nb;

	if (ptr->len_mod == -1)
	{
		nb = va_arg(args, int);
		ptr->neg = (nb < 0 && (ptr->prec == 1 || ptr->flag[3] == 1));
		get = (nb == 0) ? ft_strdup("") : ft_itoa(nb);
	}
	else
		get = convert(args, ptr);
	if (ptr->prec_w >= (int)ft_strlen(get))
		get = add_zeros(get, ptr->prec_w, ptr->neg);
	if (ptr->flag[3] == -1 && (ptr->flag[2] == 1 || ptr->flag[4] == 1))
		get = plus_space(get, ptr);
	if (ptr->w > (int)ft_strlen(get) || (!(ptr->neg) &&
		(ptr->flag[2] == 1 || ptr->flag[4] == 1)))
		get = set_width(get, ptr, ptr->neg);
	str = ft_strdup(get);
	free(get);
	return (str);
}

char	*open_percentage(t_args *ptr)
{
	char	*str;
	char	*get;

	get = ft_strnew(1);
	get[0] = '%';
	if (ptr->w > 1)
		str = set_width(get, ptr, ptr->neg);
	else
		str = ft_strdup(get);
	free(get);
	return (str);
}
