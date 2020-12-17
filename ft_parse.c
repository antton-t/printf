#include "ft_printf.h"

t_list	*ft_initialise(void)
{
	t_list	*out;

	if (!(out = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	out->negative = 0;
	out->format = 0;
	out->width = 0;
	out->dot_prec = 0;
	out->dot = 0;
	out->prec = 0;
	out->zero = 0;
	return (out);
}
void	ft_parse(va_list ap, const char **str, int *count)
{
	t_list	*print;

	print = ft_initialise();
	ft_fill_print(str, print, ap);
	if (print->format == 'p')
		ft_print_address(ap, count, print);
	else if (print->format == 's')
		print->var_string = va_arg(ap, char *);
	else if (print->format == 'x' || print->format == 'X' || print->format == 'u')
		print->var_llong = va_arg(ap,int);
	else if (print->format == 'c' || print->format == 'd' || print->format == 'i')
		print->var_int = va_arg(ap, int);
	else if (print->format == 's' && print->var_string == NULL)
		print->var_string = "(null)";
	if (print->format == 's')
		ft_print_string2 (print, count);
	else
		ft_print (print, count);
}
