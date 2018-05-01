/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:15:45 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/10 14:27:33 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*bl;

	bl = (t_list *)malloc(sizeof(t_list));
	if (!bl)
		return (NULL);
	bl->content_size = content_size;
	bl->next = NULL;
	if (content != NULL)
	{
		bl->content = ft_memalloc(content_size);
		if (!bl->content)
			return (NULL);
		ft_memcpy(bl->content, content, content_size);
	}
	else
	{
		bl->content = (void *)NULL;
		bl->content_size = 0;
	}
	return (bl);
}
