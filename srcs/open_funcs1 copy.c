/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_funcs1 copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:16 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/10 17:47:27 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*open_c(va_list args, t_args *ptr)
{
	char	*str;
	char	c;

	if (!(c = va_arg(args, int)))
		ptr->null = 1;
	str = (ptr->w > 1) ? ft_strnew(ptr->w) : ft_strnew(1);
	if (ptr->w > 1)
		ft_memset(str, " ", ptr->w);
	if (ptr->flag[1] || ptr->w < 1)
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
	if (ptr->prec && ptr->prec_w < len)
		len = ptr->prec_w;
	if (ptr->w > len)
	{
		str = ft_strnew(ptr->w);
		if (ptr->mod > 2 && ptr->flag[3] == 1 &&
			(ptr->mod == 7 || ptr->prec == 0))
			ft_memset(str, '0', ptr->w);
		else
			ft_memset(str, ' ', ptr->w);
		if (ptr->flag[1] == 1)
			ft_strncpy(str, get, len);
		else
			ft_strncpy(str + ptr->w - len, get, len);
	}
	else
		str = ft_strdup(get);
	return (str);
}

char	*open_p(va_list args, t_args *ptr)
{
	char				*get;
	char				*str;
	unsigned long long	u;
	int					len;

	if (!(u = va_arg(args, unsigned long long)) && ptr->prec_w < 1)
		get = ft_strdup("0x");
	else
		get = ft_uitoa_base(u, 16);
	len = ft_strlen(get);
	if (ptr->prec_w > len)
	{
		str = ft_strnew(ptr->prec_w);
		ft_memset(str, "0", ptr->prec_w);
		ft_strcpy(str + (ptr->prec_w - len), get);
		len = ft_strlen(str);
	}
	if (ptr->flag[3] && ptr->w > len + 2)
		str = ft_strjoin(ft_memset(ft_strnew(ptr->w - len - 2), "0", ptr->w - len - 2), str);
	else if (ptr->w > len + 2 && ptr->flag[1])
		str = ft_strjoin("0x", ft_strjoin(str, ft_memset(ft_strnew(ptr->w - len - 2), " ", ptr->w - len - 2)));
	else if (ptr->w > len + 2)
		str = ft_strjoin(ft_memset(ft_strnew(ptr->w - len - 2), " ", ptr->w - len - 2), ft_strjoin("0x", str));
	else
		str = ft_strjoin("0x", str);
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
		get = ft_itoa(nb);
	}
	else
		get = convert(args, ptr);
	if (ptr->prec_w >= (int)ft_strlen(get))
		get = add_zeros(get, ptr->prec_w, ptr->neg);
	printf("get1: %s\n", get);
	if (ptr->flag[3] == -1 && (ptr->flag[2] == 1 || ptr->flag[4] == 1))
		get = plus_space(get, ptr);
	printf("get2: %s\n", get);
	if (ptr->w > (int)ft_strlen(get) || (!(ptr->neg) &&
		(ptr->flag[2] == 1 || ptr->flag[4] == 1)))
		get = set_width(get, ptr, ptr->neg);
	printf("get3: %s\n", get);
	str = ft_strdup(get);
	free(get);
	printf("str: %s\n", str);
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
