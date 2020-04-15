/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:54:42 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/24 17:07:12 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*s_prec(char *get, int prec_w)
{
	char	*str;

	str = ft_strnew(prec_w);
	ft_strncpy(str, get, prec_w);
	free(get);
	return (str);
}

static char		*s_width(char *get, t_args *ptr, int len)
{
	char	*str;

	str = ft_strnew(ptr->w);
	ft_memset(str, ' ', ptr->w);
	if (ptr->flag[1])
		ft_strncpy(str, get, len);
	else
		ft_strbcpy(str, get);
	free(get);
	return (str);
}

int				open_s(va_list args, t_args *ptr)
{
	char		*get;
	char		*str;
	int			len;

	get = va_arg(args, char *);
	if (!(get))
		str = ft_strdup("(null)");
	else
		str = ft_strdup(get);
	len = ft_strlen(str);
	if (ptr->prec && ptr->prec_w < len)
		str = s_prec(str, ptr->prec_w);
	len = ft_strlen(str);
	if (ptr->w > len)
		str = s_width(str, ptr, len);
	return (print_string(str));
}
