/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_funcs1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:16 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/18 16:57:17 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*open_c(va_list args, t_args *ptr)
{
	char	*str;
	char	c;

	if (!(c = va_arg(args, int)))
		ptr->null = 1;
	if (!(c))
		ptr->w -= 1;
	str = (ptr->w > 1) ? ft_strnew(ptr->w) : ft_strnew(1);
	if (ptr->w > 1)
		ft_memset(str, ' ', ptr->w);
//	printf("str: '%s'\n", str);
	if (c && (ptr->flag[1] == 1 || ptr->w <= 1))
		str[0] = c;
	else if (c)
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
//		printf("STR: '%s'\n", str);
		if (ptr->flag[1] == 1)
			ft_strncpy(str, get, len);
		else
			ft_strncpy(str + ptr->w - len, get, len);
	}
	else
		str = ft_strndup(get, len);
	return (str);
}

char	*p_prec(char *get, int prec_w, unsigned long long u)
{
	char	*str;
	int		len;

	len = ft_strlen(get);
	if (prec_w <= 0 && u == 0)
		return (ft_strdup("0x"));
	else if (len > prec_w)
		return (ft_strjoin("0x", get));
	else
	{
		str = ft_strnew(prec_w);
		ft_memset(str, '0', prec_w);
		ft_strcpy(str + (prec_w - len), get);
		str = ft_strjoin("0x", str);
	}
	return (str);
}

char	*open_p(va_list args, t_args *ptr)
{
	char				*get;
	char				*str;
	unsigned long long	u;
	int					len;

	u = va_arg(args, unsigned long long);
	get = ft_uitoa_base(u, 16);
	if (ptr->prec == 1)
		get = p_prec(get, ptr->prec_w, u);
	else
		get = ft_strjoin("0x", get);
	len = ft_strlen(get);
	if (ptr->w > len)
	{
		str = ft_strnew(ptr->w);
		ft_memset(str, ' ', ptr->w);
		if (ptr->flag[1] == 1)
			ft_strcpy(str, get);
		else
			ft_strcpy(str + (ptr->w - len), get);
	}
	else
		str = ft_strdup(get);
	free(get);
	return (str);
}
/*
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
	if (ptr->flag[3] == -1 && (ptr->flag[2] == 1 || ptr->flag[4] == 1))
		get = plus_space(get, ptr);
	if (ptr->w > (int)ft_strlen(get) || (!(ptr->neg) &&
		(ptr->flag[2] == 1 || ptr->flag[4] == 1)))
		get = set_width(get, ptr, ptr->neg);
	str = ft_strdup(get);
	free(get);
	return (str);
}
*/
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
