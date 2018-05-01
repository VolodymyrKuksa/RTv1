/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_str_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:29:19 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/16 12:29:21 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_is_sorted(char **tab)
{
	int		i;

	i = 0;
	while (tab[i + 1])
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

void		ft_sort_str_tab(char **tab)
{
	int		i;
	char	*temp;

	if (tab)
	{
		while (!ft_is_sorted(tab))
		{
			i = 0;
			while (tab[i + 1])
			{
				if (ft_strcmp(tab[i], tab[i + 1]) > 0)
				{
					temp = tab[i];
					tab[i] = tab[i + 1];
					tab[i + 1] = temp;
				}
				i++;
			}
		}
	}
}
