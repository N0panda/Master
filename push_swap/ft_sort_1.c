/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:07:41 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/21 18:07:43 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_median(t_size *size, int *pile, int len, int *val)
{
	int median;
	int i;
	int *tab;

	i = 0;
	if (!(tab = malloc(sizeof(int) * len)))
		ft_exit();
	while (i < len)
	{
		tab[i] = pile[i];
		i++;
	}
	i = 0;
	ft_quicksorttwo(tab, 0, len - 1);
	i = 0;
	median = (len/2) - 1;
	*val = tab[median];
	free(tab);
	tab = NULL;
	printf("median [%d]\n", median);// MEDIANE
	return (median);
}

int		ft_partition(t_size *size, int left, int right, int choix)
{
	int pivot;
	int val_p;

	if (choix == 0)
		pivot = ft_get_median(size, size->pa, size->nba, &val_p);
	else
		pivot = ft_get_median(size, size->pb, size->nbb, &val_p);
	//push sur la pile choix
	return (pivot);
}





void		ft_quicksort(t_size *size, int start, int end, int choix)
{
	int	pivot;

	if (start >= end)//condition arret recursivite;
		return ;
	pivot = ft_partition(size, start, end, choix);

}






void		ft_simple_sort(t_size *size)
{
	ft_quicksort(size, 0, size->nba, 0);
}