/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:54:47 by ythomas           #+#    #+#             */
/*   Updated: 2018/11/06 15:32:20 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc <= 1)
		return (0);
	while (argv[i + 1])
	{
		i++;
		if (ft_strcmp(argv[i], argv[i - 1]) < 0)
		{
			argv[0] = argv[i];
			argv[i] = argv[i - 1];
			argv[i - 1] = argv[0];
			i = 1;
		}
	}
	i = 1;
	while (argv[i])
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
