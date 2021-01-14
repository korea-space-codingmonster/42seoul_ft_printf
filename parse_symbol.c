/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_symbol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namgyupark <namgyupark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:34:03 by namgyupark        #+#    #+#             */
/*   Updated: 2021/01/14 18:35:42 by namgyupark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_symbol(t_tag *tt, va_list ap)
{
	char **format;

	format = tt->format;
	if (!*format)
	{
		free(tt);
		return (0);
	}
	if ((ft_strchr(FLAG, **format)))
		parse_flag(tt);
	if ((ft_strchr(DIGIT, **format)))
		parse_width(tt, ap);
	if ((ft_strchr(".", **format)))
		parse_precision(tt, ap);
	if ((ft_strchr(LEN_MODIFIER, **format)))
		parse_len_modifier(tt);
	if ((ft_strchr(CONVERSION, **format)))
		parse_conversion(tt);
	return (0);
}
