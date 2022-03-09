/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:10:57 by mea               #+#    #+#             */
/*   Updated: 2022/03/09 14:28:40 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

unsigned int	getdiff(t_stack **stack_a, t_stack **stack_b)
{
	long int	result;
	long int	stack_aa;
	long int	stack_bb;

	if ((*stack_a)->nb < 0)
		stack_aa = (*stack_a)->nb * (-1);
	else
		stack_aa = (*stack_a)->nb;
	if ((*stack_a)->nb < 0)
		stack_bb = (*stack_b)->nb * (-1);
	else
		stack_bb = (*stack_b)->nb;
	if (stack_aa - stack_bb < 0)
		result = (stack_aa - stack_bb) * (-1);
	else
		result = stack_aa - stack_bb;
	return ((unsigned int)result);
}

int	findminpos(t_stack **stack_a)
{
	int		min;
	int		minpos;
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack_a;
	minpos = 1;
	min = (tmp)->nb;
	while ((tmp)->next != NULL)
	{
		i++;
		if (min > (tmp)->next->nb)
		{
			min = (tmp)->next->nb;
			minpos = i;
		}
	(tmp) = (tmp)->next;
	}
	return (minpos);
}

int	findmin(t_stack **stack_a)
{
	int		min;
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack_a;
	min = (tmp)->nb;
	while ((tmp)->next != NULL)
	{
		i++;
		if (min > (tmp)->next->nb)
		{
			min = (tmp)->next->nb;
		}
	(tmp) = (tmp)->next;
	}
	return (min);
}

int	morenbinstack(t_stack **stack_a, int nbf)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->nb <= nbf)
			return (1);
		else
			tmp = tmp->next;
	}
	return (0);
}

int	*changesignofarray(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = arr[i] * (-1);
		i++;
	}
	return (arr);
}
