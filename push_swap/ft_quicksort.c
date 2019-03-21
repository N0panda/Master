/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:22:03 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/19 14:33:37 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "push_swap.h"

void				ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int				ft_get_closest(t_size *size, int median)
{
	int i;
	int rate;
	int minus;
	int closest;

	i = 0;
	rate = INT_MAX;
	while (i <= size->a)
	{
		if (median >= size->a)
			minus = median - size->a;
		else
			minus = size->a - median;
		if (minus < rate)
		{
			rate = minus;
			closest = size->a;
		}
		i++;
	}
	return (closest);
}

int				ft_get_median(t_size *size)
{
	int i;
	int median;
	int closest;

	i = 0;
	median = 0;
	while (i <= size->a)
		median = median + size->pa[i++];
	median = median / size->a;
	closest = ft_get_closest(size, median);
//	printf("median => [%d]\n", median);
	i = 0;
	while (i <= size->a)
	{
		if (size->pa[i] == closest)
			return (i);
		i++;
	}
	return (i);
}

int				ft_partition(t_size *size, int left, int right)
{
	int pivot;
	int	val_p;

//	pivot = ft_get_median(tab, right);
	printf("####size -> %d\n", right);
	pivot = left;
	val_p = size->pa[left];
//	val_p = tab[pivot];
	printf("tab[pivot] => [%d]\n", size->pa[pivot]);
	printf("pivot => [%d]\n", pivot);
	int i = 0;
	printf("------------------------------------------------\n");
	while (i <= right)
		printf("[*%d*]\n", size->pa[i++]);
	printf("------------------------------------------------\n");
	while (left < right)
	{
		while (size->pa[left] <= val_p)
			left++;
		while (size->pa[right] > val_p)
			right--;
		if (left < right)
			ft_swap(size->pa + left, size->pa + right);
	}
	ft_swap(size->pa + pivot, size->pa + right);
	return (right);
}

void			ft_quicksort(t_size	*size, int start, int end)
{
	int	pivot;

	if (start >= end)
		return;
	pivot = ft_partition(size, start, end);
	ft_quicksort(size, start, pivot - 1);
	ft_quicksort(size, pivot + 1, end);
}
	