/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:00:52 by johnysavard       #+#    #+#             */
/*   Updated: 2022/11/01 11:05:06 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthexa(unsigned int nb, const char type)
{
	if (nb >= 16)
	{
		ft_puthexa(nb / 16, type);
		ft_puthexa(nb % 16, type);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
		{
			if (type == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			if (type == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}
}

int	ft_printf_hexa(unsigned int nb, const char type)
{
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_puthexa(nb, type);
	return (ft_hexa_len(nb));
}
