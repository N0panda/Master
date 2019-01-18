/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:52:58 by ythomas           #+#    #+#             */
/*   Updated: 2019/01/18 11:05:55 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define SUCCESS 1
#define FAILURE 0

char		**creat_board(int taille)
{
	char	**board;
	int		i;
	int		y;

	i = 0;
	if (!(board = (char**)malloc(sizeof(char*) * (taille + 1))))
		return (NULL);
	while (i < taille)
		if (!(board[i++] = ft_strnew(taille)))
			return (NULL);
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

int			set_new_origin(t_tetri *m, int taille)
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

int			ft_solve(char **board, t_tetri *maillon, int taille)
{
	if (maillon == NULL)
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

char		**final_result(t_tetri *tetri, int *size_b)
{
	t_tetri		*maillon;
	char		**board;
	int			nb;

	nb = 0;
	maillon = tetri;
	while (maillon != NULL)
	{
		nb++;
		maillon = maillon->next;
	}
	*size_b = ft_sqrt(4 * nb);
	board = creat_board(*size_b);
	while (ft_solve(board, tetri, *size_b) == FAILURE)
	{
		(*size_b)++;
		free_file(board, (*size_b));
		board = creat_board(*size_b);
	}
	return (board);
}
