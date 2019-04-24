/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:32:24 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/15 14:33:40 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	ft_get_indicator(t_size *size)
{
	int i;
	int signe;
	int alpha;

	i = size->a - 1;
	signe = 1;
	alpha = 0;
	while (i > 0)
	{
		if (size->pa[i] < size->pa[i - 1] && signe == 1)
		{
			signe = 0;
			alpha++;
		}
		else if (size->pa[i] > size->pa[i - 1] && signe == 0)
		{
			signe = 1;
			alpha++;
		}
		i--;
	}
	return (alpha);
}

int		ft_timetosort(t_size *size)
{
	int alpha;
	int i;

	i = 0;
	if ((alpha = ft_get_indicator(size)) == 0)
		return (SUCCESS);
	while (i < size->a)
		size->pb[i++] = 0;
	ft_simple_sort(size);
	return (SUCCESS);
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
	if (!(size->pb = (int *)malloc(sizeof (int) * (size->a))))
		ft_exit();
	if (ft_same_num(size) == 0)
		ft_exit();
	ft_timetosort(size);
	return (SUCCESS);
}
