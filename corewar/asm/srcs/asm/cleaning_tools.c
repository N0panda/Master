/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:20:57 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/24 19:31:02 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					free_tools(char **str, int er, char *name, char *line)
{
	ft_strdel(str);
	if (er == 1)
		parse_error(10, name, line);
	return (-1);
}

static void			free_label(t_env *env)
{
	t_label		*tmp;

	while (env->lab_list != NULL)
	{
		tmp = env->lab_list;
		env->lab_list = env->lab_list->next;
		ft_strdel(&tmp->label);
		ft_memdel((void**)&tmp);
	}
}

static void				free_two_dim(t_line *act)
{
	int i;

	if (act->action_tab)
	{
		i = -1;
		while (act->action_tab[++i])
			ft_strdel(&act->action_tab[i]);
		ft_memdel((void**)&act->action_tab);
	}
	if (act->param_tab)
	{
		i = -1;
		while (act->param_tab[++i])
			ft_strdel(&act->param_tab[i]);
		ft_memdel((void**)&act->param_tab);
	}
}

static void				free_action(t_line *act)
{
	//ft_printf("[%d][%d][%d][%d]\n",act->bit_type[0],act->param_code[0],act->param_final[0],act->param_type[0]);
	if (act->bit_type != NULL)
		ft_memdel((void**)&act->bit_type);
	if (act->action_line != NULL)
		ft_memdel((void**)&act->action_line);
	if (act->param_code != NULL)
		ft_memdel((void**)&act->param_code);
	if (act->param_final != NULL)
		ft_memdel((void**)&act->param_final);
	if (act->param_type != NULL)
		ft_memdel((void**)&act->param_type);
	free_two_dim(act);
}

int					free_env(t_env *env)
{
	int i;

	if (env->name != NULL)
		ft_strdel(&env->name);
	if (env->comment != NULL)
		ft_strdel(&env->comment);
	if (env->file_name != NULL)
		ft_strdel(&env->file_name);
	if (env->file != NULL)
	{
		i = -1;
		while (env->file[++i])
			ft_strdel(&env->file[i]);
		ft_memdel((void**)&env->file);
	}
	if (env->actions)
	{
		i = -1;
		while (env->actions[++i])
		{
			free_action(env->actions[i]);
			ft_memdel((void**)&env->actions[i]);
		}
		ft_memdel((void**)&env->actions);
	}
	free_label(env);
	ft_memdel((void**)&env);
	return (-1);
}
