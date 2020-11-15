/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:59:17 by mbui              #+#    #+#             */
/*   Updated: 2019/09/28 09:46:00 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	l;
	char	*d;

	i = -1;
	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	while (*s == '\n' || *s == '\t' || *s == ' ')
	{
		l--;
		s++;
	}
	while (l != 0 && (s[l - 1] == '\n' || s[l - 1] == '\t' || s[l - 1] == ' '))
		l--;
	if (!(d = ft_strnew(l)))
		return (NULL);
	while (++i < l)
		d[i] = s[i];
	return (d);
}
