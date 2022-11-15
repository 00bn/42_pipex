/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 14:37:26 by balnahdi          #+#    #+#             */
/*   Updated: 2021/10/03 14:44:15 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(char *str)
{
	int		strlen;
	int		i;
	char	*strcpy;

	strlen = 0;
	while (str[strlen] != '\0')
		strlen++;
	strcpy = (char *)(malloc(sizeof(char) * (strlen + 1)));
	if (!strcpy)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		strcpy[i] = str[i];
		i++;
	}
	strcpy[i] = '\0';
	return (strcpy);
}
