/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:50:23 by ythomas           #+#    #+#             */
/*   Updated: 2018/12/14 15:00:55 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	**file;

	if (argc != 2)
		ft_error(1);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error(1);
	if ((file = ft_creat_file(fd)) == NULL)
		ft_error(2);
	ft_prtstrtab(file);
	close(fd);
	return (0);
}
