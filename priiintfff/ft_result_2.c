/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:16:15 by ythomas           #+#    #+#             */
/*   Updated: 2019/01/22 17:16:17 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_result_s(t_param *list)
{
	char 	*str;
	int		i;

	i = 0;
	str = (char *)list->variable;
	if ((int)ft_strlen(str) < list->range)
	{
		if (!(list->result = ft_strnew(list->range)))
			return (NULL);
		if (list->flag->minus == 1)
		{
			i = ft_strlen(str);
			while (i < list->range)
				list->result[i++] = ' ';
			i = 0;
		}
		else
			while (i < (list->range - (int)ft_strlen(str)))
				list->result[i++] = ' ';
	}
	else
		if (!(list->result = ft_strnew(ft_strlen(str))))
			return (NULL);
	ft_memmove(list->result + i, str, ft_strlen(str));
	return (list->result);
}

char	*ft_get_result_c(t_param *list)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (list->range > 1)
	{
		if (!(list->result = ft_strnew(list->range)))
			return (NULL);
		if (list->conversion == '%' && list->flag->zero == 1)
			c = '0';
		while (i < list->range)
			list->result[i++] = c;
		if (list->flag->minus == 1)
			i = 1;
		i--;
	}
	else
		if (!(list->result = ft_strnew(1)))
			return (NULL);
	list->result[i] = (char)list->variable;
	return (list->result);
}

char	*ft_get_result_di(t_param *list)
 {
 	char *str;

 	str = ft_inttoa((int64_t)list->variable);
 	str = ft_flag_diu(list, str);
 	return (str);
 }

char	*ft_get_result_u(t_param *list)
{
	char	*str;

	str = ft_utoa(list->variable);
	str = ft_flag_diu(list, str);
	return (str);
}
