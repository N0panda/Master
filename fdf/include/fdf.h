/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:34:17 by ythomas           #+#    #+#             */
/*   Updated: 2019/04/08 18:31:46 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct			s_mlx
{
	double				**map;
	double				**map_x;
	double				**map_y;
	double				**map_tmp;
	double				**xtmp;
	double				**ytmp;
	int					size;
	int					nb;
	void				*ptr;
	void				*window;
	int					screen_w;
	int					screen_h;
	int					img_w;
	int					img_h;
	int					rate_x;
	int					rate_y;
	int					zoom;
	int					t_zoom;
	void				*img_ptr;
	char				*img_str;
	int					*bpp;
	int					s_l;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				rad;
	double				dx;
	double				dy;
	double				sx;
	double				sy;
	double				err;
	double				e2;
	int					slide_x;
	int					slide_y;
	int					color;
	unsigned char		red;
	unsigned char		green;
	unsigned char		blue;
	int					paulz;
	int					height;

}						t_mlx;

void					ft_exit(void);
double					**ft_check_and_get(int fd, t_mlx *list);
char					*ft_cut_white(char *str);
double					**ft_get_map(char **text, t_mlx *list);
void					ft_display_map(t_mlx *mlx);
void					ft_push_img(t_mlx *mlx);
void					ft_creat_img(t_mlx *mlx);
void					ft_refresh_img(t_mlx *mlx);
void					ft_set_pixel(t_mlx *mlx, double x, double y);
int						ft_get_key(int key, t_mlx *mlx);
void					ft_zoom(int key, t_mlx *mlx);
void					ft_display_pix(t_mlx *mlx);
void					ft_key_exit(void);
void					ft_slide(int key, t_mlx *mlx);
void					ft_rotate_z(t_mlx *mlx, int key);
void					ft_rotate_x(t_mlx *mlx, int key);
void					ft_rotate_y(t_mlx *mlx, int key);
void					ft_draw_line(t_mlx *mlx);
void					ft_rotate_bottom(t_mlx *mlx);
void					ft_rotate_top(t_mlx *mlx);
void					ft_rotate_up(t_mlx *mlx);
void					ft_rotate_down(t_mlx *mlx);
void					ft_height(t_mlx *mlx, int key);
void					ft_height_less(t_mlx *mlx);
void					ft_height_more(t_mlx *mlx);
void					ft_draw_line(t_mlx *mlx);
void					ft_color_top(t_mlx *mlx, int key);
void					ft_copy_data_tmp(t_mlx *mlx);
void					ft_get_map_tmp(t_mlx *mlx);
void					ft_height_plus(t_mlx *mlx);
void					ft_height_less(t_mlx *mlx);
void					ft_restart(t_mlx *mlx);
void					ft_draw_case1(t_mlx *mlx);
void					ft_draw_case2(t_mlx *mlx);
void					ft_draw_case3(t_mlx *mlx);
void					ft_draw_case4(t_mlx *mlx);
void					ft_get_rate(t_mlx *mlx);
void					ft_rotate_right(t_mlx *mlx);
void					ft_rotate_left(t_mlx *mlx);

#endif
