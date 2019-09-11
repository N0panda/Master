/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:30:48 by root              #+#    #+#             */
/*   Updated: 2019/06/24 19:53:38 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

t_lemin		***first_call(t_tab *lem_in, t_god *god)
{
	t_lemin		***adjacent_matrix;
	t_tab		*tmp;
	int			i;
	int			len;

	len = ft_tab_lendir(lem_in, 0);
	god->size = len;
	adjacent_matrix = ft_memalloc((len + 1) * sizeof(void**));
	i = -1;
	tmp = god->lem_in;
	while (tmp)
	{
		adjacent_matrix[++i] = ft_memalloc(len * sizeof(void*));
		((t_lemin*)tmp->content)->connexions = adjacent_matrix[i];
		((t_lemin*)tmp->content)->id = i;
		tmp = tmp->dir[0];
	}
	return (adjacent_matrix);
}

int			link_rooms(t_tab *lem_in, char *line,
	t_lemin ****adjacent_matrix, t_god *god)
{
	static int	*my_fs;
	char		**split;
	t_lemin		*_first;
	t_lemin		*_second;

	if (!*adjacent_matrix)
		*adjacent_matrix = first_call(lem_in, god);
	if (!my_fs)
		my_fs = ft_memalloc(sizeof(int) * (god->size + 1));
	if (!(split = ft_strsplit(line, '-')))
		return (ERROR);
	if ((_first = hashtable_value(god->hashtable, split[0],
		ft_strlen(split[0]))) == NULL)
		return (-1);
	if ((_second = hashtable_value(god->hashtable, split[1],
		ft_strlen(split[1]))) == NULL)
		return (-1);
	(*adjacent_matrix)[_first->id][my_fs[_first->id]++] = _second;
	(*adjacent_matrix)[_second->id][my_fs[_second->id]++] = _first;
	return (SUCCESS);
}
