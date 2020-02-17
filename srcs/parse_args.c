/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:23:27 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/13 17:27:56 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

func_ptr g_funcs_arr[13] = {open_c, open_s, open_p, open_di, open_o,
	open_u, open_x, open_f, open_h, open_hh, open_l, open_ll, open_cl};

char	*convert(va_list args, t_args *ptr)
{
	char		*str;

	str = g_funcs_arr[ptr->len_mod](args, ptr);
	return (str);
}

char	*get_argument(va_list args, t_args *ptr)
{
	char	*temp;

	if (ptr->mod < 9)
		temp = g_funcs_arr[ptr->mod](args, ptr);
	else if (ptr->mod == 9)
		temp = open_percentage(ptr);
	else
		temp = ft_strdup("");
	return (temp);
}

int		parse_arguments(char *trav, va_list args, t_args *start)
{
	t_args	*ptr;
	char	*str;
	char	*arg;
	int		len;

	ptr = start;
	str = ft_strnew(start->len);
	ft_strncpy(str, trav, start->len);
//	printf("str: '%s' | len: %d\n", str, start->len);
	len = 0;
	while (start)
	{
//		printf("STR!!:: '%s'\n", str);
		arg = get_argument(args, ptr);
		str = ft_strjoin(str, arg);
		free(arg);
		if (start->null == 1)
			len += 1;
		if (start->next)
			str = get_middle(str, trav, start);
		else
			str = get_end(str, trav, start);
		ptr = start->next;
		free_list(start);
		start = ptr;
	}
	free(start);
	len += print_string(str);
	return (len);
}
