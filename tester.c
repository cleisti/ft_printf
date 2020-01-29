#include <stdio.h>
#include "libft/libft.h"
#include <stdlib.h>

int main(void)
{
	float f;
	char *str;
//	char *s2;

	f = 682.246824;
	str = ft_ftoa(f, 6);
//	s2 = ftoa(f, 0);
	printf("%s\n", str);
	return (0);
}
