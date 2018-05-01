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

double	ft_atod(char *s)
{
	double	res;
	double	tmp;

	res = (double)ft_atoi(s);
	if ((s = ft_strchr(s, '.')))
	{
		s++;
		tmp = *s == '-' ? 0 : (double)ft_atoi(s);
		while (tmp >= 1)
			tmp /= 10;
		res = res >= 0 ? res + tmp : res - tmp;
	}
	return (res);
}
