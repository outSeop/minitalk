CLIENT_NAME = client
SERVER_NAME = server

CC = gcc

CFLAGS =

CSRC =	d_client/client.c \

SSRC =	d_server/server.c \

COBJ = $(CSRC:%.c=%.o)
SOBJ = $(SSRC:%.c=%.o)

all: libft $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(COBJ)
	$(CC) -o $@ $(COBJ) -L./shared/libft -lft -I./
$(SERVER_NAME): $(SOBJ)
	$(CC) -o $@ $(SOBJ) -L./shared/libft -lft -I./

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

clean:
	rm -f $(COBJ) $(SOBJ)

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

libft:
	make -C shared/libft/
reft:
	make re -C shared/libft/

.PHONY: all clean fclean re libft
