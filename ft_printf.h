/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namgyupark <namgyupark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:28:21 by namgyupark        #+#    #+#             */
/*   Updated: 2021/01/14 18:29:49 by namgyupark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	**format;
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

int				ft_printf(const char *format, ...);
int				process_format(char *format, va_list ap);
void			initialize(char **format, t_tag *tt);
int				write_on_condition(t_tag *tt, va_list ap);

int				parse_symbol(t_tag *tt, va_list ap);
void			parse_flag(t_tag *tt);
void			parse_width(t_tag *tt, va_list ap);
void			par_prec(t_tag *tt, va_list ap);
void			parse_len_modifier(t_tag *tt);
int				parse_conversion(t_tag *tt);

int				process_int(t_tag *tt, va_list ap);
int				process_char(t_tag *tt, va_list ap);
int				process_string(t_tag *tt, va_list ap);
int				process_unsigned_int(t_tag *tt, va_list ap);
int				process_hexa(t_tag *tt, va_list ap, char *base, char conv);

t_box			*box_create(void);
char			*fill_box(int prcs, char zero);
void			free_box(t_box *tb);

char			*prepare_sign(t_tag *tt, char *res);
char			*process_sign(char *box, t_tag *tt, int res_len);

int				print_char(t_tag *tt, char c);
char			*process_width_char(t_tag *tt, char *box);

int				print_int(t_tag *tt, char *res);
char			*process_width_int(t_tag *tt, char *res, char *box);
char			*process_precision_int(t_tag *tt, char *res, char *box);

int				print_string(t_tag *tt, char *res);
char			*process_width_string(t_tag *tt, char *box, char *res);
char			*process_precision_string(t_tag *tt, char *box, char *res);

int				print_hexa(t_tag *tt, char *res, char conv);
char			*process_width_hexa(t_tag *tt, char *box, char *res, char conv);
void			process_pound(t_tag *tt, char *box, char conv, int res_len);
char			*process_precision_hexa(t_tag *tt, char *box, char *res);

int				print_pointer(t_tag *tt, va_list ap);
char			*process_width_pointer(t_tag *tt, char *box, char *res);
char			*process_precision_pointer(t_tag *tt, char *box, char *res);

int				print_percent(t_tag *tt);
char			*process_width_percent(t_tag *tt, char *box, char c);

int				store_nbyte(t_tag *tt, va_list ap);
void			store_nbyte_ll(t_tag *tt, va_list ap);
void			store_nbyte_l(t_tag *tt, va_list ap);
void			store_nbyte_h(t_tag *tt, va_list ap);
void			store_nbyte_hh(t_tag *tt, va_list ap);

#endif
