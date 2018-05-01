/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:38:53 by vkuksa            #+#    #+#             */
/*   Updated: 2018/03/25 21:38:55 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_valid_vec(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-' && *str != '.' && *str != ',')
			return (0);
		str++;
	}
	return (1);
}

int		is_valid_nb(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-' && *str != '.')
			return (0);
		str++;
	}
	return (1);
}

int		is_valid_hex(char *str)
{
	while (*str)
	{
		*str = ft_tolower(*str);
		if (!ft_isdigit(*str) && (*str < 'a' || *str > 'f'))
			return (0);
		str++;
	}
	return (1);
}
