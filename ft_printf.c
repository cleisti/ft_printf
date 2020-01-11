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

int		print_string(char *full_str)
{
	ft_putstr(full_str);
	return (ft_strlen(full_str));
}

char		*check_args(va_list args, char *trav, size_t i)
{
	char	*temp;
	char	*str;
	char	c;

	if (trav[i] == 'c')
	{
		c = va_arg(args, int);
		str = ft_strnew(2);
		str[0] = c;
		str[1] = '\0';
	}
	else
	{
		temp = va_arg(args, char*);
		str = ft_strdup(temp);
		printf("%s\n", str);
	}
	return (str);
}

char		*concenate_strings(char *ptr, char *trav, size_t i)
{
	char	*str;
	char	*temp;
	size_t	x;

	x = i;
	while (trav[x] != '%')
		x--;
	printf("x = %zu\n", x);
	while (trav[x] != 'c')
		x++;
	x++;
	printf("x = %zu, i = %zu\n", x, i);
	str = ft_strnew(ft_strlen(ptr) + (i - x));
	ft_strcpy(str, ptr);
	temp = ft_strsub(trav, x, i - x);
	printf("strlen str = %zu\n", ft_strlen(str));
	printf("temp = %s\n", temp);
	str = ft_strjoin(str, temp);
	printf("str = %s\n", str);
	return (str);
}

char		*parse_str(va_list args, char *trav)
{
	t_args	*start;
	char	*ptr;
	size_t	len;
	size_t	i;
	char	*temp;

	if (!(start = malloc(sizeof(t_args))))
		return (NULL);
	len = 0;
	i = 0;
	while (trav[i])
	{
		if (trav[i] == '%')
		{
			if (!ptr)
				ptr = ft_strndup(trav, i);
			else
			{
				len = ft_strlen(ptr);
				ptr = ft_strjoin(ptr, ft_strsub(trav, len + 1, i - len - 1));
			}
			i++;
			temp = check_args(args, trav, i);
//			printf("temp = %s\n", temp);
			ptr = ft_strjoin(ptr, temp);
			free(temp);
//			printf("%s\n", ptr);
		}
		else if (trav[i + 1] == '\0')
		{
			printf("trav[i] = %c\n", trav[i]);
			ptr = concenate_strings(ptr, trav, i);
			printf("%s\n", ptr);
		}
		i++;
	}
	return (ptr);
}

int		ft_printf(const char *format, ...)
{
	char	*trav;
	va_list	args;

//	printf("%s\n", format);
	if (!(format))
		return (-1);
	trav = (char*)format;
//	printf("%s\n", full_str);
	va_start(args, format);
	trav = parse_str(args, trav);
//	printf("%s\n", full_str);
	va_end(args);
	return (print_string(trav));
}
