/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:50:56 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/16 15:50:58 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				get_info_p1(t_map *map, int j, int k)
{
	map->p1.pos_y = j;
	map->p1.pos_x = k;
	map->p1.w = 1;
	map->p1.h = 1;
	if (!(map->p1.l_p = (char **)malloc(sizeof(char *))))
		return (-1);
	if (!(map->p1.l_p[0] = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	map->p1.l_p[0][0] = map->p1.lettre;
	map->p1.l_p[0][1] = '\0';
	return (0);
}

void			free_last_piece(t_map *map)
{
	int i;

	i = 0;
	while (i < map->p1.h)
	{
		free(map->p1.l_p[i]);
		i++;
	}
	free(map->p1.l_p);
}

int				refresh_p1(t_map *map)
{
	int i;
	int j;

	free_last_piece(map);
	if (!(map->p1.l_p = (char **)malloc(sizeof(char *) * (map->py))))
		return (-1);
	i = 0;
	while (i < map->py)
	{
		j = 0;
		if (!(map->p1.l_p[i] = (char *)malloc(sizeof(char) * (map->px + 1))))
			return (-1);
		while (map->piece[i][j])
		{
			map->p1.l_p[i][j] = map->piece[i][j];
			j++;
		}
		map->p1.l_p[i][j] = '\0';
		i++;
	}
	map->p1.pos_y = map->opti_y;
	map->p1.pos_x = map->opti_x;
	map->p1.w = map->px;
	map->p1.h = map->py;
	return (0);
}
