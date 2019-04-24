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
		ft_printf("KO\n");
		return (ERROR);
	}
	while (i < size->a)
	{
		if (size->pa[i] < size->pa[i - 1])
		{
			ft_printf("KO\n");
			return (ERROR);
		}
		i++;
	}
	ft_printf("OK\n");
	return (SUCCESS);
}

int		main(int argc, char **argv)
{
	t_exec	*list;
	t_size	*size;

	if (!(size = (t_size *)malloc(sizeof(t_size))))
		ft_exit();
	list = NULL;
	size->a = 0;
	size->b = 0;
	size->pa = NULL;
	size->pb = NULL;
	if (argc < 2)
		ft_exit();
	if (check_format_a(argc, argv) == ERROR)
		ft_exit();
	size->pa = ft_fill_pile_a(argc, argv, size);
	if (ft_same_num(size) == 0)
		ft_exit();
	list = ft_get_exec();
	if (!(size->pb = (int *)malloc(sizeof (int) * (size->a))))
		ft_exit();
	ft_do_exec(list, size);
	int i = 0;
		printf("-----------------------------------------------------------\n");
			printf("------------------ P I L E _ A----------------------\n");
			printf("-----------------------------------------------------------\n");
	while (i < size->nba)
		printf("#[%d]\n", size->pa[i++]);
	i = 0;
	printf("-----------------------------------------------------------\n");
		printf("------------------ P I L E _ B----------------------\n");
		printf("-----------------------------------------------------------\n");
	while (i < size->nbb)
		printf("#[%d]\n", size->pb[i++]);
	ft_check_sort(size);
	return (SUCCESS);
}
