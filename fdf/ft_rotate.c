/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 18:20:58 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/31 18:21:07 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_x(t_mlx *mlx, int key)
{
	(void)mlx;
		(void)key;
	return ;
}

void	ft_rotate_y(t_mlx *mlx, int key)
{
	int i;
	int j;

	i = 0;
	if (key == 88)
	{
		while (i < mlx->size)
		{
			j = 0;
			while (j < mlx->nb)
			{
				mlx->map_x[i][j] = mlx->map_x[i][j] * cos(/*mlx->rad / (180 / M_PI)*/0.1) + mlx->map[i][j] * sin(0.1);
				mlx->map[i][j] = (-1 * mlx->map_x[i][j]) * sin(0.1) + mlx->map[i][j] * cos(0.1);
				j++;
			}
			i++;
		}
	}
	else if (key == 88)
	{

	}
	ft_refresh_img(mlx);
	return ;
}

void	ft_rotate_z(t_mlx *mlx, int key)
{
	(void)mlx;
	(void)key;
	return ;
}