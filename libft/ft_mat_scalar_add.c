/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_scalar_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 15:46:50 by vkuksa            #+#    #+#             */
/*   Updated: 2018/01/21 15:46:52 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix	ft_mat_scalar_add(t_matrix m, double nb)
{
	int		i;
	int		j;

	i = 0;
	while (i < m.i)
	{
		j = 0;
		while (j < m.j)
			m.arr[i][j++] += nb;
		i++;
	}
	return (m);
}
