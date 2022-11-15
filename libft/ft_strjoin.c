/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:37:17 by balnahdi          #+#    #+#             */
/*   Updated: 2021/12/28 16:53:54 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s1 != '\0')
	{
		str[i++] = *s1++;
	}
	while (*s2 != '\0')
	{
		str[i++] = *s2++;
	}
	str[i] = '\0';
	return (str);
}
