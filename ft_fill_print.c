#include "ft_printf.h"

int	ft_isalpha(int a)
{
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
		return (1);
	return (0);
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
	while (ft_isalpha(**str) == 0 && **str != '%')
	{
		if (**str == '-')
			print->negative = 1;
		if (**str == '.')
			print->dot = 1;
		if (**str == '*' && print->dot == 0)
			print->width = va_arg(ap, int);
		else if (**str == '*' && print->dot == 1)
			print->prec = va_arg(ap, int);
		if (ft_isdigit(**str) == 1 && print->dot == 0)
			print->width = (print->width * 10) + ((**str) - '0');
		else if (ft_isdigit(**str) == 1 && print->dot == 1)
			print->prec = (print->prec * 10) + ((**str) - '0');
		(*str)++;
	}
	printf("%d -> width\n",print->width);
	printf("%d -> prec\n",print->prec);
	print->format = **str;
}
