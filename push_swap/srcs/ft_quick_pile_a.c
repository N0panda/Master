/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_pile_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 12:54:08 by ythomas           #+#    #+#             */
/*   Updated: 2019/04/26 18:16:30 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_reverse_a(t_size *size, int k, int cas)
{
	if (cas == 0)
	{
		while (k > 0)
		{
			ft_exec_rra(size);
			k--;
		}
	}
	else
	{
		while (k > 0)
		{
			ft_exec_ra(size);
			k--;
		}
	}
}

void		ft_sort_a(t_size *size, int nb)
{
	if (nb == 3)
	{
		if (size->pa[0] > size->pa[1] && size->pa[1] > size->pa[2])
			ft_sort_a2(size);
		if (size->pa[0] > size->pa[1] && size->pa[0] > size->pa[2])
		{
			ft_exec_sa(size);
			ft_exec_ra(size);
			ft_exec_sa(size);
			ft_exec_rra(size);
		}
		if (size->pa[1] > size->pa[2])
		{
			ft_exec_ra(size);
			ft_exec_sa(size);
			ft_exec_rra(size);
		}
		if (size->pa[0] > size->pa[1])
			ft_exec_sa(size);
	}
	else if (nb == 2 && size->pa[0] > size->pa[1])
		ft_exec_sa(size);
}

void		ft_push_median_a_suit(t_size *size, int val_p, int cas)
{
	int k;

	k = 0;
	if (cas == 0)
	{
		while (size->pa[0] != val_p)
		{
			ft_exec_ra(size);
			k++;
		}
		ft_exec_pb(size);
		ft_reverse_a(size, k, cas);
	}
	else
	{
		while (size->pa[0] != val_p)
		{
			ft_exec_rra(size);
			k++;
		}
		ft_exec_pb(size);
		ft_reverse_a(size, k, cas);
	}
}

void		ft_push_median_a(t_size *size, int val_p)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	while (size->pa[i] != val_p)
		i++;
	if (i < (size->nba - i))
		ft_push_median_a_suit(size, val_p, 0);
	else
		ft_push_median_a_suit(size, val_p, 1);
}

int			ft_partition_a(t_size *size, int nb_push)
{
	int nb;
	int val_p;
	int i;
	int k;

	i = -1;
	k = 0;
	nb = 0;
	ft_get_median(size->pa, nb_push, &val_p);
	while (++i < nb_push)
	{
		if (size->pa[0] < val_p)
		{
			ft_exec_pb(size);
			nb++;
		}
		else
		{
			ft_exec_ra(size);
			k++;
		}
	}
	ft_reverse_a(size, k, 0);
	ft_push_median_a(size, val_p);
	return (nb + 1);
}
