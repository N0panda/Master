/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:24:16 by mdelory           #+#    #+#             */
/*   Updated: 2018/05/24 13:38:23 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}