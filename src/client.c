/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:59:27 by jsavard           #+#    #+#             */
/*   Updated: 2023/04/13 18:27:32 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

struct s_client_info	client_info;

static void	ft_init(char **argv)
{
	client_info.current_bit = 0;
	client_info.i = 0;
	client_info.msg = argv[2];
	client_info.server_pid = ft_atoi(argv[1]);
	client_info.len = ft_strlen(client_info.msg);
}

static void	send_with_kill(int signal, siginfo_t *server, void *empty)
{
	(void)empty;
	(void)server;
	if (signal == SIGUSR1)
	{
		ft_putendl_fd("Server received message!", 1);
		exit(EXIT_SUCCESS);
	}
	else if (signal == SIGUSR2)
	{
		if (client_info.len >= 0
			&& (client_info.msg[client_info.i] 
				& (1 << client_info.current_bit)))
			kill(client_info.server_pid, SIGUSR1);
		else
			kill(client_info.server_pid, SIGUSR2);
		client_info.current_bit++;
		if (client_info.current_bit == 8)
		{
			client_info.i++;
			client_info.current_bit = 0;
			client_info.len--;
		}
	}
	else if (signal == -1)
		exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	struct sigaction	c_sigaction;

	if (argc != 3)
		return (1);
	c_sigaction.sa_sigaction = send_with_kill;
	c_sigaction.sa_flags = SA_SIGINFO;
	ft_init(argv);
	sigaction(SIGUSR1, &c_sigaction, NULL);
	sigaction(SIGUSR2, &c_sigaction, NULL);
	kill(getpid(), SIGUSR2);
	while (1)
		pause();
	return (0);
}
