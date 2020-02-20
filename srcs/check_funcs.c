/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:15:20 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/19 11:59:22 by cleisti          ###   ########.fr       */
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
			ptr->len_mod = 3;
		return (i + 2);
	}
	else if (trav[i] == 'h' || trav[i] == 'l')
	{
		if (trav[i] == 'h')
			ptr->len_mod = 0;
		else
			ptr->len_mod = 2;
		return (i + 1);
	}
	else if (ptr->mod == 7 && trav[i] == 'L')
		ptr->len_mod = 4;
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
//	if (ptr->mod == 7 && ptr->prec_w == -1)
//		ptr->prec_w = 6;
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
//	printf("FLAG3: %d\n", ptr->flag[3]);
	if (ptr->flag[1] == 1 && ptr->flag[3] == 1)
		ptr->flag[3] = 0;
	if (ptr->flag[2] == 1 && ptr->flag[4] == 1)
		ptr->flag[4] = 0;
//	printf("ptr->flag[2]: %d\n", ptr->flag[2]);
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
