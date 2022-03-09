/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:29:54 by mea               #+#    #+#             */
/*   Updated: 2022/03/09 14:41:03 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	moveittotop(int pos_top, t_stack **stack_a)
{
	while (pos_top != 0)
	{
		rotate_a(stack_a);
		pos_top--;
	}
}

void	lastpush(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	max;

	max = getmax(stack_b);
	if ((*stack_b)->nb < max)
		move_to_top(stack_b, max);
	while (stacklen(stack_a) != size)
		push_a(stack_a, stack_b);
}

void	bestchoice(t_stack **stack_a, t_stack **stack_b, int nbfound)
{
	t_stack	*tmp;
	int		pos_top;
	int		index_bot;

	tmp = *stack_a;
	pos_top = getposnbtop(&tmp, nbfound);
	index_bot = getposnbbot(&tmp, nbfound);
	if (pos_top > (stacklen(stack_a) - index_bot))
	{
		while (index_bot != stacklen(stack_a))
		{
			rotate_reverse_a(stack_a, "rra");
			index_bot++;
		}
	}
	if (pos_top <= (stacklen(stack_a) - index_bot))
		moveittotop(pos_top, stack_a);
	if (stacklen(stack_b) > 1)
		putitright(stack_a, stack_b, getmin(stack_b), getmax(stack_b));
	push_b(stack_a, stack_b);
}
