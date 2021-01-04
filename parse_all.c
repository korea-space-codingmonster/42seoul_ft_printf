#include "ft_printf.h"


int     parse_symbol(t_tag *tt, va_list ap)
{
    char **format;

    format = tt->format;
    if (!*format)
    {
        free(tt);
        return (0);
    }
    if ((ft_strchr(FLAG, **format)))
        parse_flag(tt, ap);
    if ((ft_strchr(DIGIT, **format)))
        parse_width(tt, ap);
    if ((ft_strchr(".", **format)))
        parse_precision(tt, ap);
    if ((ft_strchr(LEN_MODIFIER, **format)))
        parse_len_modifier(tt, ap);
    
    printf("%d\n",tt->left_aligned);
    printf("%d\n",tt->width);
    printf("%d\n",tt->prcs);
    return (0);
}

void     parse_flag(t_tag *tt, va_list ap)
{
    char **format;
    format = tt->format;
    while (is_set(**format, FLAG))
    {
        **format == '-' ? tt->left_aligned = ENABLED : SKIP;
		**format == '0' ? tt->zero_fill = ENABLED : SKIP;
		**format == '+' ? tt->plus = ENABLED : SKIP;
		**format == ' ' ? tt->space = ENABLED : SKIP;
		**format == '#' ? tt->hexa = H_ENABLED : SKIP;
		(*format)++;
    }
    tt->format = format;
}

void     parse_width(t_tag *tt, va_list ap)
{
    char *dup;
    char **format;

    format = tt->format;
    if (!(**format == '*' || is_set(**format, DIGIT)))
        return ;
    if (**format == '*')
    {
        tt->width = va_arg(ap, int);
        (*format)++;
    }
    else
    {
        dup = ft_strndup(*format, ft_strlen(*format));
        tt->width = ft_atoi(dup);
        free(dup);
        while (is_set(**format, DIGIT))
            (*tt->format)++;
    }
    if (tt->width < 0)
    {
        tt->left_aligned = ENABLED;
        tt->width = -(tt->width);
    }
    tt->format = format;
}

void    parse_precision(t_tag *tt, va_list ap)
{
    char *dup;
    char **format;
    
    format = tt->format;

    if (**format != '.')
        return ;
    (*format)++;
    if (**format == '*')//printf("[%.*d]", 10,1234);
    {
        tt->prcs = va_arg(ap, int);
        (*format)++;
    }
    else if (is_set(**format, DIGIT))
    {
        dup = ft_strndup(*format, ft_strlen(*format));
        tt->prcs = ft_atoi(dup);
        free(dup);
        while (is_set(**format, DIGIT))
        {
            (*format)++;
        }
    }
    else
    {
        tt->prcs = 0;
    }
    if (tt->prcs < 0)
    {
        tt->prcs = DISABLED;
    }
    tt->format = format;
}

void    parse_len_modifier(t_tag *tt, va_list ap)
{
    char **format;
    
    format = tt->format;
    if (!(is_set(**format, LEN_MODIFIER)))
        return ;
    if ()
}