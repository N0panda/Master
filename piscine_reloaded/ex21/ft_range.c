/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:58:19 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/07 15:43:35 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int x;
	int i;

	x = max - min;
	if (min >= max)
		return (NULL);
	if (!(tab = (int*)malloc(sizeof(int) * x)))
		return (0);
	i = 0;
	while (i < x)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}
