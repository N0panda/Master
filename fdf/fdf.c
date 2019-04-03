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
	if((fd = open(argv[1], O_RDONLY)) == 0)
		return (0);
	while (get_next_line(fd, &line) > 0)
		list->size++;
	close(fd);
	if((fd = open(argv[1], O_RDONLY)) == 0)
		return (0);
	list->map = ft_check_and_get(fd, list);
	//int i = 0;int y = 0;while(i < list->size){y=0; while(y < list->nb){printf("[%f]", list->map_y[i][y]);y++;}i++;printf("\n");}
	close(fd);
	ft_display_map(list);
	return (0);
}
