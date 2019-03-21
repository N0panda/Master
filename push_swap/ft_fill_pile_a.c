/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pile_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:29:06 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/04 20:29:07 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_same_num(t_size *size)
{
	int i;
	int y;
	int x;

	y = 0;
	while (y < size->a)
	{
		i = 0;
		x = 0;
		while (i < size->a)
		{
			if (size->pa[y] == size->pa[i])
				x++;
			if (x > 1)
				return (ERROR);
			i++;
		}
		y++;
	}
	return (SUCCESS);
}

void	ft_multi_atoi(char *str, t_size *size, int *position)
{
	int i;
	int signe;
	long tmp;

	i = 0;
	while (str[i])
	{
		tmp = 0;
		signe = 1;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == '-')
			signe = -1;
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (str[i] <= '9' && str[i] >= '0')
		{
			tmp = tmp * 10 + (str[i] - '0');
			if ((tmp > 2147483647 && signe == 1)
				|| (-tmp < -2147483648 && signe == -1))
				ft_exit();
			i++;
		}
		size->pa[*position] = tmp * signe;
		(*position)++;
	}
}

int		ft_get_pile_size(int ac, char **str)
{
	int i;
	int y;
	int size;

	i = 1;
	size = 0;
	while (i < ac)
	{
		y = 0;
		while (str[i][y])
		{
			while (str[i][y] == ' ' || str[i][y] == '\t')
				y++;
			if ((str[i][y] <= '9' && str[i][y] >= '0') || str[i][y] == '+'
				|| str[i][y] == '-')
				size++;
			while ((str[i][y] <= '9' && str[i][y] >= '0') || str[i][y] == '+'
				|| str[i][y] == '-')
				y++;
		}
		i++;
	}
	return (size);
}

int		*ft_rev_tab(t_size *size, int len)
{
	int i;
	int tmp;

	i = 0;
	len--;
	while (i < len)
	{
		tmp = size->pa[i];
		size->pa[i] = size->pa[len];
		size->pa[len] = tmp;
		i++;
		len--;
	}
	return (size->pa);
}

int		*ft_fill_pile_a(int ac, char **av, t_size *size)
{
	int i;
	int y;

	i = 1;
	y = 0;
	size->a = ft_get_pile_size(ac, av);
	if (!(size->pa = (int *)malloc(sizeof (int) * (size->a))))
		ft_exit();
	while (i < ac)
	{
		av[i] = ft_cut_white(av[i]);
		ft_multi_atoi(av[i], size, &y);
		i++;
	}
	return (size->pa);
}










