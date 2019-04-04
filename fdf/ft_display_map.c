/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 22:36:14 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/25 22:36:37 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_get_rate(t_mlx *mlx)
{
	if (mlx->nb > mlx->size)
	{
		mlx->rate_x = ((mlx->img_h) / mlx->nb) / 4;
		mlx->rate_y = ((mlx->img_h) / mlx->nb) / 4;
	}
	else
	{
		mlx->rate_x = ((mlx->img_w) / mlx->size) / 4;
		mlx->rate_y = ((mlx->img_w) / mlx->size) / 4;
	}
}

void		ft_init_list(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->screen_w = 1800;
	mlx->screen_h = 1200;
	mlx->img_w = 1800;
	mlx->img_h = 1200;
	ft_get_rate(mlx);
	mlx->zoom = 200;
	mlx->t_zoom = 0;
	mlx->slide_x = 0;
	mlx->slide_y = 0;
	mlx->rad = 15;
	mlx->window = mlx_new_window(mlx->ptr, mlx->screen_w, mlx->screen_h, "test");
}

void		ft_draw_line(t_mlx *mlx)
{
	mlx->dx = (mlx->x2 - mlx->x1);
	if (mlx->dx < 0)
		mlx->dx = mlx->dx * -1;
	mlx->dy = (mlx->y2 - mlx->y1);
	if (mlx->dy < 0)
		mlx->dy = mlx->dy * -1;
	mlx->sx = mlx->x1 < mlx->x2 ? 1 : -1;
	mlx->sy = mlx->y1 < mlx->y2 ? 1 : -1;
	mlx->err = (mlx->dx > mlx->dy ? mlx->dx : (-mlx->dy)) / 2;
	if (mlx->x2 - mlx->x1 >= 0 && mlx->y2 - mlx->y1 >= 0)
	{
		while (1)
		{
			if (mlx->x1 > mlx->x2 || mlx->y1 > mlx->y2)
				break ;
			ft_set_pixel(mlx, mlx->x1, mlx->y1);
			mlx->e2 = mlx->err;
			if (mlx->e2 > - (mlx->dx))
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
	else if (mlx->x2 - mlx->x1 < 0 && mlx->y2 - mlx->y1 >= 0)
	{
		while (1)
		{
			if (mlx->x1 < mlx->x2 || mlx->y1 > mlx->y2)
				break ;
			ft_set_pixel(mlx, mlx->x1, mlx->y1);
			mlx->e2 = mlx->err;
			if (mlx->e2 > - (mlx->dx))
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
	else if (mlx->x2 - mlx->x1 >= 0 && mlx->y2 - mlx->y1 < 0)
	{
		while (1)
		{
			if (mlx->x1 > mlx->x2 || mlx->y1 < mlx->y2)
				break ;
			ft_set_pixel(mlx, mlx->x1, mlx->y1);
			mlx->e2 = mlx->err;
			if (mlx->e2 > - (mlx->dx))
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
	else
	{
		while (1)
		{
			if (mlx->x1 < mlx->x2 || mlx->y1 < mlx->y2)
				break ;
			ft_set_pixel(mlx, mlx->x1, mlx->y1);
			mlx->e2 = mlx->err;
			if (mlx->e2 > - (mlx->dx))
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
}

void		ft_display_pix_suite(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while (i < mlx->size - 1)
	{
		j = 0;
		while (j < mlx->nb)
		{
			mlx->x1 = ((mlx->map_x[i][j] * (double)(mlx->rate_x)) + (double)mlx->slide_x);
			mlx->y1 = ((mlx->map_y[i][j] * (double)(mlx->rate_y)) + (double)mlx->slide_y);
			mlx->x2 = ((mlx->map_x[i + 1][j] * (double)(mlx->rate_x)) + (double)mlx->slide_x);
			mlx->y2 = ((mlx->map_y[i + 1][j] * (double)(mlx->rate_y)) + (double)mlx->slide_y);
			ft_draw_line(mlx);
			j++;
		}
		i++;
	}
}

void        ft_display_pix(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while (i < mlx->size)
	{
		j = 0;
		while (j < mlx->nb - 1)
		{
			mlx->x1 = ((mlx->map_x[i][j] * (double)(mlx->rate_x)) + (double)mlx->slide_x);
			mlx->y1 = ((mlx->map_y[i][j] * (double)(mlx->rate_y)) + (double)mlx->slide_y);
			mlx->x2 = ((mlx->map_x[i][j + 1] * (double)(mlx->rate_x)) + (double)mlx->slide_x);
			mlx->y2 = ((mlx->map_y[i][j + 1] * (double)(mlx->rate_y)) + (double)mlx->slide_y);
			ft_draw_line(mlx);
			j++;
		}
		i++;
	}
	ft_display_pix_suite(mlx);
}

void		ft_display_map(t_mlx *mlx)
{
	ft_init_list(mlx);
	ft_creat_img(mlx);
	ft_display_pix(mlx);
	//ft_set_pixel(mlx, 0, 0);
	ft_push_img(mlx);
	mlx_key_hook(mlx->window, ft_get_key, mlx);
	mlx_loop(mlx->ptr);
}
