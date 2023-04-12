SRC =   ft_atoi.c \
        ft_itoa.c \
        ft_bzero.c \
        ft_calloc.c \
        ft_isalnum.c \
        ft_isalpha.c \
        ft_isascii.c \
        ft_isdigit.c \
        ft_isprint.c \
        ft_memchr.c \
        ft_memcmp.c \
        ft_memcpy.c \
        ft_memmove.c \
        ft_memset.c \
        ft_strchr.c \
        ft_strncmp.c \
        ft_strdup.c \
        ft_substr.c \
        ft_putendl_fd.c \
        ft_putnbr_fd.c \
        ft_striteri.c \
        ft_strjoin.c \
        ft_putchar_fd.c \
        ft_putstr_fd.c \
        ft_strlcat.c \
        ft_strlcpy.c \
        ft_strlen.c \
        ft_strmapi.c \
        ft_strnstr.c \
        ft_strrchr.c \
        ft_split.c \
        ft_strtrim.c \
        ft_tolower.c \
        ft_toupper.c \
        ft_printf.c \
        ft_print.c \
        get_next_line.c

NAME = libft.a

CFLAGS = -Werror -Wextra -Wall

CC = cc

OBJ = $(SRC:.c=.o)


$(NAME):
		$(CC) -c $(CFLAGS) $(SRC)
		ar crs $(NAME) $(OBJ)

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
