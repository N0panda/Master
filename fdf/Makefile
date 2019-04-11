# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ythomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 14:06:43 by ythomas           #+#    #+#              #
#    Updated: 2019/04/08 18:55:13 by ythomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

FLAG = -Wall -Werror -Wextra

FLAG_LIBX = -lmlx -framework OpenGL -framework AppKit

SRC = fdf.c ft_color.c ft_display_map.c ft_get_map.c ft_hook.c ft_image_tools.c \
ft_parsing.c ft_rotate.c ft_rotate_x.c ft_rotate_z.c ft_translation.c \
ft_draw_case.c ft_rotate_y.c ft_heightz.c \

SRC_DIR = src/

SRCS = $(addprefix $(SRC_DIR), $(SRC))

LIB_PATH = libft/

LIB = libft/libft.a

LIB_INC = libft/

INC_PATH = include/

INC = include/fdf.h

OBJ = $(SRC:.c=.o)

RED = \033[91m
GREEN = \033[92m
BLUE = \033[96m
YEL = \033[93m
BL = \033[0m
MAG = \033[35m

.PHONY : all, re, clean, fclean, man, lib

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(FLAG) -o $(NAME) $(OBJ) $(LIB) $(FLAG_LIBX)
	@echo "          $(RED)< Compilation Done ! >$(BL)"

$(LIB):
	@make -C $(LIB_PATH)

%.o: $(SRC_DIR)%.c $(INC)
	@$(CC) $(FLAG) -c $< -o $@ -I$(INC_PATH) -I$(LIB_INC)

clean:
	@rm -rf $(OBJ)
	@echo "          $(RED)< Clean Done >$(BL)           "

fclean: clean
	@rm -rf $(NAME)
	@echo "          $(RED)< Programme Fdf Deleted >$(BL)"

re: fclean all

lib:
	@make re -C $(LIB_PATH)

man:
	clear
	@echo ""
	@echo ""
	@echo "$(YEL) ___________________________________________________________"
	@echo "|                                                           |"
	@echo "|---------------------< MAN FDF >---------------------------|"
	@echo "|___________________________________________________________|$(BL)"
	@echo "$(YEL)|$(BL)                                                           $(YEL)|$(BL)"
	@echo "$(YEL)|$(BL)     $(MAG)< Translation >$(BL)                                       $(YEL)|$(BL)"
	@echo "$(YEL)|                                                           |"
	@echo "| TOP   =>   Fleche du haut                                 |"
	@echo "| BOT   =>   Fleche du bas                                  |"
	@echo "| LEFT  =>   Fleche de gauche                               |"
	@echo "| RIGHT =>   Fleche de droite                               |$(BL)"
	@echo "$(YEL)|$(BL)                                                           $(YEL)|$(BL)"
	@echo "$(YEL)|$(BL)     $(MAG)< Rotation >$(BL)                                          $(YEL)|$(BL)"
	@echo "$(YEL)|$(BL)                                                           $(YEL)|$(BL)"
	@echo "$(YEL)| Rotation axe Y  <-    =>  Pave Num '4'                    |"
	@echo "| Rotation axe Y  ->    =>  Pave Num '6'                    |"
	@echo "| Rotation axe x  haut  =>  Pave Num '8'                    |"
	@echo "| Rotation axe x  bas   =>  Pave Num '2'                    |"
	@echo "| Rotation axe z  <-    =>  Pave Num '9'                    |"
	@echo "| Rotation axe z  ->    =>  Pave Num '1'                    |"
	@echo "|                                                           |$(BL)"
	@echo "$(YEL)|$(BL)     $(MAG)< Zoom >$(BL)                                              $(YEL)|$(BL)"
	@echo "$(YEL)|$(BL)                                                           $(YEL)|$(BL)"
	@echo "$(YEL)| Zoom [+]  =>  Pave Num '+'                                |$(BL)"
	@echo "$(YEL)| Zoom [-]  =>  Pave Num '-'                                |$(BL)"
	@echo "$(YEL)|$(BL)                                                           $(YEL)|$(BL)"
	@echo "$(YEL)|$(BL)     $(MAG)< Couleur >$(BL)                                           $(YEL)|$(BL)"
	@echo "$(YEL)|$(BL)                                                           $(YEL)|$(BL)"
	@echo "$(YEL)| Pour ajuster la couleur, appuyer sur [q][w][e] pour faire |"
	@echo "| varier le Rouge, Vert, et bleu                            |$(BL)"
	@echo "$(YEL)|$(BL)                                                           $(YEL)|$(BL)"
	@echo "$(YEL)|$(BL) $(RED)Incrementer Rouge  =>  q$(BL)                                  $(YEL)|$(BL)"
	@echo "$(YEL)|$(BL) $(GREEN)Incrementer Vert   =>  w$(BL)                                  $(YEL)|$(BL)"
	@echo "$(YEL)|$(BL) $(BLUE)Incrementer Bleu   =>  e$(BL)                                  $(YEL)|$(BL)"
	@echo "$(YEL)|$(BL)                                                           $(YEL)|$(BL)"
	@echo "$(YEL)|___________________________________________________________|$(BL)"
	@echo ""
