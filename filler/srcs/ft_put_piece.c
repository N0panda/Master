/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:54:05 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/21 18:21:09 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <limits.h>

void			init_var_algo(t_map *map)
{
	map->tmpx = 0;
	map->tmpy = 0;
	map->opti_x = 0;
	map->opti_y = 0;
	map->dist = INT_MAX;
	map->colision = 0;
}

int				ft_touched(t_map *map)
{
	int i;
	int y;

	i = 0;
	while (i + 1 < map->by)
	{
		y = 0;
		while (y + 1 < map->bx)
		{
			if ((map->board[i][y] == 'O' && map->board[i + 1][y] == 'X')
				|| (map->board[i][y] == 'O' && map->board[i][y + 1] == 'X'))
				return (1);
			else if ((map->board[i][y] == 'X' && map->board[i + 1][y] == 'O')
				|| (map->board[i][y] == 'X' && map->board[i][y + 1] == 'O'))
				return (1);
			y++;
		}
		i++;
	}
	return (0);
}

int				ft_put_next_piece(t_map *map)
{
	if (map->touched == 0 && (map->touched = ft_touched(map)) == 0)
	{
		init_var_algo(map);
		if (rush_enemy(map) == 1)
			map->stat = 1;
	}
	else
	{
		init_var_algo(map);
		if (circle_enemy(map) == 1)
			map->stat = 1;
	}
	if (map->stat == 1 && fill_anywhere(map) == 1)
		map->stat = 0;
	if (refresh_p1(map) == -1)
		return (-1);
	return (0);
}
