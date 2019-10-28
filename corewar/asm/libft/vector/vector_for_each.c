/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_for_each.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:18:44 by mdelory           #+#    #+#             */
/*   Updated: 2019/02/18 00:27:35 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void				vector_for_each(t_vector *v, void (*f)(void *))
{
	unsigned int	i;

	if (!v || !v->data)
		return ;
	i = 0;
	while (i < v->count)
	{
		f(v->data[i]);
		i++;
	}
}
