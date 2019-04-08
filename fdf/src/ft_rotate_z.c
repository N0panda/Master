/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_z.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:19:21 by ythomas           #+#    #+#             */
/*   Updated: 2019/04/08 16:22:56 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_rotate_up(t_mlx *mlx)
{
	int		i;
	int		j;
	double	tmp;
	float	theta;

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
			mlx->map_x[i][j] = mlx->map_x[i][j] * cos(theta) - mlx->map_y[i][j]
				* sin(theta);
			mlx->map_y[i][j] = tmp * sin(theta) + mlx->map_y[i][j] * cos(theta);
			j++;
		}
		i++;
	}
	ft_refresh_img(mlx);
}

void		ft_rotate_down(t_mlx *mlx)
{
	int		i;
	int		j;
	double	tmp;
	float	theta;

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
			mlx->map_x[i][j] = mlx->map_x[i][j] * cos(theta) - mlx->map_y[i][j]
				* sin(theta);
			mlx->map_y[i][j] = tmp * sin(theta) + mlx->map_y[i][j] * cos(theta);
			j++;
		}
		i++;
	}
	ft_refresh_img(mlx);
}
