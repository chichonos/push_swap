/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:10:57 by mea               #+#    #+#             */
/*   Updated: 2022/03/09 14:29:37 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_reverse_all(t_stack **stack_a, t_stack **stack_b)
{
	rotate_reverse_a(stack_a, "");
	rotate_reverse_b(stack_b, "");
	write(1, "rrr\n", 4);
}

void	rotate_all(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack_a;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	tmp2 = *stack_b;
	while (tmp->next)
		tmp2 = tmp->next;
	tmp2->next = *stack_b;
	tmp2 = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp2->next = NULL;
	write(1, "rr\n", 3);
}

void	swap_all(t_stack **stack_a, t_stack **stack_b)
{
	int	tmp;
	int	tmp2;

	if (stacklen(stack_a) <= 1)
		return ;
	tmp = (*stack_a)->nb;
	(*stack_a)->nb = (*stack_a)->next->nb;
	(*stack_a)->next->nb = tmp;
	if (stacklen(stack_b) <= 1)
		return ;
	tmp2 = (*stack_b)->nb;
	(*stack_b)->nb = (*stack_b)->next->nb;
	(*stack_b)->next->nb = tmp2;
	write(1, "ss\n", 3);
}
