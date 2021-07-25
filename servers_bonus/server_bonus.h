/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inssong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:30:44 by inssong           #+#    #+#             */
/*   Updated: 2021/07/25 17:30:47 by inssong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <stdio.h>

# include <unistd.h>
# include <signal.h>
# include "../shared/libft/libft.h"

/*
** server.c
*/
void		print_pid(int pid);
int			send_bit(int signum, int client_pid);
void		receive(int signum, siginfo_t *siginfo, void *unused);
int			signum_to_bit(int signum);

#endif
