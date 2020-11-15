/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:20:22 by mbui              #+#    #+#             */
/*   Updated: 2019/04/27 11:37:21 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	l;
	size_t	k;

	i = 0;
	l = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && l <= n)
	{
		j = 0;
		k = i;
		while (haystack[i] && needle[j] && haystack[i] == needle[j] && i < n)
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[k]);
		i = k;
		i++;
		l++;
	}
	return (0);
}
