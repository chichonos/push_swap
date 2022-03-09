/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:48:06 by mea               #+#    #+#             */
/*   Updated: 2022/03/09 14:29:00 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	getpos(t_stack **stack, int nbf)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = *stack;
	if (!tmp)
		error_print(1);
	while (tmp->next != NULL)
	{
		if (tmp->nb != nbf)
		{
			tmp = tmp->next;
			pos++;
		}
		else
			return (pos);
	}
	return (pos);
}

int	getmax(t_stack **stack)
{
	int		max;
	t_stack	*tmp;

	tmp = *stack;
	if (!tmp)
		return (0);
	max = tmp->nb;
	while (tmp->next != NULL)
	{
		if (max < tmp->next->nb)
			max = tmp->next->nb;
		tmp = tmp->next;
	}
	return (max);
}

int	getmin(t_stack **stack)
{
	int		min;
	t_stack	*tmp;

	tmp = *stack;
	if (!tmp)
		return (0);
	min = tmp->nb;
	while (tmp->next != NULL)
	{
		if (min > tmp->next->nb)
			min = tmp->next->nb;
		tmp = tmp->next;
	}
	return (min);
}

int	getposnbtop(t_stack **stack, int nbfound)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = *stack;
	while (tmp->nb > nbfound && tmp->next != NULL)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

int	getposnbbot(t_stack **stack, int nbfound)
{
	int		pos;
	t_stack	*tmp;
	int		index;

	index = 0;
	pos = 0;
	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->nb < nbfound)
			index = pos;
		pos++;
		tmp = tmp->next;
	}
	return (index);
}
