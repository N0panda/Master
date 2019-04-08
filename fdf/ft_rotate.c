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

void	ft_rotate_right(t_mlx *mlx)
{
	int i;
	int j;
	double tmp;
	float theta;

	i = 0;
	j = 0;
	tmp = 0;
	theta = 5 * M_PI / 180;
	while (i < mlx->size)
	{
		j = 0;
		while (j < mlx->nb)
		{
			tmp = mlx->map_x[i][j];
			mlx->map_x[i][j] = mlx->map_x[i][j] * cos(theta) + mlx->map[i][j] * sin(theta);
			mlx->map[i][j] = -tmp * sin(theta) + mlx->map[i][j] * cos(theta);
			j++;
		}
		i++;
	}
		ft_refresh_img(mlx);
}

void	ft_rotate_left(t_mlx *mlx)
{
	int i;
	int j;
	double tmp;
	float theta;
	
	i = 0;
	j = 0;
	tmp = 0;
	theta = -(5 * M_PI / 180);
	while (i < mlx->size)
	{
		j = 0;
		while (j < mlx->nb)
		{
			tmp = mlx->map_x[i][j];
			mlx->map_x[i][j] = mlx->map_x[i][j] * cos(theta) + mlx->map[i][j] * sin(theta);
			mlx->map[i][j] = -tmp * sin(theta) + mlx->map[i][j] * cos(theta);
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

void	ft_rotate_x(t_mlx *mlx, int key)
{
	if (key == 91)
		ft_rotate_top(mlx);
	else if (key == 84)
		ft_rotate_bottom(mlx);
	return ;
}

void	ft_rotate_z(t_mlx *mlx, int key)
{
	if (key == 92)
		ft_rotate_up(mlx);
	else if (key == 83)
		ft_rotate_down(mlx);
	return ;
}

// void	ft_height(t_mlx *mlx, int key)
// {
// 	if (key == 85)
// 		ft_height_less(mlx);
// 	else if (key == 89)
// 		ft_height_more(mlx);
// }