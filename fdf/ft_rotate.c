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

void	ft_rotate_right(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < mlx->size)
	{
		j = 0;
		while (j < mlx->nb)
		{
			mlx->map_x[i][j] = mlx->map_x[i][j] * cos(0.3) + mlx->map[i][j] * sin(0.3);
			mlx->map[i][j] = (-1 * mlx->map_x[i][j]) * sin(0.3) + mlx->map[i][j] * cos(0.3);
			j++;
		}
		i++;
	}
	//i = 0;int y = 0;while(i < mlx->size){y=0; while(y < mlx->nb){printf("[%f]", mlx->map[i][y]);y++;}i++;printf("\n");}
		ft_refresh_img(mlx);
}

void	ft_rotate_left(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < mlx->size)
	{
		j = 0;
		while (j < mlx->nb)
		{
			mlx->map_x[i][j] = mlx->map_x[i][j] * cos(-0.3) + mlx->map[i][j] * sin(-0.3);
			mlx->map[i][j] = (-1 * mlx->map_x[i][j]) * sin(-0.3) + mlx->map[i][j] * cos(-0.3);
			j++;
		}
		i++;
	}
		ft_refresh_img(mlx);
}

void	ft_rotate_y(t_mlx *mlx, int key)
{
	if (key == 88)
		ft_rotate_right(mlx);
	else if (key == 86)
		ft_rotate_left(mlx);
	return ;
}

void	ft_rotate_z(t_mlx *mlx, int key)
{
	(void)mlx;
	(void)key;
	return ;
}