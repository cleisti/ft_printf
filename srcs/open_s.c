/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:54:42 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/19 13:54:49 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*s_prec(char *get, int prec_w)
{
	char 	*str;

	str = ft_strnew(prec_w);
	ft_strncpy(str, get, prec_w);
	return (str);
}

static char		*s_width(char *get, t_args *ptr, int len)
{
	char	*str;
	
	str = ft_strnew(ptr->w);
	ft_memset(str, ' ', ptr->w);
	if (ptr->flag[1] == 1)
		ft_strncpy(str, get, len);
	else
		ft_strbcpy(str, get);
	return (str);
}

int		open_s(va_list args, t_args *ptr)
{
	char	*get;
	char	*str;
	int		len;
	int		f;

	f = 0;
	if (!(get = va_arg(args, char *)))
	{
		get = ft_strdup("(null)");
		f = 1;
//		ptr->prec = 0;
	}
	len = ft_strlen(get);
//	printf("prec_w: %d | len : %d\n", ptr->prec_w, len);
	if (ptr->prec && ptr->prec_w < len)
		get = s_prec(get, ptr->prec_w);
	len = ft_strlen(get);
//	printf("prec_w2: %d | len: %d\n", ptr->prec_w, len);
	if (ptr->w > len)
		str = s_width(get, ptr, len);
	else
		str = ft_strdup(get);
	if (f)
		free(get);
	return (print_string(str));
}
