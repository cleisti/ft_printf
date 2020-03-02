/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:25:40 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/24 17:51:09 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_end(char *trav, t_args *ptr)
{
	char	*str;
	int		len;

	len = ft_strlen(trav) - ptr->end;
	str = ft_strndup(trav + ptr->end, len);
	return (print_string(str));
}

int		print_middle(char *trav, t_args *ptr)
{
	char	*str;
	int		i;
	int		len;

	i = ptr->end;
	while (trav[i] != '%')
		i++;
	len = i - ptr->end;
	str = ft_strndup(trav + ptr->end, len);
	return (print_string(str));
}

int		validate_modifier(char *trav, int i)
{
	char	*valids;
	int		x;

	valids = "lhjtzqL. #0+-*123456789";
	x = 0;
	while (valids[x])
	{
		if (valids[x] == trav[i])
			return (1);
		x++;
	}
	return (0);
}

char	*zero_x(char *get, int mod)
{
	char	*str;

	if (mod == 2 || mod == 6)
		str = ft_strjoin("0x", get);
	else
		str = ft_strjoin("0", get);
	free(get);
	return (str);
}
