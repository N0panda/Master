/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:52:58 by ythomas           #+#    #+#             */
/*   Updated: 2018/12/28 19:58:55 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define SUCCESS 1
#define FAILURE 0

char		**creat_board(int	taille)
{
	char **board;
	int i;
	int y;
	
	i = 0;
	if (!(board = (char**)malloc(sizeof(char*) * (taille + 1))))
		return (NULL);
	while (i < taille + 1)
	{
		board[i] = ft_strnew(taille);
		i++;
	}
	board[taille] = 0;

	i = 0;

	while (board[i])
	{
		y = 0;
		while (y < taille)
		{
			board[i][y] = '.';
			y++;
		}
		i++;
	}
	return (board);
}

int			ft_try_it(t_tetri *m, char **board, int x, int y, int taille)
{
	int i;
	int j;
	int w;

	w = 0;
	i = 0;
	while (i < m->hauteur && (i + y < taille))
	{
		j = 0;
		while (j < m->largeur && (j + x < taille))
		{
			if (m->tetriminos[m->y+i][m->x+j] == '#' && !(board[y+i][x+j] <= 'Z' && board[y+i][x+j] >='A'))
			{
				w++;
			}
			j++;
		}
		i++;
	}
	if (w != 4)
		return (0);
	i = 0;
	while (i < m->hauteur)
	{
		j = 0;
		while (j < m->largeur)
		{
			if (m->tetriminos[m->y+i][m->x+j] == '#')
			{
				board[y+i][x+j] = m->lettre;
			}
			if (m->tetriminos[m->y+i][m->x+j] == '.' && !(board[y+i][x+j] <= 'Z' && board[y+i][x+j] >='A'))
				board[y+i][x+j] = '.';
			j++;
		}
		i++;
	}
	return (1);
}

int		try_put_tetri(char **board, t_tetri *m, int taille)
{
	int x;
	int y;

	y = m->py;
	x = m->px;
	if (ft_try_it(m, board, x, y, taille) == 1)
		return (1);
	return (0);
}

void		erase_tetri(char **board, t_tetri *maillon)
{
	int i;
	int j;

	i = 0;
	while (board[i])
	{
		j = 0;
		while (board[i][j])
		{
			if (board[i][j] == maillon->lettre)
				board[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		set_new_origin(t_tetri *m, int taille)
{

	if (m->py == taille - 1 && m->px == taille - 1)
		return (FAILURE);
	if (m->px < taille - 1)
		m->px++;
	else
	{
		m->px = 0;
		m->py++;
	}
	return (SUCCESS);
}

int		ft_solve(char **board, t_tetri *maillon, int taille)
{
	if (maillon ==  NULL)
		return (SUCCESS);
	maillon->py = 0;
	maillon->px = 0;
	while (1)
	{
		if (try_put_tetri(board, maillon, taille) == SUCCESS)
		{
			if (ft_solve(board, maillon->next, taille) == SUCCESS)
				return (SUCCESS);
		}
		erase_tetri(board, maillon);
		if (set_new_origin(maillon, taille) == FAILURE)
			return (FAILURE);
	}
	return (FAILURE);
}

char		**final_result(t_tetri *tetri)
{
	t_tetri *maillon;
	char 	**board;
	int		taille;
	int		nb;

	nb = 0;
	maillon = tetri;
	while (maillon != NULL)
	{
		nb++;
		maillon = maillon->next;
	}
	taille = ft_sqrt(4 * nb);
	board = creat_board(taille);
	while (ft_solve(board, tetri, taille) == FAILURE)
	{
		taille++;
		free(board);
		board = creat_board(taille);
		ft_putnbr(taille);
		ft_putchar('\n');
	}
	return (board);
}
