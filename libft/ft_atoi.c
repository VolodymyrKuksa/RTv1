/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:49:58 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/17 12:17:14 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	res;

	sign = 1;
	i = 0;
	res = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res >= 922337203685477580 && ((str[i] - '0') > 7) && sign == 1)
			return (-1);
		else if (res > 922337203685477580 && ((str[i] - '0') > 8) && sign == -1)
			return (0);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(res * sign));
}
