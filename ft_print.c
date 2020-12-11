#include "ft_printf.h"

void	ft_print(t_list *print, int *count)
{
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
	if (print->format == 'x' || print->format == 'X' || print->format == 'p')
		ft_change_base (print->var_llong, count, print->format);
	if (print->format == 's')
		ft_print_string (print->var_string, count);	
	if (print->format == 'c')
		ft_print_char (print->var_int, count);
	if (print->format == 'u')
		ft_print_unit (print->var_llong, count);
}
void	ft_return_else(t_list *print, int *count)
{

}
