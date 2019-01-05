/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:04:11 by ythomas           #+#    #+#             */
/*   Updated: 2019/01/05 15:05:51 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "get_next_line.h"

typedef struct		s_tetri
{
	char			**tetriminos;
	int				hauteur;
	int				largeur;
	int				x;
	int				y;
	int				px;
	int				py;
	int				used;
	char			lettre;
	struct s_tetri	*next;
}					t_tetri;

int					try_put_tetri(char **board, t_tetri *m, int taille);
void				del_temp(char **tmp, int size);
char				**creat_temp_file(char **file);
int					ft_error(int type);
char				**ft_creat_file(int fd);
char				**final_result(t_tetri *tetri);
int					check_largeur(char **tetriminos);
int					check_hauteur(char **tetriminos);
int					x_origine(char **file);
int					y_origine(char**file);
t_tetri				*creat_list(char **file);
t_tetri				*creat_tetri_maillon(char **file);

#endif
