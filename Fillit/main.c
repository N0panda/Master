/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:50:23 by ythomas           #+#    #+#             */
/*   Updated: 2019/01/18 11:09:02 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	**file;
	char	**board;
	t_tetri *tetri;

	i = 0;
	if (argc != 2)
		ft_error(1);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error(1);
	if ((file = ft_creat_file(fd, &i)) == NULL)
		ft_error(2);
	tetri = creat_list(file, i);
	close(fd);
	board = final_result(tetri, &fd);
	ft_prtstrtab(board);
	ft_free_list(tetri);
	free_file(board, fd);
	return (0);
}
