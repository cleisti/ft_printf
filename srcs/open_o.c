/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:39:01 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/17 16:56:32 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*o_prec(char *get, t_args *ptr)
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

static char		*o_zero(char *get, int w)
{
	char	*str;

	str = ft_strnew(w);
	ft_memset(str, '0', w);
	ft_strbcpy(str, get);
	free(get);
	return (str);
}

static char		*o_width(char *get, t_args *ptr)
{
	char	*str;

	str = ft_strnew(ptr->w);
	ft_memset(str, ' ', ptr->w);
	if (ptr->flag[0] == 1 && str[0] != '0')
		get = ft_strjoin("0", get);
	if (ptr->flag[1] == 1)
		ft_strncpy(str, get, ft_strlen(get));
	else
		ft_strbcpy(str, get);
	free(get);
	ptr->flag[0] = 0;
	return (str);
}

static void		set_flags(t_args *ptr, int len)
{
	if (ptr->flag[3] == 1)
		ptr->flag[3] = (ptr->flag[3] == 1 && ptr->prec == 0) ? 1 : 0;
	ptr->prec = (ptr->prec_w > len) ? 1 : 0;
}

char			*open_o(va_list args, t_args *ptr)
{
	long long	nb;
	char		*str;
	int			len;

	if (ptr->len_mod == -1)
	{
		nb = va_arg(args, long long);
		ptr->flag[0] = (nb == 0) ? 0 : ptr->flag[0];
		str = (nb == 0 && ptr->prec == 1 && ptr->prec_w < 1) ? ft_strdup("") : ft_itoa_base(nb, 8);
//		printf("str: '%s'\n", str);
	}
	else
		str = convert(args, ptr);
	len = ft_strlen(str);
//	printf("str: '%s' | len: %d | w: %d | 2: %d | 4: %d | 1: %d | 3: %d\n", str, len, ptr->w, ptr->flag[2], ptr->flag[4], ptr->flag[1], ptr->flag[3]);
	set_flags(ptr, len);
	if (ptr->prec == 1)
		str = o_prec(str, ptr);
	len = ft_strlen(str);
	if (ptr->w > len && ptr->flag[3] == 1)
		str = o_zero(str, ptr->w);
	len = ft_strlen(str);
	if (ptr->w > len)
		str = o_width(str, ptr);
	if (ptr->flag[0] == 1 && str[0] != '0')
		str = ft_strjoin("0", str);
	return (str);
}
