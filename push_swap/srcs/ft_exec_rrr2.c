/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_rrr2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:00:19 by ythomas           #+#    #+#             */
/*   Updated: 2019/04/23 15:00:21 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_exec_ra(t_size *size)
{
	int *tab;
	int i;
	int y;

	if (!(tab = (int *)malloc(sizeof(int) * size->nba)))
		ft_exit();
	if (size->nba < 2)
		return (0);
	i = 0;
	y = 1;
	tab[size->nba - 1] = size->pa[0];
	while (i < size->nba - 1)
		tab[i++] = size->pa[y++];
	i = 0;
	while (i < size->nba)
	{
		size->pa[i] = tab[i];
		i++;
	}
	ft_fill_elem_with(size, "ra", 5);
	free(tab);
	return (1);
}

int		ft_exec_rb(t_size *size)
{
	int *tab;
	int i;
	int y;

	if (!(tab = (int *)malloc(sizeof(int) * size->nbb)))
		ft_exit();
	if (size->nbb < 2)
		return (0);
	i = 0;
	y = 1;
	tab[size->nbb - 1] = size->pb[0];
	while (i < size->nbb - 1)
		tab[i++] = size->pb[y++];
	i = 0;
	while (i < size->nbb)
	{
		size->pb[i] = tab[i];
		i++;
	}
	ft_fill_elem_with(size, "rb", 6);
	free(tab);
	return (1);
}

int		ft_exec_rra(t_size *size)
{
	int *tab;
	int i;
	int y;

	if (!(tab = (int *)malloc(sizeof(int) * size->nba)))
		ft_exit();
	if (size->nba < 2)
		return (0);
	i = 1;
	y = 0;
	tab[0] = size->pa[size->nba - 1];
	while (i < size->nba)
		tab[i++] = size->pa[y++];
	i = 0;
	while (i < size->nba)
	{
		size->pa[i] = tab[i];
		i++;
	}
	ft_fill_elem_with(size, "rra", 7);
	free(tab);
	return (1);
}

int		ft_exec_rrb(t_size *size)
{
	int *tab;
	int i;
	int y;

	if (!(tab = (int *)malloc(sizeof(int) * size->nbb)))
		ft_exit();
	if (size->nbb < 2)
		return (0);
	i = 1;
	y = 0;
	tab[0] = size->pb[size->nbb - 1];
	while (i < size->nbb)
		tab[i++] = size->pb[y++];
	i = 0;
	while (i < size->nbb)
	{
		size->pb[i] = tab[i];
		i++;
	}
	ft_fill_elem_with(size, "rrb", 8);
	free(tab);
	return (1);
}
