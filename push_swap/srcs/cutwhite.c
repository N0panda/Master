/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutwhite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:29:33 by ythomas           #+#    #+#             */
/*   Updated: 2019/04/26 18:11:42 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_count_char(char *str)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != ' ' && str[i] != '\t')
			y++;
		else if (i > 0 && ((str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			&& str[i - 1] != '\n' && str[i - 1] != ' ' && str[i - 1] != '\t'
			&& str[i + 1] != '\n' && str[i + 1] != ' ' && str[i + 1] != '\t'
			&& str[i + 1] != '\0'))
			y++;
		i++;
	}
	return (y);
}

int			ft_get_index(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0)
	{
		if (str[i] <= '9' && str[i] >= '0')
			return (i);
		i--;
	}
	return (0);
}

char		*ft_cut_white(char *str)
{
	char	*tmp;
	int		len;
	int		i;
	int		y;
	int		index;

	index = ft_get_index(str);
	len = ft_count_char(str);
	if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
		ft_exit();
	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != ' ' && str[i] != '\t')
			tmp[y++] = str[i];
		else if (i > 0 && ((str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			&& str[i - 1] != '\n' && str[i - 1] != ' ' && str[i - 1] != '\t'
			&& i < index))
			tmp[y++] = str[i];
		i++;
	}
	tmp[y] = '\0';
	return (tmp);
}
