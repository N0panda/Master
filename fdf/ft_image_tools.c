/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:56:05 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/26 16:56:32 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_creat_img(t_mlx *mlx)
{
	int bpp;
	int s_l;
	int endian;

	bpp = 32;
	s_l = (mlx->screen_w) * 4;
	endian = 0;
	mlx->img_ptr = mlx_new_image(mlx->ptr, mlx->img_w, mlx->img_h);
	mlx->img_str = mlx_get_data_addr(mlx->img_ptr, &bpp, &s_l, &endian);
}

void		ft_set_pixel(t_mlx *mlx, double x, double y)
{
	int px; // position dans l'image de x
	int py; // position dans l'image de y
	int result;
	
	if (x < 0 || x >= mlx->img_w || y < 0 || y >= mlx->img_h)
		return ;
	px = (4 * (int)x);
	py = ((int)y * 4 * mlx->img_w);
	result = (px + py);
	mlx->img_str[result] = mlx->red;
	mlx->img_str[result+1] = mlx->green;
	mlx->img_str[result+2] = mlx->blue;
}

void		ft_push_img(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx, mlx->window, mlx->img_ptr, 0, 0);
}

void		ft_refresh_img(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img_ptr);
	ft_creat_img(mlx);
	ft_display_pix(mlx);
	ft_push_img(mlx);
}
