/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:12:12 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/04 14:12:13 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_av(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if ((str[i] == '+' || str[i] == '-') && i == 0)
			i++;
		else if ((str[i] == '+' || str[i] == '-') && i != 0 && (str[i - 1] == ' '
			|| str[i - 1] == '\t') && (str[i + 1] <= '9' && str[i + 1] >= '0'))
			i++;
		if(!(str[i] <= '9' && str[i] >= '0') && str[i] != '\0')
			return (ERROR);
		while(str[i] <= '9' && str[i] >= '0')
			i++;
	}
	return (SUCCESS);
}

int		check_format_a(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_check_av(av[i]) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}