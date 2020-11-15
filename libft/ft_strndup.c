/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 10:23:08 by mbui              #+#    #+#             */
/*   Updated: 2019/09/28 10:09:45 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!(dst = ft_strnew(n)))
		return (NULL);
	while (s1[i] && i < n)
	{
		dst[i] = s1[i];
		i++;
	}
	return (dst);
}
