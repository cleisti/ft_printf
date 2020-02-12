/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:23:20 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/12 16:46:14 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*o_prec(char *get, int prec_w)
{
	char	*str;
	int		dif;

//	printf("prec_w: %d\n", prec_w);
	str = ft_strnew(prec_w);
	ft_memset(str, '0', prec_w);
	dif = prec_w - ft_strlen(get);
	ft_strcpy(str + dif, get);
	free(get);
	return (str);
}

static char		*o_width(char *get, int w, int left)
{
	char	*str;
	int		dif;

	str = ft_strnew(w);
	ft_memset(str, ' ', w);
	dif = w - ft_strlen(get);
	if (left == 1)
		ft_strncpy(str, get, ft_strlen(get));
	else
		ft_strcpy(str + dif, get);
	free(get);
	return (str);
}

char	*open_o(va_list args, t_args *ptr)
{
	long long	nb;
	char		*str;
	int			len;

	if (ptr->len_mod == -1)
	{
		nb = va_arg(args, long long);
		str = (nb == 0 && ptr->prec == 1 && ptr->prec_w < 1) ? ft_strdup("") : ft_itoa_base(nb, 8);
//		printf("str: '%s'\n", str);
	}
	else
		str = convert(args, ptr);
	len = ft_strlen(str);
	ptr->prec = (ptr->prec_w > len) ? 1 : 0;
	if (ptr->prec == 1)
		str = o_prec(str, ptr->prec_w);
	len = ft_strlen(str);
	if (ptr->w > len)
		str = o_width(str, ptr->w, ptr->flag[1]);
	if (ptr->flag[0] == 1 && str[0] != '0')
		str = ft_strjoin("0", str);
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
	unsigned long long	nb;
	char				*str;
	char				*get;

	if (ptr->len_mod == -1)
	{
		nb = va_arg(args, unsigned long long);
		if (nb == 0 && ((ptr->prec == 1 && ptr->w == 0 && ptr->flag[0] == -1)
			|| (ptr->prec == 1 && ptr->flag[0] == 1)))
			return (get = ft_strdup(""));
		else if (nb == 0 && ptr->flag[0] == 1)
			ptr->flag[0] = -1;
		if (nb == 0 && ptr->w > 0)
			get = ft_strdup(" ");
		else
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
