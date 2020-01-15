/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 22:54:05 by marvin            #+#    #+#             */
/*   Updated: 2020/01/07 16:32:31 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_string(char *str)
{
	int num;

	num = ft_strlen(str);
	ft_putstr(str);
	return (num);
}

char	*parse_format_str(va_list args, char *trav)
{
	t_args	*start;
	char	*full_str;
	
	start = malloc(sizeof(t_args));
	start = arguments_to_list(trav, start);
	full_str = parse_arguments(trav, args, start);
	return (full_str);
}

int		ft_printf(const char *format, ...)
{
	char	*trav;
	char	*full_str;
	va_list	args;

	if (!(format))
		return (-1);
	trav = (char*)format;
	va_start(args, format);
	full_str = parse_format_str(args, trav);
	va_end(args);
	return (print_string(full_str));
}
