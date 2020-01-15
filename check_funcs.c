/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:15:20 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/15 11:07:08 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** What happens if modifier not found ?
*/

int		check_modifier(char *trav, int i, t_args *ptr)
{
	char *modifiers;
	int x;

	modifiers = "cdiouxXspf";
	x = 0;
	while (modifiers[x])
	{
		if (modifiers[x] == trav[i])
		{
			ptr->modifier = x;
			ptr->end_index = i + 1;
			return (1);
		}
		x++;
	}
	return (0);
}

/*
** Find better solution ? Char *str instead of integer ?
*/

void	check_length_modifier(char *trav, int i, t_args *ptr)
{
	if (trav[i] == 'h')
	{
		if (trav[i + 1] == 'h')
			ptr->len_mod = 2;
		else
			ptr->len_mod = 1;
	}
	if (trav[i] == 'l')
	{
		if (trav[i + 1] == 'l')
			ptr->len_mod = 4;
		else
			ptr->len_mod = 3;
	}
}

/*
** Add loop to get bigger numbers
*/

void	check_precision(char *trav, int i, t_args *ptr)
{
	if (trav[i] == '.')
		ptr->precision = trav[i + 1];
}

void	check_flags(char *trav, int i, t_args *ptr)
{
	char *flags_arr;
	int x;

	flags_arr = "#0-+ ";
	x = 0;
	while (flags_arr[x])
	{
		if (trav[i] == flags_arr[x])
			ptr->flag = x;
		x++;
	}
}
