/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:28:26 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/14 12:50:06 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	char c = 'K';
	char d = 'L';
//	int len;
	
/*	ft_putendl("ft_printf:");
	len = ft_printf("char c = %c", c);
	ft_putnbr(len);
	ft_putchar('\n');

	ft_putendl("printf:");
	len = printf("char c = %c", c);
	ft_putnbr(len);
	ft_putchar('\n'); */
	printf("%d\n", ft_printf("ft_printf = char 1 is: %c, char 2 is: %c lol", c, d));
	printf("%d\n", printf("rl_printf = char 1 is: %c, char 2 is: %c lol", c, d));

//	printf("%d\n", ft_printf("ft_printf = str 1: '%s'\n", str));
//	printf("%d\n", printf("rl_printf = str 1: '%s'\n", str));
	return (0);
}
