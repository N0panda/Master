/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:28:55 by ythomas           #+#    #+#             */
/*   Updated: 2019/04/08 16:26:37 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_color_top(t_mlx *mlx, int key)
{
	if (key == 12)
	{
		if ((mlx->red) - 1 < 0x00)
			mlx->red = 0xff;
		else
			(mlx->red) -= 3;
	}
	else if (key == 13)
	{
		if ((mlx->green) - 1 < 0x00)
			mlx->green = 0xff;
		else
			(mlx->green) -= 3;
	}
	else if (key == 14)
	{
		if ((mlx->blue) - 1 < 0x00)
			mlx->blue = 0xff;
		else
			(mlx->blue) -= 3;
	}
	ft_refresh_img(mlx);
}
