/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:44:50 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/24 14:00:15 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visu.h"

void				final_free(t_env *env)
{
	int i;

	i = -1;
	while (++i < env->by)
		free(env->board[i]);
	free(env->board);
	free(env->p1);
	free(env->p2);
}

int					ft_fill_refresh(t_env *env, int i, char *line)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (line[j] && line[j] != 'X' && line[j] != 'o'
		&& line[j] != 'O' && line[j] != '.')
		j++;
	while (line[j])
	{
		env->board[i][k] = line[j];
		j++;
		k++;
	}
	env->board[i][k] = '\0';
	return (0);
}

int					refresh_board(t_env *env, char *line)
{
	int		i;
	int		err;

	i = 0;
	if (get_next_line(0, &line) == -1)
		return (-1);
	ft_strdel(&line);
	while (i < env->by && (err = get_next_line(0, &line)) > 0)
	{
		if (err == -1)
			return (-1);
		ft_fill_refresh(env, i, line);
		ft_strdel(&line);
		i++;
	}
	return (1);
	if (err == -1)
		return (-1);
	return (0);
}
