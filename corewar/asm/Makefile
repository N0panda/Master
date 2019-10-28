# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ythomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/01 16:40:09 by ythomas           #+#    #+#              #
#    Updated: 2019/10/28 16:46:00 by ythomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

CC = gcc 

FLAGS = -Wall -Wextra -Werror -g

ASM_SRCS = main \
		   pre_parsing \
		   cleaning_tools \
		   init_actions \
		   tools \
		   print \
		   error \
		   check_line \
		   parsing_action \
		   parse_name_comment \
		   parse_params \
		   check_param_detail \
		   ocp_and_value \
		   label_tools \
		   op \
		   label_file \
		   header_print \
		   big_endian \
		   print_file

ASM_SRC_PATH = ./srcs/asm/

LIB_DIR = ./libft
HEAD_DIR = ./includes
HEAD = asm.h
OBJ_DIR = ./obj/
OBJ_NAME = obj
HEAD_PATH = $(HEAD_DIR)/$(HEAD)
OBJ	= $(patsubst %,$(OBJ_DIR)%.o,$(ASM_SRCS))

LIB = $(LIB_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ) $(MKDIR)
	$(CC)$(FLAGS) -o $(NAME) $(OBJ) $(LIB) -I$(HEAD_PATH)

$(LIB): FORCE
	make -C $(LIB_DIR)

MKDIR: $(shell mkdir obj)

FORCE:

$(OBJ_DIR)%.o: $(ASM_SRC_PATH)%.c $(HEAD_PATH)
	$(CC) $(FLAGS) -c $< -o $@ -I$(HEAD_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all
