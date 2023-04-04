/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:42:46 by jsavard           #+#    #+#             */
/*   Updated: 2022/10/26 13:49:36 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_size(size_t len, size_t start, size_t size)
{
	if (size < (start + 1))
		return (0);
	if ((size - start) < len)
		return (size - start);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*str;

	size = ft_check_size(len, (size_t)start, ft_strlen(s));
	str = ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (len == SIZE_MAX)
		len--;
	if (size)
		ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
