#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
int	ft_count_size(long nb, int nbr)
{
	int	count;

	count = 0;
	if (nb < 0)
		nb = 4294967295 + nb + 1;
	while (nb != 0)
	{
		nb /= nbr;
		count++;
	}
	return (count);
}
void	ft_change_base(long nb, int *count, int format)
{
	char	*base;

	if (format == 'x' ||format == 'p')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb < 0)
		nb = 4294967295 + nb + 1;
	if (nb >= 16)
		ft_change_base((nb / 16), count, format);
	*count += 1;
	ft_putchar(base[nb % 16]);
}
void	ft_print_address(va_list ap, int *count, t_list *print)
{
	unsigned long	addr;

	print->var_string = va_arg(ap, char *);
	addr = (unsigned long) (print->var_string);
	print->var_llong = addr;
	*count += 2;
}
