#ifndef SERVER_H
# define SERVER_H

#include <stdio.h>

#include <unistd.h>
#include <signal.h>
#include "../shared/libft/libft.h"

void		print_pid(int pid);
void		f(int signum);
void		receive(int signum, siginfo_t *siginfo, void *unused);
int			signum_to_bit(int signum);

#endif
