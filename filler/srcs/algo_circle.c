/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:54:06 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/21 13:54:19 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_add_colision(t_map *map, int pos_y, int pos_x)
{
	int count;

	count = 0;
	if ((pos_y + 1) < map->by && map->board[pos_y + 1][pos_x] == map->p2.lettre)
		count++;
	if ((pos_y - 1) >= 0 && map->board[pos_y - 1][pos_x] == map->p2.lettre)
		count++;
	if ((pos_x + 1) < map->bx && map->board[pos_y][pos_x + 1] == map->p2.lettre)
		count++;
	if ((pos_x - 1) >= 0 && map->board[pos_y][pos_x - 1] == map->p2.lettre)
		count++;
	return (count);
}

int				ft_get_colision(t_map *map)
{
	int i;
	int j;
	int t;

	i = 0;
	t = 0;
	while (i < map->py)
	{
		j = 0;
		while (j < map->px)
		{
			if (map->piece[i][j] == '*')
				t = t + ft_add_colision(map, (map->tmpy + i), (map->tmpx + j));
			j++;
		}
		i++;
	}
	if (t > map->colision)
	{
		map->opti_x = map->tmpx;
		map->opti_y = map->tmpy;
		map->colision = t;
	}
	return (0);
}

int				try_to_circle(t_map *map, int p1y, int p1x)
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
				ft_get_colision(map);
			j++;
		}
		i++;
	}
	return (0);
}

int				circle_enemy(t_map *map)
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
				try_to_circle(map, i, j);
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
