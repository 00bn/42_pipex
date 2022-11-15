/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:50:53 by balnahdi          #+#    #+#             */
/*   Updated: 2021/10/17 08:55:13 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*d;
	unsigned char			*s;
	size_t					i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n-- > i)
	{
		*d++ = *s++;
	}
	return (dst);
}
