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

int		ft_skip_param(char *f)
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

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_param		*list;
	int 		result;

	result = 0;
	va_start(ap, format);
	if (ft_check_format((char *)format) == 1)
	{
		list = ft_create_list((char *)format);
		list = ft_input_variable(list, ap);
		list = ft_get_result(list);
		result = ft_affiche_resultat((char *)format, list);
	}
	else
	{
		result = ft_strlen(format);
		write(1, format, result);
	}
	va_end(ap);
	//free liste;
	return (result);
}

int		main(void)
{
	char str[12] = "touslemonde";
	char sti[12] = "cava";
	int i = 42;

	ft_printf("salut %s comment %s on est %d", str, sti, i);
	//ft_printf("salut");
	return 0;
}




