/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   origine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:14:12 by ythomas           #+#    #+#             */
/*   Updated: 2018/12/17 17:03:56 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		x_origine(char **file)
{
	int i;
	int j;
	int x;

	i = 0;
	x = 4;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (file[i][j] == '#' && j < x)
			{
				x = j;
				break;
			}
			j++;
		}
		i++;
	}
	return (x);
}

int		y_origine(char **file)
{
	int i;
	int j;
	int y;

	j = 0;
	y = 4;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (file[i][j] == '#' && i < y)
			{
				y = i;
				break;
			}
			i++;
		}
		j++;
	}
	return (y);
}
