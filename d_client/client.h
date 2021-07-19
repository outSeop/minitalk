#ifndef CLIENT_H
# define CLIENT_H

#include <stdio.h>

#include <unistd.h>
#include <signal.h>
#include "../shared/libft/libft.h"


void			send_str(int server_pid, char *str);
void			send_char(int server_pid, char chr);

#endif
