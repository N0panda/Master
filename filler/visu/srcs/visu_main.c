/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:03:31 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/24 14:12:42 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visu.h"

int					get_score_value(char *line)
{
	int i;
	int result;

	i = 0;
	while (line[i] && !(line[i] <= '9' && line[i] >= '0'))
		i++;
	result = ft_atoi(line + i);
	return (result);
}

int					final_display(t_env *env, char *line)
{
	env->score_p1 = get_score_value(line);
	ft_strdel(&line);
	if (get_next_line(0, &line) <= 0)
		return (-1);
	env->score_p2 = get_score_value(line);
	ft_strdel(&line);
	last_display(env);
	return (0);
}

int					disp_and_refresh(t_env *env)
{
	char	*line;
	int		err;

	while ((err = get_next_line(0, &line)) > 0)
	{
		if (ft_strstr(line, "Plateau") != NULL)
		{
			ft_strdel(&line);
			if (refresh_board(env, line) == -1)
				return (-1);
			display_board(env);
			usleep(env->speed);
		}
		else if (ft_strstr(line, "== O fin:") != NULL)
		{
			final_display(env, line);
			return (1);
		}
		else
			ft_strdel(&line);
	}
	if (err == -1)
		return (-1);
	return (0);
}

int					visu_filler(int tspeed)
{
	t_env	env;
	int		err;

	env.board = NULL;
	env.piece = NULL;
	env.speed = tspeed;
	if (init_env(&env) == -1)
		return (-1);
	display_board(&env);
	sleep(2);
	while ((err = disp_and_refresh(&env)) != 1)
	{
		if (err == -1)
			return (-1);
	}
	final_free(&env);
	return (0);
}

int					main(int argc, char **argv)
{
	int tspeed;

	if (argc > 2)
	{
		ft_printf("Usage : -[s, m, f, sf] <slow, medium, fast, superfast>");
		return (0);
	}
	else if (argc < 2 || strcmp(argv[1], "-m") == 0)
		tspeed = 250000;
	else if (strcmp(argv[1], "-s") == 0)
		tspeed = 700000;
	else if (strcmp(argv[1], "-f") == 0)
		tspeed = 150000;
	else if (strcmp(argv[1], "-sf") == 0)
		tspeed = 90000;
	else
	{
		ft_printf("Usage : -[s, m, f, sf] <slow, medium, fast, superfast>");
		return (0);
	}
	if (visu_filler(tspeed) == -1)
		exit(EXIT_FAILURE);
	return (0);
}
