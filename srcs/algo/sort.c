/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:55:28 by mea               #+#    #+#             */
/*   Updated: 2022/03/09 14:34:34 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_above5(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	firsthalf;
	int	minpos;

	while ((*stack_a) != NULL)
	{
		minpos = 0;
		min = findmin(stack_a);
		minpos = findminpos(stack_a);
		firsthalf = (stacklen(stack_a)) / 2;
		if (minpos < firsthalf)
		{
			while ((*stack_a)->nb != min)
				rotate_a(stack_a);
		}
		else if (minpos >= firsthalf)
		{
			while ((*stack_a)->nb != min)
				rotate_reverse_a(stack_a, "rra");
		}
		push_b(stack_a, stack_b);
	}
	while (*stack_b)
		push_a(stack_a, stack_b);
}

void	sort_three(t_stack **stack_a)
{
	int	one;
	int	two;
	int	three;

	one = (*stack_a)->nb;
	two = (*stack_a)->next->nb;
	three = (*stack_a)->next->next->nb;
	if (one < two && two > three && three > one)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (one < two && two > three && three < one)
		rotate_reverse_a(stack_a, "rra");
	else if (one > two && two < three && three > one)
		swap_a(stack_a);
	else if (one > two && two < three && three < one)
		rotate_a(stack_a);
	else if (one > two && two > three && three < one)
	{
		swap_a(stack_a);
		rotate_reverse_a(stack_a, "rra");
	}
}

void	sort4and5(t_stack **stack_a, t_stack **stack_b)
{	
	int	min;

	min = 0;
	while ((*stack_a)->nb != min)
	{
		min = findmin(stack_a);
		rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
	if (stacklen(stack_a) == 4)
	{
		min = findmin(stack_a);
		while ((*stack_a)->nb != min)
		{
			rotate_a(stack_a);
		}
		push_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stacklen(stack_a);
	if (size > 5)
		bigsort(stack_a, stack_b, size);
	if (size == 4 || size == 5)
		sort4and5(stack_a, stack_b);
	if (size == 3)
		sort_three(stack_a);
	if (size == 2)
		swap_a(stack_a);
}
