/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:45:23 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/24 13:59:30 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visu.h"

char				*get_name(char *line)
{
	char		*str;
	int			len;
	int			i;
	int			size;

	len = ft_strlen(line);
	while (len > 0 && line[len] != '.')
		len--;
	len--;
	i = len;
	while (i >= 0 && line[i] != '/')
		i--;
	i++;
	size = len - i + 2;
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	str[size - 1] = '\0';
	size = 0;
	while (i <= len)
		str[size++] = line[i++];
	return (str);
}

int					get_dim(t_env *env, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			break ;
		i++;
	}
	i++;
	env->by = ft_atoi(line + i);
	while (line[i] && (line[i] <= '9' && line[i] >= '0'))
		i++;
	if (line[i] == ' ')
		i++;
	else
		return (-1);
	env->bx = ft_atoi(line + i);
	return (0);
}

int					ft_fill_board(t_env *env, int i, char *line)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (line[j] && line[j] != 'X' && line[j] != 'X'
		&& line[j] != 'X' && line[j] != 'O' && line[j] != '.')
		j++;
	while (line[j])
	{
		if (line[j] != 'O' && line[j] != 'o' && line[j] != 'x'
			&& line[j] != 'X' && line[j] != '.')
			return (-1);
		env->board[i][k] = line[j];
		j++;
		k++;
	}
	env->board[i][k] = '\0';
	return (0);
}
