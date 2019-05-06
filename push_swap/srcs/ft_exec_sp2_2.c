/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_sp2_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:29:59 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/05 15:30:03 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exec_pa2(t_size *size, int *tab, int *tabb)
{
	int i;
	int y;

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
}

void	ft_exec_pb2(t_size *size, int *tab, int *tabb)
{
	int i;
	int y;

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
}
