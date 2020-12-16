#include "ft_printf.h"

int	ft_isalpha(int a)
{
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
		return (1);
	return (0);
}
void	ft_check_prec(t_list *print, int *count)
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
	while (size_print < print->prec)
	{
		write(1, "0", 1);
		size_print++;
		*count += 1;
	}
}
int	ft_isdigit(int a)
{
	if (a >='0' && a <= '9')
		return (1);
	return (0);
}
void	ft_fill_print(const char **str, t_list *print, va_list ap)
{
	(*str)++;
	if (**str == '0')
		print->zero = 1;
	while (ft_isalpha(**str) == 0 && **str != '%')
	{
		if (**str == '-')
			print->negative = 1;
		if (**str == '.')
			print->dot = 1;
		if (**str == '*' && print->dot == 0)
			print->width = va_arg(ap, int);
		else if (**str == '*' && print->dot == 1)
		{
			print->prec = va_arg(ap, int);
			print->dot_prec = 1;
		}
		if (ft_isdigit(**str) == 1 && print->dot == 0)
			print->width = (print->width * 10) + ((**str) - '0');
		else if (ft_isdigit(**str) == 1 && print->dot == 1)
		{
			print->prec = (print->prec * 10) + ((**str) - '0');
			print->dot_prec = 1;
		}
		(*str)++;
	}
	ft_check(print);
	print->format = **str;
}
void	ft_check(t_list *print)
{
	
	if (print->width < 0)
	{
		print->width = -(print->width);
		print->negative = 1;
	}
	if (print->dot == 1 && print->prec < 0)
	{
		print->dot = 0;
		print->prec = 0;
	}
}
