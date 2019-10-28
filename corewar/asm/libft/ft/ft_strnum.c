/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 01:58:18 by mdelory           #+#    #+#             */
/*   Updated: 2019/02/18 15:28:04 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int             ft_strnum(const char *str)
{
    int         sign;

    sign = 1;
    if (!str || !*str)
        return (0);
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (0);
        str++;
    }
    return (sign);
}