/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:25:15 by ythomas           #+#    #+#             */
/*   Updated: 2019/01/22 17:25:17 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
