/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:28:11 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/04 13:06:02 by cleisti          ###   ########.fr       */
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
	ptr->len = 1;
	ptr->null = 0;
	ptr->rm_p = 0;
	ptr->str = 0;
	ptr->start = 0;
	ptr->end = 0;
	ptr->next = 0;
}

int		validate_modifier(char *trav, int i, t_args *ptr)
{
	char	*valids;
	int		x;

	valids = "cspdiouxXf%lhL. #0+-123456789";
	x = 0;
	while (valids[x])
	{
		if (valids[x] == trav[i])
			return (1);
		else if (x > 27 || trav[i] == '\0')
		{
			ptr->mod = 10;
			ptr->end = i;
			return (2);
		}
		x++;
	}
	return (0);
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
	while(trav[i] != '\0' && !(check_modifier(trav, i, ptr)))
		i++;
	while (ptr->mod != -1 && x <= i)
	{
		x = check_flags(trav, x, ptr);
		x = check_width(trav, x, ptr);
		x = check_precision(trav, x, ptr);
		x = check_conversion(trav, x, ptr);
		x++;
	}
	if (ptr->mod == -1)
	{
		ptr->mod = 10;
		ptr->end = i;
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
		if (trav[i] == '%')
		{
			ptr = put_to_list(trav, i + 1, ptr);
			ptr->len = i;
			i = ptr->end - 1;
		}
		i++;
	}
	if (start->mod == -1)
		start->str = 1;
	return (start);
}
