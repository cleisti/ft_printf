/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:53:58 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/19 13:54:04 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*p_prec(char *get, int prec_w, unsigned long long u)
{
	char	*str;
	int		len;

	len = ft_strlen(get);
	if (prec_w <= 0 && u == 0)
		str = ft_strdup("0x");
	else if (len > prec_w)
		str = ft_strjoin("0x", get);
	else
	{
		str = ft_strnew(prec_w);
		ft_memset(str, '0', prec_w);
		ft_strcpy(str + (prec_w - len), get);
		str = ft_strjoin("0x", str);
	}
	free(get);
	return (str);
}

static char		*p_width(char *get, t_args *ptr)
{
	char	*str;
	
	str = ft_strnew(ptr->w);
	ft_memset(str, ' ', ptr->w);
//	printf("str: '%s'\n", str);
	if (ptr->flag[1] == 1)
		ft_strncpy(str, get, ft_strlen(get));
	else
		ft_strbcpy(str, get);
	free(get);
	return (str);
}

int		open_p(va_list args, t_args *ptr)
{
	char				*str;
	unsigned long long	u;
	int					len;

	u = va_arg(args, unsigned long long);
	str = ft_uitoa_base(u, 16);
	if (ptr->prec == 1)
		str = p_prec(str, ptr->prec_w, u);
	else
		str = ft_strjoin("0x", str);
	len = ft_strlen(str);
//	printf("w: %d | len: %d\n", ptr->w, len);
	if (ptr->w > len)
		str = p_width(str, ptr);
	return (print_string(str));
}
