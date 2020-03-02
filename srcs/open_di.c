/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:33:13 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/24 17:04:35 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*di_prec(char *get, t_args *ptr)
{
	char	*str;
	int		dif;

	str = ft_strnew(ptr->prec_w + ptr->neg);
	dif = ptr->prec_w - ft_strlen(get) + ptr->neg;
	ft_memset(str, '0', ptr->prec_w + ptr->neg);
	if (ptr->neg == 1)
		str[0] = '-';
	ft_strcpy(str + dif + ptr->neg, get + ptr->neg);
	free(get);
	ptr->flag[3] = 0;
	return (str);
}

static char		*di_psz(char *get, t_args *ptr, int neg)
{
	char	*str;
	int		len;

	if (ptr->flag[3])
	{
		len = ptr->w - ft_strlen(get);
		str = ft_strnew(ptr->w);
		ft_memset(str, '0', ptr->w);
		ft_strcpy(str + len + neg, get + neg);
		str[0] = (ptr->neg) ? '-' : str[0];
	}
	else
	{
		str = ft_strnew(ft_strlen(get) + 1);
		ft_memset(str, ' ', ft_strlen(get) + 1);
		ft_strcpy(str + 1, get);
	}
	str[0] = (ptr->flag[2]) ? '+' : str[0];
	str[0] = (ptr->flag[4]) ? ' ' : str[0];
	free(get);
	return (str);
}

static char		*di_width(char *get, int w, int left)
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

static void		set_flags(t_args *ptr, int len)
{
	if (ptr->neg)
		len--;
	ptr->prec = (ptr->prec_w >= len) ? 1 : 0;
	if (ptr->flag[3])
		ptr->flag[3] = (ptr->prec || ptr->w <= len) ? 0 : 1;
	if (ptr->flag[4])
		ptr->flag[4] = (ptr->neg) ? 0 : 1;
	if (ptr->flag[2])
		ptr->flag[2] = (ptr->neg) ? 0 : 1;
}

int				open_di(va_list args, t_args *ptr)
{
	char	*str;
	int		nb;
	int		len;

	if (ptr->len_mod == -1)
	{
		nb = va_arg(args, int);
		ptr->neg = (nb < 0) ? 1 : 0;
		str = (nb == 0 && ptr->prec == 1 && ptr->prec_w <= 0) ? ft_strdup("")
															: ft_itoa(nb);
	}
	else
		str = convert(args, ptr);
	len = ft_strlen(str);
	set_flags(ptr, len);
	if (ptr->prec == 1)
		str = di_prec(str, ptr);
	len = ft_strlen(str);
	if ((ptr->w > len && ptr->flag[3]) || ptr->flag[2]
		|| ptr->flag[4])
		str = di_psz(str, ptr, ptr->neg);
	len = ft_strlen(str);
	if (ptr->w > len)
		str = di_width(str, ptr->w, ptr->flag[1]);
	return (print_string(str));
}
