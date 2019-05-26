/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:30:51 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/24 14:01:03 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visu.h"

int					get_board_dim(t_env *env, char *line)
{
	int err;

	while ((err = get_next_line(0, &line)) > 0)
	{
		if (ft_strstr(line, "Plateau") != NULL)
			break ;
		ft_strdel(&line);
	}
	if (err == -1 || err == 0)
		return (-1);
	if (get_dim(env, line) == -1)
		return (-1);
	ft_strdel(&line);
	return (0);
}

int					get_player_name(t_env *env, char *line)
{
	int err;

	while ((err = get_next_line(0, &line)) > 0)
	{
		if (ft_strstr(line, "exec p1") != NULL)
			break ;
		ft_strdel(&line);
	}
	if (err == -1 || err == 0)
		return (-1);
	if ((env->p1 = get_name(line)) == NULL)
		return (-1);
	ft_strdel(&line);
	while ((err = get_next_line(0, &line)) > 0)
	{
		if (ft_strstr(line, "exec p2") != NULL)
			break ;
		ft_strdel(&line);
	}
	if (err == -1 || err == 0)
		return (-1);
	if ((env->p2 = get_name(line)) == NULL)
		return (-1);
	ft_strdel(&line);
	return (0);
}

int					creat_board(t_env *env, char *line)
{
	int		i;
	int		err;

	i = 0;
	if (!(env->board = (char **)malloc(sizeof(char *) * env->by)))
		return (-1);
	if (get_next_line(0, &line) == -1)
		return (-1);
	ft_strdel(&line);
	while (i < env->by && (err = get_next_line(0, &line)) > 0)
	{
		if (err == -1)
			return (-1);
		if (!(env->board[i] = (char *)malloc(sizeof(char) * (env->bx + 1))))
			return (-1);
		if (ft_fill_board(env, i, line) == -1)
			return (-1);
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	return (0);
}

int					init_env(t_env *env)
{
	char *line;

	line = NULL;
	if (get_player_name(env, line) == -1)
		return (-1);
	if (get_board_dim(env, line) == -1)
		return (-1);
	if (creat_board(env, line) == -1)
		return (-1);
	return (0);
}
