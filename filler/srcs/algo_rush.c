/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_rush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:31:27 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/17 14:31:29 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				try_it_suit(t_map *map, int sy, int sx, int *cover)
{
	int i;
	int j;

	i = 0;
	while (i < map->py)
	{
		j = 0;
		while (j < map->px)
		{
			if ((sy + i) >= map->by || (sx + j) >= map->bx)
				return (-1);
			else if (map->piece[i][j] == '*'
				&& map->board[sy + i][sx + j] == map->p2.lettre)
				return (-1);
			else if (map->piece[i][j] == '*'
				&& map->board[sy + i][sx + j] == map->p1.lettre)
				(*cover)++;
			if (*cover > 1)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int				try_it(t_map *map, int sy, int sx)
{
	int cover;

	cover = 0;
	if (sy < 0 || sx < 0 || sy >= map->by || sx >= map->bx)
		return (-1);
	if (try_it_suit(map, sy, sx, &cover) == -1)
		return (-1);
	if (cover == 0)
		return (-1);
	map->tmpy = sy;
	map->tmpx = sx;
	return (0);
}

int				try_to_place(t_map *map, int p1y, int p1x)
{
	int i;
	int j;

	i = 0;
	while (i < map->py)
	{
		j = 0;
		while (j < map->px)
		{
			if (map->piece[i][j] == '*' && try_it(map, p1y - i, p1x - j) == 0)
				get_distance(map);
			j++;
		}
		i++;
	}
	return (0);
}

int				brute_force_algo(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->by)
	{
		j = 0;
		while (j < map->bx)
		{
			if (map->board[i][j] == map->p1.lettre)
				try_to_place(map, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int				rush_enemy(t_map *map)
{
	int i;
	int j;

	i = map->p1.pos_y;
	while (i < (map->p1.pos_y + map->p1.h))
	{
		j = map->p1.pos_x;
		while (j < (map->p1.pos_x + map->p1.w))
		{
			if (map->board[i][j] == map->p1.lettre)
				try_to_place(map, i, j);
			j++;
		}
		i++;
	}
	if (map->opti_x == 0 && map->opti_y == 0)
		brute_force_algo(map);
	if (map->opti_x == 0 && map->opti_y == 0)
		return (1);
	return (0);
}
