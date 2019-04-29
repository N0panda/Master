/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 16:10:15 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/18 17:05:46 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_exec(char *s)
{
	int len;

	len = ft_strlen(s);
	if (len > 3 || len < 2)
		return (ERROR);
	if (s[0] != 's' && s[0] != 'p' && s[0] != 'r')
		return (ERROR);
	if (s[0] == 's' && (s[1] == 'a' || s[1] == 'b' || s[1] == 's') && len == 2)
		return (SUCCESS);
	else if (s[0] == 'p' && (s[1] == 'a' || s[1] == 'b') && len == 2)
		return (SUCCESS);
	else if (s[0] == 'r')
	{
		if (len == 2 && (s[1] == 'a' || s[1] == 'b' || s[1] == 'r'))
			return (SUCCESS);
		else if (len == 3 && s[1] == 'r' && (s[2] == 'a' || s[2] == 'b'
			|| s[2] == 'r'))
			return (SUCCESS);
	}
	return (ERROR);
}

t_exec	*ft_creat_maillon(char *line, int *nb)
{
	t_exec *tmp;

	if (!(tmp = (t_exec*)malloc(sizeof(t_exec))))
		return (ERROR);
	tmp->param = ft_strdup(line);
	tmp->next = NULL;
	(*nb)++;
	return (tmp);
}

t_exec	*ft_get_exec(int *nb)
{
	t_exec		*maillon;
	t_exec		*depart;
	char		*line;

	line = NULL;
	depart = NULL;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (ft_check_exec(line) == ERROR)
			ft_exit();
		if (depart == NULL)
			depart = ft_creat_maillon(line, nb);
		else
		{
			maillon = depart;
			while (maillon->next != NULL)
				maillon = maillon->next;
			maillon->next = ft_creat_maillon(line, nb);
		}
	}
	return (depart);
}
