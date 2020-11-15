/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 09:38:25 by mbui              #+#    #+#             */
/*   Updated: 2020/11/06 18:02:39 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

void	print_percent(t_print *p)
{
	if (p->flg.minus)
		ft_putchar('%');
	padding_ze_sp(1, p);
	if (!p->flg.minus)
		ft_putchar('%');
	p->ret++;
}
