/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:29:42 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/16 11:29:45 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sorted(int *tab, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < (size - 1))
	{
		if ((tab[i] - tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

void		ft_sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;

	if (tab && size)
	{
		while (!ft_is_sorted(tab, size))
		{
			i = 0;
			while (i < (size - 1))
			{
				if (tab[i] - tab[i + 1] > 0)
					ft_swap(&tab[i], &tab[i + 1]);
				i++;
			}
		}
	}
}
