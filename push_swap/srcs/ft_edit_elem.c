/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edit_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:34:35 by ythomas           #+#    #+#             */
/*   Updated: 2019/04/30 19:01:07 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_del_double(t_size *size)
{
	int			i;
	t_instru	*tmp;

	i = 1;
	tmp = size->elem;
	while (size->elem->next != NULL)
	{
		if ((size->elem->type == 1 && size->elem->next->type == 1)
			|| (size->elem->type == 2 && size->elem->next->type == 2)
			|| (size->elem->type == 3 && size->elem->next->type == 4)
			|| (size->elem->type == 4 && size->elem->next->type == 3)
			|| (size->elem->type == 5 && size->elem->next->type == 7)
			|| (size->elem->type == 7 && size->elem->next->type == 5)
			|| (size->elem->type == 6 && size->elem->next->type == 8)
			|| (size->elem->type == 8 && size->elem->next->type == 6))
		{
			size->elem = tmp;
			return (i);
		}
		i++;
		size->elem = size->elem->next;
	}
	size->elem = tmp;
	return (0);
}

void			ft_cut_elem(t_size *size, int nb)
{
	int			i;
	t_instru	*tmp;
	t_instru	*fin;

	i = 1;
	tmp = size->elem;
	while (i < nb - 1)
	{
		size->elem = size->elem->next;
		i++;
	}
	fin = size->elem->next->next->next;
	free(size->elem->next->next->action);
	free(size->elem->next->next);
	free(size->elem->next->action);
	free(size->elem->next);
	size->elem->next = fin;
	size->elem = tmp;
}

void			ft_optimize_elem(t_size *size)
{
	int			nb;
	t_instru	*tmp;

	while ((nb = ft_del_double(size)) != 0)
	{
		ft_cut_elem(size, nb);
	}
	tmp = size->elem;
	while (size->elem != NULL)
	{
		ft_putendl(size->elem->action);
		size->elem = size->elem->next;
	}
	size->elem = tmp;
	return ;
}

t_instru		*ft_creat_elem(char *str, int act)
{
	t_instru *list;

	if (!(list = (t_instru *)malloc(sizeof(t_instru))))
		ft_exit();
	list->action = ft_strdup(str);
	list->type = act;
	list->next = NULL;
	return (list);
}

void			ft_fill_elem_with(t_size *size, char *str, int act)
{
	t_instru	*tmp;

	tmp = NULL;
	if (size->elem == NULL)
	{
		size->elem = ft_creat_elem(str, act);
	}
	else
	{
		tmp = size->elem;
		while (size->elem->next != NULL)
			size->elem = size->elem->next;
		size->elem->next = ft_creat_elem(str, act);
		size->elem = tmp;
	}
}
