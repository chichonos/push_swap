/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:33:48 by mea               #+#    #+#             */
/*   Updated: 2022/03/08 14:02:26 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*node_creation(int arg, t_stack **stack)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	tmp->nb = arg;
	tmp->next = *stack;
	return (tmp);
}

int	stacklen(t_stack **stack_a)
{
	int		i;
	t_stack	*tmp;

	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (stack)
	{
		if (*stack == NULL)
			*stack = new;
		else
		{
			tmp = ft_last(*stack);
			tmp->next = new;
		}
	}
}

t_stack	*ft_last(t_stack *stack)
{
	t_stack			*curr;

	curr = stack;
	if (!stack || !curr)
		return (NULL);
	while (curr->next)
	{
		curr = curr->next;
	}
	return (curr);
}
