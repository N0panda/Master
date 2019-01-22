/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:31:47 by ythomas           #+#    #+#             */
/*   Updated: 2019/01/16 17:31:49 by ythomas          ###   ########.fr       */
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

char	*ft_get_result_p(t_param *list)
{
	char	*str;

	str = ft_pointeur(list);
	return (str);
}

char	*ft_get_result_xX(t_param *list)
{
	char *str;

	str = ft_hexa(list);
	return (str);
}

// char	*ft_get_result_f(t_param *list)
// {
// 	;
// }

 char	*ft_get_result_o(t_param *list)
{
	char *str;

	str = ft_octal(list);
	return (str);
}

t_param		*ft_get_result(t_param *list)
{
	t_param		*depart;

	depart = list;
	while (list != NULL)
	{
		if (list->conversion == 's')
			list->result = ft_get_result_s(list);
		else if (list->conversion == 'c' || list->conversion == '%')
		 	list->result = ft_get_result_c(list);
		else if (list->conversion == 'd' || list->conversion == 'i')
		 	list->result = ft_get_result_di(list);
		else if (list->conversion == 'u')
			list->result = ft_get_result_u(list);
		else if (list->conversion == 'p')
			list->result = ft_get_result_p(list);
		else if (list->conversion == 'x' || list->conversion == 'X')
		 	list->result = ft_get_result_xX(list);
		// else if (list->conversion == 'f')
		// 	list->result = ft_get_result_f(list);
		else if (list->conversion == 'o')
			list->result = ft_get_result_o(list);
		list = list->next;
	}
	return (depart);
}
