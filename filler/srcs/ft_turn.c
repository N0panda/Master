/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:14:48 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/07 13:15:03 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_get_piece_dim(t_map *map, char **line)
{
	int i;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == ' ')
			break ;
		i++;
	}
	i++;
	map->py = ft_atoi((*line) + i);
	while ((*line)[i] && (*line)[i] <= '9' && (*line)[i] >= '0')
		i++;
	if ((*line)[i] == ' ')
		i++;
	else
		return (free_line(line, -1));
	map->px = ft_atoi((*line) + i);
	return (free_line(line, 0));
}

int				ft_get_piece(t_map *map)
{
	int		i;
	char	*line;
	int		err;
	int		j;

	i = 0;
	if (!(map->piece = (char **)malloc(sizeof(char *) * (map->py))))
		return (-1);
	while (i < map->py && (err = get_next_line(0, &line)) > 0)
	{
		if (err == -1)
			return (free_line(&line, -1));
		if (!(map->piece[i] = (char *)malloc(sizeof(char) * (map->px + 1))))
			return (-1);
		j = 0;
		while (line[j])
		{
			map->piece[i][j] = line[j];
			j++;
		}
		map->piece[i][j] = '\0';
		i++;
	}
	return (0);
}

int				ft_piece(t_map *map, char **line)
{
	map->turn = 1;
	if (map->piece != NULL)
		free_old_piece(map);
	if (ft_get_piece_dim(map, line) == -1)
		return (-1);
	if (ft_get_piece(map) == -1)
		return (-1);
	return (0);
}

int				player_turn(t_map *map)
{
	char	*line;

	if (get_next_line(0, &line) == -1)
		return (free_line(&line, -1));
	if (ft_strstr(line, "Piece") != NULL)
	{
		if (ft_piece(map, &line) == -1)
			return (free_line(&line, -1));
		if (ft_put_next_piece(map) == -1)
			return (-1);
		ft_printf("%d %d\n", map->opti_y, map->opti_x);
		return (1);
	}
	else if (ft_strstr(line, "Plateau") != NULL)
	{
		if (ft_refresh_setup(map, &line) == -1)
			return (-1);
		if (map->turn == 1)
			map->turn = 0;
		return (1);
	}
	else
		return (free_line(&line, -1));
}
