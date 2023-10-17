/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:46:45 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/20 16:45:23 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	temp = ft_lstnew((*f)(lst->content));
	if (!temp->content)
	{
		ft_lstclear(&new, del);
		return (NULL);
	}
	new = temp;
	lst = lst->next;
	while (lst)
	{
		temp->next = ft_lstnew((*f)(lst->content));
		if (!temp->content)
		{
			ft_lstclear(&new, (*del));
			return (NULL);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (new);
}
