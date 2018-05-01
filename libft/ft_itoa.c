/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:19:44 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/08 13:45:28 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	comp(int n, int sign, int d, char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		if (sign == -1)
			str[i++] = '-';
		while (d >= 1)
		{
			str[i++] = '0' + n / d;
			n %= d;
			d /= 10;
		}
	}
}

char		*ft_itoa(int n)
{
	int		i;
	int		d;
	int		sign;
	char	*str;

	i = 0;
	d = 1;
	sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = -1;
		n *= -1;
		i++;
	}
	while (n / d > 9)
	{
		d *= 10;
		i++;
	}
	str = ft_strnew(i + 1);
	comp(n, sign, d, str);
	return (str);
}
