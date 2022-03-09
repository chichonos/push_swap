/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:23:36 by mea               #+#    #+#             */
/*   Updated: 2022/02/28 15:41:25 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// A utility function to get maximum value in arr[]
int get_max(int arr[], int sizeofarray)
{
	int mx;
	int i;
	
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

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int sizeofarray, int exp)
{
	int output[sizeofarray]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	i = -1;
	while (i < sizeofarray)
		count[(arr[++i] / exp) % 10]++;

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
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
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
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radix_sort(int arr[], int sizeofarray)
{
	int exp;
	int m; 

	// Find the maximum number to know number of digits
	exp = 1;
	m = get_max(arr, sizeofarray);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	while (m / exp > 0)
	{
		countSort(arr, sizeofarray, exp);
		exp *= 10;
	}
}
