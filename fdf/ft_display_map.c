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
	// mlx->rate_x = ((mlx->img_w) / mlx->nb) / 1;
	// mlx->rate_y = ((mlx->img_h) / mlx->size) / 1;
	// mlx->creat = ft_creat_img;
	// mlx->refresh = ft_refresh_img;
	// mlx->push = ft_push_img;
	mlx->zoom = 200;
	mlx->t_zoom = 0;
	mlx->slide_x = 0;
	mlx->slide_y = 0;
	mlx->window = mlx_new_window(mlx->ptr, mlx->screen_w, mlx->screen_h, "T");
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
	while (1)
	{
		ft_set_pixel(mlx, mlx->x1, mlx->y1);
		if (mlx->x1 == mlx->x2 && mlx->y1 == mlx->y2)
			break ;
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

void        ft_display_pix(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->size - 1)
	{
		x = 0;
		while (x < mlx->nb - 1)
		{
			mlx->x1 = (x * (mlx->rate_x)) + mlx->slide_x;
			mlx->y1 = (y * (mlx->rate_y)) + mlx->slide_y;
			mlx->x2 = ((x + 1) * (mlx->rate_x)) + mlx->slide_x;
			mlx->y2 = (y * (mlx->rate_y)) + mlx->slide_y;
			printf("x1[%d] y1[%d] x2[%d] y2[%d]\n", mlx->x1, mlx->y1, mlx->x2, mlx->y2);
			ft_draw_line(mlx);
			x++;
		}
		y++;
	}
	x = 0;
	while (x < mlx->nb - 1)
	{
		y = 0;
		while (y < mlx->size - 1)
		{
			mlx->x1 = (x * (mlx->rate_x)) + mlx->slide_x;
			mlx->y1 = ((y + 1) * (mlx->rate_y)) + mlx->slide_y;
			mlx->x2 = (x * (mlx->rate_x)) + mlx->slide_x;
			mlx->y2 = (y * (mlx->rate_y)) + mlx->slide_y;
			ft_draw_line(mlx);
			y++;
		}
		x++;
	}
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
