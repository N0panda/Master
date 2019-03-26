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

void		ft_init_list(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->ptr, 1000, 700, "TEST");
}

void 		ft_trace_line(t_mlx *mlx, t_coord *pts)
{
	(void)mlx;
}

void		ft_display_map(t_mlx *mlx)
{
	t_coord		*pts;

	if (!(pts = (t_coord *)malloc(sizeof(t_coord))))
		return ;
	pts->x1 = 150; pts->x2 = 800; pts->y1 = 100; pts->y2 = 650; pts->z1 = 0; pts->z2 = 0;
	ft_init_list(mlx);
	mlx_string_put(mlx->ptr, mlx->window, 450, 350, 0x6600FF, "Ca marche ou pas ??");

	ft_trace_line(mlx);

	mlx_loop(mlx->ptr);
}
