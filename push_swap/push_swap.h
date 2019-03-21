/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:34:28 by ythomas           #+#    #+#             */
/*   Updated: 2019/03/04 16:42:50 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR 0
# define SUCCESS 1
# include "ft_printf.h"
# include <stdio.h>

typedef struct					s_exec
{
	char			*param;
	struct s_exec	*next;
}								t_exec;

typedef struct 					s_size
{
	int				*pa;
	int				*pb;
	int				a;
	int				b;
	int				nba;
	int				nbb;
}								t_size;

int							check_format_a(int ac, char **av);
int							*ft_fill_pile_a(int ac, char **av, t_size *size);
char						**ft_strsplitwp(char *s);
char 						*ft_cut_white(char *str);
t_exec						*ft_get_exec(void);
void						ft_exit(void);
int							ft_do_exec(t_exec *list, t_size *size);
int							ft_exec_sa(t_size *size);
int							ft_exec_sb(t_size *size);
int							ft_exec_pa(t_size *size);
int							ft_exec_pb(t_size *size);
int							ft_exec_ra(t_size *size);
int							ft_exec_rb(t_size *size);
int							ft_exec_rra(t_size *size);
int							ft_exec_rrb(t_size *size);
int							ft_same_num(t_size *size);
void						ft_quicksort(t_size	*size, int start, int end);

#endif

