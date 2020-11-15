/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:11:13 by mbui              #+#    #+#             */
/*   Updated: 2020/11/10 16:37:13 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

void	putprefix(char *s, t_print *p)
{
	if (p->type == 'p')
	{
		ft_putstr("0x");
		p->ret += 2;
	}
	else if (p->flg.hash && *s != '0')
	{
		if (p->type == 'x')
			ft_putstr("0x");
		else if (p->type == 'X')
			ft_putstr("0X");
		else if (p->type == 'o')
			ft_putchar('0');
		p->ret += (p->type == 'o') ? 1 : 2;
	}
}

void	putsign(intmax_t n, t_print *p)
{
	((p->flg.plus && n >= 0) || (n < 0)) ? p->ret++ : p->ret;
	if (p->flg.plus && n >= 0)
		ft_putchar('+');
	else if (n < 0)
		ft_putchar('-');
}

void	padding_zero(int len, t_print *p)
{
	(p->pres - len > 0) ? p->ret += p->pres - len : p->ret;
	while (p->pres-- - len > 0)
		ft_putchar('0');
}

void	padding_space(int len, t_print *p)
{
	(p->width - len > 0) ? p->ret += p->width - len : p->ret;
	while (p->width-- - len > 0)
		ft_putchar(' ');
}

void	padding_ze_sp(int len, t_print *p)
{
	(p->width - len > 0) ? p->ret += p->width - len : p->ret;
	if (p->type == 'c' || p->type == 's' || p->type == '%' || p->type == 'f'
			|| !p->type)
		while (p->width-- - len > 0)
			ft_putchar((p->flg.zero && !p->flg.minus) ? '0' : ' ');
	else if (p->type == 'o' || p->type == 'u' || p->type == 'x'
			|| p->type == 'X' || p->type == 'd' || p->type == 'i')
		while (p->width-- - len > 0 && !p->flg.minus)
			ft_putchar((p->flg.zero && p->pres == -1) ? '0' : ' ');
}
