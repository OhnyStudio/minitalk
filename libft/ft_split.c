/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:39:04 by jsavard           #+#    #+#             */
/*   Updated: 2022/11/09 13:50:55 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_split(char const *s, char c)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (*s)
	{
		if (*s != c && tmp == 0)
		{
			tmp = 1;
			i++;
		}
		else if (*s == c)
		{
			tmp = 0;
		}
		s++;
	}
	return (i);
}

static void	*ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
	return (NULL);
}

static void	*ft_make_word(const char *s, int start, int finish)
{
	char	*temp;

	temp = ft_calloc(sizeof(char), (finish - start + 1));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, &s[start], (finish - start) + 1);
	return (temp);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		tmp;
	char	**strs;

	strs = ft_calloc(sizeof(char *), (ft_count_split(s, c) + 1));
	if (!strs || !s)
		return (NULL);
	i = -1;
	j = 0;
	tmp = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && tmp < 0)
			tmp = i;
		else if ((s[i] == c || i == ft_strlen(s)) && tmp >= 0)
		{
			strs[j] = ft_make_word(s, tmp, i);
			if (strs[j++] == NULL)
				return (ft_free(strs, j));
			tmp = -1;
		}
	}
	strs[j] = 0;
	return (strs);
}
