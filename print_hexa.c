/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namgyupark <namgyupark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:49:08 by namgyupark        #+#    #+#             */
/*   Updated: 2021/01/14 18:45:54 by namgyupark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*process_precision_hexa(t_tag *tt, char *box, char *res)
{
	int		res_len;

	res_len = ft_strlen(res);
	if (tt->prcs >= 0)
		tt->zero_fill = DISABLED;
	if (res[0] == '0')
		tt->hexa = H_DISABLED;
	if (res[0] == '0' && tt->prcs == '0')
		return (res = "");
	if (tt->prcs < res_len)
		return (res);
	box = fill_box(tt->prcs, '0');
	if (box == NULL)
		return (NULL);
	ft_strcpy(&box[tt->prcs - res_len], res);
	return (box);
}

void		process_pound(t_tag *tt, char *box, char conv, int res_len)
{
	char	hexa[3];

	hexa[0] = '0';
	hexa[1] = conv;
	hexa[2] = '\0';
	if (tt->hexa == H_DISABLED)
		return ;
	if (tt->left_aligned == ENABLED || tt->zero_fill == ENABLED)
		ft_strncpy(box, hexa, 2);
	else
		ft_strncpy(&box[tt->width - res_len - 2], hexa, 2);
}

char		*process_width_hexa(t_tag *tt, char *box, char *res, char conv)
{
	int res_len;

	res_len = ft_strlen(res);
	if (tt->width <= res_len && !tt->hexa)
		return (res);
	else if (tt->width < res_len + tt->hexa)
		tt->width = res_len + tt->hexa;
	if (tt->zero_fill == ENABLED && tt->prcs == DISABLED)
		tt->padding = '0';
	box = fill_box(tt->width, tt->padding);
	if (box == NULL)
		return (NULL);
	process_pound(tt, box, conv, res_len);
	if (tt->left_aligned == ENABLED)
		ft_strncpy(&box[0 + tt->hexa], res, res_len);
	else
		ft_strncpy(&box[tt->width - res_len], res, res_len);
	return (box);
}

int			print_hexa(t_tag *tt, char *res, char conv)
{
	t_box *tb;

	tb = box_create();
	if ((res = process_precision_hexa(tt, tb->prcs, res)) == NULL
			|| (res = process_width_hexa(tt, tb->width, res, conv)) == NULL)
	{
		free_box(tb);
		return (ERROR);
	}
	tt->nbyte += ft_putstr_n(res, ft_strlen(res));
	free_box(tb);
	return (0);
}
