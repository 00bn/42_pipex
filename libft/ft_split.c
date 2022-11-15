/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 09:13:54 by balnahdi          #+#    #+#             */
/*   Updated: 2021/10/17 09:14:06 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(const char *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i + 1] == c || s[i + 1] == '\0')
			&& (!(s[i] == c || s[i] == '\0')))
		{
			words++;
		}
		i++;
	}
	return (words);
}

static void	write_word(char *dest, const char *src, char c)
{
	int	i;

	i = 0;
	while (!(src[i] == c || src[i] == '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	clear(char **s, int i)
{
	while (i--)
		free(s[i]);
	return (0);
}

static int	write_split(char **split, const char *s, char c)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] == c || s[i] == '\0'))
		{
			j = 0;
			while (!(s[i + j] == c || s[i + j] == '\0'))
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!split[word])
				return (clear(split, word - 1));
			write_word(split[word], s + i, c);
			i = i + j;
			word++;
		}
		else
			i++;
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**a;
	int		words;

	if (!s)
		return (NULL);
	words = count(s, c);
	a = (char **)malloc(sizeof(char *) * (words + 1));
	if (!a)
		return (NULL);
	a[words] = 0;
	if (write_split(a, s, c) < 0)
		return (NULL);
	return (a);
}
