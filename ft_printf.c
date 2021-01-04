#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
    int nbyte;
    va_list    ap;
    va_start(ap, format);
    if ((nbyte = process_format((char *)format, ap)) == ERROR)//format을 넘김
        return (ERROR);
    va_end(ap);
    return (nbyte);
}

int     process_format(char *format, va_list ap)
{
    t_tag *tt;

    if (!(tt = (t_tag *)malloc(sizeof(t_tag))))
        return (ERROR);

    initialize(&format, tt);

    while (*format)
    {
        while (*format != '%' && *format)
        {
            tt->nbyte = ft_putchar(*format);
            format++;
        }
        if (*format == '%')
        {
            format++;
            if ((parse_symbol(tt, ap)) != ERROR)
                return (ERROR);
        }
    }
    return (tt->nbyte);
}

void       initialize(char **format, t_tag *tt)
{
    tt->format =  format;
    tt->nbyte   =   DISABLED;
    tt->left_aligned    =   DISABLED;
    tt->width   =   DISABLED;
    tt->prcs    =   DISABLED;
    tt->zero_fill   =   DISABLED;
    tt->plus    =   DISABLED;
    tt->space   =   DISABLED;
    tt->hexa    =   DISABLED;
    tt->len_mod =   DISABLED;
    tt->padding =   ' ';
    tt->sign    =   '\0';
}

int main(void)
{
    t_tag *tt;
    ft_printf("%.*d", 10, 123);
}