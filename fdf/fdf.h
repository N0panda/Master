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

typedef struct 			s_mlx
{
	int		**map;
	int		size;
	int		nb;
	void	*ptr;
	void	*window;
}						t_mlx;

typedef struct 			s_coord
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		z1;
	int		z2;
}						t_coord;

void					ft_exit(void);
int						**ft_check_and_get(int fd, t_mlx *list);
char					*ft_cut_white(char *str);
int						**ft_get_map(char **text, t_mlx *list);
void					ft_display_map(t_mlx *mlx);


#endif
