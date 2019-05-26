/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_visu.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:09:00 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/24 14:15:36 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_VISU_H
# define FILLER_VISU_H

# include "../ft_printf/include/ft_printf.h"

typedef struct		s_env
{
	char			*p1;
	char			*p2;
	char			**board;
	int				by;
	int				bx;
	char			**piece;
	int				py;
	int				px;
	int				score_p1;
	int				score_p2;
	int				speed;
}					t_env;

int					get_player_name(t_env *env, char *line);
char				*get_name(char *line);
int					init_env(t_env *env);
int					get_dim(t_env *env, char *line);
int					ft_fill_board(t_env *env, int i, char *line);
int					refresh_board(t_env *env, char *line);
int					display_board(t_env *env);
int					display_start(t_env *env);
void				last_display(t_env *env);
void				final_free(t_env *env);

#endif
