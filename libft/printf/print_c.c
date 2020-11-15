/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 09:38:25 by mbui              #+#    #+#             */
/*   Updated: 2020/11/06 18:01:42 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

/*
** %c: undefined behavior with +, 0, ' ', # and precision
*/

void	print_c(va_list ap, t_print *p)
{
	long long	c;

	c = va_arg(ap, long long);
	if (p->flg.minus)
		ft_putchar(c);
	padding_ze_sp(1, p);
	if (!p->flg.minus)
		ft_putchar(c);
	p->ret++;
}
