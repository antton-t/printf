#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char a[] ="helou bbao";
	int b = 12344;
	printf("%--1-4s sdf\n",a);
	printf("%.*d\n",10,b);
	ft_printf("%*.*d\n",10,b,b);

}
