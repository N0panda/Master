/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:56:09 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/16 15:56:12 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			free_old_piece(t_map *map)
{
	int i;

	i = 0;
	while (i < map->py)
	{
		free(map->piece[i]);
		i++;
	}
	free(map->piece);
}

int				get_info_player(t_map *map, int j, int k, int cas)
{
	int err;

	if (cas == 0)
	{
		if (map->p1.lettre == 'O')
			err = get_info_p1(map, j, k);
		else
			err = get_info_p2(map, j, k);
	}
	else
	{
		if (map->p1.lettre == 'X')
			err = get_info_p1(map, j, k);
		else
			err = get_info_p2(map, j, k);
	}
	return (err);
}

void			get_config(t_map *map)
{
	if (map->p1.pos_y <= map->p2.pos_y && map->p1.pos_x <= map->p2.pos_x)
		map->config = 1;
	else if (map->p1.pos_y > map->p2.pos_y && map->p1.pos_x > map->p2.pos_x)
		map->config = 4;
	else if (map->p1.pos_y <= map->p2.pos_y && map->p1.pos_x > map->p2.pos_x)
		map->config = 2;
	else if (map->p1.pos_y > map->p2.pos_y && map->p1.pos_x <= map->p2.pos_x)
		map->config = 3;
	return ;
}

char			**clone_board(t_map *map)
{
	char	**tmp;
	int		i;
	int		j;

	if (!(tmp = (char **)malloc(sizeof(char *) * (map->by + 1))))
		return (NULL);
	i = 0;
	while (i < map->by)
	{
		j = 0;
		if (!(tmp[i] = (char *)malloc(sizeof(char) * (map->bx + 1))))
			return (NULL);
		while (map->board[j])
		{
			tmp[i][j] = map->board[i][j];
			j++;
		}
		tmp[i][j] = '\0';
		i++;
	}
	return (tmp);
}
