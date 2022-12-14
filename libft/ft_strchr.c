/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:43:22 by balnahdi          #+#    #+#             */
/*   Updated: 2021/10/17 09:50:40 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;

	i = 0;
	a = (char)c;
	while ((s[i] != a) && (s[i] != '\0'))
	{
		i++;
	}	
	if (s[i] == a)
	{
		return ((char *)(s + i));
	}
	return (NULL);
}
