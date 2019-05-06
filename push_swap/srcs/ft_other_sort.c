/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:20:04 by ythomas           #+#    #+#             */
/*   Updated: 2019/04/30 19:01:24 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_small_sort(t_size *s)
{
	if (s->nba == 2 && s->pa[0] > s->pa[1])
		ft_exec_sa(s);
	else if (s->nba == 3)
	{
		if (s->pa[0] > s->pa[1] && s->pa[1] > s->pa[2])
		{
			ft_exec_ra(s);
			ft_exec_sa(s);
		}
		else if (s->pa[1] < s->pa[0] && s->pa[0] < s->pa[2])
			ft_exec_sa(s);
		else if (s->pa[1] < s->pa[2] && s->pa[2] < s->pa[0])
			ft_exec_ra(s);
		else if (s->pa[2] < s->pa[0] && s->pa[0] < s->pa[1])
			ft_exec_rra(s);
		else if (s->pa[0] < s->pa[2] && s->pa[2] < s->pa[1])
		{
			ft_exec_rra(s);
			ft_exec_sa(s);
		}
	}
}

void		ft_select(t_size *size, int pos)
{
	int		*tab;
	int		i;

	i = -1;
	if (!(tab = (int *)malloc(sizeof(int) * size->nba)))
		ft_exit();
	while (++i < size->nba)
		tab[i] = size->pa[i];
	ft_quicksorttwo(tab, 0, i - 1);
	i = 0;
	while (size->pa[i] != tab[pos])
		i++;
	if (i < (size->nba - i))
	{
		while (size->pa[0] != tab[pos])
			ft_exec_ra(size);
	}
	else
	{
		while (size->pa[0] != tab[pos])
			ft_exec_rra(size);
	}
	free(tab);
}

void		ft_medium_sort(t_size *size)
{
	int i;

	i = 0;
	while (size->nba > 3)
	{
		ft_select(size, 0);
		ft_exec_pb(size);
		i++;
	}
	ft_small_sort(size);
	while (size->nba < size->a)
		ft_exec_pa(size);
	return ;
}
