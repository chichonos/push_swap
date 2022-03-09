/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:31:35 by mea               #+#    #+#             */
/*   Updated: 2022/03/09 14:53:25 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "libft/libft.h"

int	parsing_one_arg(char **argv, t_stack **stack_a)
{
	int		i;
	char	**arr;

	i = 0;
	arr = ft_split(argv[1], ' ');
	if (!arr)
		return (0);
	while (arr[i])
	{
		if (!checkargs(arr[i]))
			error_print(1);
		i++;
	}
	while (i > 0)
		*stack_a = node_creation(ft_atoi(arr[i-- - 1]), stack_a);
	return (1);
}

void	printmystack(t_stack *stack_a)
{
	puts("-------------pile--------------");
	while (stack_a)
	{
		printf("%d\n", stack_a->nb);
		stack_a = stack_a->next;
	}
	puts("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 1)
	{
		if (argc == 2)
			if (!parsing_one_arg(argv, &stack_a))
				error_print(1);
		if (argc > 2)
		{
			while (argc > 1)
			{
				if (!checkargs(argv[argc - 1]))
					error_print(1);
				stack_a = node_creation(ft_atoi(argv[argc-- - 1]), &stack_a);
			}
		}
	}
	if (checkdouble(stack_a))
		error_print(1);
	if (checkifsorted(&stack_a))
		return (0);
	sorting(&stack_a, &stack_b);
	return (0);
}
