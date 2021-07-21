#include "client.h"

int				main(int argc, char *argv[])
{
	int			server_pid;
	struct sigaction act;
	act.sa_flags = 	SA_SIGINFO;
	act.sa_sigaction = catcha;

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
		send_char(server_pid, str[i]);
		i++;
	}
}

void		catcha(int signum, siginfo_t *siginfo, void *unused)
{
	int i = 0;
	i++;
}

void			catc(int signum)
{

	printf("catch\n");
}

void			send_char(int server_pid, char chr)
{
	int			i;
	int			bit;
	int			base_bit;
	int			sigusr[2];
	int			chk;


	base_bit = 128;
	sigusr[0] = SIGUSR1;
	sigusr[1] = SIGUSR2;
	i = 0;
	while (i < 8)
	{
		bit = (chr & base_bit) / base_bit;
		kill(server_pid, sigusr[bit]);
		chr <<= 1;
		i++;
	}
}
