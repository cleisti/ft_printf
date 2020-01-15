/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:28:11 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/14 13:29:00 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_t_args(t_args *ptr)
{
	ptr->str = NULL;
	ptr->modifier = -1;
	ptr->flag = 0;
	ptr->precision = 0;
	ptr->len_mod = 0;
	ptr->len = 0;
	ptr->end_index = 0;
	ptr->next = 0;
}

/*
** Make a check to see if there is anything unnecessary that doesn't belong ?
*/

t_args	*put_to_list(char *trav, int i, t_args *ptr)
{
	int x;

	x = i;
	if (ptr->modifier != -1)
	{
		ptr->next = malloc(sizeof(t_args));
		ptr = ptr->next;
		initialize_t_args(ptr);
	}
	while (!(check_modifier(trav, i, ptr)))
		i++;
	while (x < i)
	{
		if (!(ptr->flag))
			check_flags(trav, i, ptr);
		else if (!(ptr->precision))
			check_precision(trav, i, ptr);
		else if (!(ptr->len_mod))
			check_length_modifier(trav, i, ptr);
		x++;
	}
	return (ptr);
}

/*
** ptr->end_index necessary?
** make func to initialize t_args to NULL
*/

t_args	*arguments_to_list(char *trav, t_args *start)
{
	t_args	*ptr;
	int		i;

	if (!(start = malloc(sizeof(t_args))))
		return (NULL);
	initialize_t_args(start);
	ptr = start;
	i = 0;
	while (trav[i])
	{
		if (trav[i] == '%' && trav[i + 1] == '%')
			i += 2;
		else if (trav[i] == '%')
		{
			ptr = put_to_list(trav, i + 1, ptr);
			ptr->len = i;
		}
		i++;
	}
	if (start->modifier == 0)
		start->str = ft_strdup(trav);
	return (start);
}
