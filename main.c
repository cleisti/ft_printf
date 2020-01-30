/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:28:26 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/29 12:42:01 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	char c = 'K';
	char d = 'L';
	char e = 'M';

	printf("ret: %d\n", ft_printf("ft_printf %%c: char c is: %5c, char d is: %-10c lol, char e is: %2c\n", c, d, e));
	printf("ret: %d\n\n", printf("rl_printf %%c: char c is: %5c, char d is: %-10c lol, char e is: %2c\n", c, d, e));

//	printf("ret: %d\n", ft_printf("ft_printf = char d is: %-10c lol\n", d));
//	printf("ret: %d\n", printf("rl_printf = char d is: %-10c lol\n", d));

	char *str = "This is a test";

	printf("ret: %d\n", ft_printf("ft_printf %%s: '%-15.5s'\n", str));
	printf("ret: %d\n\n", printf("rl_printf %%s: '%-15.5s'\n", str));
	printf("ret: %d\n", ft_printf("ft_printf %%s: '%.8s'\n", str));
	printf("ret: %d\n\n", printf("rl_printf %%s: '%.8s'\n", str));

	int		a = 10;
	void	*b = &a;
	
	printf("ret: %d\n", ft_printf("ft_printf %%p: '%-20p'\n", b));
	printf("ret: %d\n\n", printf("rl_printf %%p: '%-20p'\n", b));

	int	nb = -20456;
	
	printf("ret: %d\n", ft_printf("ft_printf %%d: '%020.10d'\n", nb));
	printf("ret: %d\n\n", printf("rl_printf %%d: '%020.10d'\n", nb));

	char h = 'A';
//	int	i = a;

	printf("ret: %d\n", ft_printf("ft_printf %%hhd: '%-.9hhd'\n", h));
	printf("ret: %d\n\n", printf("rl_printf %%hhd: '%-.9hhd'\n", h));


	short s = -3787;

	printf("ret: %d\n", ft_printf("ft_printf %%hd: '%020.7hd'\n", s));
	printf("ret: %d\n\n", printf("rl_printf %%hd: '%020.7hd'\n", s));

	long lo = -819872908;

	printf("ret: %d\n", ft_printf("ft_printf %%ld: '%.16ld'\n", lo));
	printf("ret: %d\n\n", printf("rl_printf %%ld: '%.16ld'\n", lo));

	long long ll = -81987290558;

	printf("ret: %d\n", ft_printf("ft_printf %%lld: '%lld'\n", ll));
	printf("ret: %d\n\n", printf("rl_printf %%lld: '%lld'\n", ll));


	printf("ret: %d\n", ft_printf("ft_printf %%i: %i | %i | %i\n", 12, 012, 0x12));
	printf("ret: %d\n\n", printf("rl_printf %%d: %d | %d | %d\n", 12, 012, 0x12));

	int o = 523;
	
	printf("ret: %d\n", ft_printf("ft_printf %%#.7o: '%#.7o'\n", o));
	printf("ret: %d\n\n", printf("rl_printf %%#.7o: '%#.7o'\n", o));

	int u = -1;
	int up = 4292;
//	unsigned int l = 4294967295;

	printf("ret: %d\n", ft_printf("ft_printf %%u: '%u' | '%010.6u'\n", u, up));
	printf("ret: %d\n\n", printf("rl_printf %%u: '%u' | '%010.6u'\n", u, up));

	int he = -8380;

	printf("ret: %d\n", ft_printf("ft_printf %%X: '%X'\n", he));
	printf("ret: %d\n\n", printf("rl_printf %%X: '%X'\n", he));

	short sh = -2245;

	printf("ret: %d\n", ft_printf("ft_printf %%hX: '%10.7hX'\n", sh));
	printf("ret: %d\n\n", printf("rl_printf %%hX: '%10.7hX'\n", sh));

	int shh = -2245;

	printf("ret: %d\n", ft_printf("ft_printf %%hhX: '%10.7hhX'\n", (char)shh));
	printf("ret: %d\n\n", printf("rl_printf %%hhX: '%10.7hhX'\n", (char)shh));

	long llo = -434522245;

	printf("ret: %d\n", ft_printf("ft_printf %%lX: '%25lX'\n", llo));
	printf("ret: %d\n\n", printf("rl_printf %%lX: '%25lX'\n", llo));

	long long lll = 25445756565245;

	printf("ret: %d\n", ft_printf("ft_printf %%.25llX: '%-40.25llX'\n", lll));
	printf("ret: %d\n\n", printf("rl_printf %%.25llX: '%-40.25llX'\n", lll));

	double f = -64.825;

	printf("ret: %d\n", ft_printf("ft_printf %%f: '%15.8f'\n", f));
	printf("ret: %d\n\n", printf("rl_printf %%f: '%15.8f'\n", f));

	printf("ret: %d\n", ft_printf("ft_printf: t%%esting %%%%%% !%%!!\n"));
	printf("ret: %d\n\n", printf("rl_printf: t%%esting %%%%%% !%%!!\n"));

	char null = '\0';

	printf("ret: %d\n", ft_printf("ft_printf: NULL: '%1c'\n", null));
	printf("ret: %d\n\n", printf("rl_printf: NULL: '%1c'\n", null));
//	unsigned long long u = 140732770003580;
//	printf("here: %s\n", ft_itoa_base(u, 16));
	return (0);
}
