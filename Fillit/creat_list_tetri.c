/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list_tetri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:04:09 by ythomas           #+#    #+#             */
/*   Updated: 2018/12/17 16:51:06 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"



int		check_hauteur(char **tetriminos) // -------------- OK
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
				break;
			}
			y++;
		}
		i++;
	}
	return (b);
}

int		check_largeur(char **tetriminos) // -------------- OK
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
				break;
			}
			i++;
		}
		y++;
	}
	return (b);
}

t_tetri		*creat_tetri_maillon(char **file) // transforme le file correcte en liste chaine de tetriminos.
{
	t_tetri *tetri;
	int i;

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
	tetri->y= y_origine(file);
	tetri->next = NULL;
	return (tetri);
}

t_tetri		*creat_list(char **file)
{
	int i;
	t_tetri *tetri;
	t_tetri *maillon;

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
	return (tetri);
}

