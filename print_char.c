/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namgyupark <namgyupark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:48:57 by namgyupark        #+#    #+#             */
/*   Updated: 2021/01/12 21:49:00 by namgyupark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char     *process_width_char(t_tag *tt, char *box)
{
    if (tt->width < 1)
        return ("");
    box = fill_box(tt->width, tt->padding);
    if (box == NULL)
        return (NULL);
    return (box);
}

int     print_char(t_tag *tt, char c)//res = char
{
    char *res;
    t_box *box;
    int i;

    i = 0;
    box = box_create();
    if (tt->prcs > 0)//printf("%.4c". "a");
        return (UNDEFINED_BEHAVIOR);
    if ((res = process_width_char(tt, box->width)) == NULL)
    {
        free_box(box);
        return (ERROR);
    }
    if (tt->left_aligned == ENABLED)
        tt->nbyte += ft_putchar(c) + ft_putstr(res);
    else
        tt->nbyte += ft_putstr(res) + ft_putchar(c);
    free_box(box);
    return (0);
}
