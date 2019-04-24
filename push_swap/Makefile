# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ythomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/24 15:44:04 by ythomas           #+#    #+#              #
#    Updated: 2019/04/24 15:44:06 by ythomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

NAMEX = push_swap

FLAGS = -Wall -Wextra -Werror

CC = gcc

LIB = libft/libft.a

LIB_DIR = libft/

LIBINC = libft/

OBJ = $(SRC:.c=.o)

OBJX = $(SRCX:.c=.o) 

SRC = check_format.c do_exec.c ft_checker.c ft_exec_rrr.c ft_exec_sp.c \
ft_fill_pile_a.c ft_free_exit.c get_exec.c cutwhite.c

SRCX = check_format.c ft_exec_rrr2.c ft_exec_sp2.c ft_fill_pile_a.c \
ft_free_exit.c ft_fakesort.c ft_sort_1.c ft_push_swap.c

SRC_DIR = srcs/

INC = include/

all: $(NAMEX) $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ) $(LIB)

$(NAMEX): $(OBJX)
	$(CC) $(FLAG) -o $(NAMEX) $(OBJX) $(LIB)

$(LIB):
	make -C $(LIB_DIR)

%.o: $(SRC_DIR).c $(INC)
	$(CC) $(FLAG) -c $< -o $@ -I$(INC_PATH) -I$(LIB_INC)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJX)
	echo "          $(RED)< Clean Done >$(BL)           "

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAMEX)
	echo "          $(RED)< Programme Fdf Deleted >$(BL)"

re: fclean all

lib:
	make re -C $(LIB_PATH)