#include "server.h"

int			main()
{
	print_pid(getpid());
}

void		f(int signum)
{
	printf("%d\n", signum);
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
