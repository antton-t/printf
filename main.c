#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char a[] ="helou bbao";
	int b = 334;
	int c;
	c = ft_printf("%*.10Xp\n",11,b);
	printf("%d\n",c);
	c = printf("%*.10Xp\n",11,b);
	printf("%d\n",c);
}
