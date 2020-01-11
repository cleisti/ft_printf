/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 22:19:25 by marvin            #+#    #+#             */
/*   Updated: 2020/01/10 14:49:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_validity(char c, int str_base)
{
	char	*l_valids = "0123456789abcdef";
	char	*u_valids = "0123456789ABCDEF";

	while (str_base)
	{
		if (c == l_valids[str_base] || c == u_valids[str_base])
			return (1);
		str_base--;
	}
	return (0);
}

int		convert_base(char c, int str_base)
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
	while (check_validity(str[i], str_base))
	{
		res = res * str_base + convert_base(str[i], str_base);
		i++;
	}
	return (neg * res);
}
