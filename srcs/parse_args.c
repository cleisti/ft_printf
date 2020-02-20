/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:23:27 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/19 12:04:02 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

func_ptr g_funcs_arr[8] = {open_c, open_s, open_p, open_di, open_o,
	open_u, open_x, open_f};

len_mod g_len_mods[5] = {open_h, open_hh, open_l, open_ll, open_cl};

char	*convert(va_list args, t_args *ptr)
{
//	char		*str;
	return (g_len_mods[ptr->len_mod](args, ptr));
}

int		get_argument(va_list args, t_args *ptr)
{
//	char	*temp;
//	int		i;

//	i = ft_strlen(str);
	if (ptr->mod < 9)
		return (g_funcs_arr[ptr->mod](args, ptr));
	else if (ptr->mod == 9)
		return (open_percentage(ptr));
	else
	{
		ft_putstrui("\0", 1);
		return (1);
	}
//	str = ft_strjoin(str, temp);
//	if (ptr->null != 0)
//		ptr->null += i;
//	free(temp);
//	return (str);
}

int		parse_arguments(char *trav, va_list args, t_args *start)
{
	t_args	*ptr;
	int		len;

	ptr = start;
	ft_putstrui(trav, start->len);
//	str = ft_strnew(start->len);
//	ft_strncpy(str, trav, start->len);
//	printf("str: '%s' | len: %d\n", str, start->len);
	len = start->len;
	while (start)
	{
//		printf("STR!!:: '%s'\n", str);
		len += get_argument(args, ptr);
//		if (start->null != -1)
//			len += 1;
		if (start->next)
			len += get_middle(trav, start);
		else
			len += get_end(trav, start);
		ptr = start->next;
		free_list(start);
		start = ptr;
	}
	free(start);
//	len += print_string(str, ptr);
	return (len);
}
