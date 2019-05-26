/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_stuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:31:06 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/15 13:31:21 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_fill_refresh_board(t_map *map, int i, char *line)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (line[j] && line[j] != 'X' && line[j] != 'o'
		&& line[j] != 'O' && line[j] != '.')
		j++;
	while (line[j])
	{
		map->board[i][k] = line[j];
		j++;
		k++;
	}
	map->board[i][k] = '\0';
	return (0);
}

int				ft_refresh_board(t_map *map)
{
	int		i;
	char	*line;
	int		err;

	i = 0;
	if (get_next_line(0, &line) == -1)
		return (free_line(&line, -1));
	while (i < map->by && (err = get_next_line(0, &line)) > 0)
	{
		if (err == -1)
			return (free_line(&line, -1));
		ft_fill_refresh_board(map, i, line);
		ft_strdel(&line);
		i++;
	}
	return (1);
}

int				ft_refresh_setup(t_map *map, char **line)
{
	ft_strdel(line);
	if (ft_refresh_board(map) == -1)
		return (-1);
	return (0);
}
