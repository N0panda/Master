/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:56:22 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/07 12:35:33 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;

	i = 2;
	if (nb <= 3)
		return (0);
	while (i < (nb / 2) && i * i <= nb)
	{
		if (i > 46340)
			return (0);
		else if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
