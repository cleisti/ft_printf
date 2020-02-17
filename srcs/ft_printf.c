/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:53:15 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/13 15:06:58 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_string(char *str)
{
	int len;

	len = ft_strlen(str);
	if (str != '\0')
		ft_putstr(str);
	free(str);
	return (len);
}

int		parse_format_str(va_list args, char *trav)
{
	t_args		*start;
	int			len;

	if (!(start = malloc(sizeof(t_args))))
		return (0);
	start = arguments_to_list(trav, start);
	if (start->str)
		len = print_string(ft_strdup(trav));
	else
		len = parse_arguments(trav, args, start);
	return (len);
}

int		ft_printf(const char *format, ...)
{
	char	*trav;
	int		ret;
	va_list	args;

	if (!(format))
		return (-1);
	trav = (char*)format;
	va_start(args, format);
	ret = parse_format_str(args, trav);
	va_end(args);
	return (ret);
}
