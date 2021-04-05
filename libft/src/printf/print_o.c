/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:01:48 by mbui              #+#    #+#             */
/*   Updated: 2021/04/02 16:31:22 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** %o: undefined behavior with '+', ' '
*/

static void	print_o3(char *s, t_print *p, int bigger_len, int pres)
{
	int	len;

	len = ft_strlen(s);
	padding_zero(len, p);
	putprefix(s, p);
	print_result(s, pres, p);
	padding_space(bigger_len, p);
}

static void	print_o2(char *s, t_print *p, int bigger_len, int pres)
{
	int	len;

	len = ft_strlen(s);
	padding_ze_sp(bigger_len, p);
	putprefix(s, p);
	padding_zero(len, p);
	print_result(s, pres, p);
}

static void	print_o_if(char *s, t_print *p, int len, int pres)
{
	if (*s == '0' && p->pres != 0)
		p->flg.hash = 0;
	if (p->flg.hash && *s == '0')
		p->pres++;
	if (p->flg.hash && *s != '0' && p->pres <= len)
		p->width--;
	if (p->flg.hash && *s != '0' && p->pres > 0)
		p->pres--;
	if (*s == '0' && !pres && !p->flg.hash)
		p->width++;
}

void	print_o(uintmax_t arg, t_print *p)
{
	char	*s;
	int		len;
	int		bigger_len;
	int		tmp_pres;

	s = ft_utoa_base(arg, 8, 'x');
	if (!s)
		free_print(&p, 2);
	len = ft_strlen(s);
	tmp_pres = p->pres;
	bigger_len = ft_max(len, p->pres);
	print_o_if(s, p, len, tmp_pres);
	if (!p->flg.minus)
		print_o2(s, p, bigger_len, tmp_pres);
	else
		print_o3(s, p, bigger_len, tmp_pres);
	ft_strdel(&s);
}
