/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:28:26 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/10 13:44:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
