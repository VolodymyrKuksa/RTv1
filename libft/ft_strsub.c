/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:00:53 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/11 13:18:33 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*substr;

	if (!s)
		return (NULL);
	substr = ft_strnew(len);
	if (!substr)
		return (NULL);
	substr = ft_strncpy(substr, (s + start), len);
	return (substr);
}
