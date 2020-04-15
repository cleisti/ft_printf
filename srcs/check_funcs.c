/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:15:20 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/24 17:11:15 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_modifier(char *trav, int i, t_args *ptr)
{
	char	*modifiers;
	int		x;

	modifiers = "cspdiouxXf%";
	x = 0;
	while (validate_modifier(trav, i))
		i++;
	while (modifiers[x])
	{
		if (modifiers[x] == trav[i])
		{
			ptr->start = i - 1;
			(x > 3) ? x -= 1 : 0;
			ptr->mod = x;
			ptr->end = i + 1;
			(trav[i] == 'X') ? ptr->mod -= 1 : 0;
			(trav[i] == 'X') ? ptr->x = 1 : 0;
			(trav[i] == 'f') ? ptr->mod -= 1 : 0;
			return (i);
		}
		x++;
	}
	ptr->mod = 10;
	ptr->end = i;
	return (i);
}

int		check_conversion(char *trav, int i, t_args *ptr)
{
	if ((trav[i] == 'h' && trav[i + 1] == 'h') ||
		(trav[i] == 'l' && trav[i + 1] == 'l'))
	{
		if (trav[i + 1] == 'h')
			ptr->len_mod = 1;
		else
			ptr->len_mod = 2;
		return (i + 2);
	}
	else if (trav[i] == 'h' || trav[i] == 'l')
	{
		if (trav[i] == 'h')
			ptr->len_mod = 0;
		else
			ptr->len_mod = 3;
		return (i + 1);
	}
	else if (ptr->mod == 7 && trav[i] == 'L')
		ptr->len_mod = 4;
	return (i);
}

int		check_precision(char *trav, int i, t_args *ptr)
{
	if (ft_isalpha(trav[i]))
		i = check_conversion(trav, i, ptr);
	if (trav[i] == '.')
	{
		ptr->prec = 1;
		i += 1;
		ptr->prec_w = ft_atoi(&trav[i]);
		while (ft_isdigit(trav[i]))
			i++;
	}
	return (i);
}

int		check_flags(char *trav, int i, t_args *ptr)
{
	char	*flags_arr;
	int		x;

	flags_arr = "#-+0 ";
	x = 0;
	while (flags_arr[x])
	{
		if (trav[i] == flags_arr[x])
		{
			if (ptr->flag[x] == 0)
			{
				ptr->flag[x] = 1;
				i++;
				if (trav[i] != '0')
					i = check_width(trav, i, ptr);
				return (check_flags(trav, i, ptr));
			}
		}
		else if (trav[i] != '0' && ft_isdigit(trav[i]))
			i = check_width(trav, i, ptr);
		x++;
	}
	return (i);
}

int		check_width(char *trav, int i, t_args *ptr)
{
	if (ptr->w == 0 && ft_isdigit(trav[i]))
	{
		ptr->w = ft_atoi(&trav[i]);
		while (ft_isdigit(trav[i]))
			i++;
	}
	return (i);
}
