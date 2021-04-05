/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:28:09 by mbui              #+#    #+#             */
/*   Updated: 2021/04/02 16:33:55 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** %x & %X: undefined behavior with +, '0' and ' '
*/

static void	print_x2(char *s, t_print *p, int bigger_len, int pres)
{
	int	len;

	len = ft_strlen(s);
	if (p->flg.zero && p->pres == -1)
		putprefix(s, p);
	padding_ze_sp(bigger_len, p);
	if (!p->flg.zero || p->pres != -1)
		putprefix(s, p);
	padding_zero(len, p);
	print_result(s, pres, p);
}

void	print_x(uintmax_t arg, t_print *p)
{
	char		*s;
	int			len;
	int			bigger_len;
	int			tmp_pres;

	s = ft_utoa_base(arg, 16, p->type);
	if (!s)
		free_print(&p, 2);
	len = ft_strlen(s);
	tmp_pres = p->pres;
	bigger_len = ft_max(len, p->pres);
	if (*s != '0' && p->flg.hash)
		p->width -= 2;
	if (*s == '0' && !tmp_pres)
		p->width++;
	if (!p->flg.minus)
		print_x2(s, p, bigger_len, tmp_pres);
	else
	{
		putprefix(s, p);
		padding_zero(len, p);
		print_result(s, tmp_pres, p);
		padding_space(bigger_len, p);
	}
	ft_strdel(&s);
}
