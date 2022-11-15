/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:56:11 by balnahdi          #+#    #+#             */
/*   Updated: 2021/10/17 09:40:30 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = (char *) dst;
	s = (const char *) src;
	if (src < dst)
	{
		while (len--)
		{
			d[len] = s[len];
		}
	}
	else
	{
		ft_memcpy(d, s, len);
	}
	return (dst);
}
