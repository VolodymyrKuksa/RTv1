/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:30:20 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/09 16:38:38 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	j = 0;
	l = ft_strlen(dst);
	if (dstsize > 0)
	{
		i = ft_strlen(dst);
		while (i < dstsize - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	return (l < dstsize ? l + ft_strlen(src) : dstsize + ft_strlen(src));
}
