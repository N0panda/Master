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

int				ft_partitiontwo(int **tab, int left, int right)
{
	int pivot;
	int	val_p;

	pivot = left;
	val_p = (*tab)[left];
	while (left < right)
	{
		while ((*tab)[left] <= val_p && left < right)
			left++;
		while ((*tab)[right] > val_p)
			right--;
		if (left < right)
			ft_swap((*tab) + left, (*tab) + right);
	}
	ft_swap((*tab) + pivot, (*tab) + right);
	return (right);
}

void			ft_quicksorttwo(int *tab, int start, int end)
{
	int	pivot;

	if (start >= end)
		return;
	pivot = ft_partitiontwo(&tab, start, end);
	ft_quicksorttwo(tab, start, pivot - 1);
	ft_quicksorttwo(tab, pivot + 1, end);
}
	