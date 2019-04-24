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
# include "../libft/libft.h"
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
	int				ind_a;
	int				ind_b;
}								t_size;

typedef struct 					s_number
{
	int				sorted;
	int				position;
	int				nb;
	struct s_number	*next;
}								t_number;

int							check_format_a(int ac, char **av);
int							*ft_fill_pile_a(int ac, char **av, t_size *size);
char						**ft_strsplitwp(char *s);
char 						*ft_cut_white(char *str);
t_exec						*ft_get_exec(int *nb);
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
int							ft_abs(int nb);
void						ft_quicksort(t_size *size, int start, int end, int choix);
void						ft_simple_sort(t_size *size);
void						ft_quicksorttwo(int *tab, int start, int end);
int							ft_partitiontwo(int **tab, int left, int right);

#endif

