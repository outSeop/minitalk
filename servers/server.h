/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inssong <inssong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 12:36:49 by inssong           #+#    #+#             */
/*   Updated: 2021/07/25 12:37:16 by inssong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

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
