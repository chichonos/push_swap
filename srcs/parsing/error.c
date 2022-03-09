/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:28:42 by mea               #+#    #+#             */
/*   Updated: 2022/03/08 14:03:26 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	error_print(int nb)
{
	if (nb == 1)
		write(1, "Error\n", 6);
	if (nb == 2)
		write(1, "Arguments are already sorted.\n", 29);
	if (nb == 3)
		write(1, "Invalid arguments.\n", 19);
	if (nb == 4)
		write(1, "Malloc problem.\n", 17);
	exit(1);
}
