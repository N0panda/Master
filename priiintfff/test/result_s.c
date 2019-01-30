/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:33:25 by ythomas           #+#    #+#             */
/*   Updated: 2019/01/29 14:00:15 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cutstr(char *str, t_param *list)
{
	char tmp;
	int i;

	if(!(tmp = ft_strnew(list->precision)))
		return (NULL);
	i = 0;
	while (i < list->precision)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_precision(char *str, t_param *list)
{
	if (list->conversion == 's')
	{
		if(list->precision < ft_strlen(str))
			return (ft_cutstr(str, list))
	}
}

char	*ft_get_result_s(t_param *list)
{
	char *str;

	str = (char *)list->vriable;
	if(list->precision != 0 && (list->precision < ft_strlen(str)))
		str = ft_precision(str, list);
}
