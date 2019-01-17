/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:16:28 by ythomas           #+#    #+#             */
/*   Updated: 2019/01/14 17:16:30 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_check_format(char *format)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			return (1);
		i++;
	}
	return (0);
}

static int		ft_skip_param(char *f)
{
	int i;

	i = 1;
	while (f[i] != '\0' && f[i] != 'd' && f[i] != 'i' && f[i] != 'o' && f[i] != 'u' && f[i] != 'x' && f[i] != 'X' && f[i] != 'c' && f[i] != 's' && f[i] != 'p' && f[i] != 'f' && f[i] != '%')
		i++;
	return (i);
}

static t_param		*ft_create_maillon(char *format)
{
	t_param		*maillon;
	int			len;

	len = ft_skip_param(format);
	if (!(maillon = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	maillon->conversion = format[len];
	maillon->modifier = ft_get_modifier(format, len);
	maillon->precision = ft_get_precision(format, len);
	maillon->range = ft_get_range(format, len);
	maillon->flag = ft_get_flag(format, len);
	maillon->next = NULL;
	return (maillon);
}

static t_param		*ft_create_list(char *format)
{
	int		i;
	char	*tmp;
	t_param		*list;
	t_param		*depart;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (depart == NULL)
				depart = ft_create_maillon(format + i);//il faut envoyer la vleur egalement
			else
			{
				list = depart;
				while (list->next != NULL)
					list = list->next;
				list->next = ft_create_maillon(format + i);
			}
			i += ft_skip_param(format + i);
		}
		i++;
	}
	return (depart);
}

t_param		*ft_input_variable(t_param *list, va_list ap)
{
	t_param	*start;

	start = list;
	while (list != NULL)
	{
		if (list->conversion == 'c' || list->conversion == 's' || list->conversion == 'p' || list->conversion == '%')
			list->variable = ft_get_var_csp(list, ap);
		else if (list->conversion == 'd' || list->conversion == 'i')
			list->variable = ft_get_var_di(list, ap);
		else if (list->conversion == 'u' || list->conversion == 'x' || list->conversion == 'X' || list->conversion == 'o')
			list->variable = ft_get_var_uoxX(list, ap);
		else if (list->conversion == 'f')
			list->variable = ft_get_var_float(list, ap);
		list = list->next;
	}
	return (start);
}


void	ft_affiche_list(t_param *list)
{
	// printf("conv : %c ",list->conversion);
	// printf("modi : %d ",list->modifier);
	// printf("prec : %d ",list->precision);
	//printf("rang : %d\n",list->range);
	// printf("s : %d a : %d z : %d, m : %d, p : %d\n", list->flag->space, list->flag->ash, list->flag->zero, list->flag->minus, list->flag->plus);
	if (list->conversion == 'i')
		ft_putnbr((long int)(list->variable));	
	if (list->conversion == 'd')
		ft_putstr((list->result));
	else if (list->conversion == 'c' || list->conversion == '%')
		ft_putstr((list->result));
	else if (list->conversion == 's')
		ft_putstr((list->result));
	if (list->next != NULL)
		return (ft_affiche_list(list->next));
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*resultat;
	t_param		*list;

	va_start(ap, format);
	if (ft_check_format((char *)format) == 1)
	{
		list = ft_create_list((char *)format);
		list = ft_input_variable(list, ap);
		list = ft_get_result(list);
		ft_affiche_list(list);
		// resultat = ft_affichage_result(list);
	}
	else
		ft_putstr(format);
	va_end(ap);

	return 1;
	// if (resultat == NULL)
	// 	return (ft_strlen(format));
	// return (ft_strlen(resultat));
}

int		main(void)
{
	int i = 255;

	//printf("% d\n", i);
	ft_printf("%d", i);
	return 0;
}




