/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:57:11 by mbui              #+#    #+#             */
/*   Updated: 2019/04/27 12:16:10 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*d;
	unsigned int	i;
	unsigned int	l;

	i = 0;
	if (!s || !f)
		return (NULL);
	l = ft_strlen(s);
	if (!(d = ft_strnew(l)))
		return (NULL);
	while (s[i])
	{
		d[i] = f(i, s[i]);
		i++;
	}
	return (d);
}
