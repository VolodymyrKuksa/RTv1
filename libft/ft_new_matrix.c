/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:40:57 by vkuksa            #+#    #+#             */
/*   Updated: 2018/01/14 17:40:59 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix	*ft_new_matrix(int i, int j)
{
	t_matrix	*m;
	int			ind;

	m = (t_matrix*)malloc(sizeof(t_matrix));
	if (!m || i < 0 || j < 0)
		return (NULL);
	m->i = i;
	m->j = j;
	ind = 0;
	if (!(m->arr = (double**)malloc(sizeof(double*) * i)))
		return (NULL);
	while (ind < i)
	{
		if (!(m->arr[ind] = (double*)malloc(sizeof(double) * j)))
		{
			while (--ind >= 0)
				free(m->arr[ind]);
			free(m->arr);
			return (NULL);
		}
		ft_bzero(m->arr[ind], j * sizeof(double));
		ind++;
	}
	return (m);
}
