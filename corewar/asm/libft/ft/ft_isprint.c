/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:36:57 by mdelory           #+#    #+#             */
/*   Updated: 2018/05/24 13:38:23 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
