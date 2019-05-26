# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ythomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/26 12:39:06 by ythomas           #+#    #+#              #
#    Updated: 2019/05/26 12:39:10 by ythomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler_visu

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs/

INC = includes/filler_visu.h

INC_DIR = includes/

LIB = ft_printf/libftprintf.a

LIB_DIR = ft_printf/

LIB_INC = ft_printf/includes/

RED = \033[91m
BL = \033[0m

OBJ = $(SRC:.c=.o)

SRC = visu_main.c player_name.c visu_init.c refresh.c display.c

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB) -I$(LIB_INC)
	@echo "          $(RED)< Filler_visu Done ! >$(BL)           "

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
