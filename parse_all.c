/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namgyupark <namgyupark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:48:38 by namgyupark        #+#    #+#             */
/*   Updated: 2021/01/14 18:35:11 by namgyupark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_flag(t_tag *tt)
{
	char **format;

	format = tt->format;
	while (is_set(**format, FLAG))
	{
		**format == '-' ? tt->left_aligned = ENABLED : SKIP;
		**format == '0' ? tt->zero_fill = ENABLED : SKIP;
		**format == '+' ? tt->plus = ENABLED : SKIP;
		**format == ' ' ? tt->space = ENABLED : SKIP;
		**format == '#' ? tt->hexa = H_ENABLED : SKIP;
		(*format)++;
	}
	tt->format = format;
}

void		parse_width(t_tag *tt, va_list ap)
{
	char *dup;
	char **format;

	format = tt->format;
	if (!(**format == '*' || is_set(**format, DIGIT)))
		return ;
	if (**format == '*')
	{
		tt->width = va_arg(ap, int);
		(*format)++;
	}
	else
	{
		dup = ft_strndup(*format, ft_strlen(*format));
		tt->width = ft_atoi(dup);
		free(dup);
		while (is_set(**format, DIGIT))
			(*tt->format)++;
	}
	if (tt->width < 0)
	{
		tt->left_aligned = ENABLED;
		tt->width = -(tt->width);
	}
	tt->format = format;
}

void		parse_precision(t_tag *tt, va_list ap)
{
	char *dup;
	char **format;

	format = tt->format;
	if (**format != '.')
		return ;
	(*format)++;
	if (**format == '*')
	{
		tt->prcs = va_arg(ap, int);
		(*format)++;
	}
	else if (is_set(**format, DIGIT))
	{
		dup = ft_strndup(*format, ft_strlen(*format));
		tt->prcs = ft_atoi(dup);
		free(dup);
		while (is_set(**format, DIGIT))
			(*format)++;
	}
	else
		tt->prcs = 0;
	if (tt->prcs < 0)
		tt->prcs = DISABLED;
	tt->format = format;
}

void		parse_len_modifier(t_tag *tt)
{
	char **format;

	format = tt->format;
	if ((is_set(**format, LEN_MODIFIER)) == FALSE)
		return ;
	tt->len_mod += ENABLED;
	while (is_set(**format, LEN_MODIFIER))
	{
		tt->len_mod += **format;
		(*format)++;
	}
	tt->format = format;
}

int			parse_conversion(t_tag *tt)
{
	char **format;

	format = tt->format;
	if ((is_set(**format, CONVERSION)) == FALSE)
		return (0);
	tt->conversion += ENABLED;
	while (is_set(**format, CONVERSION))
	{
		tt->conversion += **format;
		(*format)++;
	}
	tt->format = format;
	return (0);
}
