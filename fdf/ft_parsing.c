/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:52:05 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/25 11:52:15 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int						ft_check(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		if ((s[i] == '+' || s[i] == '-') && i == 0)
			i++;
		else if ((s[i] == '+' || s[i] == '-') && i != 0 && (s[i - 1] == ' '
			|| s[i - 1] == '\t') && (s[i + 1] <= '9' && s[i + 1] >= '0'))
			i++;
		if(!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
			return (0);
		while(s[i] <= '9' && s[i] >= '0')
		{
			i++;
			j = 1;
		}
	}
	if (j == 0)
		return (0);
	return (1);
}

int 				ft_get_size(char *str)
{
	int 	i;
	int 	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			nb++;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (nb);
}

void				ft_get_text(int fd, t_mlx *list, char ***text)
{
	char *line;
	int i;

	i = 0;
	list->nb = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_check(line) == 0)
			ft_exit();
		if (list->nb == 0)
			list->nb = ft_get_size(line);
		else if (ft_get_size(line) != list->nb)
			ft_exit();
		if (((*text)[i] = ft_strdup(line)) == NULL)
			ft_exit();
		i++;
	}
}

int 					**ft_check_and_get(int fd, t_mlx *list)
{
	char	**text;
	int 	**map;

	if (!(text = (char **)malloc(sizeof(char *) * list->size)))
		ft_exit();
	ft_get_text(fd, list, &text);
	map = ft_get_map(text, list);

	return (map);
}
