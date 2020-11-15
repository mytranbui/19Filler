/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 10:59:47 by mbui              #+#    #+#             */
/*   Updated: 2020/11/10 15:57:48 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_size(unsigned long long value, int base)
{
	int	len;

	len = 0;
	while (value)
	{
		len++;
		value /= base;
	}
	return (len);
}

char		*ft_utoa_base(unsigned long long value, int base, char x)
{
	char	*ret;
	char	*str_base;
	int		len;

	str_base = "0123456789abcdef";
	x == 'X' ? str_base = "0123456789ABCDEF" : str_base;
	len = find_size(value, base);
	if (base < 2 || base > 16)
		return (0);
	if (value == 0)
		return (ft_strdup("0"));
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	while (value)
	{
		ret[--len] = str_base[value % base];
		value /= base;
	}
	return (ret);
}
