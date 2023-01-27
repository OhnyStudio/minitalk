/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ppid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:23:37 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/27 16:43:47 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	call_printf(void)
{
	pid_t	test;

	test = getpid();
	ft_printf("%d", test);
}

int	main(void)
{
	call_printf();
	return (0);
}
