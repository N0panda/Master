/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 00:01:47 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/21 18:27:18 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				filler(void)
{
	t_map	map;
	int		quit;

	map.touched = 0;
	map.piece = NULL;
	map.stat = 0;
	if (init_map(&map) == -1)
		return (-1);
	while ((quit = player_turn(&map)) > 0)
	{
		if (quit == -1)
			return (-1);
		if (map.stat == 1)
			break ;
	}
	if (quit == -1)
		return (-1);
	final_free(&map);
	return (0);
}

int				main(void)
{
	if (filler() == -1)
		exit(EXIT_FAILURE);
	return (0);
}
