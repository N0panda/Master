/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:07:41 by ythomas           #+#    #+#             */
/*   Updated: 2019/04/26 18:15:01 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_get_median(int *pile, int len, int *val)
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
	median = (len / 2);
	*val = tab[median];
	free(tab);
	tab = NULL;
	return (median);
}

int			ft_partition(t_size *size, int nb_push, int choix)
{
	int nb;

	if (choix == 0)
		nb = ft_partition_a(size, nb_push);
	else
		nb = ft_partition_b(size, nb_push);
	return (nb);
}

void		ft_quicksort(t_size *size, int start, int nb_push, int choix)
{
	int	nb;
	int mercilanorme;

	mercilanorme = 0;
	if (choix == 0 && nb_push < 4 && (mercilanorme = 1) == 1)
		ft_sort_a(size, nb_push);
	if (choix == 1 && nb_push < 4 && (mercilanorme = 1) == 1)
		ft_sort_b(size, nb_push);
	if ((choix == 0 && nb_push >= 4) || (choix == 1 && nb_push >= 4))
	{
		nb = ft_partition(size, nb_push, choix);
		if (choix == 0)
		{
			ft_quicksort(size, start, nb_push - nb, 0);
			ft_quicksort(size, start, nb, 1);
		}
		else if (choix == 1)
		{
			ft_quicksort(size, start, nb, 0);
			ft_quicksort(size, start, nb_push - nb, 1);
		}
	}
	if (mercilanorme != 1)
		ft_rollback(size, choix, nb);
	return ;
}

void		ft_simple_sort(t_size *size)
{
	ft_quicksort(size, 0, size->nba, 0);
}
