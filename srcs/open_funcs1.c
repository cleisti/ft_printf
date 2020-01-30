/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_funcs1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:16 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/30 16:04:33 by cleisti          ###   ########.fr       */
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
		str = set_str(ptr->w, ' ');
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
		str = set_str(ptr->w, ' ');
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
	int					len;

	u = va_arg(args, unsigned long long);
	get = base_string(u, 16, ptr);
	len = ft_strlen(get);
	if (ptr->w > len)
	{
		str = set_str(ptr->w, ' ');
		if (ptr->flag[1] == 1)
			ft_strncpy(str, get, len);
		else
			ft_strncpy(str + ptr->w - len, get, len);
	}
	else
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
		ptr->neg = (nb < 0);
		get = ft_itoa(nb);
	}
	else
		get = convert(args, ptr);
	if (ptr->prec_w >= (int)ft_strlen(get))
		get = add_zeros(get, ptr->prec_w, ptr->neg);
	if (!(ptr->neg) && (ptr->flag[2] == 1 || ptr->flag[4] == 1))
		get = plus_space(get, ptr->flag[2], ptr->flag[4]);
	if (ptr->w > (int)ft_strlen(get))
		str = set_width(get, ptr, ptr->neg);
	else
		str = ft_strdup(get);
	free(get);
	return (str);
}
