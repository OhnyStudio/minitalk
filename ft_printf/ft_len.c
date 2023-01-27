/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:20:53 by johnysavard       #+#    #+#             */
/*   Updated: 2022/11/09 15:51:43 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

int	ft_nb_len(long long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	else if (nb == 0)
		len++;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

int	ft_ptr_len(unsigned long long nb)
{
	int	len;

	len = 0;
	while (nb > 15)
	{
		len++;
		nb = nb / 16;
	}
	if (nb >= 0)
		len++;
	return (len);
}
