#include "ft_printf.h"

void	ft_check_width(t_list *print, int *count)
{
	int size_print;

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
	printf("%d size print \n",size_print);
	while (size_print < print->width && print->negative == 0)
	{
		write(1, " ", 1);
		size_print++;
	}
}
void	ft_print(t_list *print, int *count)
{
	ft_check_width(print, count);
	if (print->format == 'p')
		write(1, "0x", 2);
	if (ft_check(print) == 1)
		ft_done(print, count);
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
