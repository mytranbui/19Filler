/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:45:24 by mbui              #+#    #+#             */
/*   Updated: 2020/10/29 14:34:13 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

/*
** %d & %i: undefined behavior with # (no effect)
*/

/*
** Since 2147483648 is greater than INT_MAX, then abs(-2147483648) is undefined
** LLONG_MIN = −9223372036854775807
*/

static void	print_result_di(intmax_t arg, int pres, t_print *p)
{
	if ((arg != 0 || pres != 0) && (p->type == 'd' || p->type == 'i'))
	{
		if (arg == -9223372036854775807 - 1)
			ft_putstr("9223372036854775808");
		else
			ft_putnbrmax(ft_intmaxabs(arg));
		p->ret += (arg == 0) ? 1 : ft_intlen(ft_intmaxabs(arg));
	}
}

static void	print_di2(intmax_t arg, int len, int bigger_len, t_print *p)
{
	if (p->flg.space && !p->flg.plus && arg >= 0)
	{
		ft_putchar(' ');
		p->ret++;
	}
	if (!p->flg.minus)
	{
		if (p->flg.zero && p->pres == -1)
			putsign(arg, p);
		padding_ze_sp(bigger_len, p);
		if (!p->flg.zero || p->pres != -1)
			putsign(arg, p);
		padding_zero(len, p);
	}
}

void		print_di(intmax_t arg, t_print *p)
{
	int			len;
	int			bigger_len;
	int			tmp_pres;

	len = ft_intlen(ft_intmaxabs(arg));
	tmp_pres = p->pres;
	bigger_len = ft_max(len, p->pres);
	(arg < 0 || (p->flg.plus && arg >= 0)) ? p->width-- : p->width;
	(arg == 0 && p->pres > 0) ? p->pres-- : p->pres;
	(arg == 0 && p->pres == -1) ? p->width-- : p->width;
	(p->flg.space && !p->flg.plus && arg >= 0) ? p->width-- : p->width;
	print_di2(arg, len, bigger_len, p);
	if (!p->flg.minus)
		print_result_di(arg, tmp_pres, p);
	else
	{
		putsign(arg, p);
		padding_zero(len, p);
		print_result_di(arg, tmp_pres, p);
		padding_space(bigger_len, p);
	}
}
