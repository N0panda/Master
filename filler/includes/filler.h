/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 23:57:27 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/21 18:29:27 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../ft_printf/include/ft_printf.h"

typedef struct		s_player
{
	char			lettre;
	char			**l_p;
	int				pos_x;
	int				pos_y;
	int				w;
	int				h;
}					t_player;

typedef	struct		s_map
{
	char			**board;
	int				bx;
	int				by;
	char			**piece;
	int				px;
	int				py;
	t_player		p1;
	t_player		p2;
	int				turn;
	int				touched;
	int				config;
	int				tmpx;
	int				tmpy;
	int				opti_x;
	int				opti_y;
	int				dist;
	int				stat;
	int				colision;
}					t_map;

int					init_map(t_map *map);
int					filler(void);
int					get_player(t_map *map);
int					get_board_dim(t_map *map);
int					player_turn(t_map *map);
int					free_line(char **line, int cas);
int					ft_piece(t_map *map, char **line);
int					get_board(t_map *map);
int					ft_fill_board(t_map *map, int i, char *line);
int					ft_put_next_piece(t_map *map);
int					ft_refresh_board(t_map *map);
int					ft_refresh_setup(t_map *map, char **line);
int					get_info_player(t_map *map, int j, int k, int cas);
int					get_info_p2(t_map *map, int j, int k);
int					get_info_p1(t_map *map, int j, int k);
void				get_config(t_map *map);
int					rush_enemy(t_map *map);
int					refresh_p1(t_map *map);
void				free_old_piece(t_map *map);
int					get_distance(t_map *map);
int					circle_enemy(t_map *map);
int					try_it(t_map *map, int sy, int sx);
int					brute_force_algo(t_map *map);
int					fill_anywhere(t_map *map);
int					final_free(t_map *map);

#endif
