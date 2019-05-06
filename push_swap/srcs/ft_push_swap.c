/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:32:24 by ythomas           #+#    #+#             */
/*   Updated: 2019/04/26 18:15:39 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_indicator(t_size *size)
{
	int i;

	i = size->a - 1;
	while (i > 0)
	{
		if (size->pa[i] < size->pa[i - 1])
		{
			return (0);
		}
		i--;
	}
	return (1);
}

int		ft_timetosort(t_size *size)
{
	int alpha;
	int i;

	i = 0;
	if ((alpha = ft_get_indicator(size)) == 1)
		return (0);
	while (i < size->a)
		size->pb[i++] = 0;
	ft_simple_sort(size);
	return (1);
}

void	ft_final_free(t_size *size)
{
	t_instru	*tmp;

	while (size->elem->next != NULL)
	{
		tmp = size->elem->next;
		free(size->elem->action);
		free(size->elem);
		size->elem = tmp;
	}
	if (size->elem != NULL)
	{
		free(size->elem->action);
		free(size->elem);
	}
	free(size->pa);
	free(size->pb);
	free(size);
}

int		main(int argc, char **argv)
{
	t_size	*size;

	if (argc < 2)
		ft_exit();
	if (!(size = (t_size *)malloc(sizeof(t_size))))
		ft_exit();
	size->a = 0;
	size->b = 0;
	if (check_format_a(argc, argv) == ERROR)
		ft_exit();
	size->pa = ft_fill_pile_a(argc, argv, size);
	if (!(size->pb = (int *)malloc(sizeof(int) * (size->a))))
		ft_exit();
	if (ft_same_num(size) == 0)
		ft_exit();
	if (ft_timetosort(size) == 0)
		exit(EXIT_SUCCESS);
	ft_optimize_elem(size);
	ft_final_free(size);
	return (0);
}
