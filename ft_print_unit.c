#include "ft_printf.h"
void	ft_putnbr(unsigned int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}
void	ft_print_nbr(int nbr, int *count)
{
	unsigned int	nb;
	if (nbr < 0)
	{
		write(1, "-", 1);
		*count ++;
	}
	nb = (nbr < 0) ? -nbr : nbr;
	if (nb >= 10)
		ft_print_nbr(nb, count);
	*count ++;
	ft_putchar((nb% 10) + '0');
}
void	ft_print_unit(va_list ap, int *count)
{
	int	nbr;
	unsigned int	nb;

	nbr = va_arg(ap, int);
	if (nbr < 0)
	{
		nb = 4294967295 + nbr + 1;
		ft_putnbr(nb);
	}
	else
		ft_putnbr((unsigned int)nbr);
}
