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

char		*ft_itoa(int n)
{
	char	*r;
	int		len;
	int		minus;

	len = size(n);
	if (!(r = ft_strnew(len)))
		return (NULL);
	if (n < 0)
		r[0] = '-';
	minus = (n < 0) ? 1 : 0;
	while (len-- > minus)
	{
		r[len] = (n % 10) * (n < 0 ? -1 : 1) + 48;
		n /= 10;
	}
	return (r);
}
