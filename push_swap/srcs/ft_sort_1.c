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

int 	ft_a_is_sorted(t_size *size)
{
	int 	i = 0;

	while (i < size->a - 1)
	{
		if (size->pa[i] >= size->pa[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int 	ft_b_is_sorted(t_size *size, int nb)
{
	int 	i = 0;

	while (i < nb - 1)
	{
		if (size->pb[i] <= size->pb[i + 1])
			return (0);
		i++;
	}
	return (1);
}

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
	median = (len/2);
	*val = tab[median];
	free(tab);
	tab = NULL;
	return (median);
}

void	ft_reverse_a(t_size *size, int k)
{
	while (k > 0)
	{
		ft_exec_rra(size);
		k--;
	}
}

void	ft_reverse_b(t_size *size, int k)
{
	while (k > 0)
	{
		ft_exec_rrb(size);
		k--;
	}
}

int		ft_partition_a(t_size *size, int left, int nb_push)
{
	int nb;
	int val_p;
	int i;
	int k;

	i = 0;
	k = 0;
	nb = 0;
	ft_get_median(size, size->pa, nb_push, &val_p);
	while (i < nb_push)
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
		i++;
	}
	ft_reverse_a(size, k);
	k = 0;
	while (size->pa[0] != val_p)
	{
		ft_exec_ra(size);
		k++;
	}
	ft_exec_pb(size);
	ft_reverse_a(size, k);
	return (nb + 1);
}

int		ft_partition_b(t_size *size, int left, int nb_push)
{
	int val_p;
	int i;
	int k;
	int nb;

	i = 0;
	k = 0;
	nb = 0;
	ft_get_median(size, size->pb, nb_push, &val_p);
	while (i < nb_push)
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
		i++;
	}
	ft_reverse_b(size, k);
	k = 0;
	while (size->pb[0] != val_p)
	{
		ft_exec_rb(size);
		k++;
	}
	ft_exec_pa(size);
	ft_reverse_b(size, k);
	return (nb + 1);
}

int		ft_partition(t_size *size, int left, int nb_push, int choix)
{
	int nb;

	if (choix == 0)
		nb = ft_partition_a(size, left, nb_push);
	else
		nb = ft_partition_b(size, left, nb_push);
	return (nb);
}

void		ft_sort_a(t_size *size, int nb)
{
	if (nb == 3)
	{
		if (size->pa[0] > size->pa[1] && size->pa[1] > size->pa[2])
		{
			ft_exec_sa(size);
			ft_exec_ra(size);
			ft_exec_sa(size);
			ft_exec_rra(size);
			ft_exec_sa(size);
		}
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

void		ft_sort_b(t_size *size, int nb)
{
	if (nb == 3)
	{
		if (size->pb[0] < size->pb[1] && size->pb[1] < size->pb[2])
		{
			ft_exec_sb(size);
			ft_exec_rb(size);
			ft_exec_sb(size);
			ft_exec_rrb(size);
			ft_exec_sb(size);
		}
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


void		ft_quicksort(t_size *size, int start, int nb_push, int choix)
{
	int	nb;
	if (choix == 0 && nb_push < 4)
	{
		ft_sort_a(size, nb_push);
		return ;
	}
	if (choix == 1 && nb_push < 4)
	{
		ft_sort_b(size, nb_push);
		return ;
	}

	if ((choix == 0 && nb_push >= 4) || (choix == 1 && nb_push >= 4))
	{
			nb = ft_partition(size, start, nb_push, choix);
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
	if (choix == 1)
	{
		int i = 0;
		while (i < nb)
		{
			ft_exec_pb(size);
			i++;
		}
	}
	else if (choix == 0)
	{
		int i = 0;
		while (i < nb)
		{
			ft_exec_pa(size);
			i++;
		}
	}
	return ;
}

void		ft_simple_sort(t_size *size)
{
	ft_quicksort(size, 0, size->nba, 0);
	// printf("----- PILE A -------\n");
	// int i = 0;
	// while (i < size->a)
	// 	printf("%d\n", size->pa[i++]);
	// printf("\n");
	// printf("----- PILE B -------\n");
	// 	i = 0;
	// while (i < size->nbb)
	// 	printf("%d\n", size->pb[i++]);
	// if (ft_a_is_sorted(size) == 1)
	// 	printf("OK\n");
	// else
	// 	printf("KO\n");
}
