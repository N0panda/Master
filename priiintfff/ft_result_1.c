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
