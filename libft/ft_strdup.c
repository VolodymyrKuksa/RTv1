/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:04:32 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/06 18:50:25 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = ft_strnew(ft_strlen(str));
	if (dup == NULL)
		return (NULL);
	while (i < ft_strlen(str))
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}
