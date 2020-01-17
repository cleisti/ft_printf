/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:23:27 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/17 17:52:23 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

func_ptr g_funcs_arr[9] = {open_c, open_s, open_p, open_d};

char	*get_argument(va_list args, t_args *ptr)
{
	char		*str;

	str = g_funcs_arr[ptr->mod](args, ptr);
	return (str);
}

char	*parse_arguments(char *trav, va_list args, t_args *start)
{
	t_args *ptr;
	char *str;
	char *temp;

	ptr = start;
	str = ft_strnew(start->len);
	ft_strncpy(str, trav, start->len);
	while (start)
	{
		temp = get_argument(args, ptr);
		str = ft_strjoin(str, temp);
		if (start->next)
			str = get_middle(str, trav, start);
		free(temp);
		if (start->next == NULL)
			str = get_end(str, trav, start);
		ptr = start->next;
		free(start);
		start = ptr;
	}
	free(start);
	str = check_for_percentage_signs(str);
	return (str);
}
