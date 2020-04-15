/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:32:25 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/24 18:41:12 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*x_prec(char *get, t_args *ptr)
{
	char	*str;
	int		dif;

	str = ft_strnew(ptr->prec_w);
	ft_memset(str, '0', ptr->prec_w);
	dif = ptr->prec_w - ft_strlen(get);
	ft_strcpy(str + dif, get);
	free(get);
	ptr->flag[3] = 0;
	return (str);
}

static char		*x_zero(char *get, t_args *ptr)
{
	char	*str;
	int		dif;

	if (ptr->flag[0] && ptr->w < (int)ft_strlen(get) + 2)
		return (get);
	str = (ptr->flag[0]) ? ft_strnew(ptr->w - 2) : ft_strnew(ptr->w);
	str = (ptr->flag[0]) ? ft_memset(str, '0', ptr->w - 2)
							: ft_memset(str, '0', ptr->w);
	dif = ptr->w - ft_strlen(get);
	ft_strbcpy(str, get);
	free(get);
	str = (ptr->flag[0]) ? zero_x(str, ptr->mod) : str;
	ptr->flag[0] = 0;
	return (str);
}

static char		*x_width(char *get, int w, int left)
{
	char	*str;
	int		dif;

	str = ft_strnew(w);
	ft_memset(str, ' ', w);
	dif = w - ft_strlen(get);
	if (left)
		ft_strncpy(str, get, ft_strlen(get));
	else
		ft_strcpy(str + dif, get);
	free(get);
	return (str);
}

int				open_x(va_list args, t_args *ptr)
{
	unsigned int	u;
	char			*str;

	if (ptr->len_mod == -1)
	{
		u = va_arg(args, unsigned long long);
		ptr->flag[0] = (u == 0) ? 0 : ptr->flag[0];
		str = (u == 0 && ptr->prec == 1 && ptr->prec_w < 1) ? ft_strdup("")
													: ft_uitoa_base(u, 16);
	}
	else
		str = convert(args, ptr);
	ptr->prec = (ptr->prec_w > (int)ft_strlen(str)) ? 1 : 0;
	if (ptr->prec)
		str = x_prec(str, ptr);
	if (ptr->w > (int)ft_strlen(str) && ptr->flag[3])
		str = x_zero(str, ptr);
	if (ptr->flag[0])
		str = zero_x(str, ptr->mod);
	if (ptr->w > (int)ft_strlen(str))
		str = x_width(str, ptr->w, ptr->flag[1]);
	if (ptr->x)
		str = ft_strtoupper(str);
	return (print_string(str));
}
