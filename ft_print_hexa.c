#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_change_base(unsigned long long nb, t_list *print)
{
	char	*base;

	if (print->format == 'x' ||print->format == 'p')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
		ft_change_base((nb / 16), print);
	ft_putchar(base[nb % 16]);
}
void	ft_print_hexa(va_list ap, int *count, t_list *print)
{
	int	nb;

	nb = va_arg(ap, int);
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		*count++;
	}
	(unsigned long long)nb;
	ft_change_base(nb, print);
}
void	ft_print_address(va_list ap, int *count, t_list *print)
{
	unsigned long	addr;

	print->var_string = va_arg(ap, char *);
	addr = (unsigned long) (print->var_string);
	print->var_llong = addr;
	*count += 2;
}
