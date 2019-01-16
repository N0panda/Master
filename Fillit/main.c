/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:50:23 by ythomas           #+#    #+#             */
/*   Updated: 2018/12/29 11:50:44 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	**file;
	char	**board;
	t_tetri *tetri;

	if (argc != 2)
		ft_error(1);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error(1);
	if ((file = ft_creat_file(fd)) == NULL)
		ft_error(2);
	tetri = creat_list(file);
	close(fd);
	board = final_result(tetri);
	i = 0;
	ft_prtstrtab(board);
	return (0);
}