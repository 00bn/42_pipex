/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:40:19 by balnahdi          #+#    #+#             */
/*   Updated: 2021/10/17 09:50:13 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	a;

	i = ft_strlen(s);
	a = (char)c;
	while (i >= 0)
	{
		if (s[i] == a)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
