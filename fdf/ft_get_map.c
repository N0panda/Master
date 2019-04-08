/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:17:25 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/25 18:17:42 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_get_map_tmp(t_mlx *mlx)
{
	int i;

	i = 0;
	if (!(mlx->map_tmp = (double **)malloc(sizeof(double *) * (mlx->size + 1)))
		|| !(mlx->map_xtmp = (double **)malloc(sizeof(double *) * (mlx->size + 1)))
		|| !(mlx->map_ytmp = (double **)malloc(sizeof(double *) * (mlx->size + 1))))
		ft_exit();
	while (i < mlx->size)
	{
		if (!(mlx->map_tmp[i] = (double *)malloc(sizeof(double) * mlx->nb))
			|| !(mlx->map_xtmp[i] = (double *)malloc(sizeof(double) * (mlx->nb)))
			|| !(mlx->map_ytmp[i] = (double *)malloc(sizeof(double) * (mlx->nb))))
			ft_exit();
		i++;
	}
}

void			ft_copy_data_tmp(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while (i < mlx->size)
	{
		j = 0;
		while (j < mlx->nb)
		{
			mlx->map_tmp[i][j] = mlx->map[i][j];
			mlx->map_xtmp[i][j] = mlx->map_x[i][j];
			mlx->map_ytmp[i][j] = mlx->map_y[i][j];
			j++;
		}
		i++;
	}

}

void			ft_multi_atoi(char *str, double *map, int *y, int *signe)
{
	int i;
	double tmp;

	i = 0;
	while (str[i])
	{
		tmp = 0;
		*signe = 1;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == '-')
			*signe = -1;
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (str[i] <= '9' && str[i] >= '0')
		{
			tmp = tmp * 10 + (str[i] - '0');
			if ((tmp > 2147483647 && *signe == 1)
				|| (-tmp < -2147483648 && *signe == -1))
				ft_exit();
			i++;
		}
		map[*y] = tmp * (*signe);
		(*y)++;
	}
}

void 			ft_fill_map_tab(t_mlx *mlx)
{
	int i;
	int y;

	i = 0;
	while (i < mlx->size)
	{
		y = 0;
		while (y < mlx->nb)
		{
			mlx->map_x[i][y] = y;
			mlx->map_y[i][y] = i;
			y++;
		}
		i++;
	}
}

double				**ft_get_map(char **text, t_mlx *list)
{
	double 	**map;
	int 	i;
	int		y;
	int 	signe;

	signe = 1;
	if (!(map = (double **)malloc(sizeof(double *) * (list->size + 1)))
		|| !(list->map_x = (double **)malloc(sizeof(double *) * (list->size + 1)))
		|| !(list->map_y = (double **)malloc(sizeof(double *) * (list->size + 1))))
		ft_exit();
	i = 0;
	while (i < list->size)
	{
		y = 0;
		if (!(map[i] = (double *)malloc(sizeof(double) * list->nb))
			|| !(list->map_x[i] = (double *)malloc(sizeof(double) * (list->nb)))
			|| !(list->map_y[i] = (double *)malloc(sizeof(double) * (list->nb))))
			ft_exit();
		ft_multi_atoi(text[i], map[i], &y, &signe);
		i++;
	}
	ft_fill_map_tab(list);
	return (map);
}
