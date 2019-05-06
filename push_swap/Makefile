# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ythomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/24 15:44:04 by ythomas           #+#    #+#              #
#    Updated: 2019/05/05 14:29:49 by ythomas          ###   ########.fr        #
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
ft_fill_pile_a.c ft_free_exit.c get_exec.c cutwhite.c ft_exec_sp2_2.c

SRCX = check_format.c ft_exec_rrr2.c ft_exec_sp2.c ft_fill_pile_a.c \
ft_free_exit.c ft_fakesort.c ft_sort_1.c ft_push_swap.c cutwhite.c \
ft_quick_pile_b.c ft_quick_pile_a.c ft_edit_elem.c ft_sort_2.c \
ft_other_sort.c ft_exec_sp2_2.c

SRC_DIR = srcs/

INC = include/push_swap.h

INC_DIR = include/

RED = \033[91m
BL = \033[0m

.PHONY : all, re, clean, fclean, lib

all: $(NAME) $(NAMEX)

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo "          $(RED)< Checker Done ! >$(BL)           "

$(NAMEX): $(LIB) $(OBJX)
	@$(CC) $(FLAGS) -o $(NAMEX) $(OBJX) $(LIB)
	@echo "          $(RED)< Push_swap Done ! >$(BL)           "

$(LIB): FORCE
	@make -C $(LIB_DIR)

FORCE:

%.o: $(SRC_DIR)%.c $(INC)
	@$(CC) $(FLAGS) -c $< -o $@ -I$(INC_DIR) -I$(LIBINC)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJX)
	@echo "          $(RED)< Clean Done >$(BL)           "

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAMEX)
	@echo "          $(RED)< Programme Checker et Push_swap Deleted >$(BL)"

re: fclean all

lib:
	@make re -C $(LIB_DIR)
	@echo "          $(RED)< Libft Remake Done ! >$(BL)           "
