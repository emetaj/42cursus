# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emetaj <emetaj@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 17:14:00 by emetaj            #+#    #+#              #
#    Updated: 2023/05/10 16:13:55 by emetaj           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = libft
LIBFT = ./libft/libft.a
RM = rm -rf
SRCS = utils.c move.c sort.c main.c utils2.c
SRC	= $(addprefix ./src/,$(SRCS))
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)
	@echo "Done!"
	@echo "To test the program, run 'make test' or 'make test size=10'"
	@echo "for example for testing 10 random numbers"
	@echo "./push_swap 1 2 3 4 5 6 7 8 9 10"

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFT_DIR) -lft

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $? -I./$(LIBFT_DIR)
	@mv *.o src

clean:
	@$(RM) src/*.o
	@make -s -C $(LIBFT_DIR) clean

fclean:	clean
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean

re:	fclean all clean

.PHONY: all clean fclean test re

OS = $(shell uname)

size ?= 10

ifeq ($(OS),Linux)
CHECKER = valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)
endif

test:
	@$(eval ARG = $(shell seq -1000 1000 | shuf -n $(size)))
	@echo "Checker result: "
	$(CHECKER)
	@echo "Instructions count: "
	@./push_swap $(ARG) | wc -l
