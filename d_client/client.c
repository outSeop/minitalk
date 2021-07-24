#include "client.h"

int				main(int argc, char *argv[])
{
	int			server_pid;
	struct sigaction act;
	act.sa_flags = 	SA_SIGINFO;
	act.sa_sigaction = catcha;

	init_err_check(argc, argv);
	server_pid = ft_atoi(argv[1]);
	sigaction(SIGUSR1, &act, 0);
	send_str(server_pid, argv[2]);
}

void			send_str(int server_pid, char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		send_char(server_pid, str[i], 1);
		i++;
	}
	send_char(server_pid, str[i], 1);
}

void		catcha(int signum, siginfo_t *siginfo, void *unused)
{
	send_char(0, 0, 0);
}

void			send_char(int server_pid, char chr, int flag)
{
	int			i;
	int			bit;
	int			sigusr[2];
	static	int	stop = 0;

	if (!flag)
	{
		stop = 1;
		return ;
	}
	sigusr[0] = SIGUSR1;
	sigusr[1] = SIGUSR2;
	i = 0;
	while (i < 8)
	{
		bit = (chr & BASE_BIT) / BASE_BIT;
		if (kill(server_pid, sigusr[bit]) == -1)
			print_error("ERROR - There is wrong PID\n");
		while (!stop)
			;
		stop = 0;
		chr <<= 1;
		i++;
	}
}
