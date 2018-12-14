# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ythomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:00:49 by ythomas           #+#    #+#              #
#    Updated: 2018/11/13 16:29:50 by ythomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = srcs/ft_putchar.c \
	  srcs/ft_putstr.c \
	  srcs/ft_strcmp.c \
	  srcs/ft_strlen.c \
	  srcs/ft_swap.c
$(NAME):
	gcc -c $(SRC)
	ar rc $(NAME) ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

all: $(NAME)

clean:
	rm -rf ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
