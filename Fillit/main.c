/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:50:23 by ythomas           #+#    #+#             */
/*   Updated: 2018/12/17 18:02:10 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	**file;
	char	**board;
	t_tetri *tetri;
	t_tetri *maillon;

	if (argc != 2)
		ft_error(1);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error(1);
	if ((file = ft_creat_file(fd)) == NULL)
		ft_error(2);
	tetri = creat_list(file);
	close(fd);
	maillon = tetri;
	while (maillon != NULL)
	{
		printf("Hauteur : %d\n", maillon->hauteur);
		printf("Largeur : %d\n", maillon->largeur);
		printf("Lettre : %c\n", maillon->lettre);
		printf("coordonnee x : %d\n", maillon->x);
		printf("coordonnee y : %d\n", maillon->y);
		printf("%s\n", maillon->tetriminos[0]);
		printf("%s\n", maillon->tetriminos[1]);
		printf("%s\n", maillon->tetriminos[2]);
		printf("%s\n\n\n", maillon->tetriminos[3]);
		maillon = maillon->next;
	}
	//board = final_result(tetri);
	return (0);
}
