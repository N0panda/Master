/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:59:38 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/30 16:59:55 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



void	ft_zoom(int key, t_mlx *mlx)
{
	if (key == 78)
	{
		if ((mlx->rate_x - 0.01 * mlx->zoom) < 0 || (mlx->rate_y - 0.01 * mlx->zoom) < 0)
			return;
		if (mlx->t_zoom == 0)
			mlx->zoom = 200;
		if (mlx->t_zoom > 0)
			mlx->zoom = mlx->zoom - 50;
		mlx->t_zoom--;
		mlx->rate_x = mlx->rate_x - 0.01 * mlx->zoom;
		mlx->rate_y = mlx->rate_y - 0.01 * mlx->zoom;
		ft_refresh_img(mlx);
	}
	else
	{
		if (mlx->t_zoom == 0)
			mlx->zoom = 200;
		if (mlx->t_zoom > 0)
			mlx->zoom = mlx->zoom + 50;
		mlx->rate_x = mlx->rate_x + 0.01 * mlx->zoom;
		mlx->rate_y = mlx->rate_y + 0.01 * mlx->zoom;
		mlx->t_zoom++;
		ft_refresh_img(mlx);
	}
}

void	ft_restart(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while (i < mlx->size)
	{
		j = 0;
		while (j < mlx->nb)
		{
			mlx->map[i][j] = mlx->map_tmp[i][j];
			mlx->map_x[i][j] = mlx->map_xtmp[i][j];
			mlx->map_y[i][j] = mlx->map_ytmp[i][j];
			j++;
		}
		i++;
	}
	ft_refresh_img(mlx);
}

int		ft_get_key(int key, t_mlx *mlx)
{
	if (key == 78 || key == 69)
		ft_zoom(key, mlx);
	else if (key == 53)
		ft_key_exit();
	else if (key == 126 || key == 123 || key == 125 || key == 124)
	 	ft_slide(key, mlx);
	else if (key == 83 || key == 92)
		ft_rotate_z(mlx, key);
	else if (key == 86|| key == 88)
		ft_rotate_y(mlx, key);
	else if (key == 91 || key == 84)
		ft_rotate_x(mlx, key);
	// else if (key == 85 || key == 89)
	// 	ft_height(mlx, key);
	else if (key == 12 || key == 13 || key == 14)
		ft_color_top(mlx, key);
	else if (key == 49)
		ft_restart(mlx);
	return (0);
}
