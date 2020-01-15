/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_funcs1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:16 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/15 11:13:58 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*open_c(va_list args)
{
	char	*str;
	char	c;

	c = va_arg(args, int);
	str = ft_strnew(2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*open_s(va_list args)
{
	char	*str;
	
	str = va_arg(args, char *);
	return (str);
}

