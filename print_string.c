/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namgyupark <namgyupark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:49:42 by namgyupark        #+#    #+#             */
/*   Updated: 2021/01/12 21:49:48 by namgyupark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *process_precision_string(t_tag *tt, char *box, char *res)
{
    if (tt->prcs == DISABLED ||
			(tt->prcs != 0 && tt->prcs >= ft_strlen(res)))
        return (res);
    box = malloc(sizeof(char) * (tt->prcs + 1));
    if (box == NULL)
        return (NULL);
    ft_strncpy(box, res, tt->prcs);
    box[tt->prcs] = '\0';
    return (box);
}

char    *process_width_string(t_tag *tt, char *box, char *res)
{
    int res_len;

    res_len = ft_strlen(res);
    if (tt->width < res_len)
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

int     print_string(t_tag *tt, char *res)
{
    t_box *box;
    int     flag;

    flag = DISABLED;
    if (res == NULL)
    {
        res = ft_strndup("(null)", 6);
        flag = ENABLED;
    }
    box = box_create();
    if ((res = process_precision_string(tt, box->prcs, res)) == NULL
            || (res = process_width_string(tt, box->width, res)) == NULL)
    {
        free_box(box);
        return (ERROR);
    }
    tt->nbyte += ft_putstr_n(res, ft_strlen(res));
    free_box(box);
    if (flag == ENABLED)
        free(res);
    return (0);
}
//res = unsigned char
//box메모리 설정 -> box안에 unsigned char string