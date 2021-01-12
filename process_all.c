
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
    return (print_int(tt, res));
}

int     process_char(t_tag *tt, va_list ap)
{
    wint_t w;
    char *res;
    char c;

    if (tt->len_mod == DISABLED)
    {    
        c = (char)va_arg(ap, int);
        return (print_char(tt, c));
    }
    else if (tt->len_mod == 'l')
    {
        w = (wchar_t)va_arg(ap, wint_t);
        res = ft_atouni(w);
        return (print_string(tt, res));
    }
    return (ERROR);
}

int     process_string(t_tag *tt, va_list ap)
{
    wchar_t *s;
    char *res;
    char *rs;
    int i;

    if (tt->len_mod == DISABLED)
    {
        res = va_arg(ap, char *);
        return (print_string(tt, res));
    }
    else if (tt->len_mod == 'l')
    {
        s = va_arg(ap, wchar_t *);
        res = ft_atouni(s[0]);
        i = 1;
        while (s[i] != L'\0')
        {
            rs = ft_strjoin(res, ft_atouni(s[i++]));
            res = rs;
            free(rs);
        }
        return (print_string(tt, res));
    }
    return (ERROR);
}

int     process_unsigned_int(t_tag *tt, va_list ap)
{
    char *res;

    if (tt->len_mod == DISABLED)
        res = ft_uitoa((unsigned int)va_arg(ap, int));
    else if (tt->len_mod == 'h' + 'h')
        res = ft_uitoa((unsigned char)va_arg(ap, int));
    else if (tt->len_mod == 'h')
        res = ft_uitoa((unsigned short)va_arg(ap, int));
    else if (tt->len_mod == 'l')
        res = ft_ulltoa((unsigned long)va_arg(ap, long));
    else if (tt->len_mod == 'l' + 'l')
        res = ft_ulltoa((unsigned long long)va_arg(ap, long long));
    else
        return (ERROR);
    if(res == NULL)
        return (ERROR);
    return (print_int(tt, res));
}

int     process_hexa(t_tag *tt, va_list ap, char *base, char conv)
{
    char *res;
    int i = 0;

    if (tt->len_mod == DISABLED)
        res = ft_itoa_base((int)va_arg(ap, int), base);
    else if (tt->len_mod == 'h' + 'h')
        res = ft_itoa_base((unsigned char)va_arg(ap, int), base);
    else if (tt->len_mod == 'h')
        res = ft_itoa_base((unsigned short)va_arg(ap, int), base);
    else if (tt->len_mod == 'l')
        res = ft_lltoa_base((long)va_arg(ap, long), base);
    else if (tt->len_mod == 'l' + 'l')
        res = ft_lltoa_base((long long)va_arg(ap, long long), base);
    else
        return (ERROR);
    if (res == NULL)
        return (ERROR);
    while (res[i] != '\0')
    {
        printf("[%c]", *res);
        i++;
    }
    return (print_hexa(tt, res, conv));
}