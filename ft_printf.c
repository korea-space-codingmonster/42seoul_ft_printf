/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namgyupark <namgyupark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:48:16 by namgyupark        #+#    #+#             */
/*   Updated: 2021/01/12 21:48:19 by namgyupark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
            if ((parse_symbol(tt, ap)) == ERROR)
                return (ERROR);
            if ((write_on_condition(tt, ap)) == ERROR)
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
    tt->conversion = DISABLED;
    tt->padding =   ' ';
    tt->sign    =   '\0';
}

int     write_on_condition(t_tag *tt, va_list ap)
{
    if (tt->conversion == 'd' || tt->conversion == 'i')
        return (process_int(tt, ap));
    if (tt->conversion == 'c')
        return (process_char(tt, ap));
    if (tt->conversion == 's')
        return (process_string(tt, ap));
    if (tt->conversion == 'u')
        return (process_unsigned_int(tt, ap));
    if (tt->conversion == 'x')
        return (process_hexa(tt, ap, HEX_LOW, 'x'));
    if (tt->conversion == 'X')
        return (process_hexa(tt, ap, HEX_UP, 'X'));
    if (tt->conversion == 'p')
        return (print_pointer(tt, ap));
    if (tt->conversion == '%')
        return (print_percent(tt));
    if (tt->conversion == 'n')
        return (store_nbyte(tt, ap));
    else 
        return (ERROR);
}
