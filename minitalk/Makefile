# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emetaj <emetaj@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 15:42:36 by emetaj            #+#    #+#              #
#    Updated: 2023/04/12 13:30:40 by emetaj           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CLIENT_SRCS		=	./src/client.c

SERVER_SRCS		= 	./src/server.c

SRCS			=	$(CLIENT_SRCS) $(SERVER_SRCS)

OBJS			=	$(SRCS:.c=.o)

CLIENT_OBJS		=	$(CLIENT_SRCS:.c=.o)

SERVER_OBJS		=	$(SERVER_SRCS:.c=.o)

CLIENT_NAME		=	client

SERVER_NAME		=	server

LIBFT_NAME		=	libft.a

CC				=	cc

RM				=	rm -f

CFLAGS = -Wall -Wextra -Werror


all:            $(LIBFT_NAME) $(CLIENT_NAME) $(SERVER_NAME)

$(LIBFT_NAME):
		@echo "compiling libft..."

		@$(MAKE) -s all -C ./libft
		@echo "compiling done"

$(CLIENT_NAME): $(CLIENT_OBJS)
		@echo "compiling client..."
		@$(CC) -o $(CLIENT_NAME) $(CFLAGS) $(CLIENT_OBJS) ./libft/libft.a
		@echo "compiling done"

$(SERVER_NAME): $(SERVER_OBJS)
		@echo "compiling server..."
		@$(CC) -o $(SERVER_NAME) $(CFLAGS) $(SERVER_OBJS) ./libft/libft.a
		@echo "compiling done"

clean:
		@$(MAKE) -s clean -C ./libft
		@$(RM) $(OBJS)

fclean: clean
		@echo "cleaned all"
		@$(MAKE) -s fclean -C ./libft
		@$(RM) $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re client server
