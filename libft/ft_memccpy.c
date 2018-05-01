/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:01:42 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/07 14:15:12 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n)
	{
		((unsigned char *)dst)[j] = ((unsigned char *)src)[j];
		if (((unsigned char *)dst)[j] == (unsigned char)c)
			return (dst + j + 1);
		j++;
	}
	return (NULL);
}
