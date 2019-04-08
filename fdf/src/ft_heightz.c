/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_height.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:30:45 by hcasanov          #+#    #+#             */
/*   Updated: 2019/04/08 16:15:10 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_height_less(t_mlx *mlx)
{
	int		i;
	int		j;
	double	theta;

	theta = 5 * M_PI / 180;
	i = 0;
	j = 0;
	while (i < mlx->size)
	{
		j = 0;
		while (j < mlx->nb)
		{
			if (mlx->map[i][j] != 0)
				mlx->map[i][j] = mlx->map[i][j] / 1.2;
			j++;
		}
		i++;
	}
	if (mlx->height > 0)
		(mlx->height)--;
	ft_refresh_img(mlx);
}

void		ft_height_more(t_mlx *mlx)
{
	int		i;
	int		j;
	double	theta;

	theta = 5 * M_PI / 180;
	i = 0;
	j = 0;
	if (mlx->height >= 20)
		return ;
	while (i < mlx->size)
	{
		j = 0;
		while (j < mlx->nb)
		{
			if (mlx->map[i][j] != 0)
				mlx->map[i][j] = mlx->map[i][j] * 1.2;
			j++;
		}
		i++;
	}
	(mlx->height)++;
	ft_refresh_img(mlx);
}
