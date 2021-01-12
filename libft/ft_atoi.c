/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namgyupark <namgyupark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 00:34:37 by mihykim           #+#    #+#             */
/*   Updated: 2021/01/11 04:55:41 by namgyupark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int atoi;
	int sign;

	sign = 1;
	while (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -sign : sign;
		str++;
	}
	atoi = 0;
	if (!is_set(*str, DIGIT))
		return (0);
	while (*str >= '0' && *str <= '9')//str = 13
	{
		atoi = atoi * 10 + (*str - '0');
		str++;
	}
	return (atoi * sign);
}
