/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:00:49 by mbui              #+#    #+#             */
/*   Updated: 2020/09/26 10:02:38 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size(int n, size_t len)
{
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char			*r;
	size_t			len;
	unsigned int	nb;

	nb = n;
	len = 1;
	if (n < 0)
	{
		len++;
		nb = -n;
	}
	len = size(n, len);
	if (!(r = ft_strnew(len)))
		return (NULL);
	while (nb / 10 != 0)
	{
		r[--len] = (nb % 10) + 48;
		nb /= 10;
	}
	r[len - 1] = nb + 48;
	if (len == 2)
		r[0] = '-';
	return (r);
}
