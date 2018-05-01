/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brainfuck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:40:36 by vkuksa            #+#    #+#             */
/*   Updated: 2018/01/10 14:41:06 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_loop_back(char *bf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j != 1)
	{
		while (*bf != '[' && *bf != ']')
			bf--;
		*(bf--) == '[' ? i-- : i++;
		if (i == 0 && bf[1] == '[')
			j = 1;
	}
	return (bf);
}

static void	ft_oper(char *bf, char *p)
{
	while (*bf)
	{
		if (*bf == '>')
			p++;
		if (*bf == '<')
			p--;
		if (*bf == '+')
			*p += 1;
		if (*bf == '-')
			*p -= 1;
		if (*bf == ',')
			read(1, p, 1);
		if (*bf == '.')
			ft_putchar(*p);
		if (*bf == ']' && *p != 0)
			bf = ft_loop_back(bf);
		bf++;
	}
}

void		ft_brainfuck(char *bf)
{
	int		lc;
	int		rc;
	int		i;
	char	*str;

	i = 0;
	lc = 0;
	rc = 0;
	while (bf[i])
	{
		if (bf[i] == '<')
			lc++;
		if (bf[i] == '>')
			rc++;
		i++;
	}
	str = ft_strnew(lc + rc);
	ft_oper(bf, &str[lc]);
	free(str);
}
