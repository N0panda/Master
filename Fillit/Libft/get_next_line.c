/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:56:25 by ythomas           #+#    #+#             */
/*   Updated: 2018/12/12 12:42:36 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <limits.h>
#include "libft.h"

char	*f(char *tb, int a)
{
	if (a == 1)
		return (ft_strchr(tb, '\n'));
	else
		return (ft_strsub(tb, 0, (size_t)(f(tb, 1) - tb)));
}

int		get_next_line(int fd, char **line)
{
	static char		*tb[OPEN_MAX];
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				lu;

	lu = 0;
	if (!line || (read(fd, NULL, 0) < 0))
		return (-1);
	while ((!tb[fd] || !f(tb[fd], 1)) && (lu = (read(fd, buf, BUFF_SIZE))) > 0)
	{
		buf[lu] = '\0';
		tmp = tb[fd] ? tb[fd] : NULL;
		if (!(tb[fd] = tb[fd] ? ft_strjoin(tb[fd], buf) : ft_strdup(buf)))
			return (-1);
		tmp ? free(tmp) : 0;
	}
	if (!lu && (!tb[fd] || !tb[fd][0]))
		return ((*line = ft_strnew(0)) ? 0 : -1);
	if (!(*line = f(tb[fd], 1) ? f(tb[fd], 0) : ft_strdup(tb[fd])))
		return (-1);
	if (!(tmp = f(tb[fd], 1) ? ft_strdup(f(tb[fd], 1) + 1) : (char*)1))
		return (-1);
	tmp = tmp == (char*)1 ? NULL : tmp;
	free(tb[fd]);
	return ((tb[fd] = tmp) ? 1 : 1);
}
