/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:23:27 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/15 10:27:56 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

func_ptr g_funcs_arr[1] = { (open_c) };

char	*get_argument(t_args *ptr, va_list args)
{
	char		*str;

	str = g_funcs_arr[ptr->modifier](args);
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
		temp = get_argument(start, args);
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
