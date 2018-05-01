/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:43:07 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/10 20:25:11 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;

	i = 0;
	if (len > 0)
	{
		if (src >= dst)
			ft_memcpy(dst, src, len);
		else
		{
			i = (int)len - 1;
			while (i >= 0)
			{
				((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
				i--;
			}
		}
	}
	return (dst);
}
