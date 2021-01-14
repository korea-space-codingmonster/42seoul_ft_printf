/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namgyupark <namgyupark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:49:15 by namgyupark        #+#    #+#             */
/*   Updated: 2021/01/14 18:48:26 by namgyupark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*process_precision_int(t_tag *tt, char *res, char *box)
{
	int res_len;

	res_len = ft_strlen(res);
	if (res[0] == '0' && tt->prcs == 0)
		res = "";
	if (tt->prcs <= res_len)
		return (res);
	box = fill_box(tt->prcs, '0');
	if (box == NULL)
		return (NULL);
	ft_strcpy(&box[tt->prcs - res_len], res);
	return (box);
}

char		*process_width_int(t_tag *tt, char *res, char *box)
{
	int res_len;

	res_len = ft_strlen(res);
	if (tt->sign == '\0' && tt->width <= res_len)
		return (res);
	if (tt->zero_fill == ENABLED && tt->left_aligned == DISABLED &&
				tt->prcs == DISABLED)
		tt->padding = '0';
	if (tt->width < res_len)
		tt->width = res_len;
	if (tt->sign && tt->width == res_len)
		tt->width++;
	box = fill_box(tt->width, tt->padding);
	if (box == NULL)
		return (NULL);
	if (tt->left_aligned == ENABLED && tt->sign)
		ft_strncpy(box + 1, res, res_len);
	if (tt->left_aligned == ENABLED)
		ft_strncpy(box, res, res_len);
	else
		ft_strncpy(&box[tt->width - res_len], res, res_len);
	return (process_sign(box, tt, res_len));
}

int			print_int(t_tag *tt, char *res)
{
	int		i;
	t_box	*box;

	i = 0;
	box = box_create();
	res = prepare_sign(tt, res);
	if ((res = process_precision_int(tt, res, box->prcs)) == NULL ||
			(res = process_width_int(tt, res, box->width)) == NULL)
	{
		free_box(box);
		return (0);
	}
	while (res[i] != '\0')
	{
		ft_putchar(res[i]);
		i++;
		tt->nbyte++;
	}
	free_box(box);
	return (0);
}
