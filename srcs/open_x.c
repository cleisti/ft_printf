/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:32:25 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/19 11:52:20 by cleisti          ###   ########.fr       */
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

//	printf("check\n");
	if (ptr->flag[0] == 1 && ptr->w < (int)ft_strlen(get) + 2)
		return (get);
	str = (ptr->flag[0] == 1) ? ft_strnew(ptr->w - 2) : ft_strnew(ptr->w);
	str = (ptr->flag[0] == 1) ? ft_memset(str, '0', ptr->w - 2) : ft_memset(str, '0', ptr->w);
	dif = ptr->w - ft_strlen(get);
//	printf("dif: %d | w: %d | h: %d | str: '%s'\n", dif, ptr->w, ptr->flag[0], str);
	ft_strbcpy(str, get);
	free(get);
	str = (ptr->flag[0] == 1) ? ft_strjoin("0x", str) : str;
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
	if (left == 1)
		ft_strncpy(str, get, ft_strlen(get));
	else
		ft_strcpy(str + dif, get);
	free(get);
	return (str);
}

static void		set_flags(t_args *ptr, int len)
{
	if (ptr->flag[3] == 1)
		ptr->flag[3] = (ptr->flag[3] == 1 && ptr->prec == 0) ? 1 : 0;
	ptr->prec = (ptr->prec_w > len) ? 1 : 0;
	
}

int			open_x(va_list args, t_args *ptr)
{
	unsigned long long	ull;
	char				*str;
	int					len;
	
	if (ptr->len_mod == -1)
	{
		ull = va_arg(args, unsigned long long);
		ptr->flag[0] = (ull == 0) ? 0 : ptr->flag[0];
		str = (ull == 0 && ptr->prec == 1 && ptr->prec_w < 1) ? ft_strdup("") : ft_uitoa_base(ull, 16);
	}
	else
		str = convert(args, ptr);
	len = ft_strlen(str);
	set_flags(ptr, len);
//	printf("str: '%s' | len: %d | w: %d | 2: %d | 4: %d | 1: %d | 3: %d\n", str, len, ptr->w, ptr->flag[2], ptr->flag[4], ptr->flag[1], ptr->flag[3]);
	if (ptr->prec == 1)
		str = x_prec(str, ptr);
	if (ptr->w > len && ptr->flag[3] == 1)
		str = x_zero(str, ptr);
	if (ptr->flag[0] == 1)
		str = ft_strjoin("0x", str);
	len = ft_strlen(str);
	if (ptr->w > len)
		str = x_width(str, ptr->w, ptr->flag[1]);
	if (ptr->x)
		str = ft_strtoupper(str);
	return (print_string(str));
}