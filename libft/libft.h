/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:07:45 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 23:07:59 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <stdarg.h>
# include <math.h>
# define BUFF_SIZE  1

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_format
{
	int		padding;
	int		leftjustify;
	int		sign;
	int		hash;
	int		space;
	int		width;
	int		isprecised;
	int		precision;
	char	modifer;
	char	specifier;
}				t_format;

typedef struct	s_point
{
	int n1;
	int	n2;
}				t_point;

typedef struct	s_man
{
	char	*nbr;
	char	*man;
	int		exp;
	int		pos;
}				t_man;

typedef struct	s_mult
{
	t_point	len;
	t_point	i;
	int		m;
	int		carry;
	t_point nbr;
}				t_mult;

typedef union	u_float
{
	double		f;
	struct		s_comp
	{
		unsigned long int	mantissa	: 52;
		unsigned long int	exponent	: 11;
		unsigned int		sign		: 1;
	}			t_comp;
}				t_float;

typedef union	u_long_float
{
	long double	f;
	struct		s_lcomp
	{
		unsigned long int	mantissa	: 63;
		unsigned int		int_part	: 1;
		unsigned long int	exponent	: 15;
		unsigned int		sign		: 1;
	}			t_comp;
}				t_long_float;

typedef struct        s_gnl
{
    char            buff[BUFF_SIZE + 1];
    int                c;
    int                p;
}                    t_gnl;

int				get_next_line(const int fd, char **line);
int				ft_isspace(int c);
int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_strpos(char *s1, char *s2);
size_t			ft_strlen(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int ch);
char			*ft_strrchr(const char *s, int ch);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack,
				const char *needle, size_t len);
char			*ft_strrev(char *s);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_itoa(long long int n);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			**ft_strsplit(char const *s, char c);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_strindex(const char *s, int ch);

t_format		ft_get_format(char *str);
int				ft_printf(const char *format, ...);
int				ft_format(char *str, va_list args);
int				ft_print_params(va_list args, t_format format);

void			ft_prefixfixer(char *str);
void			ft_initialise(t_format *format);
void			ft_get_flags(char *str, t_format *f);
void			ft_get_width(char *str, t_format *format);
void			ft_get_padding(char *str, t_format *format);
void			ft_get_modifier(char *str, t_format *format);
void			ft_get_precision(char *str, t_format *format);

int				is_specifier(char c);
int				ft_itoa_base_count(unsigned long int nb, unsigned int base);
char			*ft_itoa_base(unsigned long int nb, unsigned int base);

char			*ft_fix_sign(char *number);
char			*ft_fix_space(char *number);
char			*ft_sign(char *number, t_format format);
int				ft_print_int(long long int nbr, t_format format);
char			*ft_precise_int(char *number, long long int nbr,
				t_format format);

char			*ft_precise_hex(char *number, int precision);
char			*ft_resize_hex(char *number, int width, t_format format);
void			ft_cptoend(char *src, char *dest, int slen, int dlen);
void			ft_cptostart(char *src, char *dest, int slen);

int				ft_convert_id(va_list args, t_format format);
int				ft_print_char(va_list args, t_format format);
int				ft_convert_oux(va_list args, t_format format);
int				ft_print_string(va_list args, t_format format);
int				ft_print_pointer(va_list args, t_format format);

void			ft_fix_prefix(char *str);
int				ft_printhex_getlen(char *str);
int				ft_print_hexa(unsigned long long int nbr, t_format format);
char			*ft_setup_hex(unsigned long long int nbr, t_format format);

int				ft_print_octal(unsigned long long int nbr, t_format format);
char			*ft_setup_octal(unsigned long long int nbr, t_format format);
char			*ft_add_prefix_o(char *str);

int				ft_print_unsigned(unsigned long long int nbr, t_format format);
char			*ft_setup_unsigned(unsigned long long int nbr, t_format format);

char			*ft_add_prefix(char *str, int len);
char			*ft_resize(int width, char zeropad);
char			*ft_precise(char *str, int precision);
char			*ft_str_toupper(char *str, char specifer);
char			*ft_reform(char *src, char*dest, int position);
char			*ft_putatstart(char *src, char *dest, int lsrc, int ldest);
char			*ft_putatend(char *src, char *dest, int lsrc, int ldest);

char			*add(char *nbr1, char *nbr2);
char			*multiply(char *nbr1, char *nbr2);
char			*ft_power(char *nbr, int pow);
int				ft_swap_rev(char **str1, char **str2, t_point *l);
int				ft_swap(char **str1, char **str2, t_point *l);
char			*ft_rm_zeros(char *res);
int				add_zeros(t_man *man, t_format format);

void			ft_double_print(t_float f, t_man *m, t_format format);
void			ft_ldouble_print(t_long_float f, t_man *m, t_format format);
void			ft_fix_float(t_man *man, t_format format);
void			ft_rounding(t_man *m, t_format *f, int exp_pow, int l);

int				ft_print_f(double nbr, t_format format);
int				ft_print_lf(long double nbr, t_format format);
int				ft_convert_double(va_list args, t_format format);
int				add_zeros(t_man *man, t_format format);
void			ft_print_re(char *ret, int *len);

#endif
