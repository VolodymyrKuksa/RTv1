/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:11:38 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/09 12:32:31 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (str == NULL)
		return (NULL);
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	ft_strcpy(str, s1);
	ft_strcpy(&str[ft_strlen(s1)], s2);
	return (str);
}
