/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:28:26 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/09 13:11:30 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int		main(void)
{
	char c = 'K';
	char d = 'L';
	char *str = "test string";
	
	printf("%d\n", ft_printf("ft_printf = char 1 is: %c, char 2 is: %c lol\n", c, d));
	printf("%d\n", printf("rl_printf = char 1 is: %c, char 2 is: %c lol\n", c, d));

	printf("%d\n", ft_printf("ft_printf = str 1: '%s'\n", str));
	printf("%d\n", printf("rl_printf = str 1: '%s'\n", str));
	return (0);
}
