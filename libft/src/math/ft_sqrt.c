/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:50:46 by mbui              #+#    #+#             */
/*   Updated: 2021/04/02 12:41:53 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

double	ft_sqrt(double nb)
{
	double	tmp;
	double	sqrt;

	tmp = 0;
	if (nb < 0)
		return (0);
	sqrt = nb / 2;
	while (sqrt != tmp)
	{
		tmp = sqrt;
		sqrt = (nb / tmp + tmp) / 2;
	}
	return (sqrt);
}
