/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:57:11 by mbui              #+#    #+#             */
/*   Updated: 2021/04/02 13:34:17 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*d;
	unsigned int	i;
	unsigned int	l;

	i = 0;
	if (!s || !f)
		return (NULL);
	l = ft_strlen(s);
	d = ft_strnew(l);
	if (!d)
		return (NULL);
	while (s[i])
	{
		d[i] = f(i, s[i]);
		i++;
	}
	return (d);
}
