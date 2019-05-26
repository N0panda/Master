/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:22:02 by ythomas           #+#    #+#             */
/*   Updated: 2019/05/24 14:02:18 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visu.h"

void				last_display(t_env *env)
{
	display_board(env);
	ft_putchar('\n');
	if (env->score_p1 > env->score_p2)
	{
		ft_printf("\033[38;5;206m       [*%s*] WIN with =*%d*= Points\033[0m",
			env->p1, env->score_p1);
		ft_putchar('\n');
		ft_printf("\033[38;5;42m       [*%s*] LOOSE with =*%d*= Points\033[0m",
			env->p2, env->score_p2);
		ft_putchar('\n');
	}
	else
	{
		ft_printf("\033[38;5;206m       [*%s*] LOOSE with =*%d*= Points\033[0m",
			env->p1, env->score_p1);
		ft_putchar('\n');
		ft_printf("\033[38;5;42m       [*%s*] WIN with =*%d*= Points\033[0m",
			env->p2, env->score_p2);
		ft_putchar('\n');
	}
}

void				display_filler_name(void)
{
	ft_putstr("\033[38;5;45m            _______   __    __");
	ft_putendl("    __        ________    _______         ");
	ft_putstr("           |   ____| |__|  |  |  |  ");
	ft_putendl("|      |        |  |   __   \\       ");
	ft_putstr("           |  |       __   |  |  |  |     ");
	ft_putendl(" |   _____|  |  | _|  |       ");
	ft_putstr("           |  |__    |  |  |  |  |  |   ");
	ft_putendl("   |  |__      |  |/   /        ");
	ft_putstr("           |   __|   |  |  |  |  |");
	ft_putendl("  |___   |   __|     |      \\         ");
	ft_putstr("           |  |      |  |  |  |  |");
	ft_putendl("______|  |  |_____   |   |\\  \\        ");
	ft_putstr("           |  |      |  |  |  |____");
	ft_putendl("        |        |  |   | \\  \\       ");
	ft_putstr("           |__|      |__|  |_______| ");
	ft_putendl("      |________|  |___|  \\__\\      \033[0m");
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
}

void				disp_board(t_env *env)
{
	int i;
	int j;

	i = 0;
	while (i < env->by)
	{
		j = 0;
		ft_putstr("\033[38;5;124m               | \033[0m");
		while (j < env->bx)
		{
			if (env->board[i][j] == 'O')
				ft_printf("\033[38;5;206mO\033[0m");
			else if (env->board[i][j] == 'X')
				ft_printf("\033[38;5;42mX\033[0m");
			else if (env->board[i][j] == '.')
				ft_printf("\033[38;5;8m.\033[0m");
			else if (env->board[i][j] == 'o' || env->board[i][j] == 'x')
				ft_printf("\033[38;5;91m%c\033[0m", env->board[i][j]);
			j++;
		}
		ft_putstr("\033[38;5;124m | \033[0m\n");
		i++;
	}
}

void				name_part(t_env *env)
{
	ft_printf("               \033[38;5;206m[*%s*]\033[0m     ", env->p1);
	ft_putstr("\033[1;38;5;124mVERSUS\033[22m     \033[38;5;42m");
	ft_printf("[*%s*]\033[0m\n", env->p2);
	ft_putchar('\n');
	ft_putchar('\n');
}

int					display_board(t_env *env)
{
	int tmp;

	ft_putstr("\033[2J");
	display_filler_name();
	tmp = -1;
	name_part(env);
	ft_putstr("               ");
	while (++tmp < (env->bx + 4))
		ft_putstr("\033[38;5;124m-\033[0m");
	ft_putchar('\n');
	disp_board(env);
	tmp = -1;
	ft_putstr("               ");
	while (++tmp < (env->bx + 4))
		ft_putstr("\033[38;5;124m-\033[0m");
	ft_putchar('\n');
	return (0);
}
