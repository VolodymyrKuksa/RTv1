/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:03:50 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/06 17:10:58 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;
	t_list	*bl;
	t_list	*p;

	if (!lst || !f)
		return (NULL);
	elem = lst;
	if (elem)
	{
		bl = f(elem);
		p = bl;
		elem = elem->next;
	}
	while (elem)
	{
		p->next = f(elem);
		if (!p->next)
		{
			free(p->next);
			return (NULL);
		}
		p = p->next;
		elem = elem->next;
	}
	return (bl);
}
