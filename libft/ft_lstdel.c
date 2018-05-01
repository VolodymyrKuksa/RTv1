/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:06:37 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/10 15:46:35 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p;

	if (alst && del)
	{
		while (*alst)
		{
			p = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = p;
		}
	}
}
