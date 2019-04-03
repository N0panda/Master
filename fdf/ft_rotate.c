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

void	ft_rotate_x(t_mlx *mlx)
{
	(void)mlx;
	return ;
}

void	ft_rotate_y(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while (i < mlx->size)
	{
		j = 0;
		while (j < mlx->nb)
		{
			mlx->map_x[i][j] = mlx->map_x[i][j] * cos(0.5);
			j++;
		}
		i++;
	}
	ft_refresh_img(mlx);
	return ;
}

void	ft_rotate_z(t_mlx *mlx)
{
	(void)mlx;
	return ;
}