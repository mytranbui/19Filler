/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:33:59 by mbui              #+#    #+#             */
/*   Updated: 2019/09/28 10:52:39 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*d;
	const unsigned char	*s;

	d = s1;
	s = s2;
	while (n--)
	{
		if (*d != *s)
			return (*d - *s);
		d++;
		s++;
	}
	return (0);
}
