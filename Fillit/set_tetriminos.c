/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:52:58 by ythomas           #+#    #+#             */
/*   Updated: 2018/12/17 18:43:22 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**creat_board(int	taille)
{
	char **board;
	int i;
	
	i = 0;
	if (!(board = (char**)malloc(sizeof(char*) * (taille + 1))))
		return (NULL);
	while (i < taille + 1)
	{
		board = strnew(taille);
		i++;
	}
	board[taille + 1] = 0;
	return (board);
}

char		**ft_put_tetri(char **board, t_tetri *maillon)
{
	int i;
	int y;

	i = 0;
	while (board[i])
	{
		
	}
}

char		**final_result(t_tetri *tetri)
{
	t_tetri *maillon;
	char 	**board;
	int		taille;

	taille = 2;
	board = creat_board(taille);
	maillon = tetri;
	while (maillon != NULL)
	{
		board = ft_put_tetri(board, maillon);
		maillon = maillon->next;
	}
	return (board);
}
