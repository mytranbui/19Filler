/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:41:33 by mbui              #+#    #+#             */
/*   Updated: 2019/09/27 08:44:58 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strspn(const char *s, const char *charset)
{
	size_t	i;

	i = 0;
	if (!s || !charset)
		return (0);
	while (s[i] && ft_strchr(charset, s[i]))
		i++;
	return (i);
}
