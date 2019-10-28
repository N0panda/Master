/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lk_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 17:23:02 by mdelory           #+#    #+#             */
/*   Updated: 2018/08/11 03:50:29 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lklist			*lk_lst_new(void *content, size_t size)
{
	t_lklist		*new;

	if ((new = (t_lklist *)ft_memalloc(sizeof(t_lklist))))
	{
		if (content)
		{
			if ((new->content = ft_memalloc(size)))
			{
				ft_memcpy(new->content, content, size);
				new->size = size;
			}
		}
	}
	return (new);
}
