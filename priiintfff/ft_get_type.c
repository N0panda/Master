/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:04:59 by ythomas           #+#    #+#             */
/*   Updated: 2019/01/16 14:05:02 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t		ft_get_var_csp(t_param *list, va_list ap)
{
	char c;

	c = '%';
	if (list->conversion == '%')
		return (list->variable = (uint64_t)c);
	if (list->conversion == 'c')
		return (list->variable = (uint64_t)(va_arg(ap, int)));
	if (list->conversion == 's')
		return (list->variable = (uint64_t)(va_arg(ap, char *)));
	if (list->variable == 'p')
		return (list->variable = (uint64_t)(va_arg(ap, void *)));
	return (0);
}

uint64_t		ft_get_var_di(t_param *list, va_list ap)
{
	if (list->modifier == 4)
		return (list->variable = (uint64_t)(va_arg(ap, long long int)));
	if (list->modifier == 3)
		return (list->variable = (uint64_t)(va_arg(ap, long int)));
	if (list->modifier <= 2 || list->modifier == 5)
		return (list->variable = (uint64_t)(va_arg(ap, int)));
	return (0);
}

uint64_t		ft_get_var_uoxX(t_param *list, va_list ap)
{
	if (list->modifier == 4)
		return (list->variable = (uint64_t)(va_arg(ap, unsigned long long int)));
	if (list->modifier == 3)
		return (list->variable = (uint64_t)(va_arg(ap, unsigned long int)));
	if (list->modifier <= 2 || list->modifier == 5)
		return (list->variable = (uint64_t)(va_arg(ap, unsigned int)));
	return (0);
}

uint64_t		ft_get_var_float(t_param *list, va_list ap)
{
	if (list->modifier == 5)
		return (list->variable = (uint64_t)(va_arg(ap, long double)));
	if (list->modifier == 3)
		return (list->variable = (uint64_t)(va_arg(ap, double)));
	else
		return (list->variable = (uint64_t)(va_arg(ap, float)));
}