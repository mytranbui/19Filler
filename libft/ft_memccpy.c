/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:55:06 by mbui              #+#    #+#             */
/*   Updated: 2019/09/28 11:03:00 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;
	char		ch;

	i = -1;
	d = dst;
	s = src;
	while (++i < n)
	{
		ch = *s++;
		*d++ = ch;
		if (ch == (char)c)
			return (d);
	}
	return (NULL);
}
