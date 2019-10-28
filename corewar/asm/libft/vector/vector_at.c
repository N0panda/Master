/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_at.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:23:54 by mdelory           #+#    #+#             */
/*   Updated: 2018/11/22 11:40:58 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		*vector_at(t_vector *v, unsigned int index)
{
	if (!v || index > v->count || !v->data)
		return (NULL);
	return (v->data[index]);
}
