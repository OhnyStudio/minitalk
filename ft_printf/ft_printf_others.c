/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_others.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:15:30 by jsavard           #+#    #+#             */
/*   Updated: 2022/12/16 12:34:16 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf_nb(uintptr_t n, int is_unsigned)
{
	int		len;

	len = 0;
	if (is_unsigned == 1)
		ft_putnbr_u_fd(n, 1);
	else
	{
		ft_putnbr_fd(n, 1);
	}
	len = ft_nb_len(n);
	return (len);
}

static void	ft_putptr(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_putptr(nb / 16);
		ft_putptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
			ft_putchar_fd((nb - 10 + 'a'), 1);
	}
}

int	ft_printf_ptr(uintptr_t ptr)
{
	int	len;

	len = 2;
	write(1, "0x", 2);
	if (ptr == 0)
	{
		len++;
		write(1, "0", 1);
	}
	else
	{
		ft_putptr(ptr);
		len += ft_ptr_len(ptr);
	}
	return (len);
}
