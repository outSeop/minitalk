# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inssong <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 12:36:14 by inssong           #+#    #+#              #
#    Updated: 2021/07/25 12:36:16 by inssong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SERVER_NAME = server

CLIENT_NAME_BONUS = client_bonus
SERVER_NAME_BONUS = server_bonus

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CSRC =	clients/client.c \
		clients/error.c
SSRC =	servers/server.c

COBJ = $(CSRC:%.c=%.o)
SOBJ = $(SSRC:%.c=%.o)

CSRCB =	clients_bonus/client_bonus.c \
		clients_bonus/error_bonus.c
SSRCB =	servers_bonus/server_bonus.c

COBJB = $(CSRCB:%.c=%.o)
SOBJB = $(SSRCB:%.c=%.o)

all: $(CLIENT_NAME) $(SERVER_NAME)

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

libft:
	make fclean -C shared/libft
	make -C shared/libft/

$(CLIENT_NAME): libft $(COBJ)
	$(CC) -o $@ $(COBJ) -L./shared/libft -lft -I./
$(SERVER_NAME): libft $(SOBJ)
	$(CC) -o $@ $(SOBJ) -L./shared/libft -lft -I./

bonus: $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

$(CLIENT_NAME_BONUS): libft $(COBJB)
	$(CC) -o $(CLIENT_NAME) $(COBJB) -L./shared/libft -lft -I./
$(SERVER_NAME_BONUS): libft $(SOBJB)
	$(CC) -o $(SERVER_NAME) $(SOBJB) -L./shared/libft -lft -I./

clean:
	rm -f $(COBJ) $(SOBJ)
	rm -f $(COBJB) $(SOBJB)

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)
	rm -f $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

re: fclean all


.PHONY: all clean fclean re libft bonus
