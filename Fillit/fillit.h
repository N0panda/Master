/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:04:11 by ythomas           #+#    #+#             */
/*   Updated: 2018/12/14 14:59:09 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "get_next_line.h"

void	del_temp(char ***tmp);
char	**creat_temp_file(char **file);
int		ft_error(int type);
char	**ft_creat_file(int fd);


#endif
