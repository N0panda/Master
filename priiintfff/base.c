/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:02:04 by ythomas           #+#    #+#             */
/*   Updated: 2019/01/21 15:02:06 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_copy_nb(char *str, t_param *list, char *base, int a)
{
	uint64_t val_base;
	uint64_t var;
	int		i;

	i = ft_len_number(list->variable, (uint64_t)ft_strlen(base)) + a;
	if (i < list->range)
		i = list->range;
	if (list->flag->minus == 1)
		i = ft_len_number(list->variable, (uint64_t)ft_strlen(base)) + a;
	i--;
	val_base = (uint64_t)ft_strlen(base);
	var = list->variable;
	while (var > val_base - 1)
	{
		str[i] = base[var % val_base];
		var = var / val_base;
		i--;
	}
	str[i] = base[var % val_base];
	return (str);
}

char	*ft_octal(t_param *list)
{
	char	*str;
	int		len;
	char	c;

	c = ' ';
	len = ft_len_number(list->variable, 8);
	if (list->flag->ash == 1)
		len++;
	if (len < list->range)
		len = list->range;
	if (list->flag->zero == 1)
		c = '0';
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len >= 0)
		str[--len] = c;
	ft_copy_nb(str, list, "01234567", list->flag->ash);
	len = 0;
	if (list->flag->ash == 1)
	{
		while (str[len] == c)
			len++;
		str[--len] = '0';
	}
	return (str);
}

char	*ft_pointeur(t_param *list)
{
	char *str;
	int		len;
	int		i;

	i = 0;
	len = ft_len_number(list->variable, 16) + 2;
	if (len < list->range)
	{
		if (!(str = ft_strnew(list->range)))
			return (NULL);
		while (i < list->range)
			str[i++] = ' ';
		if (list->flag->minus == 1)
			i = 0;
		else
			i = i - len;
	}
	else
		if (!(str = ft_strnew(len + 2)))
			return (NULL);
	str[i] = '0';
	str[i + 1] = 'x';
	ft_copy_nb(str, list, "0123456789abcdef", 2);
	return (str);
}

char	*ft_copy_hex(char *str, t_param *list, int a)
{
	int i;

	i = 0;
	if (list->conversion == 'x')
		ft_copy_nb(str, list, "0123456789abcdef", a);
	else
		ft_copy_nb(str, list, "0123456789ABCDEF", a);
	if (list->flag->ash == 1)
	{
		while (str[i] == ' ')
			i++;
		if (list->flag->zero == 1)
			i = 2;
		str[--i] = list->conversion;
		str[--i] = '0';
	}
	return (str);
}

char	*ft_hexa(t_param *list)
{
	char	*str;
	int		len;
	char	c;
	int		a;

	c = ' ';
	a = 0;
	len = ft_len_number(list->variable, 16);
	if (list->flag->ash == 1)
	{
		len += 2;
		a = 2;
	}
	if (len < list->range)
		len = list->range;
	if (list->flag->zero == 1)
		c = '0';
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len >= 0)
		str[--len] = c;
	str = ft_copy_hex(str, list, a);
	return (str);
}

