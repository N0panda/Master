/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:53:20 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/21 15:53:33 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static const char		base[17] = "0123456789abcdef";

static int				get_hexa_len(int octet, long nb)
{
	int		i;

	i = 0;
	while (nb)
	{
		nb /= BASE;
		i++;
	}
	if (i > octet * 2)
		return (-1);
	return (0);
}

char					*convert_to_neg_hexa(int octet, long nb)
{
	char			*str;
	int				len;
	long			converted;

	if (octet == 2 && nb >= -32768 && nb <= 32767)
		converted = nb + 65536;
	else if (octet == 4 && nb <= 2147483647 && nb >= -2147483648)
		converted = nb + 4294967296;
	else
		return (NULL);
	if (get_hexa_len(octet, converted) == -1)
		return (NULL);
	len = 2 * octet - 1;
	if (!(str = ft_memalloc(sizeof(char) * (octet * 2 + 1))))
		return (NULL);
	while (converted)
	{
		str[len--] = base[converted % BASE];
		converted /= BASE;
	}
	while (len >= 0)
		str[len--] = '0';
	return (str);
}

char					*convert_to_hexa(int octet, long nb)
{
	char	*str;
	int		len;

	if (get_hexa_len(octet, nb) == -1)
		return (NULL);
	len = 2 * octet - 1;
	if (!(str = ft_memalloc(sizeof(char) * (octet * 2 + 1))))
		return (NULL);
	while (nb)
	{
		str[len--] = base[nb % BASE];
		nb /= BASE;
	}
	while (len >= 0)
		str[len--] = '0';
	return (str);
}
