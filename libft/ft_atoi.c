/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 09:46:45 by mbui              #+#    #+#             */
/*   Updated: 2019/09/30 18:21:21 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		n;
	long	r;
	long	before_r;

	n = 1;
	r = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			n = -1;
	while (*str >= '0' && *str <= '9')
	{
		before_r = r;
		r = r * 10 + *str++ - 48;
		if (before_r && (before_r ^ r) < 0)
			return (n == 1 ? -1 : 0);
	}
	return ((int)r * n);
}
