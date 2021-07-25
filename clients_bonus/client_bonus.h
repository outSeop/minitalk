/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inssong <inssong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 12:30:00 by inssong           #+#    #+#             */
/*   Updated: 2021/07/25 12:32:52 by inssong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <stdio.h>

# include <unistd.h>
# include <signal.h>
# include "../shared/libft/libft.h"

# define BASE_BIT 128

/*
** client.c
*/
void			send_str(int server_pid, char *str);
void			send_char(int server_pid, char chr, int flag);
void			signal_handler(int signum, siginfo_t *siginfo, void *unused);

/*
** error.c
*/
int				isdigits(char *str);
void			init_err_check(int argc, char *argv[]);
void			argc_err_check(int argc);
void			argv_err_check(char *argv[]);
void			print_error(char *error);

#endif
