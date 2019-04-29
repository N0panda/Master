/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:34:28 by ythomas           #+#    #+#             */
/*   Updated: 2019/04/29 12:41:24 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR 0
# define SUCCESS 1
# include "../libft/libft.h"

typedef struct				s_exec
{
	char					*param;
	struct s_exec			*next;
}							t_exec;

typedef struct				s_instru
{
	char					*action;
	int						type;
	struct s_instru			*next;
}							t_instru;

typedef struct				s_size
{
	int						*pa;
	int						*pb;
	int						a;
	int						b;
	int						nba;
	int						nbb;
	int						ind_a;
	int						ind_b;
	t_instru				*elem;
}							t_size;

int							check_format_a(int ac, char **av);
int							*ft_fill_pile_a(int ac, char **av,
							t_size *size);
char						**ft_strsplitwp(char *s);
char						*ft_cut_white(char *str);
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
void						ft_quicksort(t_size *size, int start,
							int end, int choix);
void						ft_simple_sort(t_size *size);
void						ft_quicksorttwo(int *tab, int start, int end);
int							ft_partitiontwo(int **tab, int left, int right);
int							ft_partition_a(t_size *size, int nb_push);
int							ft_partition_b(t_size *size, int nb_push);
void						ft_sort_b(t_size *size, int nb);
void						ft_sort_a(t_size *size, int nb);
int							ft_get_median(int *pile,
							int len, int *val);
void						ft_fill_elem_with(t_size *size, char *str, int act);
void						ft_optimize_elem(t_size *size);
void						ft_sort_a2(t_size *size);
void						ft_sort_b2(t_size *size);
void						ft_rollback(t_size *size, int choix, int nb);

#endif
