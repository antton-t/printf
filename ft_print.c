#include "ft_printf.h"

void	ft_check_width(t_list *print, int *count, int width, int prec)
{
	int size_print;
	int dif;

	dif = width - prec;
	if (print->format == 'c')
		size_print = 1;
	else if(print->format == 'p' || print->format == 'x' || print->format == 'X')
		size_print = ft_count_size (print->var_llong, 16);
	else if (print->format == 'u')
		size_print = ft_count_size (print->var_llong, 10);
	else if (print->format == 'd' || print->format == 'i')
		size_print = ft_count_nbr (print->var_int);
	if (print->format == 'p')
		size_print += 2;
	while (size_print < print->width && dif > 0)
	{
		if (print->zero == 0)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		size_print++;
		*count++;
		dif--;
	}
}
void	ft_print(t_list *print, int *count)
{
	printf("%d negative  \n",print->negative);
	if (print->width > print->prec && print->negative == 0)
		ft_check_width(print, count, print->width, print->prec);
	ft_check_prec(print, count);
	if (print->format == 'p')
		write(1, "0x", 2);
	if (ft_check(print) == 1)
		ft_done(print, count);
	if (print->width > print->prec && print->negative == 1)
		ft_check_width(print, count, print->width, print->prec);
	free(print);
}
int	ft_check(t_list *print)
{
	return (1);
}
void	ft_done(t_list *print, int *count)
{
	if (print->format == 'd' || print->format == 'i')
		ft_print_nbr (print->var_int, count);
	else if (print->format == 'x' || print->format == 'X' || print->format == 'p')
		ft_change_base (print->var_llong, count, print->format);
	else if (print->format == 's')
		ft_print_string (print->var_string, count);	
	else if (print->format == 'c')
		ft_print_char (print->var_int, count);
	else if (print->format == 'u')
		ft_print_unit (print->var_llong, count);
}
void	ft_return_else(t_list *print, int *count)
{

}
