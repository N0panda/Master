/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:15:04 by ythomas           #+#    #+#             */
/*   Updated: 2019/01/15 16:15:07 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_search(char *format, char *to_find, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (format[i] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (1);
			i++;
			j++;
		}
		i = i - j;
		i++;
	}
	return (0);
}

t_flag	*ft_inti_struct_flag(t_flag *flag)
{
	flag->space = 0;
	flag->ash = 0;
	flag->zero = 0;
	flag->minus = 0;
	flag->plus = 0;
	return (flag);
}

t_flag	*ft_exception_flag(t_flag *flag)
{
	if (flag->zero == 1 && flag->minus == 1)
		flag->zero = 0;
	if (flag->plus == 1 && flag->space == 1)
		flag->space = 0;
	return (flag);
}

t_flag	*ft_get_flag(char *f, int len)
{
	t_flag *flag;
	int i;

	if (!(flag = (t_flag *)malloc(sizeof(t_flag))))
		return (NULL);
	flag = ft_inti_struct_flag(flag);
	i = 1;
	while (i < len && (f[i] == '#' || f[i] == '-' || f[i] == '+' || f[i] == ' '
		|| f[i] == '0'))
	{
		if (f[i] == '#')
			flag->ash = 1;
		if (f[i] == '0')
			flag->zero = 1;
		if (f[i] == '-')
			flag->minus = 1;
		if (f[i] == '+')
			flag->plus = 1;
		if (f[i] == ' ')
			flag->space = 1;
		i++;
	}
	ft_exception_flag(flag);
	return (flag);
}

int		ft_get_range(char *format, int len)
{
	int		i;
	int		resultat;

	i = 0;
	resultat = 0;
	while (i < len && (format[i] < '1' || format[i] > '9'))
	{
		if (format[i] == '.')
			return (0);
		i++;
	}
	if (i == len)
		return (0);
	while (format[i] >= '0' && format[i] <= '9')
	{
		resultat = resultat * 10;
		resultat += (format[i] - '0');
		i++;
	}
	return (resultat);
}

int		ft_get_precision(char *format, int len)
{
	int		i;
	int		resultat;

	i = 0;
	resultat = 0;
	while (i < len && format[i] != '.')
		i++;
	if (format[i] != '.')
		return (0);
	i++;
	while (format[i] >= '0' && format[i] <= '9')
	{
		resultat = resultat * 10;
		resultat += (format[i] - '0');
		i++;
	}
	return (resultat);
}

int		ft_get_modifier(char *format, int len)
{
	if (ft_search(format, "L", len) == 1)
		return (5);
	if (ft_search(format, "ll", len) == 1)
		return (4);
	if (ft_search(format, "l", len) == 1)
		return (3);
	if (ft_search(format, "hh", len) == 1)
		return (1);
	if (ft_search(format, "h", len) == 1)
		return (2);
	return (0);
}