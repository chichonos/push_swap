/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:14:09 by marvin            #+#    #+#             */
/*   Updated: 2021/12/29 13:14:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_a(t_stack **stack)
{
	int	tmp;

	if (stacklen(stack) <= 1)
		return ;
	tmp = (*stack)->nb;
	(*stack)->nb = (*stack)->next->nb;
	(*stack)->next->nb = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **stack)
{
	int	tmp;

	if (stacklen(stack) <= 1)
		return ;
	tmp = (*stack)->nb;
	(*stack)->nb = (*stack)->next->nb;
	(*stack)->next->nb = tmp;
	write(1, "sb\n", 3);
}

void	rotate_reverse_a(t_stack **stack, char *str)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	tmp2 = *stack;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp->next = *stack;
	*stack = tmp;
	tmp2->next = NULL;
	if (!str)
		;
	else
		ft_printstr(str, 3);
}

void	rotate_reverse_b(t_stack **stack, char *str)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	tmp2 = *stack;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp->next = *stack;
	*stack = tmp;
	tmp2->next = NULL;
	if (!str)
		;
	else
		ft_printstr(str, 3);
}
