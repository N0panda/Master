# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ythomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 17:31:24 by ythomas           #+#    #+#              #
#    Updated: 2019/01/31 18:59:09 by ythomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_aff_resultat.c ft_get.c ft_printf.c ft_toa.c ft_flag.c ft_get_type.c \
	  ft_result_1.c ft_result_2.c tools.c ft_flag_2.c base.c ft_precision.c \
	  ft_free.c ft_float.c check_format.c \

DIR_OBJ = obj/

DIR_SRC = src/

LIBFT = libft

INC = include

FLAG  = -Werror -Wall -Wextra

SRCS = $(addprefix $(DIR_SRC), $(SRC))

OBJS =  $(addprefix $(DIR_OBJ), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[92m============================================\033[0m"
	@echo "\033[92m=============== MAKE DONE ==================\033[0m"
	@echo "\033[92m============================================\033[0m"

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@mkdir -p $(DIR_OBJ)
	@gcc $(FLAG) -I $(INC) -I libft -o $@ -c $<

clean:
	@rm -rf $(DIR_OBJ)
	@make -C $(LIBFT) clean
	@echo "\033[92m============================================\033[0m"
	@echo "\033[92m=============== CLEAN DONE =================\033[0m"
	@echo "\033[92m============================================\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

norm:
	@echo "\033[92m===========================================\033[0m"
	@echo "\033[92mPassage de la norminette sur les fichier .c\033[0m"
	@echo "\033[92m===========================================\033[0m"
	@norminette $(SRCS)

re: fclean all

.PHONY : all, re, clean, fclean, norm
