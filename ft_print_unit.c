#include "ft_printf.h"
void	ft_putnbr(unsigned int nbr, int *count)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10, count);
	*count+= 1;
	ft_putchar(nbr % 10 + '0');
}
int    ft_count_nbr(int n)
{
	int	count;
	unsigned int	nb;

	count = 0;
	if (n < 0)
	{
		nb = (unsigned int) -n;
		count++;
	}
	else
		nb = (unsigned int) n;
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}
void    ft_print_nbr(int n, int *count)
{
        unsigned int    nb;

        if (n < 0)
        {
                nb = (unsigned int)n * (-1);
                write(1, "-", 1);
		*count += 1;
        }
        else
                nb = (unsigned int)n;
        if (nb >= 10)
                ft_print_nbr(nb / 10, count);
        *count += 1;
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

void	ft_width_nbr(t_list *print, int *count, int width, int prec)
{
	int size_print;
	int dif;

	dif = width - prec;
	if (print->format == 'u')
		size_print = ft_count_size (print->var_llong, 10);
	else
		size_print = ft_count_nbr (print->var_int);
	while (size_print < print->width && dif > 0)
	{
		if (print->dot == 1)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		size_print++;
		*count += 1;
		dif--;
	}
}
