/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lk_lst_prev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:57:32 by mdelory           #+#    #+#             */
/*   Updated: 2018/08/11 04:04:11 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			lk_lst_prev(t_lklist *lst)
{
	if (!lst || !lst->cur)
		return ;
	lst->cur = lst->cur->prev;
}
