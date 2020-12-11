#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
void	ft_print_string(char *out, int *count)
{
	write(1, out, ft_strlen(out));
	*count = *count + ft_strlen(out);
}
