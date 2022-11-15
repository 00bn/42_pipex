/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:36:04 by balnahdi          #+#    #+#             */
/*   Updated: 2021/10/17 08:56:51 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*a;
	char	*s;
	int		size;

	size = 0;
	s = (char *)s1;
	if (!s1)
		return (NULL);
	if (!set)
		return (s);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (s1)
		size = ft_strlen(s1);
	while (s1 && ft_strrchr(set, s1[size]) && size > 0)
		size--;
	a = ft_substr(s1, 0, size + 1);
	return (a);
}
