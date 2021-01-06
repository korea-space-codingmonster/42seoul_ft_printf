
#include "ft_printf.h"
//정수를 char형으로 바꾸기
int     process_int(t_tag *tt, va_list ap)
{
    char *res;

    if (tt->len_mod == DISABLED)
        res = ft_itoa((int)va_arg(ap, int));//정수 반환
    else if (tt->len_mod == 'h' + 'h')
        res = ft_itoa((char)va_arg(ap, int));
    else if (tt->len_mod == 'h')
        res = ft_itoa((short)va_arg(ap, int));
    else if (tt->len_mod == 'l')
        res = ft_lltoa((long)va_arg(ap, long));
    else if (tt->len_mod == 'l' + 'l')
        res = ft_lltoa((long long)va_arg(ap, long long));
    else
        return (ERROR);
    if (res == NULL)
        return (ERROR);//itoa->%s
    return (print_int(tt, ap, res));
}
