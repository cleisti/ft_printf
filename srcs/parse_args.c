/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:23:27 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/25 10:57:53 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_func_ptr	g_funcs_arr[8] = {open_c, open_s, open_p, open_di, open_o,
	open_u, open_x, open_f};

t_len_mod	g_len_mods[4] = {open_h, open_hh, open_ll, open_l};

char		*convert(va_list args, t_args *ptr)
{
	return (g_len_mods[ptr->len_mod](args, ptr));
}

int			print_argument(va_list args, t_args *ptr)
{
	if (ptr->mod < 9)
		return (g_funcs_arr[ptr->mod](args, ptr));
	else if (ptr->mod == 9)
		return (open_percentage(ptr));
	return (0);
}

int			parse_args(char *trav, va_list args, t_args *start)
{
	t_args	*ptr;
	int		len;

	ptr = start;
	len = start->len;
	write(1, trav, len);
	while (start)
	{
		len += print_argument(args, ptr);
		if (start->next)
			len += print_middle(trav, start);
		else
			len += print_end(trav, start);
		ptr = start->next;
		free_list(start);
		start = ptr;
	}
	free(start);
	return (len);
}
