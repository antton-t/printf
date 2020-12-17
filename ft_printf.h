#ifndef FT_PRINTF_H_
#define FT_PRINTF_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_list
{
	char	*var_string;
	int	var_int;
	int	zero;
	int	dot_prec;
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
void	ft_width_string(int lengh, t_list *print, int *count);
void	ft_print_char(char c, int *count);
void	ft_print_string(char *out, int *count);
void	ft_width_nbr(t_list *print, int *count, int width, int prec);
int	ft_strlen(char *str);
void	ft_check(t_list *print);
void	ft_check_width(t_list *print, int *count, int width, int prec);
void	ft_check_prec(t_list *print, int *count);
int	ft_count_size(long nb, int nbr);
void	ft_change_base(long nb, int *count, int format);
int	ft_count_nbr(int n);
void	ft_precision_string(t_list *print, int *count);
void	ft_print_address(va_list ap, int *count, t_list *print);
void	ft_print_unit(long nbr, int *count);
void	ft_print_nbr(int nbr, int *count);
void	ft_putnbr(unsigned int nbr, int *count);
void	ft_fill_print(const char **str, t_list *print, va_list ap);
int	ft_isalpha(int a);
void	ft_print_string2(t_list *print, int *count);
void	ft_check(t_list *print);
void	ft_done(t_list *print, int *count);
void	ft_print(t_list *print, int *count);

#endif
