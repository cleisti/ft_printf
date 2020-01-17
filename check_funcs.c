/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:15:20 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/17 17:53:51 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** What happens if modifier not found ?
*/

int		check_modifier(char *trav, int i, t_args *ptr)
{
	char	*modifiers;
	int		x;

	modifiers = "cspdiouxXf";
	x = 0;
	while (modifiers[x])
	{
		if (modifiers[x] == trav[i])
		{
			ptr->start = i - 1;
			ptr->mod = x;
			ptr->end = i + 1;
			return (1);
		}
		x++;
	}
	return (0);
}

/*
** Find better solution ? Char *str instead of integer ?
** h = 1
** hh = 2;
** l = 3;
** ll = 4;
*/

int		check_length_modifier(char *trav, int i, t_args *ptr)
{
	int		n;
	
	n = 0;
	if (trav[i + 1] == 'h' || trav[i + 1] == 'l')
	{
		if (trav[i + 1] == 'h')
			ptr->len_mod = 2;
		else
			ptr->len_mod = 4;
		n = 1;
	}
	else if (trav[i] == 'h' || trav[i] == 'l')
	{
		if (trav[i] == 'h')
			ptr->len_mod = 1;
		else
			ptr->len_mod = 3;
		n = 2;
	}
	return (i + n);
}

/*
** Add loop to get bigger numbers (atoi! ahoi!)
*/

int		check_precision(char *trav, int i, t_args *ptr)
{
//	int	nl;

//	nl = 0;	
	if (trav[i] == '.')
	{
		ptr->prec = 1;
		ptr->len_mod = ft_atoi(&trav[i + 1]);
		i += 1;
		while (ft_isdigit(trav[i]))
			i++;
	}
	return (i);
}

/*
** # = 0, 0 = 1, - = 2, + = 3, ' ' = 4
*/

/*
int		check_flags(char *trav, int i, t_args *ptr)
{
	char	*flags_arr;
	int		x;
	int		ri;

	flags_arr = "#-+0 ";
	x = 0;
	while (flags_arr[x])
	{
		if (trav[i] == flags_arr[x])
		{
			printf("trav[i] = %c\n", trav[i]);
			ptr->flag[x] = 1;
			ri = 1 + check_width(trav, i + 1, ptr);
			printf("check\n");
			return (ri);
		}
		x++;
	}
	return (0);
} */

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
