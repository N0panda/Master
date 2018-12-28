/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:52:58 by ythomas           #+#    #+#             */
/*   Updated: 2018/12/20 13:38:09 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_used_tetri(t_tetri *tetri) // retourne 1 si tout les maillons ont ete place.
{
	t_tetri *maillon;

	maillon = tetri;
	while (maillon != NULL)
	{
		if (maillon->used == 0)
			return (0);
		maillon = maillon->next;
	}
	return (1);
}


char		**creat_board(int	taille) // reallou une taille pour le board a +1 si aucune piece n'est placable
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

char		**try_put_tetri(char **board, t_tetri *tetri, int taille)
{
	t_tetri *maillon;
	int x;
	int y;

	y = 0;
	while (y < taille)
	{
		x = 0;
		while (x < taille)
		{
			maillon = tetri;
			while (maillon != NULL)
			{
				if (maillon->largeur > taille || maillon->hauteur > taille || maillon->used == 1)
				{
					maillon = maillon->next;
				}
				else
				{
					if (ft_try_it(maillon, board, x, y, taille) == 1 )
					{	
						maillon->used = 1;
						return (board);
					}
					maillon = maillon->next;
				}
			}
			x++;
		}
		y++;
	}
	return (NULL);
}

char		**realloc_board(int taille, char **board)
{
	char **temp;
	int i;
	int y;

	i = 0;
	temp = creat_board(taille);
	while (board[i])
	{
		y = 0;
		while (y < taille)
		{
			temp[i][y] = board[i][y];
			y++;
		}
		i++;
	}
	del_temp(board, taille);
	return (temp);

}

char		**final_result(t_tetri *tetri)
{
	t_tetri *maillon;
	char 	**board;
	int		taille;

	taille = 4;
	board = creat_board(taille);
	maillon = tetri;
	while (check_used_tetri(tetri) != 1) // tant que toutes les pieces ne sont pas utilise
	{
		if (try_put_tetri(board, tetri, taille) == NULL)
		{	
			taille++; // plus aucune piece ne peut etre placer a la taille donc on incremente
			board = realloc_board(taille, board);
		}
	}
	return (board);
}
