/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_y.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:30:47 by hcasanov          #+#    #+#             */
/*   Updated: 2019/04/08 16:22:35 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_rotate_right(t_mlx *mlx)
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
			mlx->map_x[i][j] = mlx->map_x[i][j] * cos(theta) + mlx->map[i][j] *
				sin(theta);
			mlx->map[i][j] = -tmp * sin(theta) + mlx->map[i][j] * cos(theta);
			j++;
		}
		i++;
	}
	ft_refresh_img(mlx);
}

void		ft_rotate_left(t_mlx *mlx)
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
			mlx->map_x[i][j] = mlx->map_x[i][j] * cos(theta) + mlx->map[i][j] *
				sin(theta);
			mlx->map[i][j] = -tmp * sin(theta) + mlx->map[i][j] * cos(theta);
			j++;
		}
		i++;
	}
	ft_refresh_img(mlx);
}
