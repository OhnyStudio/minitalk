/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:23:37 by jsavard           #+#    #+#             */
/*   Updated: 2023/04/04 17:38:30 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

char	*ft_str_add_char(char *str, char c)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(str) + 2;
	new_str = malloc(sizeof(*str) * len);
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		new_str[j++] = str[i];
		i++;
	}
	new_str[j++] = c;
	new_str[j] = 0;
	return (new_str);
}

static void	action(int sig, siginfo_t *info, void *context)
{
	static char				*str;
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)*context;
	if (!str)
		str = malloc(sizeof(*str));
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			if (c == 0)
				ft_putstr_fd(str, 1);
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		str = ft_str_add_char(str, c);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
