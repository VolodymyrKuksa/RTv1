/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:32:20 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/16 13:32:22 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*ft_convert(const char *s, int str_base)
{
	char	*lbase;
	char	*ubase;
	int		*tab;
	int		i;
	int		j;

	lbase = "0123456789abcdef";
	ubase = "0123456789ABCDEF";
	tab = (int *)malloc(sizeof(int) * ft_strlen(s));
	if (!lbase || !ubase || !tab)
		return ((int *)NULL);
	i = 0;
	while (i < (int)ft_strlen(s))
	{
		j = 0;
		while (lbase[j] != s[i] && ubase[j] != s[i] && ubase[j])
			j++;
		if (j < str_base)
			tab[i++] = j;
		else
			return ((int *)NULL);
	}
	return (tab);
}

static int	ft_count(int *tab, int i, int str_base, int sign)
{
	int		nb;
	int		base;

	nb = 0;
	base = 1;
	while (i >= 0)
	{
		nb = nb + (tab[i--] * base);
		if (nb < 0)
			if (nb != -2147483648 || sign != -1 || i != -1)
				return ((int)NULL);
		base *= str_base;
	}
	free(tab);
	return (nb);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int		*tab;
	int		sign;
	char	*s;
	int		len;

	if (!str || !str_base)
		return ((int)NULL);
	s = ft_strdup((char *)str);
	sign = 1;
	if (s[0] == '-')
	{
		sign = -1;
		s++;
	}
	tab = ft_convert(s, str_base);
	if (!tab)
		return ((int)NULL);
	len = ft_strlen(s) - 1;
	free(s);
	return (sign * ft_count(tab, len, str_base, sign));
}
