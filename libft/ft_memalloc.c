/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:35:49 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/07 14:52:19 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;

	if (!size)
		return (NULL);
	res = (void *)malloc(size);
	if (!res)
		return (NULL);
	ft_bzero(res, size);
	return (res);
}
