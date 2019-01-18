# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ythomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/29 13:00:34 by ythomas           #+#    #+#              #
#    Updated: 2019/01/15 12:30:04 by ythomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = check_tetriminos.c creat_list_tetri.c main.c origine.c \
temp.c set_tetri_v2.c try_put_tetri.c \

FLAGS = -Wall -Werror -Wextra

LIBDIR = libft
LIB = $(LIBDIR)/libft.a

INC = libft

all : $(NAME)

$(NAME) : $(LIB)
	gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME) -I $(INC)

$(LIB) :
	make -C $(LIBDIR) all

clean :
	make -C $(LIBDIR) clean

fclean :
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

re : fclean all

.PHONY : all, re, clean, fclean
