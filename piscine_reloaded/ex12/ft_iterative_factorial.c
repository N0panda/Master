/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:32:15 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/07 15:14:11 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;

	if (nb > 12)
		return (0);
	else if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	i = nb;
	while (i > 1)
	{
		i--;
		nb = i * nb;
	}
	return (nb);
}
