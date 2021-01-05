#include "ft_printf.h"

int     process_int(t_tag *tt, va_list ap)
{
    char *res;

    if (tt->len_mod == DISABLED)
        res = ft_itoa(va_arg(ap, int)); 
    if (tt->len_mod = 'h' + 'h')
        res = ft_itoa((char)va_arg(ap, int));
    if (tt->len_mod = 'h')
        res = ft_itoa((short)va_arg(ap, int));
    if (tt->len_mod = 'l')
        res = ft_lltoa((long)va_arg(ap, long));
    if (tt->len_mod = 'l' + 'l')
        res = ft_lltoa((long long)va_arg(ap, long long));
    else
        return (ERROR);
    if (res == NULL)
        return (ERROR);
    return (print_int(tt, ap, res));
}