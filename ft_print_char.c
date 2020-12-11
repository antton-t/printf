#include "ft_printf.h"

void	ft_print_char(va_list ap, int *count)
{
	char	c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	count++;
}
