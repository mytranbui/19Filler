/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:27:37 by mbui              #+#    #+#             */
/*   Updated: 2021/04/02 13:29:10 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;

	i = -1;
	if (!s)
		return (NULL);
	d = ft_strnew(len);
	if (!d)
		return (NULL);
	while (++i < len)
		d[i] = s[start + i];
	return (d);
}
