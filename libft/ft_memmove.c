/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:38:44 by jsavard           #+#    #+#             */
/*   Updated: 2022/10/30 09:46:44 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*lastd;
	char	*lasts;
	char	*sourc;

	dest = (char *)dst;
	sourc = (char *)src;
	if (!dest && !sourc)
		return (dst);
	if (dest < sourc)
		while (len--)
			*dest++ = *sourc++;
	else
	{
		lastd = dest + (len - 1);
		lasts = sourc + (len - 1);
		while (len--)
		{
			*lastd-- = *lasts--;
		}
	}
	return (dst);
}
