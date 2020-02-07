/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:15:20 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/07 18:03:03 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_modifier(char *trav, int i, t_args *ptr)
{
	char	*modifiers;
	int		x;

	modifiers = "cspdiouxXf%";
	x = 0;
	while (modifiers[x])
	{
		if (!(validate_modifier(trav, i, ptr)))
			return (1);
		if (modifiers[x] == trav[i])
		{
			ptr->start = i - 1;
			(x > 3) ? x -= 1 : 0;
			ptr->mod = x;
			ptr->end = i + 1;
			(trav[i] == 'X') ? ptr->mod -= 1 : 0;
			(trav[i] == 'X') ? ptr->x = 1 : 0;
			(trav[i] == 'f') ? ptr->mod -= 1 : 0;
			return (1);
		}
		x++;
	}
	return (0);
}

int		check_conversion(char *trav, int i, t_args *ptr)
{
	if ((trav[i] == 'h' && trav[i + 1] == 'h') ||
		(trav[i] == 'l' && trav[i + 1] == 'l'))
	{
		if (trav[i + 1] == 'h')
			ptr->len_mod = 9;
		else
			ptr->len_mod = 11;
		return (i + 2);
	}
	else if (trav[i] == 'h' || trav[i] == 'l')
	{
		if (trav[i] == 'h')
			ptr->len_mod = 8;
		else
			ptr->len_mod = 10;
		return (i + 1);
	}
	else if (ptr->mod == 7 && trav[i] == 'L')
		ptr->len_mod = 12;
	return (i);
}

int		check_precision(char *trav, int i, t_args *ptr)
{
	if (trav[i] == '.')
	{
		ptr->prec = 1;
		ptr->prec_w = ft_atoi(&trav[i + 1]);
		i += 1;
		while (ft_isdigit(trav[i]))
			i++;
	}
	if (ptr->mod == 7 && ptr->prec_w == -1)
		ptr->prec_w = 6;
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
			if (ptr->flag[x] == -1)
			{
				ptr->flag[x] = 1;
				i += 1;
				return (check_flags(trav, i, ptr));
			}
		}
		x++;
	}
	if (ptr->flag[1] == 1)
		ptr->flag[3] = -1;
	if (ptr->flag[2] == 1)
		ptr->flag[4] = -1;
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
