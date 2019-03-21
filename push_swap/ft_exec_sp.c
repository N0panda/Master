/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_sp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:36:45 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/12 16:37:02 by ythomas          ###   ########.fr       */
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
	return (1);
}

int		ft_exec_pa(t_size *size)
{
	int tab[size->nba + 1];
	int tabb[size->nbb - 1];
	int i;
	int y;
	(size->nbb)--;
	(size->nba++);

	i = 0;
	y = 1;
	tabb[0] = size->pb[0];
	while (i < size->nba)
		tabb[y++] = size->pa[i++];
	i = -1;
	while (++i < size->nba)
		size->pa[i] = tabb[i];
	i = 0;
	y = 1;
	while (i < size->nbb)
		tab[i++] = size->pb[y++];
	i = -1;
	while (++i < size->nbb)
		size->pb[i] = tab[i];
	while (i < size->b)
		size->pb[i++] = 0;
	return (1);
}

int		ft_exec_pb(t_size *size)
{
	int tab[size->nba - 1];
	int tabb[size->nbb + 1];
	int i;
	int y;
	(size->nbb)++;
	(size->nba--);

	i = 0;
	y = 1;
	tabb[0] = size->pa[0];
	while (i < size->nbb)
		tabb[y++] = size->pb[i++];
	i = -1;
	while (++i < size->nbb)
		size->pb[i] = tabb[i];
	i = 0;
	y = 1;
	while (i < size->nba)
		tab[i++] = size->pa[y++];
	i = -1;
	while (++i < size->nba)
		size->pa[i] = tab[i];
	while (i < size->a)
		size->pa[i++] = 0;
	return (1);
}