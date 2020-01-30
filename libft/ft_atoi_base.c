/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 22:19:25 by marvin            #+#    #+#             */
/*   Updated: 2020/01/30 15:50:30 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		check_validity(char c, int str_base)
{
	char	*lc_vals;
	char	*uc_vals;

	lc_vals = "0123456789abcdef";
	uc_vals = "0123456789ABCDEF";
	while (str_base >= 0)
	{
		if (c == lc_vals[str_base] || c == uc_vals[str_base])
			return (1);
		str_base--;
	}
	return (0);
}

int				convert_base(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return ((c - 'a') + 10);
	return ((c - 'A') + 10);
}

int				ft_atoi_base(const char *str, int str_base)
{
	unsigned long long	res;
	int					neg;
	int					i;

	res = 0;
	neg = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	(str[i] == '-' || str[i] == '+') ? i++ : 0;
	if (str[i - 1] == '-')
		neg = -1;
	while (str[i])
	{
		if (check_validity(str[i], str_base))
			res = res * str_base + convert_base(str[i]);
		else
			return (0);
		i++;
	}
	return (neg * res);
}
