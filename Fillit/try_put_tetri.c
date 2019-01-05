/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_put_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 12:04:06 by ythomas           #+#    #+#             */
/*   Updated: 2019/01/05 15:21:22 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_try_it(t_tetri *m, char **board, int taille)
{
	int i;
	int j;
	int w;

	w = 0;
	i = 0;
	while (i < m->hauteur && (i + m->py < taille))
	{
		j = 0;
		while (j < m->largeur && (j + m->px < taille))
		{
			if (m->tetriminos[m->y + i][m->x + j] == '#' &&
				!(board[m->py + i][m->px + j] <= 'Z' &&
				board[m->py + i][m->px + j] >= 'A'))
				w++;
			j++;
		}
		i++;
	}
	if (w != 4)
		return (0);
	return (1);
}

static int	ft_do_it(t_tetri *m, char **board)
{
	int i;
	int j;

	i = 0;
	while (i < m->hauteur)
	{
		j = 0;
		while (j < m->largeur)
		{
			if (m->tetriminos[m->y + i][m->x + j] == '#')
				board[m->py + i][m->px + j] = m->lettre;
			if (m->tetriminos[m->y + i][m->x + j] == '.' &&
				!(board[m->py + i][m->px + j] <= 'Z' &&
				board[m->py + i][m->px + j] >= 'A'))
				board[m->py + i][m->px + j] = '.';
			j++;
		}
		i++;
	}
	return (1);
}

int			try_put_tetri(char **board, t_tetri *m, int taille)
{
	if (ft_try_it(m, board, taille) == 1)
		return (ft_do_it(m, board));
	else
		return (0);
}
