/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:38:37 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/17 17:39:51 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_str(int len, int w, char c)
{
	char *str;

	if (w > len)
	{
		str = ft_strnew(w);
		ft_memset(str, c, w);
		return (str);
	}
	str = ft_strnew(len);
	ft_memset(str, c, w);
	return (str);
}

char	*base_string(unsigned long long u)
{
	char	*str;
	char	*get;
	char	*zx;

	zx = "0x";
	get = ft_itoa_base(u, 16);
	str = ft_strjoin(zx, get);
	free(get);
	return (str);
}
