/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inssong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:30:04 by inssong           #+#    #+#             */
/*   Updated: 2021/07/25 17:30:06 by inssong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void			init_err_check(int argc, char *argv[])
{
	argc_err_check(argc);
	argv_err_check(argv);
}

void			argc_err_check(int argc)
{
	if (argc < 3)
		print_error("ERROR - Too few arguments\n");
	else if (argc > 3)
		print_error("ERROR - Too many argumetns\n");
}

void			argv_err_check(char *argv[])
{
	if (isdigits(argv[1]) == 0)
		print_error("ERROR - PID is not number\n");
	if (ft_atoi(argv[1]) < 2)
		print_error("ERROR - PID is out of range\n");
	if (ft_strlen(argv[2]) == 0)
		print_error("ERROR - String dose not exist\n");
}

int				isdigits(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void			print_error(char *error)
{
	ft_putstr_fd(error, 1);
	exit(0);
}
