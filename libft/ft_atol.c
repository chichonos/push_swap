/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:50:19 by mea               #+#    #+#             */
/*   Updated: 2022/03/09 14:55:16 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *str)
{
	int		i;
	long	res;
	char	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] && \
	res >= -2147483648 && res <= 2147483647)
	{
		res *= 10;
		res += str[i++] - 48;
	}
	res *= sign;
	if ((str[i] && (str[i] < '0' || str[i] > '9')) || \
	(res < -2147483648 || res > 2147483647))
		return (-1);
	return (res);
}
