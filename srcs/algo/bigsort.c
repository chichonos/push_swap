/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:29:54 by mea               #+#    #+#             */
/*   Updated: 2022/03/09 16:48:16 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	bestmove(int minpos, t_stack **stack_b)
{
	if (minpos > stacklen(stack_b) / 2)
	{
		while (minpos < stacklen(stack_b))
		{
			rotate_reverse_b(stack_b, "rrb");
			minpos++;
		}
	}
	else
	{
		while (minpos != 0)
		{
			rotate_b(stack_b);
			minpos--;
		}
	}
}

void	putitinthemiddle(t_stack *tmp, t_stack **stack_a, t_stack **stack_b, \
int pos)
{
	unsigned int	min;
	int				minpos;

	min = -1;
	while (tmp != NULL)
	{
		if (tmp->nb < (*stack_a)->nb && getdiff(stack_a, tmp) < min)
		{
			min = getdiff(stack_a, tmp);
			minpos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	bestmove(minpos, stack_b);
}

void	putitright(t_stack **stack_a, t_stack **stack_b, int min_b, int max_b)
{
	int		pos;
	int		minpos;
	t_stack	*tmp;

	pos = 0;
	minpos = 0;
	tmp = *stack_b;
	if ((*stack_a)->nb > max_b)
		move_to_top(stack_b, max_b);
	else if ((*stack_a)->nb < min_b)
		move_to_top(stack_b, max_b);
	else
		putitinthemiddle(tmp, stack_a, stack_b, pos);
}

void	bigsort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		*arr;
	int		nbfound;
	int		chunck;
	int		divider;

	size = stacklen(stack_a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		error_print(4);
	arr = get_array_sorted(stack_a, arr, size);
	chunck = 0;
	divider = checksize(size);
	while (stacklen(stack_a) != 1 && stacklen(stack_a) > 0)
	{
		nbfound = calculebestnb(size, divider, chunck, arr);
		while (morenbinstack(stack_a, nbfound))
			bestchoice(stack_a, stack_b, nbfound);
		chunck += (size / divider);
	}
	push_b(stack_a, stack_b);
	free(arr);
	lastpush(stack_a, stack_b, size);
}
