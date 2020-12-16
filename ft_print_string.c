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

void	ft_precision_string(t_list *print, int *count)
{
	int		i;
	char	*str;

	i = 0;
	str = print->var_string;
	if (ft_strlen(str) > print->prec && print->dot_prec == 1)
	{
		while (i < print->prec)
		{
			ft_putchar(str[i]);
			i++;
			*count += 1;
		}
	}
	else if (print->prec == 0 && print->width == 0 && print->dot == 1)
		;
	else
		ft_print_string(str, count);
}

void	ft_print_string2(t_list *print, int *count)
{
	int lengh;

	lengh = ft_strlen(print->var_string);
	if (print->width > lengh && print->negative == 0)
		ft_width_string(lengh, print, count);
	ft_precision_string(print, count);
	if (print->width > lengh && print->negative == 1)
		ft_width_string(lengh, print, count);
}

void	ft_width_string(int lengh, t_list *print, int *count)
{
	if (print->zero == 0)
	{
		while (print->width > lengh)
		{
			write(1, " ", 1);
			lengh++;
			*count += 1;
		}
	}
	else
	{
		while (print->width > lengh)
		{
			write(1, "0", 1);
			lengh++;
			*count += 1;
		}
	}
}
