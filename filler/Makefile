# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ythomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/06 23:42:47 by ythomas           #+#    #+#              #
#    Updated: 2019/05/09 14:54:44 by ythomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ythomas.filler

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs/

INC = includes/filler.h

INC_DIR = includes/

LIB = ft_printf/libftprintf.a

LIB_DIR = ft_printf/

LIB_INC = ft_printf/includes/

RED = \033[91m
BL = \033[0m

OBJ = $(SRC:.c=.o)

SRC = main.c ft_init.c ft_free.c ft_turn.c ft_put_piece.c ft_refresh_stuff.c \
player1.c player2.c tools.c algo_rush.c distance.c algo_circle.c algo_fill.c

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB) -I$(LIB_INC)
	@echo "          $(RED)< Filler Done ! >$(BL)           "

$(LIB): FORCE
	@make -C $(LIB_DIR)

FORCE:

%.o: $(SRC_DIR)%.c $(INC)
	@$(CC) $(FLAGS) -c $< -o $@ -I$(INC_DIR)

clean:
	@rm -rf $(OBJ)
	@echo "          $(RED)< Clean Done >$(BL)           "

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIB_DIR) fclean
	@echo "          $(RED)< FClean Done >$(BL)           "

re: fclean all
