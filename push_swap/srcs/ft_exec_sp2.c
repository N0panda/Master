/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_sp2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:59:42 by ythomas           #+#    #+#             */
/*   Updated: 2019/04/23 14:59:44 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_exec_sa(t_size *size)
{
	int tmp;

	if (size->nba < 2)
		return (0);
	tmp = size->pa[0];
	size->pa[0] = size->pa[1];
	size->pa[1] = tmp;
	ft_fill_elem_with(size, "sa", 1);
	return (1);
}

int		ft_exec_sb(t_size *size)
{
	int tmp;

	if (size->nbb < 2)
		return (0);
	tmp = size->pb[0];
	size->pb[0] = size->pb[1];
	size->pb[1] = tmp;
	ft_fill_elem_with(size, "sb", 2);
	return (1);
}

int		ft_exec_pa(t_size *size)
{
	int *tab;
	int *tabb;

	(size->nbb)--;
	(size->nba++);
	if (!(tab = (int *)malloc(sizeof(int) * size->a)))
		ft_exit();
	if (!(tabb = (int *)malloc(sizeof(int) * size->nbb)))
		ft_exit();
	ft_exec_pa2(size, tab, tabb);
	ft_fill_elem_with(size, "pa", 3);
	free(tab);
	free(tabb);
	return (1);
}

int		ft_exec_pb(t_size *size)
{
	int *tab;
	int *tabb;

	(size->nbb)++;
	(size->nba--);
	if (!(tab = (int *)malloc(sizeof(int) * size->a)))
		ft_exit();
	if (!(tabb = (int *)malloc(sizeof(int) * (size->nbb + 1))))
		ft_exit();
	ft_exec_pb2(size, tab, tabb);
	ft_fill_elem_with(size, "pb", 4);
	free(tab);
	free(tabb);
	return (1);
}
