/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:38:37 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/10 16:26:29 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_str(t_args *ptr)
{
	char *str;

	str = ft_strnew(ptr->w);
	if (ptr->mod > 2 && ptr->flag[3] == 1 &&
		(ptr->mod == 7 || ptr->prec == 0))
		ft_memset(str, '0', ptr->w);
	else
		ft_memset(str, ' ', ptr->w);
	ptr->w = (ptr->mod > 2 && ptr->flag[2] == -1) ? 0 : ptr->w;
//	ptr->w = 0;
	return (str);
}

char	*base_string(char *get, t_args *ptr)
{
	char	*str;
	int		i;

	i = 0;
	if (ptr->prec_w > (int)ft_strlen(get))
		get = add_zeros(get, ptr->prec_w, ptr->neg);
	if (ptr->w > (int)ft_strlen(get))
		get = set_width(get, ptr, ptr->neg);
	if (ptr->mod == 2 || (ptr->mod == 6 && ptr->flag[0] == 1))
		get = ft_strjoin("0x", get);
	if (ptr->flag[0] == 1 && ptr->mod == 4 && get[0] != '0')
		get = ft_strjoin("0", get);
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

/*
** get original strlen when opened argument
*/

char	*plus_space(char *get, t_args *ptr)
{
	char *str;

//	printf("ptr->w: %d | get: %zu\n", ptr->w, ft_strlen(get));
	if (ptr->w < (int)ft_strlen(get))
	{
		str = ft_strnew(ft_strlen(get) + 1);
		if (ptr->flag[2] == 1)
			str[0] = '+';
		else if (ptr->flag[4] == 1)
			str[0] = ' ';
		ft_strcpy(str + 1, get);
	}
	else
	{
		if (ptr->flag[2] == 1)
			get[0] = '+';
		else if (ptr->flag[4] == 1)
			get[0] = ' ';
	//	ft_strcpy(str + 1, get);
		str = ft_strdup(get);
	}
//	ptr->flag[2] = 0;
//	ptr->flag[4] = 0;
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

	ptr->w = (ptr->flag[0] == 1 && ptr->mod == 6) ? ptr->w - 2 : ptr->w;
//	printf("!!! get1: %s | ptr->flag[3]: %d | ptr->w: %d | ptr->mod: %d\n", get, ptr->flag[3], ptr->w, ptr->mod);
//	if ((ptr->flag[0] == 1 && ptr->mod == 6) || ptr->mod == 2)
//		ptr->w -= 2;
	if (ptr->flag[0] == 1 && ptr->mod == 4)
	{
		get = ft_strjoin("0", get);
		ptr->flag[0] = 0;
	}
	len = ft_strlen(get) - ptr->neg;
	dif = ptr->w - ft_strlen(get) + ptr->neg;
	str = set_str(ptr);
//	printf("STR: %s | len: %d | ptr->w: %d\n", str, len, ptr->w);
	if (neg == 1 && ptr->flag[1] == -1 && !(ptr->prec))
		str[0] = '-';
	else if (ptr->flag[2] == 1 || ptr->flag[4] == 1)
		str = plus_space(str, ptr);
//	printf("!!str: %s\n", str);
	if (ptr->flag[1] == 1)
		ft_strncpy(str, get + ptr->neg, len);
	else
		ft_strncpy(str + dif, get + ptr->neg, len);
	return (str);
}
