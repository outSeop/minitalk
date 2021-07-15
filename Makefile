CLIENT_NAME = client
SERVER_NAME = server

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I. -c

CSRC =	d_client/client.c \

SSRC =	d_server/server.c \

COBJ = $(CSRC:%.c=%.o)
SOBJ = $(SSRC:%.c=%.o)

all: libft $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(COBJ)
	ar rcs $(CLIENT_NAME) $(COBJ)
$(SERVER_NAME): $(SOBJ)
	ar rcs $(SERVER_NAME) $(SOBJ)

$ (COBJ): $(CSRC)
	$(CC) $(CFLAGS) $(CSRC) -Llibft
$ (SOBJ): $(SSRC)
	$(CC) $(CFLAGS) $(SSRC) -Llibft

clean:
	rm -f $(COBJ) $(SOBJ)

fclean:
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re:
	fclean all

libft:
	make -C shared/libft/

.PHONY: all clean fclean re libft
