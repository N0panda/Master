/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:51:04 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/16 15:51:06 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				get_info_p2(t_map *map, int j, int k)
{
	map->p2.pos_y = j;
	map->p2.pos_x = k;
	map->p2.w = 1;
	map->p2.h = 1;
	if (!(map->p2.l_p = (char **)malloc(sizeof(char *))))
		return (-1);
	if (!(map->p2.l_p[0] = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	map->p2.l_p[0][0] = map->p2.lettre;
	map->p2.l_p[0][1] = '\0';
	return (0);
}
