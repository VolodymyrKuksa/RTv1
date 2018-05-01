/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:24:49 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/09 13:15:45 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;

	if (s)
	{
		i = 0;
		j = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		if (j >= i)
			return (ft_strsub(s, i, (j - i + 1)));
		else
			return (ft_strnew(0));
	}
	return (NULL);
}
