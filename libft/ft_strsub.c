/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:27:37 by mbui              #+#    #+#             */
/*   Updated: 2019/10/15 10:58:34 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;

	i = -1;
	if (!s)
		return (NULL);
	if (!(d = ft_strnew(len)))
		return (NULL);
	while (++i < len)
		d[i] = s[start + i];
	return (d);
}
