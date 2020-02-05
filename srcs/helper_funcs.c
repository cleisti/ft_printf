/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:38:37 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/05 19:27:51 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_str(int w, char c)
{
	char *str;

	str = ft_strnew(w);
	ft_memset(str, c, w);
	return (str);
}

char	*base_string(char *get, t_args *ptr)
{
	char	*str;
	int		i;

	i = 0;
	if (ptr->prec_w > (int)ft_strlen(get))
		get = add_zeros(get, ptr->prec_w, ptr->neg);
	if (ptr->mod == 2 || (ptr->mod == 6 && ptr->flag[0] == 1))
		get = ft_strjoin("0x", get);
	if (ptr->flag[0] == 1 && ptr->mod == 4)
		get = ft_strjoin("0", get);
	if (ptr->w > (int)ft_strlen(get))
		str = set_width(get, ptr, ptr->neg);
	else
		str = ft_strdup(get);
	if (ptr->x == 1)
	{
		while (str[i])
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	free(get);
	return (str);
}

char	*plus_space(char *get, int plus, int space)
{
	char *str;

	str = ft_strnew(ft_strlen(get) + 1);
	if (plus == 1)
		str[0] = '+';
	else if (space == 1)
		str[0] = ' ';
	ft_strcpy(str + 1, get);
	free(get);
	return (str);
}

char	*add_zeros(char *get, int len, int neg)
{
	char	*str;
	int		dif;

	str = ft_strnew(len + neg);
	dif = len - ft_strlen(get) + neg;
	ft_memset(str, '0', len + neg);
	if (neg == 1)
		str[0] = '-';
	ft_strcpy(str + dif + neg, get + neg);
	free(get);
	return (str);
}

char	*set_width(char *get, t_args *ptr, int neg)
{
	char	*str;
	int		len;
	int		dif;

	len = ft_strlen(get);
	dif = ptr->w - ft_strlen(get);
	if (ptr->mod > 2 && ptr->flag[3] == 1 && ptr->flag[1] != 1 &&
		(ptr->mod == 7 || ptr->prec == 0))
		str = set_str(ptr->w, '0');
	else
		str = set_str(ptr->w, ' ');
	if (neg == 1 && ptr->flag[1] != 1 && !(ptr->prec))
		str[0] = '-';
	if (ptr->flag[1] == 1)
		ft_strncpy(str, get, len);
	else
		ft_strncpy(str + dif, get, len);
	return (str);
}
