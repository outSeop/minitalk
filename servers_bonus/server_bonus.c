/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inssong <inssong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 12:37:43 by inssong           #+#    #+#             */
/*   Updated: 2021/07/25 12:39:23 by inssong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

int			main(void)
{
	struct sigaction act;

	print_pid(getpid());
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = receive;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
}

void		receive(int signum, siginfo_t *siginfo, void *unused)
{
	int			bit;
	static int	client_pid = 0;

	(void)unused;
	if (client_pid == 0)
		client_pid = siginfo->si_pid;
	bit = signum_to_bit(signum);
	if (send_bit(bit, client_pid))
		client_pid = 0;
}

int			signum_to_bit(int signum)
{
	if (signum == SIGUSR1)
		return (0);
	else
		return (1);
}

int			send_bit(int bit, int client_pid)
{
	static char c = 0;
	static int	cnt = 0;

	c = c | bit;
	cnt++;
	if (cnt == 8)
	{
		if (c == '\0')
		{
			c = 0;
			cnt = 0;
			return (!kill(client_pid, SIGUSR1));
		}
		write(1, &c, 1);
		c = 0;
		cnt = 0;
	}
	c <<= 1;
	return (kill(client_pid, SIGUSR1));
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
