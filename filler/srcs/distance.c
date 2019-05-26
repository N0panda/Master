/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 15:01:00 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/19 15:01:10 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				get_distance_value(int vy1, int vx1, int vy2, int vx2)
{
	int result;

	result = (((vx2 - vx1) * (vx2 - vx1)) + ((vy2 - vy1) * (vy2 - vy1)));
	return (result);
}

void			get_closest_enemy(t_map *map, int vy1, int vx1)
{
	int vy2;
	int vx2;
	int tmp;

	vy2 = 0;
	while (vy2 < map->by)
	{
		vx2 = 0;
		while (vx2 < map->bx)
		{
			if (map->board[vy2][vx2] == map->p2.lettre)
			{
				if (map->dist > (tmp = get_distance_value(vy1, vx1, vy2, vx2)))
				{
					map->dist = tmp;
					map->opti_x = map->tmpx;
					map->opti_y = map->tmpy;
				}
			}
			vx2++;
		}
		vy2++;
	}
}

int				get_distance(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->py)
	{
		j = 0;
		while (j < map->px)
		{
			if (map->piece[i][j] == '*')
				get_closest_enemy(map, (map->tmpy + i), (map->tmpx + j));
			j++;
		}
		i++;
	}
	return (0);
}
