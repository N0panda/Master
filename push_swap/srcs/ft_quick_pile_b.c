/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_pile_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 12:54:13 by ythomas           #+#    #+#             */
/*   Updated: 2019/04/26 12:54:14 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_reverse_b(t_size *size, int k, int cas)
{
	if (cas == 0)
	{
		while (k > 0)
		{
			ft_exec_rrb(size);
			k--;
		}
	}
	else
	{
		while (k > 0)
		{
			ft_exec_rb(size);
			k--;
		}
	}
}

void		ft_sort_b(t_size *size, int nb)
{
	if (nb == 3)
	{
		if (size->pb[0] < size->pb[1] && size->pb[1] < size->pb[2])
			ft_sort_b2(size);
		if (size->pb[0] < size->pb[1] && size->pb[0] < size->pb[2])
		{
			ft_exec_sb(size);
			ft_exec_rb(size);
			ft_exec_sb(size);
			ft_exec_rrb(size);
		}
		if (size->pb[1] < size->pb[2])
		{
			ft_exec_rb(size);
			ft_exec_sb(size);
			ft_exec_rrb(size);
		}
		if (size->pb[0] < size->pb[1])
			ft_exec_sb(size);
	}
	else if (nb == 2 && size->pb[0] < size->pb[1])
		ft_exec_sb(size);
}

void		ft_push_median_b_suit(t_size *size, int val_p, int cas)
{
	int k;

	k = 0;
	if (cas == 0)
	{
		while (size->pb[0] != val_p)
		{
			ft_exec_rb(size);
			k++;
		}
		ft_exec_pa(size);
		ft_reverse_b(size, k, cas);
	}
	else
	{
		while (size->pb[0] != val_p)
		{
			ft_exec_rrb(size);
			k++;
		}
		ft_exec_pa(size);
		ft_reverse_b(size, k, cas);
	}
}

void		ft_push_median_b(t_size *size, int val_p)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	while (size->pb[i] != val_p)
		i++;
	if (i < (size->nbb - i))
		ft_push_median_b_suit(size, val_p, 0);
	else
		ft_push_median_b_suit(size, val_p, 1);
}

int			ft_partition_b(t_size *size, int nb_push)
{
	int val_p;
	int i;
	int k;
	int nb;

	i = -1;
	k = 0;
	nb = 0;
	ft_get_median(size->pb, nb_push, &val_p);
	while (++i < nb_push)
	{
		if (size->pb[0] > val_p)
		{
			ft_exec_pa(size);
			nb++;
		}
		else
		{
			ft_exec_rb(size);
			k++;
		}
	}
	ft_reverse_b(size, k, 0);
	ft_push_median_b(size, val_p);
	return (nb + 1);
}
