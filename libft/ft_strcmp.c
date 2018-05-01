/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:20:54 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/08 14:02:16 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	l;

	l = ft_strlen(s1) > ft_strlen(s2) ? ft_strlen(s2) : ft_strlen(s1);
	l++;
	return (ft_memcmp(s1, s2, l));
}
