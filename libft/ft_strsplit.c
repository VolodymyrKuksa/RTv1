/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:47:26 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/13 14:47:29 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_clean(char **res, int count)
{
	while (count >= 0)
		free(res[count--]);
	free(res);
	res = NULL;
	return (NULL);
}

static char	**split(char const *s, char c, int count)
{
	int		b;
	int		i;
	int		e;
	char	**res;

	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (res == NULL)
		return (NULL);
	res[count] = NULL;
	i = 0;
	b = 0;
	while (i < count)
	{
		while (s[b] == c && s[b])
			b++;
		e = b;
		while (s[e] != c && s[e])
			e++;
		res[i] = ft_strsub(s, b, (e - b));
		if (!res[i])
			return (ft_clean(res, count));
		b = e;
		i++;
	}
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (split(s, c, count));
}
