/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namgyupark <namgyupark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 23:15:07 by mihykim           #+#    #+#             */
/*   Updated: 2021/01/12 17:28:46 by namgyupark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned int n, const char *base)
{// n = 12, base = 0123456789abcdef
	unsigned int	div;
	unsigned int	len;
	unsigned int	base_len;
	char			*res;

	div = n;//127
	len = (n == 0) ? 1 : 0;//0
	base_len = (unsigned int)ft_strlen((char *)base);//16
	while (div != 0)
	{
		div = div / base_len;// 12/16
		len++;//1,2,3
	}
	//if (!(res = malloc(sizeof(char) * (len + 1))))
	//	return (NULL);
	if (!(res = calloc((len + 1), sizeof(char))))
		return (NULL);
	res[0] = '0';
	while (n != 0)
	{
		len--;//2->1
		res[len] = base[(n % base_len)];//res[2] = base[127%16 = 15], res[1] = base[7%16 = 0]
		n = n / base_len;//127/16 = 7
	}
	return (res);
}
