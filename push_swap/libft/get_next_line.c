/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:39:56 by ythomas           #+#    #+#             */
/*   Updated: 2019/04/30 18:58:19 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_input_line(char **line, char *tab)
{
	int				i;
	char			*tmp;

	i = 0;
	if (tab != NULL && tab[0] == '\0')
		ft_strdel(&tab);
	else if (tab != NULL && ft_strchr(tab, '\n') != NULL)
	{
		while (tab[i] != '\n')
			i++;
		*line = ft_strndup(tab, i);
		i++;
		tmp = ft_strdup(tab + i);
		free(tab);
		tab = tmp;
	}
	else if (tab != NULL && ft_strchr(tab, '\n') == NULL)
	{
		*line = ft_strdup(tab);
		ft_strdel(&tab);
		tab = ft_strnew(0);
	}
	return (tab);
}

static int			ft_mercilanorme(char **tb, int fd)
{
	if (tb[fd] == NULL)
	{
		free(tb[fd]);
		return (0);
	}
	if (tb[fd][0] == '\0')
	{
		free(tb[fd]);
		tb[fd] = NULL;
	}
	return (1);
}

void				ft_gnl_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int					ft_parsing(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 's' && str[i] != 'p' && str[i] != 'a' && str[i] != 'b'
			&& str[i] != '\n' && str[i] != 'r')
			return (0);
		i++;
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*tb[OPEN_MAX];
	int				lu;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	lu = 0;
	if (!line || read(fd, NULL, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	while ((!tb[fd] || !ft_strchr(tb[fd], 10))
		&& (lu = read(fd, buf, BUFF_SIZE)))
	{
		buf[lu] = '\0';
		if (ft_parsing(buf) == 0)
			ft_gnl_exit();
		tmp = tb[fd];
		tb[fd] = tb[fd] ? ft_strjoin(tb[fd], buf) : ft_strdup(buf);
		ft_strdel(&tmp);
	}
	tb[fd] = ft_input_line(line, tb[fd]);
	if (tb[fd] == NULL || tb[fd][0] == '\0')
		return (ft_mercilanorme(tb, fd));
	return (1);
}
