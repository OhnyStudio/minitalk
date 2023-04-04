/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:00:26 by jsavard           #+#    #+#             */
/*   Updated: 2022/11/09 11:50:32 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_len(int n)
{
	int		i;
	long	tmp;

	tmp = n;
	i = 0;
	if (tmp < 0)
	{
		tmp *= -1;
		i++;
	}
	while (tmp > 9)
	{
		tmp /= 10;
		i++;
	}
	if (tmp >= 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char			*nb;
	unsigned int	nbr;
	int				len;

	len = ft_check_len(n);
	nb = ft_calloc(sizeof(char), len + 1);
	if (!nb)
		return (NULL);
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	nb[len] = '\0';
	while (len--)
	{
		nb[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		nb[0] = '-';
	return (nb);
}
