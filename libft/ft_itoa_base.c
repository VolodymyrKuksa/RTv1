/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:08:07 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/17 13:08:13 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_len(unsigned int nb, int base, int sign)
{
	int	n;
	int len;

	len = 0;
	if (sign == -1)
		len++;
	n = nb;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

static char	*ft_convert(unsigned int nb, int base, int sign)
{
	char	*res;
	char	*str_base;
	int		i;

	i = ft_count_len(nb, base, sign);
	str_base = ft_strdup("0123456789ABCDEF");
	res = ft_strnew(i);
	if (!res)
		return (NULL);
	if (sign == -1)
		res[0] = '-';
	while (nb)
	{
		res[--i] = str_base[nb % base];
		nb /= base;
	}
	return (res);
}

char		*ft_itoa_base(int value, int base)
{
	int				sign;
	unsigned int	nb;

	if (!value || !base)
		return (NULL);
	sign = 0;
	(base == 10 && value < 0) ? sign-- : sign++;
	if (value < 0)
		nb = -value;
	else
		nb = value;
	return (ft_convert(nb, base, sign));
}
