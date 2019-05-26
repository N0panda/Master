/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 03:04:22 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/07 03:06:51 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			free_players(t_map *map)
{
	int i;

	i = 0;
	while (i < map->p1.h)
		ft_strdel(&(map->p1.l_p[i++]));
	free(map->p1.l_p);
	i = 0;
	while (i < map->p2.h)
		ft_strdel(&(map->p2.l_p[i++]));
	free(map->p2.l_p);
	return ;
}

int				final_free(t_map *map)
{
	int i;

	i = 0;
	while (i < map->by)
		ft_strdel(&(map->board[i++]));
	free(map->board);
	i = 0;
	while (i < map->py)
		ft_strdel(&(map->piece[i++]));
	free(map->piece);
	i = 0;
	free_players(map);
	return (0);
}

int				free_line(char **line, int cas)
{
	free(*line);
	(*line) = NULL;
	if (cas == 0)
		return (0);
	else
		return (-1);
}
