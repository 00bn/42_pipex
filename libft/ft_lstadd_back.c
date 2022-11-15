/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:45:35 by balnahdi          #+#    #+#             */
/*   Updated: 2021/10/11 14:01:27 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back_elm;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	back_elm = ft_lstlast(*lst);
	back_elm->next = new;
}
