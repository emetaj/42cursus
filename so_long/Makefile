# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emetaj <emetaj@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 13:23:45 by emetaj            #+#    #+#              #
#    Updated: 2023/04/07 15:31:20 by emetaj           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX = minilibx-linux
	EVENT = src/event_linux.c
	MLX_LIB = $(MLX)/libmlx.a
	FLAGS = -lXext -lX11 ./$(MLX)/libmlx.a -I./$(MLX) -L./$(MLX) -lmlx
endif

NAME = so_long
CC = cc
SRC = src/main.c src/map.c src/render.c src/libft_utils.c \
	src/map_check.c src/map_check2.c $(EVENT)
OBJ = $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror

.PHONY:		all clean fclean test re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX)
	@$(CC) -o $@ $? $(MLX_LIB) $(FLAGS) $(CFLAGS)
	@echo Done...
	@echo Usage:    ./so_long maps/map.ber
	@echo or just:  make test
	@echo Controls: press W A S D to move the Player

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $?
	@mv *.o src

clean:
	@rm -rf src/*.o
	@make clean -C $(MLX)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
	@rm -rf src/*.o

test: all
	./so_long maps/map.ber
