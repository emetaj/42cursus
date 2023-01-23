NAME = libftprintf.a

SRCS =	ft_printf.c ft_print.c

CC = gcc

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

$(NAME): ft_printf.h
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
