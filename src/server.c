/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:23:37 by jsavard           #+#    #+#             */
/*   Updated: 2023/04/13 18:32:07 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

struct s_server_info	g_server_info;

static char	*str_add_char(char *str, char c)
{
	char	*new_str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	new_str = ft_calloc(len + 2, sizeof(char));
	if (str)
	{
		while (str[i])
		{
			new_str[i] = str[i];
			i++;
		}
	}
	new_str[i] = c;
	free(str);
	return (new_str);
}

static void	ft_cleanserver(int *binairy, int *received)
{
	free(g_server_info.msg);
	g_server_info.msg = 0;
	g_server_info.client_pid = 0;
	*binairy = 0;
	*received = 0;
}

static void	received_with_kill(int signal, siginfo_t *client, void *empty)
{
	static int	binairy;
	static int	received;

	(void)empty;
	if (g_server_info.client_pid != client->si_pid && client->si_pid != 0)
		ft_cleanserver(&binairy, &received);
	if (!g_server_info.client_pid)
		g_server_info.client_pid = client->si_pid;
	if (signal == SIGUSR1)
		received |= (1 << binairy);
	if (++binairy == 8)
	{	
		if (!received)
		{
			ft_putendl_fd(g_server_info.msg, 1);
			kill(g_server_info.client_pid, SIGUSR1);
			ft_cleanserver(&binairy, &received);
			return ;
		}
		else
			g_server_info.msg = str_add_char(g_server_info.msg, received);
		binairy = 0;
		received = 0;
	}
	kill(g_server_info.client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	s_sigaction;

	s_sigaction.sa_sigaction = received_with_kill;
	s_sigaction.sa_flags = SA_SIGINFO;
	g_server_info.msg = NULL;
	g_server_info.client_pid = 0;
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
		pause();
	return (0);
}
