/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:48:11 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/11 14:48:12 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_abs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

void		ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}