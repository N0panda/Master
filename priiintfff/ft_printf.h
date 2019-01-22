/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:28:14 by ythomas           #+#    #+#             */
/*   Updated: 2019/01/14 18:58:27 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct  s_flag
{
	int space;
	int ash;
	int zero;
	int minus;
	int plus;
}				t_flag;

typedef struct			s_param
{
	char				*result;
	uint64_t			variable;//ok
	t_flag				*flag; //ok
	int					range;  //.......OK
 	int					precision;//float....OK
	int					modifier; //..... OK
	char				conversion;//int/char/char *.... OK
	struct s_param		*next;
}						t_param;

int				ft_printf(const char *format, ...);
int				ft_get_modifier(char *format, int len);
int				ft_get_precision(char *format, int len);
int				ft_get_range(char *format, int len);
t_flag			*ft_get_flag(char *format, int len);
uint64_t		ft_get_var_csp(t_param *list, va_list ap);
uint64_t		ft_get_var_di(t_param *list, va_list ap);
uint64_t		ft_get_var_uoxX(t_param *list, va_list ap);
uint64_t		ft_get_var_float(t_param *list, va_list ap);
t_param			*ft_get_result(t_param *list);
char			*ft_inttoa(int64_t n);
char			*ft_utoa(uint64_t nb);
char			*ft_flag_diu(t_param *list, char *str);
char			*ft_pointeur(t_param *list);
char			*ft_octal(t_param *list);
char			*ft_hexa(t_param *list);
int				ft_affiche_resultat(char *format, t_param *list);
int				ft_skip_param(char *f);

#endif
