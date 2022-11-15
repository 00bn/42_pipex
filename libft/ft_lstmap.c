/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:18:38 by balnahdi          #+#    #+#             */
/*   Updated: 2021/10/13 16:14:38 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*final;

	if (!lst)
		return (NULL);
	final = ft_lstnew ((*f)(lst->content));
	if (!final)
		return (NULL);
	tmp = final;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew((*f)(lst->content));
		if (!tmp->next)
		{
			ft_lstclear(&final, del);
			return (0);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (final);
}
