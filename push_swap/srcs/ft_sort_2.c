/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:30:12 by ythomas           #+#    #+#             */
/*   Updated: 2019/04/26 17:30:13 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sort_a2(t_size *size)
{
	ft_exec_sa(size);
	ft_exec_ra(size);
	ft_exec_sa(size);
	ft_exec_rra(size);
	ft_exec_sa(size);
}

void		ft_sort_b2(t_size *size)
{
	ft_exec_sb(size);
	ft_exec_rb(size);
	ft_exec_sb(size);
	ft_exec_rrb(size);
	ft_exec_sb(size);
}

void		ft_rollback(t_size *size, int choix, int nb)
{
	int i;

	i = 0;
	if (choix == 1)
	{
		while (i < nb)
		{
			ft_exec_pb(size);
			i++;
		}
	}
	else if (choix == 0)
	{
		while (i < nb)
		{
			ft_exec_pa(size);
			i++;
		}
	}
}
