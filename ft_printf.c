#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int	count;
	va_list	ap;

	va_start(ap, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
			ft_parse(ap, &str, &count);
		else
		{
			write (1, str, 1);
			count++;
		}
		*str++;
	}
	va_end(ap);
	return (count);
}
