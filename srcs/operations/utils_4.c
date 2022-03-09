/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:10:57 by mea               #+#    #+#             */
/*   Updated: 2022/03/09 14:45:29 by mea              ###   ########.fr       */
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

int	sizeofmyarray(int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	checksize(int size)
{
	int	divider;

	divider = 0;
	if (size > 5 && size < 50)
		divider = 5;
	if (size >= 50 && size < 500)
		divider = 8;
	else if (size >= 500)
		divider = 10;
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
