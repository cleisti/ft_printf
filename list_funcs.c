/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:28:11 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/17 17:46:16 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_t_args(t_args *ptr)
{
	ptr->mod = -1;
	ptr->flag[0] = -1;
	ptr->flag[1] = -1;
	ptr->flag[2] = -1;
	ptr->flag[3] = -1;
	ptr->flag[4] = -1;
	ptr->w = 0;
	ptr->prec = 0;
	ptr->len_mod = 0;
	ptr->len = 0;
	ptr->start = 0;
	ptr->end = 0;
	ptr->next = 0;
}

/*
** Make a check to see if there is anything unnecessary that doesn't belong ?
** printf("ptr->flag: %d | ptr->w: %d | ptr->prec: %d | ptr->len_mod: %d\n", ptr->flag, ptr->w, ptr->prec, ptr->len_mod);
*/

t_args	*put_to_list(char *trav, int i, t_args *ptr)
{
	static int x;

	x = i;
	if (ptr->mod != -1)
	{
		ptr->next = malloc(sizeof(t_args));
		ptr = ptr->next;
		initialize_t_args(ptr);
	}
	while (!(check_modifier(trav, i, ptr)))
		i++;
	while (x < i)
	{
//		printf("x = %d\n", x);
		x = check_flags(trav, x, ptr);
//		printf("x2 = %d\n", x);
		x = check_width(trav, x, ptr);
//		printf("x3 = %d\n", x);
		x = check_precision(trav, x, ptr);
//		printf("x4 = %d\n", x);
		x = check_length_modifier(trav, x, ptr);
//		printf("x5 = %d\n", x);
		x++;
	}
//	printf("ptr->flags: %d|%d|%d|%d|%d | ptr->w: %d | ptr->prec: %d | ptr->len_mod: %d\n", ptr->flag[0], ptr->flag[1],ptr->flag[2],ptr->flag[3],ptr->flag[4],ptr->w, ptr->prec, ptr->len_mod);
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
	if (start->mod == -1)
		start = NULL;
	return (start);
}
