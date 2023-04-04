/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:38:54 by jsavard           #+#    #+#             */
/*   Updated: 2022/10/22 13:05:11 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*new_b;
	unsigned char	new_c;
	int				i;

	new_b = b;
	new_c = c;
	i = 0;
	while (len--)
	{
		new_b[i++] = new_c;
	}
	return ((void *)new_b);
}
