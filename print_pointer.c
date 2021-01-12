/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namgyupark <namgyupark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:49:32 by namgyupark        #+#    #+#             */
/*   Updated: 2021/01/12 21:49:35 by namgyupark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *process_precision_pointer(t_tag *tt, char *box, char *res)
{
    int res_len;

    if (res == NULL && tt->prcs != 0)
        res= "0";
    res_len = ft_strlen(res) + ft_strlen("0x");
    box = malloc(sizeof(char) * (res_len + 1));
    if (box == NULL)
        return (NULL);
    ft_strcpy(box, "0x");
    ft_strcpy(&box[2], res);
    return (box);
}

char *process_width_pointer(t_tag *tt, char *box, char *res)
{
    int res_len;

    res_len = ft_strlen(res);
    if (tt->width <= res_len)
        return (res);
    box = fill_box(tt->width, tt->padding);
    if (box == NULL)
        return (NULL);
    if (tt->left_aligned == ENABLED)
        ft_strncpy(box, res, res_len);
    else
        ft_strncpy(&box[tt->width - res_len], res, res_len);
    return (box);
}

int     print_pointer(t_tag *tt, va_list ap)
{
    char *res;
    t_box *tb;

    res = ft_lltoa_base(va_arg(ap, long long), HEX_LOW);
    tb = box_create();
    if ((res = process_precision_pointer(tt, tb->prcs, res)) == NULL 
            || (res = process_width_pointer(tt, tb->width, res)) == NULL)
    {
        free_box(tb);
        return (ERROR);
    }
    tt->nbyte += ft_putstr_n(res, ft_strlen(res));
    free_box(tb);
    return (0);
}