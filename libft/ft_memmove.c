/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:01:35 by mbui              #+#    #+#             */
/*   Updated: 2019/09/28 10:47:45 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	i = 0;
	d = dst;
	s = src;
	if (!s && !d)
		return (NULL);
	if (d < s)
		ft_memcpy(d, s, len);
	else
	{
		i = len + 1;
		while (--i > 0)
			d[i - 1] = s[i - 1];
	}
	return (dst);
}
