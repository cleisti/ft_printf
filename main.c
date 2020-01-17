/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:28:26 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/17 17:50:43 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	char c = 'K';
	char d = 'L';
	char e = 'M';

	printf("ret: %d\n", ft_printf("ft_printf = char c is: %5c, char d is: %-10c lol, char e is: %2c\n", c, d, e));
	printf("ret: %d\n\n", printf("rl_printf = char c is: %5c, char d is: %-10c lol, char e is: %2c\n", c, d, e));

//	printf("ret: %d\n", ft_printf("ft_printf = char d is: %-10c lol\n", d));
//	printf("ret: %d\n", printf("rl_printf = char d is: %-10c lol\n", d));

	char *str = "This is a test";

	printf("ret: %d\n", ft_printf("ft_printf = '%-15.5s'\n", str));
	printf("ret: %d\n\n", printf("rl_printf = '%-15.5s'\n", str));
	printf("ret: %d\n", ft_printf("ft_printf = '%.8s'\n", str));
	printf("ret: %d\n\n", printf("rl_printf = '%.8s'\n", str));

	int		a = 10;
	void	*b = &a;
	
	printf("ret: %d\n", ft_printf("ft_printf = '%-20p'\n", b));
	printf("ret: %d\n\n", printf("rl_printf = '%-20p'\n", b));

	int		nb = 21;
	
	printf("ret: %d\n", ft_printf("ft_printf = '%+5d'\n", nb));
	printf("ret: %d\n", printf("rl_printf = '% d'\n", nb));
//	while (1);
//	unsigned long long u = 140732770003580;
//	printf("here: %s\n", ft_itoa_base(u, 16));
	return (0);
}
