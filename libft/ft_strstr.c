/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:11:59 by mbui              #+#    #+#             */
/*   Updated: 2019/04/27 11:42:41 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		k = i;
		while (haystack[i] && needle[j] && haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[k]);
		i = k;
		i++;
	}
	return (0);
}
