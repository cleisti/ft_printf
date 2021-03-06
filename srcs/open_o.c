/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:39:01 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/24 18:06:37 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*o_prec(char *get, t_args *ptr)
{
	char	*str;
	int		dif;

	str = ft_strnew(ptr->prec_w);
	ft_memset(str, '0', ptr->prec_w);
	dif = ptr->prec_w - ft_strlen(get);
	ft_strcpy(str + dif, get);
	free(get);
	ptr->flag[3] = 0;
	ptr->flag[0] = 0;
	return (str);
}

static char		*o_width(char *get, t_args *ptr)
{
	char	*str;

	str = ft_strnew(ptr->w);
	if (ptr->flag[3])
		ft_memset(str, '0', ptr->w);
	else
		ft_memset(str, ' ', ptr->w);
	if (ptr->flag[0] && get[0] != '0')
		get = zero_x(get, ptr->mod);
	if (ptr->flag[1])
		ft_strncpy(str, get, ft_strlen(get));
	else
		ft_strbcpy(str, get);
	free(get);
	ptr->flag[0] = 0;
	return (str);
}

static void		set_flags(t_args *ptr, int len)
{
	if (ptr->flag[3])
		ptr->flag[3] = (ptr->flag[3] && ptr->prec == 0) ? 1 : 0;
	if ((ptr->flag[0] && ptr->prec_w <= len && !(ptr->flag[3])) ||
		(ptr->flag[0] && ptr->flag[3] && ptr->w <= len))
		ptr->prec_w = len + 1;
	ptr->prec = (ptr->prec_w > len) ? 1 : 0;
}

static char		*nb_to_string(unsigned int nb, t_args *ptr)
{
	char	*str;

	if (nb == 0 && ptr->prec == 1 && ptr->prec_w < 1)
		str = ft_strdup("");
	else
	{
		str = ft_itoa_base(nb, 8);
		if (nb == 0 && ptr->flag[0])
			ptr->flag[0] = 0;
	}
	return (str);
}

int				open_o(va_list args, t_args *ptr)
{
	unsigned int	nb;
	char			*str;
	int				len;

	if (ptr->len_mod == -1)
	{
		nb = va_arg(args, long);
		str = nb_to_string(nb, ptr);
	}
	else
		str = convert(args, ptr);
	len = ft_strlen(str);
	set_flags(ptr, len);
	if (ptr->prec)
		str = o_prec(str, ptr);
	len = ft_strlen(str);
	if (ptr->w > len || ptr->flag[3])
		str = o_width(str, ptr);
	if (ptr->flag[0] && str[0] != '0')
		str = zero_x(str, ptr->mod);
	return (print_string(str));
}
