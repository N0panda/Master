/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:28:58 by ythomas           #+#    #+#             */
/*   Updated: 2018/12/14 15:05:05 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**creat_temp_file(char **file)
{
	char	**tmp;
	int		i;
	char 	*temp;

	if (!(tmp = (char**)malloc(sizeof(char*) * 6)))
		return (NULL);
	i = 0;
	tmp[i] = ft_strnew(5);
	tmp[i] = ft_strcpy(tmp[i], "00000");
	i++;
	while (i < 5)
	{
		tmp[i] = ft_strnew(1);
		tmp[i][0] = '0';
		temp = tmp[i];
		tmp[i] = ft_strjoin(tmp[i], file[i - 1]);
		free(temp);
		i++;
	}
	tmp[i] = ft_strnew(5);
	tmp[i] = ft_strcpy(tmp[i], "00000");
	return (tmp);
}

void	del_temp(char ***tmp)
{
	int i;

	i = 0;
	while (i < 6)
	{
		free((*tmp)[i]);
		(*tmp)[i] = NULL;
		i++;
	}
	free (*tmp);
}

void	ft_error(int type)
{
	if (type == 1)
	{
		ft_putendl("usage: fillit tetriminos_file");
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_putendl("error");
		exit(EXIT_SUCCESS);
	}
}
