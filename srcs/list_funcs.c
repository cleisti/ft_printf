/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:28:11 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/29 12:56:34 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_list(t_args *ptr)
{
	free(ptr);
	ptr = NULL;
}

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
	ptr->prec_w = -1;
	ptr->len_mod = -1;
	ptr->neg = 0;
	ptr->x = 0;
	ptr->len = 0;
	ptr->null = 0;
	ptr->start = 0;
	ptr->end = 0;
	ptr->next = 0;
}

t_args	*put_to_list(char *trav, int i, t_args *ptr)
{
	static int x;

	x = i;
	if (ptr->mod != -1)
	{
		if (!(ptr->next = malloc(sizeof(t_args))))
			return (NULL);
		ptr = ptr->next;
		initialize_t_args(ptr);
	}
	while (!(check_modifier(trav, i, ptr)))
		i++;
	while (x <= i)
	{
		x = check_flags(trav, x, ptr);
		x = check_width(trav, x, ptr);
		x = check_precision(trav, x, ptr);
		x = check_conversion(trav, x, ptr);
		x++;
	}
	return (ptr);
}

t_args	*arguments_to_list(char *trav, t_args *start)
{
	t_args	*ptr;
	int		i;

	initialize_t_args(start);
	ptr = start;
	i = 0;
	while (trav[i])
	{
		if (trav[i] == '%' && trav[i + 1] == '%')
			i++;
		else if (trav[i] == '%' && trav[i + 1] != '%')
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
