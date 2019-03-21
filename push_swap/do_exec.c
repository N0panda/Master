/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:37:22 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/12 15:37:35 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		exec_part_one(t_exec *list, t_size *size)
{
	if (ft_strcmp(list->param, "sa") == 0)
		ft_exec_sa(size);
	else if (ft_strcmp(list->param, "sb") == 0)
		ft_exec_sb(size);
	else if (ft_strcmp(list->param, "ss") == 0)
	{
		ft_exec_sa(size);
		ft_exec_sb(size);
	}
	else if (ft_strcmp(list->param, "pa") == 0 && size->nbb > 0)
		ft_exec_pa(size);
	else if (ft_strcmp(list->param, "pb") == 0 && size->nba > 0)
		ft_exec_pb(size);
	return (0);
}

int		exec_part_two(t_exec *list, t_size *size)
{
	int i;

	i = 0;
	if (ft_strcmp(list->param, "ra") == 0)
		ft_exec_ra(size);
	else if (ft_strcmp(list->param, "rb") == 0)
		ft_exec_rb(size);
	else if (ft_strcmp(list->param, "rr") == 0)
	{
		ft_exec_ra(size);
		ft_exec_rb(size);
	}
	else if (ft_strcmp(list->param, "rra") == 0)
		ft_exec_rra(size);
	else if (ft_strcmp(list->param, "rrb") == 0)
		ft_exec_rrb(size);
	else if (ft_strcmp(list->param, "rrr") == 0)
	{
		ft_exec_rra(size);
		ft_exec_rrb(size);
	}
	return (0);
}

int		exec_part(t_exec *list, t_size *size)
{
	while (list != NULL)
	{
		if (list->param[0] == 's' || list->param[0] == 'p')
			exec_part_one(list, size);
		else
			exec_part_two(list, size);
		list = list->next;
	}
	return (0);
}

int		ft_do_exec(t_exec *list, t_size *size)
{
	int i;

	i = 0;
	size->nba = size->a;
	size->nbb = 0;
	while (i < size->a)
		size->pb[i++] = 0;
	exec_part(list, size);
	return (1);
}
