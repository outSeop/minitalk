#include "server.h"

int		i;
int			main()
{
	struct sigaction act;

	print_pid(getpid());
	act.sa_flags = 	SA_SIGINFO;
	act.sa_sigaction = receive;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while(1)
		pause();
}

void		receive(int signum, siginfo_t *siginfo, void *unused)
{
	int		bit;

	bit = signum_to_bit(signum);
	f(bit);
}
int			signum_to_bit(int signum)
{
	if (signum == SIGUSR1)
		return (0);
	else
		return (1);
}

void		f(int bit)
{
	static char c = 0;
	static int	cnt = 0;

	c = c | bit;
	cnt++;
	if (cnt == 8)
	{
		write(1, &c, 1);
		c = 0;
		cnt = 0;
	}
	c <<= 1;
}

void		print_pid(int pid)
{
	int		pid_length;
	char	*str_pid;

	str_pid = ft_itoa(pid);
	pid_length = ft_strlen(str_pid);
	write(1, "[PID] - ", 9);
	write(1, str_pid, pid_length + 1);
	write(1, "\n", 1);
}
