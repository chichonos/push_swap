/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:10:57 by mea               #+#    #+#             */
/*   Updated: 2022/03/08 14:17:03 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	*mergearrays(int *arr, int *arr2, int i, int j)
{
	int *arrayfinal;
	int sizearrays;
	int k;
	int l;

	sizearrays = i + j;
	arrayfinal = malloc(sizeof(int) * sizearrays);
	if (!arrayfinal)
		error_print(4);
	k = 0;
	while (j != 0)
	{
		arrayfinal[k] = arr2[j - 1];
		k++;
		j--;
	}
	l = 0;
	while (k < sizearrays)
	{
		arrayfinal[k] = arr[l];
		k++;
		l++;
	}
	return (arrayfinal);
}

void	printmyarray(int *arr, int size)
{
for (int i = 0; i < size; i++) {     
        printf("%d ARRAY\n", arr[i]);     
    }      
}

void	ft_printstr(char *str, int nb)
{
	write(1, str, nb);
	write(1, "\n", 1);
}


int	*get_array_sorted(t_stack **stack_a, int *arr, int size)
{
	int i;
	int j;
	int *arr2;
	
	arr2 = malloc(sizeof(int) * size);
	if (!arr2)
		error_print(4);
	arr = copyposnbinarray(arr, stack_a);
	arr2 = copynegnbinarray(arr2, stack_a);
	i = sizeofmyarray(arr);
	j = sizeofmyarray(arr2);
	arr2 = changesignofarray(arr2, j);
	radix_sort(arr, i);
	radix_sort(arr2, j);
	arr2 = changesignofarray(arr2, j);
	arr = mergearrays(arr, arr2, i, j);
	free(arr2);
	return (arr);
}

void	move_to_top(t_stack **stack_b, int nbf)
{
	int pos;
	t_stack *tmp;
	
	tmp = *stack_b;
	//Calculer meilleur choix pour push en B;
	pos = getpos(&tmp, nbf);
	if ((stacklen(stack_b) - pos) < (stacklen(stack_b)/2))
		while ((*stack_b)->nb != nbf)
			rotate_reverse_b(stack_b, "rrb");
	else
		while ((*stack_b)->nb != nbf)
			rotate_b(stack_b);
}
