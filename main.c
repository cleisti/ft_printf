/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:28:26 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/10 17:57:36 by cleisti          ###   ########.fr       */
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
	*/
//	ft_printf("'%x'\n", 0);
	char c = 'A';
 	char b = 'B';
 	printf("'%-c' | 1.p: '%-10c'\n", c, b);
 	printf("'%c' | 2.p: '%10c'\n", c, b);
 	printf("'%%%c%%' | 3.p: '%%%10c%%'\n\n", c, b);

	char *str = "Hello World";
 	printf("'%-015s' | '%15c'\n", str, c);
 	printf("'%-0*s' | '%15c'\n", 15, str, c);
 	printf("'%15.s'\n", str);
 	printf("'%15.0s'\n", str);
 	printf("'%-15.0006s'\n", str);
 	printf("'%*.6s'\n", 15, str);
	printf("'hello, %s.'\n\n", NULL);

	printf("%%0p null: '%0p'\n", NULL);
	printf("%%.p null: '%.p'\n", NULL);
	printf("%%05.p null: '%05.p'\n", NULL);
	printf("%%6p null: '%6p'\n", NULL);
	printf("%%.6p null: '%.6p'\n", NULL);
	printf("%%p 0: '%p'\n", 0);
	printf("%%0p 0: '%0p'\n", 0);
	printf("%%.p 0: '%.p'\n", 0);
	printf("%%05.p 0: '%05.p'\n", 0);
	printf("%%6p 0: '%6p'\n", 0);
	printf("%%.6p 0: '%.6p'\n", 0);
	printf("%%p str: '%p'\n", str);
	printf("%%0p str: '%0p'\n", str);
	printf("%%.p str: '%.p'\n", str);
	printf("%%05.p str: '%05.p'\n", str);
	printf("%%6p str: '%6p'\n", str);
	printf("%%.12p str: '%.12p'\n", str);
	printf("%%20.12p str: '%20.12p'\n", str);
	printf("%%.20p str: '%.20p'\n", str);
	printf("%%20p str: '%20p'\n", str);
	printf("%%020p str: '%020p'\n", str);
	printf("%%-020p str: '%-020p'\n", str);
	printf("%%-20p str: '%-20p'\n\n", str);

	printf("%%d 21: '%d'\n", 21);
	printf("%%.1d 21: '%.1d'\n", 21);
	printf("%%.d 21: '%.d'\n", 21);
	printf("%%.5d 21: '%.5d'\n", 21);
	printf("%%.10d 21: '%.10d'\n", 21);
	printf("%%1d 21: %1d'\n", 21);
	printf("%%5d 21: '%5d'\n", 21);
	printf("%%5.10d 21: '%5.10d'\n", 21);
	printf("%%10.5d 21: '%10.5d'\n", 21);
	printf("%%-5d 21: '%-5d'\n", 21);
	printf("%%-10d 21: '%-10d'\n", 21);
	printf("%%010d 21: '%010d'\n", 21);
	printf("%%+d 21: '%+d'\n", 21);
	printf("%%+d -21: '%+d'\n", -21);
	printf("%%+-10d 21: '%+-10d'\n", 21);
	printf("%%+-10d -21: '%+-10d'\n", -21);
/*
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
