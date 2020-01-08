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

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include "../libft/libft.h"
#include <stdio.h>

int		print_string(char *full_str)
{
	ft_putstr(full_str);
	return (ft_strlen(full_str));
}

char		*check_args(va_list args, char **full_str)
{
	char	*str;
	char	c;
//	int		i;

	if (**full_str + 1 == 'c')
		c = va_arg(args, int);
//	ft_putchar(i);
//	c = i;
	ft_putchar(c);
//	ft_strncat(*full_str, &c, 1);
	return (str);
}

char		*parse_str(va_list args, char *full_str)
{
	t_args	*start;
	char	*ptr;
	int		len;

	if (!(start = malloc(sizeof(t_args))))
		return (NULL);
	len = 0;
	while (full_str[len])
	{
		if (full_str[len] == '%')
		{
			if (!(ptr = (char*)malloc(sizeof(char) * len)))
				return (NULL);
//			printf("%s\n", full_str);
			ptr = ft_strndup(full_str, len);
//			printf("%s\n", ptr);
			ft_strjoin(full_str, check_args(args, &full_str));
		}
		len++;
	}
	return (ptr);
}

int		ft_printf(const char *format, ...)
{
	char	*traverse;
	va_list	args;

//	printf("%s\n", format);
	if (!(format))
		return (-1);
	traverse = (char*)format;
//	printf("%s\n", full_str);
	va_start(args, format);
	traverse = parse_str(args, traverse);
//	printf("%s\n", full_str);
	va_end(args);
	return (print_string(traverse));
}
