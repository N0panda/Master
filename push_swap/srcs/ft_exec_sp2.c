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
	int tab[size->a];
	int tabb[size->nbb];
	int i;
	int y;

	(size->nbb)--;
	(size->nba++);
	i = 0;
	y = 1;
	tab[0] = size->pb[0];
	while (y < size->nba)
		tab[y++] = size->pa[i++];
	i = -1;
	while (++i < size->a)
		size->pa[i] = tab[i];
	i = 0;
	y = 1;
	while (i < size->nbb)
		tabb[i++] = size->pb[y++];
	i = -1;
	while (++i < size->nbb)
		size->pb[i] = tabb[i];
	ft_fill_elem_with(size, "pa", 3);
	return (1);
}

int		ft_exec_pb(t_size *size)
{
	int tab[size->a];
	int tabb[size->nbb + 1];
	int i;
	int y;

	(size->nbb)++;
	(size->nba--);
	i = 0;
	y = 1;
	tabb[0] = size->pa[0];
	while (y < size->nbb)
		tabb[y++] = size->pb[i++];
	i = -1;
	while (++i < size->nbb)
		size->pb[i] = tabb[i];
	i = 0;
	y = 1;
	while (y < size->a)
		tab[i++] = size->pa[y++];
	i = -1;
	while (++i < size->a)
		size->pa[i] = tab[i];
	ft_fill_elem_with(size, "pb", 4);
	return (1);
}
