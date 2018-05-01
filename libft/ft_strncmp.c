/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:15:59 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/08 14:17:07 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	l;

	l = ft_strlen(s1) > ft_strlen(s2) ? ft_strlen(s2) + 1 : ft_strlen(s1) + 1;
	return (ft_memcmp(s1, s2, l > n ? n : l));
}
