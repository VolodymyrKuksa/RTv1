/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:27:04 by vkuksa            #+#    #+#             */
/*   Updated: 2018/03/23 17:27:06 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(char *str)
{
	double	res;
	double	tmp;
	char	*s;

	res = (double)ft_atoi(str);
	if ((s = ft_strchr(str, '.')))
	{
		while (str != s && ft_isdigit(*str))
			str++;
		if (str == s)
		{
			s++;
			tmp = *s == '-' ? 0 : (double)ft_atoi(s);
			while (tmp >= 1)
				tmp /= 10;
			res = res >= 0 ? res + tmp : res - tmp;
		}
	}
	return (res);
}
