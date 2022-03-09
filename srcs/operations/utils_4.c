/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:10:57 by mea               #+#    #+#             */
/*   Updated: 2022/03/09 17:47:47 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	*copystackinarray(int *arr, t_stack **stack_a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->nb >= 0)
		{
			arr[i] = tmp->nb;
			i++;
		}
		tmp = tmp->next;
	}
	return (arr);
}

int	*copynegnbinarray(int *arr, t_stack **stack_a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->nb < 0)
		{
			arr[i] = tmp->nb;
			i++;
		}
		tmp = tmp->next;
	}
	return (arr);
}

int	checksize(int size)
{
	int	divider;

	divider = 0;
	if (size < 500)
		divider = 5;
	else
		divider = 12;
	return (divider);
}

int	calculebestnb(int size, int divider, int chunck, int *arr)
{
	int	nbfound;

	if ((size / divider + chunck - 1) > size)
		nbfound = arr[size - 1];
	else
		nbfound = arr[(size / divider) + chunck - 1];
	return (nbfound);
}
