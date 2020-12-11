#include "ft_printf.h"
void	ft_putnbr(unsigned int nbr, int *count)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10, count);
	*count++;
	ft_putchar(nbr % 10 + '0');
}
void    ft_print_nbr(int n, int *count)
{
        unsigned int    nb;

        if (n < 0)
        {
                nb = (unsigned int)n * (-1);
                write(1, "-", 1);
		*count++;
        }
        else
                nb = (unsigned int)n;
        if (nb >= 10)
                ft_print_nbr(nb / 10, count);
        *count++;
	ft_putchar(nb % 10 + '0');
}
void	ft_print_unit(long nbr, int *count)
{
	if (nbr < 0)
	{
		nbr = 4294967295 + nbr + 1;
		ft_putnbr((unsigned int)nbr, count);
	}
	else
		ft_putnbr((unsigned int)nbr, count);
}
