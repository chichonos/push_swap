/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:23:36 by mea               #+#    #+#             */
/*   Updated: 2022/03/09 16:19:56 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "../../includes/push_swap.h"

int	get_max(int arr[], int sizeofarray)
{
	int	mx;
	int	i;

	mx = arr[0];
	i = 0;
	while (i < sizeofarray)
	{
		if (arr[i] > mx)
			mx = arr[i];
		i++;
	}
	return (mx);
}

void	countSort(int *arr, int sizeofarray, int digit)
{
	int	size;
	int	*output;
	int	i;
	int	count[10];

	output = malloc(sizeof(int) * sizeofarray);
	if (!output)
		error_print(4);	
	
	// Store count of occurrences in count[]
	i = -1;
	while (i < sizeofarray)
		count[(arr[++i] / digit) % 10]++;
	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	i = 0;
	while (i < 10)
	{
		count[i] += count[i - 1];
		i++;
	}

	// Build the output array
	i = sizeofarray - 1;
	while (i >= 0)
	{
		output[count[(arr[i] / digit) % 10] - 1] = arr[i];
		count[(arr[i] / digit) % 10]--;
		i--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	i = 0;
	while (i < sizeofarray)
	{
		arr[i] = output[i];
		i++;
	}
	free(output);
}

void	radix_sort(int arr[], int sizeofarray)
{
	int	digit;
	int	nbofdigits; 

	// Find the maximum number to know number of digits
	digit = 1;
	nbofdigits = get_max(arr, sizeofarray);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, digit is passed. digit is 10^i
	// where i is current digit number
	while (nbofdigits / digit > 0)
	{
		countSort(arr, sizeofarray, digit);
		digit *= 10;
	}
}
*/