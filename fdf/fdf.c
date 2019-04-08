/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:33:34 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/25 11:34:09 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_key_exit(void)
{
	exit(EXIT_SUCCESS);
}

void		ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void		ft_exit_color(void)
{
	write(2, "Error Color\n", 12);
	exit(EXIT_FAILURE);
}

int						main(int argc, char **argv)
{
	int				fd;
	char			*line;
	t_mlx			*list;

	if (argc < 2)
		ft_exit();
	if (!(list = (t_mlx *)malloc(sizeof(t_mlx))))
		ft_exit();
	list->size = 0;
	if((fd = open(argv[1], O_RDONLY)) == -1)
		ft_exit();
	while (get_next_line(fd, &line) > 0)
		list->size++;
	close(fd);
	if((fd = open(argv[1], O_RDONLY)) == -1)
		ft_exit();
	list->map = ft_check_and_get(fd, list);
		close(fd);
	ft_get_map_tmp(list);
	ft_copy_data_tmp(list);
	ft_display_map(list);
	return (0);
}
