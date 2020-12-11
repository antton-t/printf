#ifndef FT_PRINTF_H_
#define FT_PRINTF_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_list
{
	char	*var_string;
	int	var_int;
	long	var_llong;
	int	negative;
	char	format;
	int	dot;
	int	prec;
	int	width;
}	t_list;

t_list	*ft_initialise(void);
int	ft_printf(const char *str, ...);
void	ft_parse(va_list ap, const char **str, int *count);
int	ft_isdigit(int a);
void	ft_putchar(char c);
void	ft_print_char(char c, int *count);
void	ft_print_string(char *out, int *count);
size_t	ft_strlen(char *str);
void	ft_change_base(long nb, int *count, int format);
void	ft_print_address(va_list ap, int *count, t_list *print);
void	ft_print_unit(long nbr, int *count);
void	ft_print_nbr(int nbr, int *count);
void	ft_putnbr(unsigned int nbr, int *count);
void	ft_fill_print(const char **str, t_list *print, va_list ap);
int	ft_isalpha(int a);
int	ft_check(t_list *print);
void	ft_done(t_list *print, int *count);
void	ft_return_else(t_list *print, int *count);
void	ft_print(t_list *print, int *count);

#endif
