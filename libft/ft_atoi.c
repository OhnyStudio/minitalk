/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:27:02 by jsavard           #+#    #+#             */
/*   Updated: 2022/11/09 15:31:01 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_check_max(unsigned long long nb, int signe)
{
	if (nb > 9223372036854775807)
	{
		if (signe < 0)
			return (0);
		else
			return (-1);
	}
	return (nb * signe);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					signe;
	unsigned long long	nb;

	i = 0;
	signe = 1;
	nb = 0;
	if (str[i] == '\0')
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (ft_check_max(nb, signe));
}
