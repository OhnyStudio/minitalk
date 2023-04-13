/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:59:27 by jsavard           #+#    #+#             */
/*   Updated: 2023/04/13 18:31:47 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

struct s_client_info	g_client_info;

static void	ft_init(char **argv)
{
	g_client_info.current_bit = 0;
	g_client_info.i = 0;
	g_client_info.msg = argv[2];
	g_client_info.server_pid = ft_atoi(argv[1]);
	g_client_info.len = ft_strlen(g_client_info.msg);
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
		if (g_client_info.len >= 0
			&& (g_client_info.msg[g_client_info.i]
				& (1 << g_client_info.current_bit)))
			kill(g_client_info.server_pid, SIGUSR1);
		else
			kill(g_client_info.server_pid, SIGUSR2);
		g_client_info.current_bit++;
		if (g_client_info.current_bit == 8)
		{
			g_client_info.i++;
			g_client_info.current_bit = 0;
			g_client_info.len--;
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
