/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 18:20:58 by ythomas           #+#    #+#             */
/*   Updated: 2019/04/08 16:21:06 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_y(t_mlx *mlx, int key)
{
	mlx->paulz = 1;
	if (key == 88)
		ft_rotate_right(mlx);
	else if (key == 86)
		ft_rotate_left(mlx);
	return ;
}

void	ft_rotate_x(t_mlx *mlx, int key)
{
	mlx->paulz = 1;
	if (key == 91)
		ft_rotate_top(mlx);
	else if (key == 84)
		ft_rotate_bottom(mlx);
	return ;
}

void	ft_rotate_z(t_mlx *mlx, int key)
{
	mlx->paulz = 1;
	if (key == 92)
		ft_rotate_up(mlx);
	else if (key == 83)
		ft_rotate_down(mlx);
	return ;
}

void	ft_height(t_mlx *mlx, int key)
{
	if (mlx->paulz == 0)
	{
		if (key == 85)
			ft_height_less(mlx);
		else if (key == 89)
			ft_height_more(mlx);
	}
	else
		return ;
}
