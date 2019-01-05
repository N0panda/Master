/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:50:09 by ythomas           #+#    #+#             */
/*   Updated: 2018/12/29 11:44:57 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"

static int			ft_checkfile(char **file, int size)
{
	int i;
	int y;

	i = 0;
	if (file[size - 1][0] == '\0' || !(size % 5 == 4))
		return (-1);
	while (i < size)
	{
		if (i != 0 && ((i + 1) % 5) == 0 && ft_strcmp(file[i], "") != 0)
			return (-1);
		if (((i + 1) % 5) != 0 && (file[i][0] != '#' && file[i][0] != '.'))
			return (-1);
		y = 0;
		while (file[i][y])
		{
			if (y > 3 || (file[i][y] != '#' && file[i][y] != '.'))
				return (-1);
			y++;
		}
		if (y < 4 && (i + 1) % 5 != 0 && i != 0)
			return (-1);
		i++;
	}
	return (1);
}

static int			ft_hashtag_check(char **file)
{
	int i;
	int y;
	int z;

	i = 0;
	z = 0;
	while (i < 4)
	{
		y = 0;
		while (file[i][y])
		{
			if (file[i][y] == '#')
				z++;
			y++;
		}
		i++;
	}
	if (z != 4)
		return (-1);
	return (1);
}

static int			ft_is_tetriminos(char **file)
{
	int i;
	int y;
	int z;

	z = 0;
	file = creat_temp_file(file);
	i = 0;
	while (i++ < 5)
	{
		y = 1;
		while (file[i][y])
		{
			if (file[i][y] == '#' && file[i][y + 1] == '#')
				z++;
			if (file[i][y] == '#' && file[i + 1][y] == '#')
				z++;
			if (file[i][y] == '#' && file[i][y - 1] == '#')
				z++;
			if (file[i][y] == '#' && file[i - 1][y] == '#')
				z++;
			y++;
		}
	}
	del_temp(file, 6);
	return (z < 6 ? -1 : 1);
}

static int			ft_check_tetriminos(char **file, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if ((ft_hashtag_check(file + i)) == -1)
			return (-1);
		if ((ft_is_tetriminos(file + i)) == -1)
			return (-1);
		i = i + 5;
	}
	return (1);
}

char				**ft_creat_file(int fd)
{
	char	*line;
	char	**file;
	int		i;

	i = 0;
	if (!(file = (char **)malloc(sizeof(char *) * 130)))
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		file[i] = ft_strdup(line);
		i++;
		free(line);
		line = NULL;
		if (i > 129)
			return (NULL);
	}
	if (i < 4)
		return (NULL);
	else
		file[i] = 0;
	if ((ft_checkfile(file, i)) == -1)
		return (NULL);
	if ((ft_check_tetriminos(file, i)) == -1)
		return (NULL);
	return (file);
}
