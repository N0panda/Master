/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:05:05 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/04 14:11:44 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_sort(t_size *size)
{
	int i;

	i = 1;
	if (size->nbb > 0)
	{
		ft_putendl("KO");
		return (ERROR);
	}
	while (i < size->a)
	{
		if (size->pa[i] < size->pa[i - 1])
		{
			ft_putendl("KO");
			return (ERROR);
		}
		i++;
	}
	ft_putendl("OK");
	return (SUCCESS);
}

void	ft_init_size(t_size *size)
{
	size->a = 0;
	size->b = 0;
	size->pa = NULL;
	size->pb = NULL;
}

int		main(int argc, char **argv)
{
	t_exec	*list;
	t_size	*size;
	int		nb_exec;

	nb_exec = 0;
	if (!(size = (t_size *)malloc(sizeof(t_size))))
		ft_exit();
	list = NULL;
	ft_init_size(size);
	if (argc < 2)
		ft_exit();
	if (check_format_a(argc, argv) == ERROR)
		ft_exit();
	size->pa = ft_fill_pile_a(argc, argv, size);
	if (ft_same_num(size) == 0)
		ft_exit();
	list = ft_get_exec(&nb_exec);
	if (!(size->pb = (int *)malloc(sizeof(int) * (size->a))))
		ft_exit();
	ft_do_exec(list, size);
	ft_check_sort(size);
	exit(EXIT_SUCCESS);
	return (SUCCESS);
}
