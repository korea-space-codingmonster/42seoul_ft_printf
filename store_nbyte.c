/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_nbyte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namgyupark <namgyupark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:50:00 by namgyupark        #+#    #+#             */
/*   Updated: 2021/01/12 21:50:06 by namgyupark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    store_nbyte_hh(t_tag *tt, va_list ap)
{
    signed char *ptr;
    ptr = (signed char *)va_arg(ap, int *);
    *ptr = tt->nbyte;
}

void    store_nbyte_h(t_tag *tt, va_list ap)
{
    short int   *ptr;

    ptr = (short int *)va_arg(ap, int *);
    *ptr = tt->nbyte;
}

void    store_nbyte_l(t_tag *tt, va_list ap)
{
    long *ptr;
    ptr = (long *)va_arg(ap, long *);
    *ptr = tt->nbyte;
}

void    store_nbyte_ll(t_tag *tt, va_list ap)
{
    long long *ptr;

    ptr = (long long *)va_arg(ap, long long *);
    *ptr = tt->nbyte;
}

int     store_nbyte(t_tag *tt, va_list ap)
{
    int *ptr;

    if (tt->len_mod == DISABLED)
    {
        ptr = (int *)va_arg(ap, int *);
        *ptr = tt->nbyte;
    }
    else if (tt->len_mod == 'h' + 'h')
        store_nbyte_hh(tt, ap);
    else if (tt->len_mod == 'h')
        store_nbyte_h(tt, ap);
    else if (tt->len_mod == 'l')
        store_nbyte_l(tt, ap);
    else if (tt->len_mod == 'l' + 'l')
        store_nbyte_ll(tt, ap);
    else
        return (ERROR);
    return (0);
}