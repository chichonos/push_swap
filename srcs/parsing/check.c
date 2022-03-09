/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:30:35 by mea               #+#    #+#             */
/*   Updated: 2022/03/08 14:05:09 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_int_overflow(char *str)
{
	if (ft_atol(str) == -1)
		return (1);
	return (0);
}

int	checkargs(char *str)
{
	int		i;
	int		len;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	len = ft_strlen(str);
	if (len > 11 && str[1] != '0')
		return (0);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if ((len == 10 || len == 11) && check_int_overflow(str))
		return (0);
	return (1);
}

int	checkdouble(t_stack *stack_a)
{
	t_stack	*a;
	t_stack	*b;

	a = stack_a;
	while (a)
	{
		b = a;
		while (b)
		{
			if (a != b && a->nb == b->nb)
				return (1);
			b = b->next;
		}
		a = a->next;
	}
	return (0);
}

int	checkifsorted(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while ((tmp)->next != NULL)
	{
		if (tmp->nb < tmp->next->nb)
				tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}
