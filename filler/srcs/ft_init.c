/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 00:44:20 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/21 18:19:42 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_fill_board(t_map *map, int i, char *line)
{
	int j;
	int k;
	int err;

	j = 0;
	k = 0;
	while (line[j] && line[j] != 'X' && line[j] != 'X'
		&& line[j] != 'X' && line[j] != 'O' && line[j] != '.')
		j++;
	while (line[j])
	{
		if (line[j] == 'O' && (map->board[i][k] = 'O') == 'O')
			err = get_info_player(map, i, k, 0);
		else if (line[j] == 'X' && (map->board[i][k] = 'X') == 'X')
			err = get_info_player(map, i, k, 1);
		else if ((err = 0) == 0)
			map->board[i][k] = line[j];
		j++;
		k++;
	}
	map->board[i][k] = '\0';
	return (err);
}

int				get_board(t_map *map)
{
	int		i;
	char	*line;
	int		err;

	i = 0;
	if (!(map->board = (char **)malloc(sizeof(char*) * (map->by))))
		return (-1);
	if (get_next_line(0, &line) == -1)
		return (free_line(&line, -1));
	ft_strdel(&line);
	while (i < map->by && (err = get_next_line(0, &line)) > 0)
	{
		if (err == -1)
			return (free_line(&line, -1));
		if (!(map->board[i] = (char *)malloc(sizeof(char) * (map->bx + 1))))
			return (-1);
		if (ft_fill_board(map, i, line) == -1)
			return (-1);
		ft_strdel(&line);
		i++;
	}
	return (0);
}

int				get_player(t_map *map)
{
	char	*line;

	if (get_next_line(0, &line) < 0)
		return (free_line(&line, -1));
	if (ft_strstr(line, "exec p1") != NULL)
	{
		ft_strdel(&line);
		map->p1.lettre = 'O';
		map->p2.lettre = 'X';
		return (0);
	}
	else if (ft_strstr(line, "exec p2") != NULL)
	{
		ft_strdel(&line);
		map->turn = 0;
		map->p1.lettre = 'X';
		map->p2.lettre = 'O';
		return (0);
	}
	else
		ft_strdel(&line);
	return (-1);
}

int				get_board_dim(t_map *map)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) == -1)
		return (-1);
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			break ;
		i++;
	}
	i++;
	map->by = ft_atoi(line + i);
	while (line[i] && (line[i] <= '9' && line[i] >= '0'))
		i++;
	if (line[i] == ' ')
		i++;
	else
		return (-1);
	map->bx = ft_atoi(line + i);
	return (0);
}

int				init_map(t_map *map)
{
	if (get_player(map) == -1)
		return (-1);
	if (get_board_dim(map) == -1)
		return (-1);
	if (get_board(map) == -1)
		return (-1);
	get_config(map);
	return (0);
}
