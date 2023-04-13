/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:27:08 by jsavard           #+#    #+#             */
/*   Updated: 2023/04/13 16:05:35 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_server_info
{
	char	*msg;
	int		client_pid;
}	t_server_info;

typedef struct s_client_info
{
	char	*msg;
	int		i;
	int		current_bit;
	int		server_pid;
	int		len;
}	t_client_info;

#endif