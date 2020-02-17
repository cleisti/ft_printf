/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:49:25 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/17 16:36:38 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*u_prec(char *get, t_args *ptr)
{
	char	*str;
	int		dif;

//	printf("prec_w: %d\n", prec_w);
	str = ft_strnew(ptr->prec_w);
	ft_memset(str, '0', ptr->prec_w);
	dif = ptr->prec_w - ft_strlen(get);
	ft_strcpy(str + dif, get);
	free(get);
	ptr->flag[3] = 0;
	return (str);
}

static char		*u_zero(char *get, int w)
{
	char	*str;

	str = ft_strnew(w);
	ft_memset(str, '0', w);
	ft_strbcpy(str, get);
	free(get);
	return (str);
}

static char		*u_width(char *get, int w, int left)
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

char	*open_u(va_list args, t_args *ptr)
{
	unsigned long long	u;
	char				*str;
	int					len;

	if (ptr->len_mod == -1)
	{
		u = va_arg(args, unsigned long long);
		str = (u == 0 && ptr->prec && ptr->prec_w < 1) ? ft_strdup("") : ft_uitoa_base(u, 10);
	}
	else
		str = convert(args, ptr);
	len = ft_strlen(str);
//	printf("str: '%s' | len: %d | w: %d | 2: %d | 4: %d | 1: %d | 3: %d\n", str, len, ptr->w, ptr->flag[2], ptr->flag[4], ptr->flag[1], ptr->flag[3]);
	ptr->flag[3] = (ptr->flag[3] == 1 && ptr->prec == 0) ? 1 : 0;
	ptr->prec = (ptr->prec_w > len) ? 1 : 0;
	if (ptr->prec == 1)
		str = u_prec(str, ptr);
//	printf("STR2:: '%s'\n", str);
	if (ptr->w > len && ptr->flag[3] == 1)
		str = u_zero(str, ptr->w);
	len = ft_strlen(str);
	if (ptr->w > len)
		str = u_width(str, ptr->w, ptr->flag[1]);
//	printf("STR3:: '%s'\n", str);
	return (str);
}
