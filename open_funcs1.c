/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_funcs1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:16 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/17 17:51:23 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** SHOULD WORK! =)
*/

char	*open_c(va_list args, t_args *ptr)
{
	char	*str;
	char	c;
	int		len;

	c = va_arg(args, int);
	len = 1;
	str = set_str(len, ptr->w, ' ');
	if (ptr->flag[1] == 1 || ptr->w <= len)
		str[0] = c;
	else
		str[ptr->w - 1] = c;
	return (str);
}

/*
** SHOULD WORK! =)
*/

char	*open_s(va_list args, t_args *ptr)
{
	char	*get;
	char	*str;
	int		len;
	
	get = va_arg(args, char *);
	len = ft_strlen(get);
	if (ptr->len_mod != 0 && ptr->len_mod < len)
		len = ptr->len_mod;
	if (ptr->w > len)
	{
		str = set_str(len, ptr->w, ' ');
		if (ptr->flag[1] == 1)
			ft_strncpy(str, get, len);
		else
			ft_strncpy(str + ptr->w - len, get, len);
	}
	else
		str = ft_strndup(get, len);
	return (str);
}

/*
** 
*/

char	*open_p(va_list args, t_args *ptr)
{
	char				*get;
	char				*str;
	unsigned long long	u;
	int					len;

	u = va_arg(args, unsigned long);
	get = base_string(u);
	len = ft_strlen(get);
	if (ptr->w > len)
	{
		str = set_str(len, ptr->w, ' ');
		if (ptr->flag[1] == 1)
			ft_strncpy(str, get, len);
		else
			ft_strncpy(str + ptr->w - len, get, len);
	}
	else
		return (get);
	free(get);
	return (str);
}

/*
** 
*/

char	*open_d(va_list args, t_args *ptr)
{
	char	*get;
	char	*str;
	int		nb;
	int		len;

	nb = va_arg(args, int);
	get = ft_itoa(nb);
	len = ft_strlen(get);
	str = set_str(len, ptr->w, ' ');
	str = ft_strdup(get);
	return (str);
}
