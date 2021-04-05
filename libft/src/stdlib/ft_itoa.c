/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:00:49 by mbui              #+#    #+#             */
/*   Updated: 2021/04/02 12:54:56 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	size(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*r;
	int		len;
	int		minus;
	int		bit;

	len = size(n);
	r = ft_strnew(len);
	minus = 0;
	bit = 1;
	if (!r)
		return (NULL);
	if (n < 0)
		r[0] = '-';
	if (n < 0)
		minus = 1;
	while (len-- > minus)
	{
		if (n < 0)
			bit = -1;
		else
			bit = 1;
		r[len] = (n % 10) * bit + 48;
		n /= 10;
	}
	return (r);
}
