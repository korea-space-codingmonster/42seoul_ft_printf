/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namgyupark <namgyupark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:48:27 by namgyupark        #+#    #+#             */
/*   Updated: 2021/01/12 21:48:31 by namgyupark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_box   *box_create(void)
{
    t_box *tb;

    tb = malloc(sizeof(t_box));
    tb->prcs = NULL;
    tb->width = NULL;
    return (tb);
}

char    *fill_box(int prcs, char zero)
{
    char *box;

    box = malloc(sizeof(char) * (prcs + 1));
    ft_memset(box, zero, prcs);//사이즈만큼 0 채우기
    box[prcs] = '\0';//마지막 null 추가
    return (box);//box 리턴
}

void    free_box(t_box *tb)
{
    if (tb->prcs)
    {
        // printf("freed\n");
        free (tb->prcs);
    }
    if (tb->width)
    {
        //printf("freed\n");
        free (tb->width);   
    }
    free(tb);
}
