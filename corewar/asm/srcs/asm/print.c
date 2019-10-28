/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:51:32 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/28 14:30:32 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			print_ocp(t_env *env)
{
	int i;
	int j;

	i = 0;
	while (env->actions[i])
	{
		j = -1;
		while (++j < env->actions[i]->nb_params)
			ft_printf("--%d--\n", env->actions[i]->bit_type[j]);
		ft_printf("%s\n", env->actions[i]->value_ocp);
		i++;
	}
}

void			print_type(t_env *env)
{
	int i;
	int j;

	i = 0;
	while (env->actions[i])
	{
		j = 0;
		while (j < env->actions[i]->nb_params)
		{
			ft_printf("[%d]", env->actions[i]->bit_type[j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void			print_param_hexa(t_env *env)
{
	int i;
	int j;

	i = 0;
	while (env->actions[i])
	{
		j = 0;
		if (env->actions[i]->type == ZZ_OP)
			ft_printf("(%s)  ",
			env->actions[i]->action_tab[env->actions[i]->op_position]);
		while (j < env->actions[i]->nb_params)
		{
			ft_printf("[%d]", env->actions[i]->param_final[j]);
			j++;
		}
		if (env->actions[i]->type == ZZ_OP)
			ft_printf(" : %d -> %d", env->actions[i]->octet,
			env->actions[i]->dist);
		ft_printf("\n");
		i++;
	}
}

void			print_param_tab(t_env *env)
{
	int i;
	int j;

	i = 0;
	while (env->actions[i])
	{
		j = 0;
		if (env->actions[i]->type == ZZ_OP)
		{
			while (env->actions[i]->param_tab[j])
			{
				ft_printf("[%s]", env->actions[i]->param_tab[j]);
				j++;
			}
			ft_printf("\n");
		}
		i++;
	}
}

void			print_whole_file(char **file)
{
	int i;

	i = 0;
	while (file[i])
		ft_printf("||  %s  ||\n", file[i++]);
}

void			print_all_actions(t_env *env)
{
	int i;

	i = 0;
	while (env->actions[i])
	{
		ft_printf("[%s]\n", env->actions[i]->action_line);
		i++;
	}
}

void			print_label_tab(t_env *env)
{
	t_label *tmp;

	tmp = env->lab_list;
	while (tmp != NULL)
	{
		ft_printf("Label -> #%s# pos = %d\n", tmp->label, tmp->position);
		tmp = tmp->next;
	}
}

void			print_action_tab(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (env->actions[i])
	{
		j = 0;
		if (env->actions[i]->type == ZZ_OP || env->actions[i]->type == ZZ_LAB)
		{
			while (env->actions[i]->action_tab[j])
			{
				ft_printf("[%s]", env->actions[i]->action_tab[j]);
				j++;
			}
			ft_printf("   -[%d]-", env->actions[i]->op_position);
			ft_printf("\n");
		}
		i++;
	}
}
