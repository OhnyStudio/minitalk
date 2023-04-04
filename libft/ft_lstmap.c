/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:17 by jsavard           #+#    #+#             */
/*   Updated: 2022/11/09 14:43:27 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_item;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		new_item = ft_lstnew(content);
		if (new_item == NULL)
		{
			ft_lstclear(&new_list, del);
			free(content);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_item);
		lst = lst->next;
	}
	return (new_list);
}
