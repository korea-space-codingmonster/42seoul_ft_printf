#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <wchar.h>
# include "libft/libft.h"

# define FLAG "-+ 0#"
# define LEN_MODIFIER "hl"
# define CONVERSION "cspdiuxXn%"

# define DIGIT "0123456789"
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

# define H_ENABLED 2
# define H_DISABLED 0
# define ENABLED 1
# define DISABLED -1
# define ERROR -1
# define UNDEFINED_BEHAVIOR -1
# define EQUAL 0
# define SKIP 0

typedef struct	s_tag
{
    char    **format;
	int		nbyte;
	int		left_aligned;
	int		width;
	int		prcs;
	int		zero_fill;
	int		plus;
	int		space;
	int		hexa;
	int		len_mod;
	char	padding;
	char	sign;
	int		conversion;
}				t_tag;

typedef struct	s_box
{
	char *prcs;
	char *width;
}				t_box;


/*********************  ft_printf ***********************/
int     ft_printf(const char *format, ...);
int     process_format(char *format, va_list ap);
void     parse_flag(t_tag *tt, va_list ap);
void       initialize(char **format, t_tag *tt);
int     write_on_condition(t_tag *tt, va_list ap);

/********************* process_all *********************/
int     process_int(t_tag *tt, va_list ap);


/********************* parse_all ***********************/
int     parse_symbol(t_tag *tt, va_list ap);
void     parse_width(t_tag *tt, va_list ap);
void    parse_precision(t_tag *tt, va_list ap);
void     parse_len_modifier(t_tag *tt, va_list ap);
int     parse_conversion(t_tag *tt, va_list ap);

/********************* prepare_sign *******************/
char    *prepare_sign(t_tag *tt, char *res);
char    *process_sign(char *box, t_tag *tt, int res_len);

/********************* print_int **********************/
int     print_int(t_tag *tt, va_list ap, char *res);
char     *process_precision(t_tag *tt, char *res, char *box);
char    *process_width(t_tag *tt, char *res, char *box);


/******************** manage_box **********************/
t_box   *box_create(void);
char    *fill_box(int prc_count, char zero);
void    free_box(t_box *tb);



/******************** process_all *********************/
int     process_int(t_tag *tt, va_list ap);

#endif