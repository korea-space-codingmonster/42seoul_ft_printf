/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namgyupark <namgyupark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:49:23 by namgyupark        #+#    #+#             */
/*   Updated: 2021/01/12 21:49:25 by namgyupark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *process_width_percent(t_tag *tt, char *box, char c)
{
    if (tt->width < 2)
        tt->width = 1;
    if (tt->left_aligned == DISABLED && tt->zero_fill == ENABLED)
        tt->padding = '0';
    box = fill_box(tt->width, tt->padding);
    if (box == NULL)
        return (NULL);
    if (tt->left_aligned == ENABLED)
        box[0] = c;
    else
        box[tt->width - 1] = c;
    return (box);
}

int     print_percent(t_tag *tt)
{
    char c;
    char *res;
    t_box *tb;

    c = '%';
    tb = box_create();
    if ((res = process_width_percent(tt, tb->width, c)) == NULL)
    {
        free_box(tb);
        return (ERROR);
    }
    tt->nbyte += ft_putstr_n(res, ft_strlen(res));
    free_box(tb);
    return (0);
}