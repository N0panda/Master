/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:34:17 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/25 11:36:30 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "ft_printf/include/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include <math.h>

typedef struct 			s_mlx
{
	int		**map;
	int		size;
	int		nb;
	void	*ptr;
	void	*window;
	int		screen_w;
	int		screen_h;
	int		img_w;
	int		img_h;
	int		rate_x;
	int		rate_y;
	int		zoom;
	int		t_zoom;
	void	*img_ptr;
	char	*img_str;
	int		*bpp;
	int		s_l;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int 	dx;
	int 	dy;
	int 	sx;
	int 	sy;
	int 	err;
	int 	e2;
	int		slide_x;
	int		slide_y;
	// void	(*creat)(struct s_mlx *);
	// void	(*push)(struct s_mlx *);
	// void	(*refresh)(struct s_mlx *);

}						t_mlx;

void					ft_exit(void);
int						**ft_check_and_get(int fd, t_mlx *list);
char					*ft_cut_white(char *str);
int						**ft_get_map(char **text, t_mlx *list);
void					ft_display_map(t_mlx *mlx);
void					ft_push_img(t_mlx *mlx);
void					ft_creat_img(t_mlx *mlx);
void					ft_refresh_img(t_mlx *mlx);
void					ft_set_pixel(t_mlx *mlx, int x, int y);
int						ft_get_key(int key, t_mlx *mlx);
void					ft_zoom(int key, t_mlx *mlx);
void					ft_display_pix(t_mlx *mlx);
void					ft_key_exit(void);
void					ft_slide(int key, t_mlx *mlx);
void					ft_rotate_z(t_mlx *mlx);
void					ft_rotate_x(t_mlx *mlx);
void					ft_rotate_y(t_mlx *mlx);

#endif
