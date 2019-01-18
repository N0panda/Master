/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list_tetri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:04:09 by ythomas           #+#    #+#             */
/*   Updated: 2019/01/18 11:03:13 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_hauteur(char **tetriminos)
{
	int i;
	int y;
	int b;

	i = 0;
	b = 0;
	while (i < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tetriminos[i][y] == '#')
			{
				b++;
				break ;
			}
			y++;
		}
		i++;
	}
	return (b);
}

int			check_largeur(char **tetriminos)
{
	int i;
	int y;
	int b;

	y = 0;
	b = 0;
	while (y < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetriminos[i][y] == '#')
			{
				b++;
				break ;
			}
			i++;
		}
		y++;
	}
	return (b);
}

t_tetri		*creat_tetri_maillon(char **file)
{
	t_tetri		*tetri;
	int			i;

	i = 0;
	if (!(tetri = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	if (!(tetri->tetriminos = (char**)malloc(sizeof(char*) * 4)))
		return (NULL);
	while (i < 4)
	{
		tetri->tetriminos[i] = ft_strnew(4);
		ft_strncpy(tetri->tetriminos[i], file[i], 4);
		i++;
	}
	tetri->hauteur = check_hauteur(file);
	tetri->largeur = check_largeur(file);
	tetri->x = x_origine(file);
	tetri->y = y_origine(file);
	tetri->px = 0;
	tetri->py = 0;
	tetri->next = NULL;
	return (tetri);
}

void		free_file(char **file, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(file[i]);
		i++;
	}
	free(file);
	file = NULL;
}

t_tetri		*creat_list(char **file, int size)
{
	int			i;
	t_tetri		*tetri;
	t_tetri		*maillon;

	tetri = creat_tetri_maillon(file);
	tetri->lettre = 'A';
	maillon = tetri;
	i = 4;
	while (file[i])
	{
		maillon->next = creat_tetri_maillon(file + i + 1);
		maillon->next->lettre = maillon->lettre + 1;
		maillon = maillon->next;
		i = i + 5;
	}
	free_file(file, size);
	return (tetri);
}
