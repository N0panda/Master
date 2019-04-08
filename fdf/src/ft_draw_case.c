/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:33:13 by hcasanov          #+#    #+#             */
/*   Updated: 2019/04/08 15:23:49 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_case1(t_mlx *mlx)
{
	while (1)
	{
		if (mlx->x1 > mlx->x2 || mlx->y1 > mlx->y2 || ((mlx->x1 == mlx->x2) &&
					(mlx->y1 == mlx->y2)))
			break ;
		ft_set_pixel(mlx, mlx->x1, mlx->y1);
		mlx->e2 = mlx->err;
		if (mlx->e2 > -(mlx->dx))
		{
			mlx->err = mlx->err - mlx->dy;
			mlx->x1 = mlx->x1 + mlx->sx;
		}
		if (mlx->e2 < mlx->dy)
		{
			mlx->err = mlx->err + mlx->dx;
			mlx->y1 = mlx->y1 + mlx->sy;
		}
	}
}

void		ft_draw_case2(t_mlx *mlx)
{
	while (1)
	{
		if (mlx->x1 < mlx->x2 || mlx->y1 > mlx->y2 || ((mlx->x1 == mlx->x2) &&
					(mlx->y1 == mlx->y2)))
			break ;
		ft_set_pixel(mlx, mlx->x1, mlx->y1);
		mlx->e2 = mlx->err;
		if (mlx->e2 > -(mlx->dx))
		{
			mlx->err = mlx->err - mlx->dy;
			mlx->x1 = mlx->x1 + mlx->sx;
		}
		if (mlx->e2 < mlx->dy)
		{
			mlx->err = mlx->err + mlx->dx;
			mlx->y1 = mlx->y1 + mlx->sy;
		}
	}
}

void		ft_draw_case3(t_mlx *mlx)
{
	while (1)
	{
		if (mlx->x1 > mlx->x2 || mlx->y1 < mlx->y2 || ((mlx->x1 == mlx->x2) &&
					(mlx->y1 == mlx->y2)))
			break ;
		ft_set_pixel(mlx, mlx->x1, mlx->y1);
		mlx->e2 = mlx->err;
		if (mlx->e2 > -(mlx->dx))
		{
			mlx->err = mlx->err - mlx->dy;
			mlx->x1 = mlx->x1 + mlx->sx;
		}
		if (mlx->e2 < mlx->dy)
		{
			mlx->err = mlx->err + mlx->dx;
			mlx->y1 = mlx->y1 + mlx->sy;
		}
	}
}

void		ft_draw_case4(t_mlx *mlx)
{
	while (1)
	{
		if (mlx->x1 < mlx->x2 || mlx->y1 < mlx->y2 || ((mlx->x1 == mlx->x2) &&
					(mlx->y1 == mlx->y2)))
			break ;
		ft_set_pixel(mlx, mlx->x1, mlx->y1);
		mlx->e2 = mlx->err;
		if (mlx->e2 > -(mlx->dx))
		{
			mlx->err = mlx->err - mlx->dy;
			mlx->x1 = mlx->x1 + mlx->sx;
		}
		if (mlx->e2 < mlx->dy)
		{
			mlx->err = mlx->err + mlx->dx;
			mlx->y1 = mlx->y1 + mlx->sy;
		}
	}
}
