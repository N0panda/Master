/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:33:17 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/21 15:34:28 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				fill_anywhere(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->by)
	{
		j = 0;
		while (j < map->bx)
		{
			if (try_it(map, i, j) == 0)
			{
				map->opti_x = map->tmpx;
				map->opti_y = map->tmpy;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
