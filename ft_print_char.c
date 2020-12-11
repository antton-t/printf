#include "ft_printf.h"

void	ft_print_char(char c, int *count)
{
	write(1, &c, 1);
	count++;
}
