/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:31:49 by balnahdi          #+#    #+#             */
/*   Updated: 2021/10/10 14:46:30 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	len2;

	if (*s2 == '\0')
		return ((char *)s1);
	len2 = ft_strlen(s2);
	while (*s1 != '\0' && len-- >= len2)
	{
		if (ft_strncmp(s1, s2, len2) == 0 && *s1 == *s2)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
