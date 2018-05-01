/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:40:49 by vkuksa            #+#    #+#             */
/*   Updated: 2018/01/05 15:40:53 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix	*ft_mat_mult(t_matrix *a, t_matrix *b, int fr)
{
	int			i;
	int			j;
	int			w;
	int			h;
	t_matrix	*tmp;

	if (!(tmp = ft_new_matrix(a->i, b->j)))
		return (NULL);
	i = -1;
	while (++i < tmp->i)
	{
		j = -1;
		while (++j < tmp->j)
		{
			h = 0;
			w = 0;
			while (w < tmp->j)
				(tmp->arr)[i][j] += (a->arr)[i][w++] * (b->arr[h++][j]);
		}
	}
	if (fr == 1 || fr == 3)
		ft_clear_matrix(&a);
	if (fr == 2 || fr == 3)
		ft_clear_matrix(&b);
	return (tmp);
}
