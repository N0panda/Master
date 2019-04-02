/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:58:51 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/30 19:59:00 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_slide_right(t_mlx *mlx)
{
	if (mlx->slide_x <= mlx->img_w)
	{
		mlx->slide_x = mlx->slide_x + 50;
		ft_refresh_img(mlx);
	}
	return ;

}

void	ft_slide_left(t_mlx *mlx)
{
	if (mlx->slide_x >= -mlx->img_w)
	{
		mlx->slide_x = mlx->slide_x - 50;
		ft_refresh_img(mlx);
	}
	return ;
}

void	ft_slide_top(t_mlx *mlx)
{
	if (mlx->slide_y >= -mlx->img_h)
	{
		mlx->slide_y = mlx->slide_y - 50;
		ft_refresh_img(mlx);
	}
	return ;
}

void	ft_slide_bot(t_mlx *mlx)
{
	if (mlx->slide_y <= mlx->img_h)
	{
		mlx->slide_y = mlx->slide_y + 50;
		ft_refresh_img(mlx);
	}
	return ;
}

void	ft_slide(int key, t_mlx *mlx)
{
	if (key == 123)
		ft_slide_left(mlx);
	else if (key == 124)
		ft_slide_right(mlx);
	else if (key == 125)
		ft_slide_bot(mlx);
	else if(key == 126)
		ft_slide_top(mlx);
}