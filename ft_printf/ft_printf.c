/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:13:25 by johnysavard       #+#    #+#             */
/*   Updated: 2022/12/16 12:35:19 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_char(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_printf_pct(void)
{
	write(1, "%", 1);
	return (1);
}

static int	ft_check_type(const char *s, va_list args, int i, int len)
{
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == 'c')
				len += ft_printf_char(va_arg(args, int));
			else if (s[i + 1] == 's')
				len += ft_printf_s(va_arg(args, char *));
			else if (s[i + 1] == 'p')
				len += ft_printf_ptr(va_arg(args, long long));
			else if (s[i + 1] == 'd' || s[i + 1] == 'i')
				len += ft_printf_nb(va_arg(args, int), 0);
			else if (s[i + 1] == 'u')
				len += ft_printf_nb(va_arg(args, unsigned int), 1);
			else if (s[i + 1] == 'x' || s[i + 1] == 'X')
				len += ft_printf_hexa(va_arg(args, unsigned int), s[i + 1]);
			else if (s[i + 1] == '%')
				len += ft_printf_pct();
			i++;
		}
		else
			len += ft_printf_char(s[i]);
		i++;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(args, s);
	len += ft_check_type(s, args, i, len);
	va_end(args);
	return (len);
}
