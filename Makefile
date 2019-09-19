# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/07 09:18:52 by bperez       #+#   ##    ##    #+#        #
#    Updated: 2019/09/19 15:40:04 by bperez      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf
CC = gcc
FLAGS = -Wall -Wextra -Werror
FLAGS2 = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
INC = fdf.h
SRC_DIR = src/
SRC = fdf.c init_fdf.c utils.c rotate.c draw_map.c projections.c more.c\
		gradient.c
OBJ_DIR = obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

.PHONY: all libft mlx clean fclean re

all: libft mlx $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(FLAGS) $(FLAGS2) -I$(INC) libft/libft.a $(OBJ) -o $(NAME)
	@echo "\033[32mcompiled [ ✔ ]"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(INC)
	$(CC) $(FLAGS) -I$(INC) -c $< -o $@

libft: libft/
	$(MAKE) -C libft/

mlx: minilibx_macos/
	$(MAKE) -C minilibx_macos/

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(MAKE) -C libft/ clean
	$(MAKE) -C minilibx_macos/ clean
	/bin/rm -rf obj/

fclean: clean
	$(MAKE) -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
