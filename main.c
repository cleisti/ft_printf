/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:28:26 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/18 17:07:09 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
/*	char c = 'K';
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

	long oo = 72940275853;

	printf("ret: %d\n", ft_printf("ft_printf %%#.7lo: '%#.7lo'\n", oo));
	printf("ret: %d\n\n", printf("rl_printf %%#.7lo: '%#.7lo'\n", oo));

	unsigned long long ooo = 61987334538990;

	printf("ret: %d\n", ft_printf("ft_printf %%#25llo: '%#25llo'\n", ooo));
	printf("ret: %d\n\n", printf("rl_printf %%#25llo: '%#25llo'\n", ooo));

	int u = -1;
	int up = 4292;
//	unsigned int l = 4294967295;

	printf("ret: %d\n", ft_printf("ft_printf %%010.6u: '%u' | '%010.6u'\n", u, up));
	printf("ret: %d\n\n", printf("rl_printf %%010.6u: '%u' | '%010.6u'\n", u, up));

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


// THIS NEEDS TESTING: gives random answers
	printf("ret: %d\n", ft_printf("ft_printf: NULL: '%llu'\n", -1ll));
	printf("ret: %d\n\n", printf("rl_printf: NULL: '%llu'\n", -1ll));

//	printf("uitoa: %s | printf: %o\n", ft_uitoa_base(-1ll, 16), -1);

	printf("%Lf\n", -56.2012685l);
	ft_printf("%Lf\n", -56.2012685l); 

//	printf("%");
	printf("'%#.x %#.0x'\n", 0, 0);
	ft_printf("'%#.x %#.0x'\n", 0, 0);
	ft_printf("%5%\n");

	ft_printf("% hZ%\n");
	ft_printf("% Z%s\n\n", "test");
//	printf("% Z%s\n\n", "test");
	
	ft_printf("%jx\n", 4294967295);
	printf("%jx\n\n", 4294967295);

	ft_printf("%jx\n", 4294967296);
	printf("%jx\n\n", 4294967296);

	ft_printf("'%#x'\n", 0);
	printf("'%#x'\n\n", 0);

	ft_printf("'%#08x'\n", 42);
	printf("'%#08x'\n\n", 42);

	ft_printf("@moulitest: '%#.x %#.0x'\n", 0, 0);
	printf("@moulitest: '%#.x %#.0x'\n\n", 0, 0);

	ft_printf("@moulitest: '%.x %.0x'\n", 0, 0);
	printf("@moulitest: '%.x %.0x'\n\n", 0, 0);

	ft_printf("@moulitest: '%5.x %5.0x'\n", 0, 0);
	printf("@moulitest: '%5.x %5.0x'\n\n", 0, 0);

	printf("ret: %d\n", ft_printf("'%2c'\n", '\0'));
	printf("ret: %d\n\n", printf("'%2c'\n", '\0'));

	ft_printf("@moulitest: '%c'\n", 0);
	printf("@moulitest: '%c'\n\n", 0);

	ft_printf("'%2c'\n", 0);
	printf("'%2c'\n\n", 0);

	printf("ret: %d\n", ft_printf("null %c and text\n", 0));
	printf("ret: %d\n\n", printf("null %c and text\n", 0));

	printf("ret: %d\n", ft_printf("'% c'", 0));
	printf("ret: %d\n\n", printf("'%c'", 0));

	printf("ret: %d\n", ft_printf("@moulitest: '%.o %.0o'\n", 0, 0));
	printf("ret: %d\n\n", printf("@moulitest: '%.o %.0o'\n", 0, 0));

	printf("ret: %d\n", ft_printf("@moulitest: '%5.o %5.0o'\n", 0, 0));
	printf("ret: %d\n\n", printf("@moulitest: '%5.o %5.0o'\n", 0, 0));

	printf("ret: %d\n", ft_printf("@moulitest: '%#.o %#.0o'\n", 0, 0));
	printf("ret: %d\n\n", printf("@moulitest: '%#.o %#.0o'\n", 0, 0));

	printf("ret: %d\n", ft_printf("@moulitest: '%#.o %#.0o'\n", 0, 0));
	printf("ret: %d\n\n", printf("@moulitest: '%#.o %#.0o'\n", 0, 0));

	printf("ret: %d\n", ft_printf("'%0+5d'\n", 42));
	printf("ret: %d\n\n", printf("'%0+5d'\n", 42));

	printf("ret: %d\n", ft_printf("'%5d'\n", -42));
	printf("ret: %d\n\n", printf("'%5d'\n", -42));

	printf("ret: %d\n", ft_printf("'%05d'\n", -42));
	printf("ret: %d\n\n", printf("'%05d'\n", -42));

	printf("ret: %d\n", ft_printf("'%0+5d'\n", -42));
	printf("ret: %d\n\n", printf("'%0+5d'\n", -42));

	printf("ret: %d\n", ft_printf("@moulitest: '%.d %.0d'\n", 0, 0));
	printf("ret: %d\n\n", printf("@moulitest: '%.d %.0d'\n", 0, 0));

	printf("ret: %d\n", ft_printf("@moulitest: '%5.d %5.0d'\n", 0, 0));
	printf("ret: %d\n\n", printf("@moulitest: '%5.d %5.0d'\n", 0, 0));

//	ft_printf("%+i\n", 5);
//	printf("%+i\n", 5);
//	-------------------------------------
//	ft_printf("'%x'\n", 0);
	printf("rl %%c: '%c'\n", 'a');
	ft_printf("ft %%c: '%c'\n", 'a');
	printf("rl %%5c: '%5c'\n", 'a');
	ft_printf("ft %%5c: '%5c'\n", 'a');
	printf("rl %%-5c: '%-5c'\n", 'a');
	ft_printf("ft %%-5c: '%-5c'\n\n", 'a');

	char *str = "Hello World";
	char c = 'b';

 	printf("'%-15s' | '%15c'\n", str, c);
	ft_printf("'%-15s' | '%15c'\n", str, c);
 	printf("'%-s' | '%15c'\n", str, c);
	ft_printf("'%-s' | '%15c'\n", str, c);
 	printf("'%15.s'\n", str);
	ft_printf("'%15.s'\n", str);
 	printf("'%15.0s'\n", str);
	ft_printf("'%15.0s'\n", str);
 	printf("'%-15.0006s'\n", str);
	ft_printf("'%-15.0006s'\n", str);
 	printf("'%.6s'\n", str);
	ft_printf("'%.6s'\n", str);
	printf("'hello, %s.'\n", NULL);
	ft_printf("'hello, %s.'\n\n", NULL);
	printf("%%.3s str: '%.3s'\n", str);
	ft_printf("%%.3s str: '%.3s'\n", str);
	printf("%%.s str: '%.s'\n", str);
	ft_printf("%%.s str: '%.s'\n", str);
	printf("%%.s str: '%.0s'\n", str);
	ft_printf("%%.s str: '%.0s'\n", str);
	printf("%%.3s 'holla' %%.2s 'bitch': '%.3s%.2s'\n", "holla", "bitch"); //holbi
	ft_printf("%%.3s 'holla' %%.2s 'bitch': '%.3s%.2s'\n", "holla", "bitch"); //holbi
	printf("%%.2s 'hello' %%.7 'world': '%.2s%.7s'\n", "hello", "world"); //heworld
	ft_printf("%%.2s 'hello' %%.7 'world': '%.2s%.7s'\n", "hello", "world"); //heworld
	printf("%%3.3s%%7.7s 'hello' 'world': %3.3s%7.7s\n", "hello", "world");
	ft_printf("%%3.3s%%7.7s 'hello' 'world': %3.3s%7.7s\n\n", "hello", "world");
	
	

	printf("%%p null: '%p'\n", NULL);
	ft_printf("%%p null: '%p'\n", NULL);
	printf("%%.p null: '%.p'\n", NULL);
	ft_printf("%%.p null: '%.p'\n", NULL);
	printf("%%5p null: '%5.p'\n", NULL);
	ft_printf("%%5p null: '%5.p'\n", NULL);
	printf("%%6p null: '%6p'\n", NULL);
	ft_printf("%%6p null: '%6p'\n", NULL);
	printf("%%p null: '%p'\n", NULL);
	ft_printf("%%p null: '%p'\n", NULL);	
	printf("%%p 0: '%p'\n", NULL);
	ft_printf("%%p 0: '%p'\n", NULL);
	printf("%%p 0: '%p'\n", NULL);
	ft_printf("%%p 0: '%p'\n", NULL);
	printf("%%.p 0: '%.p'\n", NULL);
	ft_printf("%%.p 0: '%.p'\n", NULL);
	printf("%%5.p 0: '%5.p'\n", NULL);
	ft_printf("%%5.p 0: '%5.p'\n", NULL);
	printf("%%6p 0: '%6p'\n", NULL);
	ft_printf("%%6p 0: '%6p'\n", NULL);
	printf("%%6p 0: '%6p'\n", NULL);
	ft_printf("%%6p 0: '%6p'\n", NULL);
	printf("%%p str: '%p'\n", str);
	ft_printf("%%p str: '%p'\n", str);
	printf("%%p str: '%p'\n", str);
	ft_printf("%%p str: '%p'\n", str);
	printf("%%.p str: '%.p'\n", str);
	ft_printf("%%.p str: '%.p'\n", str);
	printf("%%5.p str: '%5.p'\n", str);
	ft_printf("%%5.p str: '%5.p'\n", str);
	printf("%%6p str: '%6p'\n", str);
	ft_printf("%%6p str: '%6p'\n", str);
	printf("%%12p str: '%12p'\n", str);
	ft_printf("%%12p str: '%12p'\n", str);
	printf("%%20p str: '%20p'\n", str);
	ft_printf("%%20p str: '%20p'\n", str);
	printf("%%20p str: '%20p'\n", str);
	ft_printf("%%20p str: '%20p'\n", str);
	printf("%%20p str: '%20p'\n", str);
	ft_printf("%%20p str: '%20p'\n", str);
	printf("%%20p str: '%20p'\n", str);
	ft_printf("%%20p str: '%20p'\n", str);
	printf("%%-20p str: '%-20p'\n", str);
	ft_printf("%%-20p str: '%-20p'\n", str);
	printf("%%-20p str: '%-20p'\n", str);
	ft_printf("%%-20p str: '%-20p'\n\n", str);
*/ /*
	printf("%%07i -54: '%07i'\n", -54);
	ft_printf("%%07i -54: '%07i'\n", -54);
	printf("%%08.5i 34: '%08.5i'\n", 34);
	ft_printf("%%08.5i 34: '%08.5i'\n", 34);
	printf("%%010.5i -216: '%010.5i'\n", -216);
	ft_printf("%%010.5i -216: '%010.5i'\n", -216);
	printf("%%08.5i 0: '%08.5i'\n", 0);
	ft_printf("%%08.5i 0: '%08.5i'\n", 0);
	printf("%%08.3i 8437: '%08.3i'\n", 8473);
	ft_printf("%%08.3i 8437: '%08.3i'\n", 8473);
	printf("%%08.3i -8437: '%08.3i'\n", -8473);
	ft_printf("%%08.3i -8437: '%08.3i'\n", -8473);
	printf("%%0+8.5i 34: '%0+8.5i'\n", 34);
	ft_printf("%%0+8.5i 34: '%0+8.5i'\n", 34);
	printf("%%0+8.5i -634: '%0+8.5i'\n", -634);
	ft_printf("%%0+8.5i -634: '%0+8.5i'\n", -634);
	printf("%%05i 43: '%05i'\n", 43);
	ft_printf("%%05i 43: '%05i'\n", 43);
	printf("%%05i -25543: '%05i'\n", -25543);
	ft_printf("%%05i -25543: '%05i'\n", -25543);
	printf("%%03i 0: '%03i'\n", 0);
	ft_printf("%%03i 0: '%03i'\n", 0);
	printf("%%+i 5: '%+i'\n", 5);
	ft_printf("%%+i 5: '%+i'\n", 5);
	printf("%%+i 2147483647: '%+i'\n", 2147483647);
	ft_printf("%%+i 2147483647: '%+i'\n", 2147483647);
	printf("%%7i 33: '%7i'\n", 33);
	ft_printf("%%7i 33: '%7i'\n", 33);
	printf("this '% i' number\n", 267);
	ft_printf("this '% i' number\n", 267);
	printf("this '% i' number\n", -267);
	ft_printf("this '% i' number\n", -267);
	printf("%% i -1: '% i'\n", -1);
	ft_printf("%% i -1: '% i'\n", -1);
	printf("%% 03i 634: '% 03i'\n", 634);
	ft_printf("%% 03i 634: '% 03i'\n", 634);
	printf("%%.0i 0: '%.0i'\n", 0);
	ft_printf("%%.0i 0: '%.0i'\n", 0);
	printf("%%5.0i 0: '%5.0i'\n", 0);
	ft_printf("%%5.0i 0: '%5.0i'\n", 0);
	
	printf("\n%%d 21: '%d'\n", 21);
	ft_printf("%%d 21: '%d'\n", 21);
	printf("%%.1d 21: '%.1d'\n", 21);
	ft_printf("%%.1d 21: '%.1d'\n", 21);
	printf("%%.d 21: '%.d'\n", 21);
	ft_printf("%%.d 21: '%.d'\n", 21);
	printf("%%.5d 21: '%.5d'\n", 21);
	ft_printf("%%.5d 21: '%.5d'\n", 21);	
	printf("%%.10d 21: '%.10d'\n", 21);
	ft_printf("%%.10d 21: '%.10d'\n", 21);
	printf("%%1d 21: %1d'\n", 21);
	ft_printf("%%1d 21: %1d'\n", 21);
	printf("%%5d 21: '%5d'\n", 21);
	ft_printf("%%5d 21: '%5d'\n", 21);
	printf("%%5.10d 21: '%5.10d'\n", 21);
	ft_printf("%%5.10d 21: '%5.10d'\n", 21);
	printf("%%10.5d 21: '%10.5d'\n", 21);
	ft_printf("%%10.5d 21: '%10.5d'\n", 21);
	printf("%%-5d 21: '%-5d'\n", 21);
	ft_printf("%%-5d 21: '%-5d'\n", 21);
	printf("%%-10d 21: '%-10d'\n", 21);
	ft_printf("%%-10d 21: '%-10d'\n", 21);
	printf("%%010d 21: '%010d'\n", 21);
	ft_printf("%%010d 21: '%010d'\n", 21);
	printf("%%+d 21: '%+d'\n", 21);
	ft_printf("%%+d 21: '%+d'\n", 21);
	printf("%%+d -21: '%+d'\n", -21);
	ft_printf("%%+d -21: '%+d'\n", -21);
	printf("%%+-10d 21: '%+-10d'\n", 21);
	ft_printf("%%+-10d 21: '%+-10d'\n", 21);
	printf("%%+-10d -21: '%+-10d'\n", -21);
	ft_printf("%%+-10d -21: '%+-10d'\n", -21);
	printf("%%010.5d 21: '%10.5d'\n", 21);
	ft_printf("%%010.5d 21: '%10.5d'\n\n", 21);

	printf("%%hd 2110: '%hd'\n", 2110);
	ft_printf("%%hd 2110: '%hd'\n", 2110);
	printf("%%hd -2110: '%hd'\n", -2110);
	ft_printf("%%hd -2110: '%hd'\n", -2110);
	printf("%%10hd 2110: '%10hd'\n", 2110);
	ft_printf("%%10hd 2110: '%10hd'\n", 2110);
	printf("%%3hd 2110: '%3hd'\n", 2110);
	ft_printf("%%3hd 2110: '%3hd'\n", 2110);
	printf("%%.10hd 2110: '%.10hd'\n", 2110);
	ft_printf("%%.10hd 2110: '%.10hd'\n", 2110);
	printf("%%010hd 2110: '%010hd'\n", 2110);
	ft_printf("%%010hd 2110: '%010hd'\n", 2110);
	printf("%%-20hd 2110: '%-20hd'\n", 2110);
	ft_printf("%%-20hd 2110: '%-20hd'\n", 2110);
	printf("%%-20.10hd 2110: '%-20.10hd'\n", 2110);
	ft_printf("%%-20.10hd 2110: '%-20.10hd'\n", 2110);
	printf("%%-+20.10hd 2110: '%-+20.10hd'\n", 2110);
	ft_printf("%%-+20.10hd 2110: '%-+20.10hd'\n", 2110);
	printf("%%-+20.10hd -2110: '%-+20.10hd'\n", -2110);
	ft_printf("%%-+20.10hd -2110: '%-+20.10hd'\n", -2110);
	printf("%%- +20.10hd -2110: '%-+20.10hd'\n", -2110);
	ft_printf("%%- +20.10hd -2110: '%-+20.10hd'\n", -2110);
	printf("%%hd 0: '%hd'\n", 0);
	ft_printf("%%hd 0: '%hd'\n", 0);
	printf("%%hd NULL: '%hd'\n", NULL);
	ft_printf("%%hd NULL: '%hd'\n", NULL);
	printf("%%hd 272893939474377473: '%hd'\n", 272893939474377473);
	ft_printf("%%hd 272893939474377473: '%hd'\n", 272893939474377473);
	printf("%%hd -272893939474377473: '%hd'\n", -272893939474377473);
	ft_printf("%%hd -272893939474377473: '%hd'\n\n", -272893939474377473);
	
	printf("%%ld 21111111110: %ld\n", 21111111110);
	ft_printf("%%ld 21111111110: %ld\n", 21111111110);
	printf("%%ld -2110: '%ld'\n", -2110);
	ft_printf("%%ld -2110: '%ld'\n", -2110);
	printf("%%10ld 2110: '%10ld'\n", 2110);
	ft_printf("%%10ld 2110: '%10ld'\n", 2110);
	printf("%%3ld 2110: '%3ld'\n", 2110);
	ft_printf("%%3ld 2110: '%3ld'\n", 2110);
	printf("%%.10ld 2110: '%.10ld'\n", 2110);
	ft_printf("%%.10ld 2110: '%.10ld'\n", 2110);
	printf("%%010ld 2110: '%010ld'\n", 2110);
	ft_printf("%%010ld 2110: '%010ld'\n", 2110);
	printf("%%-20ld 2110: '%-20ld'\n", 2110);
	ft_printf("%%-20ld 2110: '%-20ld'\n", 2110);
	printf("%%-20.10ld 2110: '%-20.10ld'\n", 2110);
	ft_printf("%%-20.10ld 2110: '%-20.10ld'\n", 2110);
	printf("%%-+20.10ld 2110: '%-+20.10ld'\n", 2110);
	ft_printf("%%-+20.10ld 2110: '%-+20.10ld'\n", 2110);
	printf("%%-+20.10ld -2110: '%-+20.10ld'\n", -2110);
	ft_printf("%%-+20.10ld -2110: '%-+20.10ld'\n", -2110);
	printf("%%- +20.10ld -2110: '%-+20.10ld'\n", -2110);
	ft_printf("%%- +20.10ld -2110: '%-+20.10ld'\n", -2110);
	printf("%%ld 0: '%ld'\n", 0);
	ft_printf("%%ld 0: '%ld'\n", 0);
	printf("%%ld NULL: '%ld'\n", NULL);
	ft_printf("%%ld NULL: '%ld'\n", NULL);
	printf("%%.5ld NULL: '%.5ld'\n", NULL);
	ft_printf("%%.5ld NULL: '%.5ld'\n", NULL);
	printf("%%ld 272893939474377473: '%ld'\n", 272893939474377473);
	ft_printf("%%ld 272893939474377473: '%ld'\n", 272893939474377473);
	printf("%%ld -272893939474377473: '%ld'\n", -272893939474377473);
	ft_printf("%%ld -272893939474377473: '%ld'\n", -272893939474377473);
	printf("%%-20.10ld 75126389712389028: '%-20.10ld'\n", 75126389712389028);
	ft_printf("%%-20.10ld 75126389712389028: '%-20.10ld'\n", 75126389712389028);
	printf("%%-+20.30ld -75126389712389028: '%-+20.30ld'\n", -75126389712389028);
	ft_printf("%%-+20.30ld -75126389712389028: '%-+20.30ld'\n", -75126389712389028);
	printf("%%0+20.30ld -75126389712389028: '%0+20.30ld'\n", -75126389712389028);
	ft_printf("%%0+20.30ld -75126389712389028: '%0+20.30ld'\n", -75126389712389028);
	printf("%%+20.30ld -75126389712389028: '%+20.30ld'\n", -75126389712389028);
	ft_printf("%%+20.30ld -75126389712389028: '%+20.30ld'\n", -75126389712389028);
	printf("%%-+20.10ld -2110: '%-+20.10ld'\n", -2110);
	ft_printf("%%-+20.10ld -2110: '%-+20.10ld'\n", -2110);
	printf("%%- +20.10ld -2110: '%-+20.10ld'\n", -2110);
	ft_printf("%%- +20.10ld -2110: '%-+20.10ld'\n\n", -2110);

	printf("%%hhd c: %hhd\n", 'c');
	ft_printf("%%hhd c: %hhd\n", 'c');
	printf("%%hhd c: %hhd\n", 'c');
	ft_printf("%%hhd c: %hhd\n", 'c');
	printf("%%hhd c: '%hhd'\n", 'c');
	ft_printf("%%hhd c: '%hhd'\n", 'c');
	printf("%%10hhd a: '%10hhd'\n", 'a');
	ft_printf("%%10hhd a: '%10hhd'\n", 'a');
	printf("%%3hhd a: '%3hhd'\n", 'a');
	ft_printf("%%3hhd 'a: '%3hhd'\n", 'a');
	printf("%%.10hhd 'a': '%.10hhd'\n", 'a');
	ft_printf("%%.10hhd 'a': '%.10hhd'\n", 'a');
	printf("%%010hhd 'a': '%010hhd'\n", 'a');
	ft_printf("%%010hhd 'a': '%010hhd'\n", 'a');
	printf("%%-20hhd 'a': '%-20hhd'\n", 'a');
	ft_printf("%%-20hhd 'a': '%-20hhd'\n", 'a');
	printf("%%-20.10hhd 'a': '%-20.10hhd'\n", 'a');
	ft_printf("%%-20.10hhd 'a': '%-20.10hhd'\n", 'a');
	printf("%%-+20.10hhd 'a': '%-+20.10hhd'\n", 'a');
	ft_printf("%%-+20.10hhd 'a': '%-+20.10hhd'\n", 'a');
	printf("%%-+20.10hhd 'a': '%-+20.10hhd'\n", -'a');
	ft_printf("%%-+20.10hhd 'a': '%-+20.10hhd'\n", -'a');
	printf("%%- +20.10hhd 'a': '%-+20.10hhd'\n", -'a');
	ft_printf("%%- +20.10hhd 'a': '%-+20.10hhd'\n", -'a');
	printf("%%hhd a: '%hhd'\n", 'a');
	ft_printf("%%hhd a: '%hhd'\n", 'a');
	printf("%%hhd NULL: '%hhd'\n", NULL);
	ft_printf("%%hhd NULL: '%hhd'\n", NULL);
	printf("%%.5hhd NULL: '%.5hhd'\n", NULL);
	ft_printf("%%.5hhd NULL: '%.5hhd'\n", NULL);
	printf("%%hhd 'b': '%hhd'\n", 'b');
	ft_printf("%%hhd 'b': '%hhd'\n", 'b');
	printf("%%hhd 'b': '%hhd'\n", 'b');
	ft_printf("%%hhd 'b': '%hhd'\n", 'b');
	printf("%%-20.10hhd 'd': '%-20.10hhd'\n", 'd');
	ft_printf("%%-20.10hhd 'd': '%-20.10hhd'\n", 'd');
	printf("%%-+20.30hhd -'d': '%-+20.30hhd'\n", -'d');
	ft_printf("%%-+20.30hhd -'d': '%-+20.30hhd'\n", -'d');
	printf("%%0+20.30hhd -'d': '%0+20.30hhd'\n", -'d');
	ft_printf("%%0+20.30hhd -'d': '%0+20.30hhd'\n", -'d');
	printf("%%+20.30hhd -'d': '%+20.30hhd'\n", -'d');
	ft_printf("%%+20.30hhd -'d': '%+20.30hhd'\n", -'d');
	printf("%%-+20.10hhd -'a': '%-+20.10hhd'\n", -'a');
	ft_printf("%%-+20.10hhd -'a': '%-+20.10hhd'\n", -'a');
	printf("%%- +20.10hhd -'a': '%-+20.10hhd'\n", -'a');
	ft_printf("%%- +20.10hhd -'a': '%-+20.10hhd'\n\n", -'a');
	
	printf("%%lld 74628920203743245: %lld\n", 74628920203743245);
	ft_printf("%%lld 74628920203743245: %lld\n", 74628920203743245);
	printf("%%lld -74628920203743245: %lld\n", -74628920203743245);
	ft_printf("%%lld -74628920203743245: %lld\n", -74628920203743245);
	printf("%%lld 21111111110: %lld\n", (long long)21111111110);
	ft_printf("%%lld 21111111110: %lld\n", (long long)21111111110);
	printf("%%lld -2110: '%lld'\n", (long long)-2110);
	ft_printf("%%lld -2110: '%lld'\n", (long long)-2110);
	printf("%%10lld 2110: '%10lld'\n", (long long)2110);
	ft_printf("%%10lld 2110: '%10lld'\n", (long long)2110);
	printf("%%3lld 2110: '%3lld'\n", (long long)2110);
	ft_printf("%%3lld 2110: '%3lld'\n", (long long)2110);
	printf("%%.10lld 2110: '%.10lld'\n", (long long)2110);
	ft_printf("%%.10lld 2110: '%.10lld'\n", (long long)2110);
	printf("%%010lld 2110: '%010lld'\n", (long long)2110);
	ft_printf("%%010lld 2110: '%010lld'\n", (long long)2110);
	printf("%%-20lld 2110: '%-20lld'\n", (long long)2110);
	ft_printf("%%-20lld 2110: '%-20lld'\n", (long long)2110);
	printf("%%-20.10lld 2110: '%-20.10lld'\n", (long long)2110);
	ft_printf("%%-20.10lld 2110: '%-20.10lld'\n", (long long)2110);
	printf("%%-+20.10lld 2110: '%-+20.10lld'\n", (long long)2110);
	ft_printf("%%-+20.10lld 2110: '%-+20.10lld'\n", (long long)2110);
	printf("%%-+20.10lld -2110: '%-+20.10lld'\n", (long long)-2110);
	ft_printf("%%-+20.10lld -2110: '%-+20.10lld'\n", (long long)-2110);
	printf("%%- +20.10lld -2110: '%-+20.10lld'\n", (long long)-2110);
	ft_printf("%%- +20.10lld -2110: '%-+20.10lld'\n", (long long)-2110);
	printf("%%lld 0: '%lld'\n", (long long)0);
	ft_printf("%%lld 0: '%lld'\n", (long long)0);
	printf("%%lld NULL: '%lld'\n", NULL);
	ft_printf("%%lld NULL: '%lld'\n", NULL);
	printf("%%.5lld NULL: '%.5lld'\n", NULL);
	ft_printf("%%.5lld NULL: '%.5lld'\n", NULL);
	printf("%%lld 272893939474377473: '%lld'\n", 272893939474377473);
	ft_printf("%%lld 272893939474377473: '%lld'\n", 272893939474377473);
	printf("%%lld -272893939474377473: '%lld'\n", -272893939474377473);
	ft_printf("%%lld -272893939474377473: '%lld'\n", -272893939474377473);
	printf("%%-20.10lld 75126389712389028: '%-20.10lld'\n", 75126389712389028);
	ft_printf("%%-20.10lld 75126389712389028: '%-20.10lld'\n", 75126389712389028);
	printf("%%-+20.30lld -75126389712389028: '%-+20.30lld'\n", -75126389712389028);
	ft_printf("%%-+20.30lld -75126389712389028: '%-+20.30lld'\n", -75126389712389028);
	printf("%%0+20.30lld -75126389712389028: '%0+20.30lld'\n", -75126389712389028);
	ft_printf("%%0+20.30lld -75126389712389028: '%0+20.30lld'\n", -75126389712389028);
	printf("%%+20.30lld -75126389712389028: '%+20.30lld'\n", -7512634575656686786);
	ft_printf("%%+20.30lld -75126389712389028: '%+20.30lld'\n", -7512634575656686786);
	printf("%%-+20.10lld -2110: '%-+20.10lld'\n", (long long)-2110);
	ft_printf("%%-+20.10lld -2110: '%-+20.10lld'\n", (long long)-2110);
	printf("%%- +20.10lld -2110: '%-+20.10lld'\n", (long long)-2110);
	ft_printf("%%- +20.10lld -2110: '%-+20.10lld'\n\n", (long long)-2110);
*/
	printf("%%o 1234567: '%o'\n", 1234567);
	ft_printf("%%o 1234567: '%o'\n", 1234567);
	printf("%%o -1234567: '%o'\n", -1234567);
	ft_printf("%%o -1234567: '%o'\n", -1234567);
	printf("%%o 1234567890: '%o'\n", 1234567890);
	ft_printf("%%o 1234567890: '%o'\n", 1234567890);
	printf("%%o -1234567890: '%o'\n", -1234567890);
	ft_printf("%%o -1234567890: '%o'\n", -1234567890);
	printf("%%o 0: '%o'\n", 0);
	ft_printf("%%o 0: '%o'\n", 0);
	printf("%%o NULL: '%o'\n", NULL);
	ft_printf("%%o NULL: '%o'\n", NULL);
	printf("%%#o 0: '%#o'\n", 0);
	ft_printf("%%#o 0: '%#o'\n", 0);
	printf("%%#o NULL: '%#o'\n", NULL);
	ft_printf("%%#o NULL: '%#o'\n", NULL);
	printf("%%.10o 1234567: '%.10o'\n", 1234567);
	ft_printf("%%.10o 1234567: '%.10o'\n", 1234567);
	printf("%%#.20o 1234567: '%#.20o'\n", 1234567);
	ft_printf("%%#.20o 1234567: '%#.20o'\n", 1234567);
	printf("%%.5o 1234567: '%.5o'\n", 1234567);
	ft_printf("%%.5o 1234567: '%.5o'\n", 1234567);
	printf("%%#.5o 1234567: '%#.5o'\n", 1234567);
	ft_printf("%%#.5o 1234567: '%#.5o'\n", 1234567);
	printf("%%10o -1234567: '%10o'\n", -1234567);
	ft_printf("%%10o -1234567: '%10o'\n", -1234567);
	printf("%%10.5o -1234567: '%10.5o'\n", -1234567);
	ft_printf("%%10.5o -1234567: '%10.5o'\n", -1234567);
	printf("%%020.10o -1234567: '%020.10o'\n", -1234567);
	ft_printf("%%020.10o -1234567: '%020.10o'\n", -1234567);
	printf("%%-10.5o -1234567: '%-10.5o'\n", -1234567);
	ft_printf("%%-10.5o -1234567: '%-10.5o'\n", -1234567);
	printf("%%o 1234567890: '%o'\n", 1234567890);
	ft_printf("%%o 1234567890: '%o'\n", 1234567890);
	printf("%%o -1234567890: '%o'\n", -1234567890);
	ft_printf("%%o -1234567890: '%o'\n", -1234567890);
	printf("%%.o 0: '%.o'\n", 0);
	ft_printf("%%.o 0: '%.o'\n", 0);
	printf("%%.0o 0: '%.0o'\n", 0);
	ft_printf("%%.0o 0: '%.0o'\n", 0);
	printf("%%.1o 0: '%.1o'\n", 0);
	ft_printf("%%.1o 0: '%.1o'\n", 0);
	printf("%%.-3o 0: '%.-1o'\n", 0);
	ft_printf("%%.-3o 0: '%.-1o'\n", 0);
	printf("%%05o 43: '%05o'\n", 43);
	ft_printf("%%05o 43: '%05o'\n", 43);
	printf("%%03o 0: '%03o'\n", 0);
	ft_printf("%%03o 0: '%03o'\n", 0);
	printf("%%037lo 22337203685477ul: '%037lo'\n", 22337203685477ul);
	ft_printf("%%037lo 22337203685477ul: '%037lo'\n", 22337203685477ul);
	printf("%%#7o 33: '%#7o'\n", 33);
	ft_printf("%%#7o 33: '%#7o'\n", 33);
	printf("%%#3o 0: '%#3o'\n", 0);
	ft_printf("%%#3o 0: '%#3o'\n", 0);
	printf("%%#8.5 34: '%#8.5o'\n", 34);
	ft_printf("%%#8.5 34: '%#8.5o'\n", 34);
	printf("%%#-8.5 34: '%#-8.5o'\n", 34);
	ft_printf("%%#-8.5 34: '%#-8.5o'\n", 34);
	printf("%%#08.5 34: '%#08.5o'\n", 34);
	ft_printf("%%#08.5 34: '%#08.5o'\n", 34);
	printf("%%#.0o 0: '%#.0o'\n", 0);
	ft_printf("%%#.0o 0: '%#.0o'\n", 0);
	printf("%%#.1o 0: '%#.1o'\n", 0);
	ft_printf("%%#.1o 0: '%#.1o'\n", 0);
	printf("%%#5.0o 0: '%#5.0o'\n", 0);
	ft_printf("%%#5.0o 0: '%#5.0o'\n", 0);
	printf("%%#-5.o 0: '%#-5.o'\n", 0);
	ft_printf("%%#-5.o 0: '%#-5.o'\n", 0);
	printf("%%#7o 33: '%#7o'\n", 33);
	ft_printf("%%#7o 33: '%#7o'\n", 33);
	printf("%%#8.3o 8375: '%#8.3o'\n", 8375);
	ft_printf("%%#8.3o 8375: '%#8.3o'\n", 8375);

	printf("\n%%f 1.0: '%f'\n", 1.0);
	ft_printf("%%f 1.0: '%f'\n", 1.0);
	printf("%%f 1.1: '%f'\n", 1.1);
	ft_printf("%%f 1.1: '%f'\n", 1.1);
	printf("%%f 1.143: '%f'\n", 1.143);
	ft_printf("%%f 1.143: '%f'\n", 1.143);
	printf("%%.0f 1.143: '%.0f'\n", 1.143);
	ft_printf("%%.0f 1.143: '%.0f'\n", 1.143);
	printf("%%.0f 1.1: '%.0f'\n", 1.1);
	ft_printf("%%.0f 1.1: '%.0f'\n", 1.1);
	printf("%%.1f 1.1: '%.1f'\n", 1.1);
	ft_printf("%%.1f 1.1: '%.1f'\n", 1.1);
	printf("%%.-1f 1.1: '%.-1f'\n", 1.1);
	ft_printf("%%.-1f 1.1: '%.-1f'\n", 1.1);
	printf("%%.3f 1.1: '%.3f'\n", 1.1);
	ft_printf("%%.3f 1.1: '%.3f'\n", 1.1);
	printf("%%7.3f 1.1: '%7.3f'\n", 1.1);
	ft_printf("%%7.3f 1.1: '%7.3f'\n\n", 1.1);
	printf("%%f: '%f'\n", 573.924);
	ft_printf("%%f: '%f'\n", 573.924);
	
	printf("%%-5c null: '%-5c'\n", '\0');
	ft_printf("%%-5c null: '%-5c'\n", '\0');
/*
	printf("%%llu max: '%llu'\n", 9223372036854775807);
	ft_printf("%%llu max: '%llu'\n", 9223372036854775807);
	printf("%%lu max: '%lu'\n", 9223372036854775807);
	ft_printf("%%lu max: '%lu'\n", 9223372036854775807);
	printf("%%.0u 0: '%.0u'\n", 0);
	ft_printf("%%.0u 0: '%.0u'\n", 0);
	printf("%%.u 0: '%.u'\n", 0);
	ft_printf("%%.u 0: '%.u'\n", 0);
	printf("%%5.0u 0: '%5.0u'\n", 0);
	ft_printf("%%5.0u 0: '%5.0u'\n", 0);
	printf("%%05u 43: '%05u'\n", 43);
	ft_printf("%%05u 43: '%05u'\n", 43);
	printf("%%03u 0: '%03u'\n", 0);
	ft_printf("%%03u 0: '%03u'\n", 0);
	printf("%%+037lu 22337203685477ul: '%037lu'\n", 22337203685477ul);
	ft_printf("%%+037lu 22337203685477ul: '%037lu'\n", 22337203685477ul);
	printf("%%08.3u 8375: '%08.3u'\n", 8375);
	ft_printf("%%08.3u 8375: '%08.3u'\n\n", 8375);

	printf("%%7x 33: '%7x'\n", 33);
	ft_printf("%%7x 33: '%7x'\n", 33);
	printf("%%3x 0: '%3x'\n", 0);
	ft_printf("%%3x 0: '%3x'\n", 0);
	printf("%%5x 52625: '%5x'\n", 52625);
	ft_printf("%%5x 52625: '%5x'\n", 52625);
	printf("%%-7x 33: '%-7x'\n", 33);
	ft_printf("%%-7x 33: '%-7x'\n", 33);
	printf("%%07.2x 44: '%07.2x'\n", 44);
	ft_printf("%%07.2x 44: '%07.2x'\n", 44);
	printf("'this '%#x' number'\n", 0);
	ft_printf("'this '%#x' number'\n", 0);
	printf("'this '%5#x' number'\n", 0);
	ft_printf("'this '%5#x' number'\n", 0);
	printf("%%#3x 0: '%#3x'\n", 0);
	ft_printf("%%#3x 0: '%#3x'\n", 0);
	printf("%%#-3x 0: '%#-3x'\n", 0);
	ft_printf("%%#-3x 0: '%#-3x'\n", 0);
	printf("%%#.3x 0: '%#.3x'\n", 0);
	ft_printf("%%#.3x 0: '%#.3x'\n", 0);
	printf("%%+.3x 4: '%+.3x'\n", 4);
	ft_printf("%%+.3x 4: '%+.3x'\n", 4);
	printf("%%#05x 43: '%#05x'\n", 43);
	ft_printf("%%#05x 43: '%#05x'\n", 43);
	printf("%%#03x 0: '%#03x'\n", 0);
	ft_printf("%%#03x 0: '%#03x'\n", 0);
	printf("%%X 4294967295u: '%X'\n", 4294967295u);
	ft_printf("%%X 4294967295u: '%X'\n", 4294967295u);

//	printf("%");
	ft_printf("\n\n%");
//	printf("%5");
	ft_printf("%5");
//	printf("%-5");
	ft_printf("%-5");
	printf("%%.3x 0: '%.3x'\n", 0);
	ft_printf("%%.3x 0: '%.3x'\n", 0);
	printf("%%03x 0: '%03x'\n", 0);
	ft_printf("%%03x 0: '%03x'\n", 0);
	printf("'%%'\n");
	ft_printf("'%%'\n");
	ft_printf("hello %s hello \n", "heya");

/*
	ft_printf("\033[1;31m");
    ft_printf("%s\n", "hdsfjlksellrwekjrrlkdjf");
	ft_printf("woowowowo \n");
    ft_printf("\033[0m;");
	

	long double d = 3.1415926535;
 	long long int lli = 55165;
 	long long int lli_m = 18446744073709551615;
 	int	i = 3;
 	long long int lli_n = -55165;
 	int	i_n = -3;

//	ft_printf("\n****** TEST #FLAGS TEST ll******\n\n");
 //	ft_printf("'%-+lli'\n'%-+lli'\n", lli, lli);
 	printf("'%-+lli'\n'%-+lli'\n", lli, lli);
	
//	ft_printf("\n****** TEST #FLAGS TEST l ******\n\n");
 //	ft_printf("'%-+li'\n'%-+li'\n", (long int)42, (long int)42);
 	printf("'%-+li'\n'%-+li'\n", (long int)42, (long int)42);

//	ft_printf("\n****** TEST #FLAGS TEST h ******\n\n");
 //	ft_printf("'%-+hi'\n'%-+hi'\n", (short int)42, (short int)42);
 	printf("'%-+hi'\n'%-+hi'\n", (short int)42, (short int)42);

//	ft_printf("\n****** TEST #FLAGS TEST hh ******\n\n");
 //	ft_printf("'%-+hhi'\n'%-+hhi'\n", (signed char)42, (signed char)42);
 	printf("'%-+hhi'\n'%-+hhi'\n", (signed char)42, (signed char)42);

//	ft_printf("\n****** TEST #1******\n\n");
 //	ft_printf("'%-+i'\n'%-+lli'\n", i, lli);
 	printf("'%-+i'\n'%-+lli'\n", i, lli);

 //	ft_printf("\n****** TEST #2 ******\n\n");
 //	ft_printf("'%-i'\n'%-lli'\n", i_n, lli_n);
 	printf("'%-i'\n'%-lli'\n", i_n, lli_n);

 //	ft_printf("\n****** TEST #3 ******\n\n");
 //	ft_printf("'%-+ i'\n'%-+ lli'\n", i, lli);
 	printf("'%-+ i'\n'%-+ lli'\n", i, lli);

 //	ft_printf("\n****** TEST #4 ******\n\n");
 //	ft_printf("'%- i'\n'%- lli'\n", i_n, lli_n);
 	printf("'%- i'\n'%- lli'\n", i_n, lli_n);

 //	ft_printf("\n****** TEST #5 ******\n\n");
 //	ft_printf("'%-10 i'\n'%-10 lli'\n", i, lli);
 	printf("'%-10 i'\n'%-10 lli'\n", i, lli);

 //	ft_printf("\n****** TEST #6 ******\n\n");
 //	ft_printf("'%- i'\n'%- lli'\n", i, lli);
 	printf("'%- i'\n'%- lli'\n", i, lli);

 //	ft_printf("\n****** TEST #7 ******\n\n");
 //	ft_printf("'%- .5i'\n'%- .10lli'\n", i, lli);
 	printf("'%- .5i'\n'%- .10lli'\n", i, lli);

 //	ft_printf("\n****** TEST #8 ******\n\n");
 //	ft_printf("'%- .i'\n'%- .lli'\n", i, lli);
 	printf("'%- .i'\n'%- .lli'\n", i, lli);

 //	ft_printf("\n****** TEST #9 ******\n\n");
 //	ft_printf("'%- .0i'\n'%- .0lli'\n", i, lli);
 	printf("'%- .0i'\n'%- .0lli'\n", i, lli);

 //	ft_printf("\n****** TEST #10 ******\n\n");
 //	ft_printf("'%- i'\n'%- lli'\n", i_n, lli_n);
 	printf("'%- i'\n'%- lli'\n", i_n, lli_n);

 //	ft_printf("\n****** TEST #11 ******\n\n");
 //	ft_printf("'%-10 i'\n'%-10 lli'\n", i_n, lli_n);
 	printf("'%-10 i'\n'%-10 lli'\n", i_n, lli_n);

 //	ft_printf("\n****** TEST #12 ******\n\n");
 //	ft_printf("'%-10.5lld'\n'%-10.5d'\n", lli, i);
 	printf("'%-10.5lld'\n'%-10.5d'\n", lli, i);

 //	ft_printf("\n****** TEST #13 ******\n\n");
 //	ft_printf("'%-+10.5d'\n", i);
 	printf("'%-+10.5d'\n", i);

 //	ft_printf("\n****** TEST #14 ******\n\n");
 //	ft_printf("'%-+60.20d'\n", i_n);
 	printf("'%-+60.20d'\n", i_n);

 //	ft_printf("\n****** TEST #15 ******\n\n");
 //	ft_printf("'%-10.5d'\n", i);
 	printf("'%-10.5d'\n", i);

 //	ft_printf("\n****** TEST #16 ******\n\n");
 //	ft_printf("'%-010.5lld'\n'%-10.5d'\n", lli_n, i_n);
 	printf("'%-010.5lld'\n'%-10.5d'\n", lli_n, i_n);

 //	ft_printf("\n****** TEST #17 ******\n\n");
 //	ft_printf("'%-lld'\n'%-d'\n", lli, i);
 	printf("'%-lld'\n'%-d'\n", lli, i);

 //	ft_printf("\n****** TEST #18 ******\n\n");
 //	ft_printf("'%-+015.10hi.'\n", (short int)92);
 	printf("'%-+015.10hi.'\n", (short int)92);

 //	ft_printf("\n****** TEST #19 ******\n\n");
 	printf("'%-020.4lli'\n'%-10.5i'\n", lli_n, i_n);
 //	ft_printf("'%-020.4lli'\n'%-10.5i'\n", lli_n, i_n);
//	printf("% hZ%\n");
//	printf("%")
//	unsigned long long u = 140732770003580;
//	printf("here: %s\n", ft_itoa_base(u, 16)); */
	return (0);
}
