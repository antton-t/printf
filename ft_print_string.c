#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
void	ft_print_string(va_list ap, int *count)
{
	char	*out;

	out = va_arg(ap, char*);
	write(1, out, ft_strlen(out));
	count = count + ft_strlen(out);
}
